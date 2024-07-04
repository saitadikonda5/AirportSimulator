//
//  ECAirlineOperation.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"
#include "ECFlight.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//ECAirlineOperation Class

ECAirlineOperation::ECAirlineOperation() {}

ECAirlineOperation::~ECAirlineOperation() {}

void ECAirlineOperation::AddFlight(const ECFlight& flight) {
    flights.push_back(flight);
}

const std::vector<ECFlight>& ECAirlineOperation::GetAllFlights() const {
    return flights;
}