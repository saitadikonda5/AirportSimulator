//
//  ECAirlineFinancial.cpp
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#include "ECAirlineFinancial.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECFlight.h"

#include <string>
#include <iostream>
#include <vector>
using namespace std;



ECAirlineFinancial::ECAirlineFinancial() {}

ECAirlineFinancial::~ECAirlineFinancial() {}

double ECAirlineFinancial::CalculatePrice(const ECFlightItinerary& itinerary) const {

    double flightTime = itinerary.GetFlightTime();
    double price = 120.0 * flightTime; //$120 per hour of flight time
    return price;
}

