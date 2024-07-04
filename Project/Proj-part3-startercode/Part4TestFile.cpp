#include "ECTextViewImp.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUITextLabel.h"
#include "ECConsoleUIListBox.h"
#include "ECConsoleUIButton.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

// Function to read the input text file and extract information
void ReadInputFile(const string& filename, vector<string>& airports, vector<pair<string, string>>& distances, vector<tuple<string, string, double, int, int>>& flights, ECAirlineSimulator& simulator) {
    ifstream infile(filename);
    string line;
    while (getline(infile, line)) {
        if (line.empty() || line[0] == '#') continue; // Ignore comments and empty lines
        istringstream iss(line);
        int type;
        iss >> type;
        if (type == 1) {
            string code, description;
            iss >> code >> description;
            string airport = code + " " + description;
            airports.push_back(airport);
            simulator.AddAirport(description, code);
        } else if (type == 2) {
            string origination, destination;
            int distance;
            iss >> origination >> destination >> distance;
            distances.emplace_back(origination, destination);
            simulator.SetDistBtwAirports(origination, destination, distance);
        } else if (type == 3) {
            string origination, destination;
            double time;
            int length, cost;
            iss >> origination >> destination >> time >> length >> cost;
            flights.emplace_back(origination, destination, time, length, cost);
            simulator.AddFlight(origination, destination, time, length, cost);
        }
    }
}


// Function to create UI based on parsed data
void CreateUI(ECConsoleUIView &view, const vector<string>& airports, const vector<pair<string, string>>& distances, const vector<tuple<string, string, double, int, int>>& flights, ECAirlineSimulator& sim) {
    int row = 5;

    // Add list boxes
    view.AddUIItem(new ECConsoleUITextLabel(5, row-1, "Airport Origination"));
    ECConsoleUIListBox *instructorsListBox = new ECConsoleUIListBox(20, row, 40, row + airports.size() + 2);
    for (const auto& flight : flights) {
        string origination, destination;
        tie(origination, destination, ignore, ignore, ignore) = flight;
        instructorsListBox->AddChoice(origination);
    }
    view.AddUIItem(instructorsListBox);


    view.AddUIItem(new ECConsoleUITextLabel(45, row-1, "Airport Destination"));
    ECConsoleUIListBox *lecturesListBox = new ECConsoleUIListBox(60, row, 80, row + airports.size() + 2);
    for (const auto& flight : flights) {
        string origination, destination;
        tie(origination, destination, ignore, ignore, ignore) = flight;
        lecturesListBox->AddChoice(destination);
    }
    view.AddUIItem(lecturesListBox);


    row= row+10;

    view.AddUIItem(new ECConsoleUITextLabel(40, row - 1, "Flights"));
    ECConsoleUIListBox *flightsListBox = new ECConsoleUIListBox(40, row, 120, row + flights.size() + 2);
    for (const auto& flight : flights) {
        string origination, destination;
        double time;
        int length, cost;
        tie(origination, destination, time, length, cost) = flight;
        flightsListBox->AddChoice(origination + " " + destination + " (" + to_string(time) + " hrs, $" + to_string(cost) + ", " + to_string(length) + " seats)");
    }
    view.AddUIItem(flightsListBox);

    row += 12;

    //Add itineraries listbox
    ECConsoleUIListBox *itinerariesListBox = new ECConsoleUIListBox(40, row + 5, 120, row + 15);
    view.AddUIItem(itinerariesListBox);

    //Add search button
    ECConsoleUITextLabel *pl9 = new ECConsoleUITextLabel(40, row-1, "------------");
    view.AddUIItem(pl9);
    view.AddUIItem(new ECConsoleUIButton(40, row, 40 + 11, row, "Search", *instructorsListBox, *lecturesListBox, *itinerariesListBox, sim));
    ECConsoleUITextLabel *pl10 = new ECConsoleUITextLabel(40, row+1, "------------");
    view.AddUIItem(pl10);


}


void displayItineraries(const std::string& sourceAirport, const std::string& destinationAirport, ECConsoleUIListBox& itinerariesListBox, ECAirlineSimulator& simulator)
{
    //open debugging output file to display info
    std::ofstream outputFile("flight_search.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open debug file for writing" << std::endl;
        return;
    }
    outputFile << "Selected source: " << sourceAirport << std::endl;
    outputFile << "Selected destination: " << destinationAirport << std::endl;


    // Search for valid flight itineraries using the simulator
    std::vector<ECFlightItinerary> validItineraries;
    // Call the simulator function to search for flights
    simulator.SearchForFlights(sourceAirport, destinationAirport, validItineraries);
    
    outputFile << "Flight search complete" << std::endl;

    itinerariesListBox.ClearChoices();
    

    // Check if any valid itineraries were found
    if (validItineraries.empty())
    {
        outputFile << "No valid itineraries found." << std::endl;
    }
    else
    {
        // Write the valid itineraries to the output file
        outputFile << "Valid itineraries:" << std::endl;
        for (const auto& itinerary : validItineraries)
        {
            outputFile << itinerary.ToString() << std::endl; // Assuming you have a ToString() method in ECFlightItinerary class
        }
        
        // Also add valid flight itineraries to the itineraries list box
        for (const auto& itinerary : validItineraries)
        {
            itinerariesListBox.AddChoice(itinerary.ToString()); // Assuming you have a ToString() method in ECFlightItinerary class
        }
    }

    // Close the output file
    outputFile.close();
}



int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " input_file.txt" << endl;
        return 1;
    }

    vector<string> airports;
    vector<pair<string, string>> distances;
    vector<tuple<string, string, double, int, int>> flights;

    ECAirlineSimulator sim;


    //read inout file and set up simulation
    ReadInputFile(argv[1], airports, distances, flights, sim);

    // Construct UI
    ECTextViewImp wndTest;
    ECConsoleUIView viewUI(&wndTest);
    CreateUI(viewUI, airports, distances, flights, sim);

    // Display UI
    viewUI.Refresh();
    wndTest.Show();

    return 0;
}