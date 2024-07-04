//
//  ECFlightItinerary.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlightItinerary_h
#define ECFlightItinerary_h

#include <vector>
#include <string>

class ECFlight;
class ECAirlineFinancial;

// ****************************************************************************
// Flight itineary: consisting segments of flights so to go from one airport to another airport

class ECFlightItinerary
{
public:
    ECFlightItinerary();
    
    // access/edit segments
    // Return the number of segments of the itineary
    int GetNumSegments() const;
    
    // Return a segment
    ECFlight *GetSegment(int segIndex) const;
    
    // Get flight time: from departure to arrival
    double GetFlightTime() const;
    
    // Get segment time: add the time of all segments
    double GetTimeAllSegments() const;
    
    // Get departure time
    double GetDepartTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;
    
    // Price 
    double GetPrice() const;


    //additional methods
    // Add a flight segment to the itinerary
    void AddSegment(const ECFlight& flight);

    // Check if the itinerary is valid
    bool IsValid() const;

    void Dump() const;


    // Function to check if adding a flight segment is valid
    bool IsValidNextSegment(const ECFlight& flight) const;

    // Function to add a flight segment to the itinerary
    //void AddSegment(const ECFlight& flight);

    // Function to remove the last flight segment from the itinerary
    void RemoveLastSegment();

    std::string ToString() const;

    

    
    
private:
    // your code
    std::vector<ECFlight> segments; // Vector to store flight segments

    bool validity;

    void UpdatePrice();
};

#endif /* ECFlightItinerary_h */
