//
//  ECFlight.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlight.h"
#include "ECAirport.h"

#include <iostream>
#include <vector>
using namespace std;

ECFlight::ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn)
    : source(srcIn), destination(destIn), departureTime(tmDepartIn), maxPassengers(maxPassengersIn) {
    
    //get distance between airports
    int distance = ECAirportInfo::getInstance().GetDistanceBtw(source, destination);
    
    //flight time determined by distance and 500 mph
    double flightTime = static_cast<double>(distance) / 500.0;
    arrivalTime = departureTime + flightTime;
}

ECFlight::~ECFlight() {}

double ECFlight::GetDepartureTime() const {
    return departureTime;
}

double ECFlight::GetArrivalTime() const {
    return arrivalTime;
}

void ECFlight::SetMaxNumPassengers(int m) {
    maxPassengers = m;
}

std::string ECFlight::GetSource() const {
    return source;
}

std::string ECFlight::GetDest() const {
    return destination;
}

int ECFlight::GetMaxPassengers() const{
    return maxPassengers;
}

