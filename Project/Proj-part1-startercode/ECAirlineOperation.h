//
//  ECAirlineOperation.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//  About operation of an airline: especially flights management

#include <vector>

#ifndef ECAirlineOperation_h
#define ECAirlineOperation_h

class ECFlight;
// put your code about airline operation here...
class ECAirlineOperation
{
public:
    ECAirlineOperation();
    virtual ~ECAirlineOperation();
    
    // Add a flight to the airline's operations
    void AddFlight(const ECFlight& flight);
    
    // Get all flights
    const std::vector<ECFlight>& GetAllFlights() const;
    
private:
    std::vector<ECFlight> flights;
};


#endif /* ECAirlineOperation_h */

