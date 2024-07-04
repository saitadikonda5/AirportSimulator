//
//  ECAirport.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirport.h"
#include <unordered_map>
#include "ECFlight.h"
#include <vector>
#include <stdexcept>


//******************************ECAirport

ECAirport::ECAirport() : operating(false) {}

ECAirport::ECAirport(const std::string& name, const std::string& code) : nameAP(name), codeIATA(code), operating(true) {}

ECAirport::ECAirport(const ECAirport& rhs) : nameAP(rhs.nameAP), codeIATA(rhs.codeIATA), operating(rhs.operating) {}

std::string ECAirport::GetName() const {
    return nameAP;
}

std::string ECAirport::GetCode() const {
    return codeIATA;
}

bool ECAirport::IsOperating(){
    return operating;
}

void ECAirport::SetOperating(bool isOperating) {
    operating = isOperating;
}




//***********************************ECAirportInfo


ECAirportInfo& ECAirportInfo::getInstance() {
    static ECAirportInfo instance;
    return instance;
}

void ECAirportInfo::CreateAirport(const std::string& name, const std::string& code) {
    airports[code] = ECAirport(name, code);
}

const ECAirport& ECAirportInfo::GetAirport(const std::string& code) const {
    auto it = airports.find(code);
    if (it == airports.end()) {
        throw std::runtime_error("Airport with code " + code + " not found.");
    }
    return it->second;
}

void ECAirportInfo::SetDistanceBtw(const std::string& ap1Code, const std::string& ap2Code, int dist) {
    //Set distance between
    distances[ap1Code][ap2Code] = dist;
    distances[ap2Code][ap1Code] = dist;
}

int ECAirportInfo::GetDistanceBtw(const std::string& ap1Code, const std::string& ap2Code) const {
    //return distance between
    auto it = distances.find(ap1Code);
    if (it != distances.end()) {
        auto innerIt = it->second.find(ap2Code);
        if (innerIt != it->second.end()) {
            // If distance is found, return
            return innerIt->second;
        }
    }

    //else throw exception
    throw std::runtime_error("distance between airports not found");
}
