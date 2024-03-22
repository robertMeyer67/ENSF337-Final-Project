//
//  airline.hpp
//  Final Project 2
//
//  Created by Robert Meyer on 2023-11-29.
//

#ifndef AIRLINE_CLASS
#define AIRLINE_CLASS

#include "flight.hpp"
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Airline {
    
public:
    Airline(): airline_name("N/A"), num_flights(0) { }
    Airline(string n, int num): airline_name(n), num_flights(num), flights(num_flights) { }
    void add_flight(const Flight& new_flight);
    void remove_flight(string fnum);
    
    const string get_name() const {return airline_name;}
    const int get_num_flights() const {return num_flights;}
    
    void set_name(string n) {airline_name = n;}
    
private:
    string airline_name;
    int num_flights;
    vector<Flight> flights;
};

#endif /* airline_hpp */
