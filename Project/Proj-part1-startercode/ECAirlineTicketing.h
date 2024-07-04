//
//  ECAirlineTicketing.h
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#ifndef ECAirlineTicketing_h
#define ECAirlineTicketing_h
#include <string>
#include <vector>

class ECFlightItinerary;
class ECFlight;
// ****************************************************************************
// Airline ticketing: search for flights, issue tickets, etc



class ECAirlineTicketing
{
public:
    ECAirlineTicketing();
    virtual ~ECAirlineTicketing();
    
    // Search for flights between source and destination airports
    std::vector<ECFlightItinerary> SearchForFlights(const std::string& sourceAirport, const std::string& destinationAirport, const std::vector<ECFlight>& flights) const;
    
    // Book a flight itinerary
    void BookFlight(const ECFlightItinerary& itinerary);
};


#endif /* ECAirlineTicketing_h */
