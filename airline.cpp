//
//  airline.cpp
//  Final Project 2
//
//  Created by Robert Meyer on 2023-11-29.
//

#include "airline.hpp"

void Airline::add_flight(const Flight& new_flight) {
    flights.push_back(new_flight);
    num_flights++;
}

void Airline::remove_flight(string fnum) {
    for (int i = 0; i < flights.size(); i++) {
        if (flights.at(i).get_flight_num() == fnum) {
            flights.erase(flights.begin()+i);
            num_flights--;
        }
    }
}
