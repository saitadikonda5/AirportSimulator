//
//  ECFlightItinerary.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;



ECFlightItinerary::ECFlightItinerary() {}

int ECFlightItinerary::GetNumSegments() const {
    return segments.size();
}

ECFlight *ECFlightItinerary::GetSegment(int segIndex) const {
    if (segIndex >= 0 && segIndex < segments.size()) {
        return const_cast<ECFlight*>(&segments[segIndex]);
    }
    return nullptr;
}

double ECFlightItinerary::GetFlightTime() const {
    double totalFlightTime = 0.0;
    for (const ECFlight& flight : segments) {
        double departTime = flight.GetDepartureTime();
        double arriveTime = flight.GetArrivalTime();
        totalFlightTime += arriveTime - departTime;
    }
    return totalFlightTime;
}


double ECFlightItinerary::GetTimeAllSegments() const {
    if (!segments.empty()) {
        return segments.back().GetArrivalTime() - segments.front().GetDepartureTime();
    }
    return 0.0;
}

double ECFlightItinerary::GetDepartTime() const {
    if (!segments.empty()) {
        return segments.front().GetDepartureTime();
    }
    return 0.0;
}

double ECFlightItinerary::GetArrivalTime() const {
    if (!segments.empty()) {
        return segments.back().GetArrivalTime();
    }
    return 0.0;
}

double ECFlightItinerary::GetPrice() const {
    return 120.0 * (GetFlightTime()); //120$ per hour
}

void ECFlightItinerary::AddSegment(const ECFlight& flight) {
    segments.push_back(flight);
    UpdatePrice();
}

bool ECFlightItinerary::IsValid() const {
    if (segments.empty()) {
        return false; //not valid
    }
    for (size_t i = 1; i <= segments.size(); ++i) {
        if (segments[i].GetDepartureTime() < segments[i - 1].GetArrivalTime()) {
            return false; //not valid
        }
    }
    return true;
}

void ECFlightItinerary::UpdatePrice() {
}



void ECFlightItinerary::Dump() const {
    std::cout << "Flight Itinerary Details:" << std::endl;
    std::cout << "Number of segments: " << GetNumSegments() << std::endl;
    std::cout << "Total flight time: " << GetFlightTime() << " hours" << std::endl;
    std::cout << "Total time for all segments: " << GetTimeAllSegments() << " hours" << std::endl;
    std::cout << "Departure time: " << GetDepartTime() << std::endl;
    std::cout << "Arrival time: " << GetArrivalTime() << std::endl;
    std::cout << "Price: " << GetPrice() << std::endl;
    std::cout << "Validity: " << (IsValid() ? "Valid" : "Invalid") << std::endl;
}





// Function to check if adding a flight segment is valid
bool ECFlightItinerary::IsValidNextSegment(const ECFlight& flight) const {
    //if empty, anything could be added
    if (segments.empty()) {
        return true;
    }


    double lastArrivalTime = segments.back().GetArrivalTime();

    double flightDepartureTime = flight.GetDepartureTime();

    if (flightDepartureTime > lastArrivalTime) {
        return true;
    } else {
        return false;
    }
}


// Function to remove the last flight segment from the itinerary
void ECFlightItinerary::RemoveLastSegment() {
    if (!segments.empty()) {
        segments.pop_back();
    }
}


std::string ECFlightItinerary::ToString() const {
    std::string result;
    for (size_t i = 0; i < segments.size(); ++i) {
        const ECFlight& flight = segments[i];
        result += flight.GetSource() + " -> ";
    }
    if (!segments.empty()) {
        result += segments.back().GetDest();
    }
    return result;
}



