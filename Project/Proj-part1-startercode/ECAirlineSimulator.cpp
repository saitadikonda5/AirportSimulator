//
//  ECAirlineSimulator.cpp
//  
//
//  Created by Yufeng Wu on 5/17/23.
//

#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirport.h"
#include "ECFlight.h"
#include "ECFlightItinerary.h"

#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;


ECAirlineSimulator::ECAirlineSimulator() {
    Init();
}

ECAirlineSimulator::~ECAirlineSimulator() {
    delete pAirlineOp;
    delete pAirlineFin;
    delete pAirlineTicket;
}

void ECAirlineSimulator::Init() {
    pAirlineOp = new ECAirlineOperation();
    pAirlineFin = new ECAirlineFinancial();
    pAirlineTicket = new ECAirlineTicketing();
}



void ECAirlineSimulator::PreferLowPrice() {
    //preferring low price
}


void ECAirlineSimulator::PreferShortTime() {
    //preferring short time
}


void ECAirlineSimulator::PreferEarlyArrival() {
    //preferring early arrival
}


void ECAirlineSimulator::Dump() const {
}


void ECAirlineSimulator::AddAirport(const std::string &name, const std::string &code) {
    // Check if the airport code already exists
    if (airports.find(code) != airports.end()) {
        cout << "Airport with code " << code << " already exists.\n";
        return;
    }

    airports[code] = name;
    //cout << "Added airport: " << name << " (" << code << ")\n";
}


void ECAirlineSimulator::SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist) {
    //check that the airports exist before setting the distance
    try {
        ECAirportInfo::getInstance().SetDistanceBtw(srcAirport, destAirport, dist);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ECAirlineSimulator::AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate ) {
    // Check if the same itinerary already exists
    for (const ECFlight& existingFlight : flights) {
        if (existingFlight.GetSource() == srcAirport && existingFlight.GetDest() == destAirport &&
            existingFlight.GetDepartureTime() == tmDepart && existingFlight.GetMaxPassengers() == maxPassengers) {
            //Itinerary already exists,  don't add this flight
            return;
        }
    }
    // else add the flight
    ECFlight flight(srcAirport, destAirport, tmDepart, maxPassengers);
    flights.push_back(flight);
}

void ECAirlineSimulator::DoneFlightAdding() {
    //no more flights to add function
}

const std::vector<ECFlight>& ECAirlineSimulator::GetFlights() const {
    return flights;
}



void ECAirlineSimulator::SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries ) const {
    //Delegated functionality to ECAirlineTicketing
    listItineraries = pAirlineTicket->SearchForFlights(src, dest, GetFlights());
}