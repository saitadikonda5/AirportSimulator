//
//  ECAirlineFinancial.h
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#ifndef ECAirlineFinancial_h
#define ECAirlineFinancial_h
#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <string>
#include <vector>

// ****************************************************************************
// Airline finanical: budgetting, pricing and money bookkeeping

class ECAirlineFinancial
{
public:
    ECAirlineFinancial();
    virtual ~ECAirlineFinancial();
    
    //Calculate price of a flight itinerary
    double CalculatePrice(const ECFlightItinerary& itinerary) const;
};

#endif /* ECAirlineFinancial_h */
