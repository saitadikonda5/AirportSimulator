//
//  ECAirport.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECAirport_h
#define ECAirport_h

#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>



// ****************************************************************************
// Airport: start/end point of a flight

class ECAirport 
{
public:
    // by default, airport is operating (except in default constructor)

    //default constructor is false
    ECAirport();
 
    //constructor with airport name and IATA code
    ECAirport(const std::string &nameAP, const std::string &codeIATA);

    //copy constructor
    ECAirport(const ECAirport &rhs);

    
    // Get the name of the airport
    std::string GetName() const;
    
    // Get IATA code
    std::string GetCode() const;
    
    // Operating status: is it operating normally?
    bool IsOperating();
    
    // Set operating status
    void SetOperating(bool isOperating);
    
private:
    // your code
    bool operating; //true if operating, false if not
    std::string nameAP; //airport name
    std::string codeIATA; //airport code

};

// ****************************************************************************
// Airport info: access airport information
// Use singleton pattern

class ECAirportInfo
{
public:

    //Static method to get the instance of ECAirportInfo
    static ECAirportInfo& getInstance();
    
    void CreateAirport(const std::string &name, const std::string &code);
    

    const ECAirport &GetAirport(const std::string &code) const;
    
    // Set distance (in miles) between airports
    void SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist);
    
    // more to add...
    int GetDistanceBtw(const std::string& ap1Code, const std::string& ap2Code) const;

    
private:
   // your code 
    ECAirportInfo() {} //private constructor for singleton pattern

    std::unordered_map<std::string, ECAirport> airports; 
    std::unordered_map<std::string, std::unordered_map<std::string, int> > distances;  //2 airports then the corresponding distance between
};


#endif /* ECAirport_h */

