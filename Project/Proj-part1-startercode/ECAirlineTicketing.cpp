//
//  ECAirlineTicketing.cpp
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#include "ECAirlineTicketing.h"
#include <iostream> 
#include <vector>
#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <set>
#include <functional>


ECAirlineTicketing::ECAirlineTicketing() {}

ECAirlineTicketing::~ECAirlineTicketing() {}

std::vector<ECFlightItinerary> ECAirlineTicketing::SearchForFlights(const std::string& sourceAirport, const std::string& destinationAirport, const std::vector<ECFlight>& flights) const {
    //Uses depth first search from <functional> to return all possible valid flight itineraries
    
    std::vector<ECFlightItinerary> itineraries;

    //set of visited airports to not revisit
    std::set<std::string> visitedAirports;

    //helper function to do dfs as a lambda function(got partially from stack overflow)
    std::function<void(const std::string&, const std::string&, ECFlightItinerary&)> dfs = [&](const std::string& currentAirport, const std::string& destination, ECFlightItinerary& currentItinerary) {
        //check if the current airport is the destination
        if (currentAirport == destination) {
            itineraries.push_back(currentItinerary);
            return;
        }
        //put in visited set
        visitedAirports.insert(currentAirport);

        //Iterate through all departing flights from the airport
        for (const ECFlight& flight : flights) {
            if (flight.GetSource() == currentAirport && currentItinerary.IsValidNextSegment(flight)) {

                if (visitedAirports.find(flight.GetDest()) == visitedAirports.end()) {
                    currentItinerary.AddSegment(flight);
                    //recursively call dfs again
                    dfs(flight.GetDest(), destination, currentItinerary);
                    //backtrack
                    currentItinerary.RemoveLastSegment();
                }
            }
        }

        visitedAirports.erase(currentAirport);
    };

    ECFlightItinerary currentItinerary;
    dfs(sourceAirport, destinationAirport, currentItinerary);

    return itineraries;
}


void ECAirlineTicketing::BookFlight(const ECFlightItinerary& itinerary) {
    //booking a flight
}




