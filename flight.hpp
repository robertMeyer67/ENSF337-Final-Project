//
//  flight.hpp
//  Final Project
//
//  Created by Robert Meyer on 2023-11-22.
//

#include "passenger.hpp"
#include "seat.hpp"
#ifndef FLIGHT_CLASS
#define FLIGHT_CLASS

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Passenger item;
  Node* next;
};

typedef  vector< vector<Seat> > seat_map;

class Flight {
    
public:
//    Flight(): headM(nullptr), seat_map() { }
    Flight(): headM(nullptr), flight_num("N/A"), numRows(0), numSeats(0) { }
    Flight(string num, int rows, int seats);
    Flight(const Flight& src): headM(nullptr) {copy(src);}
    Flight& operator=(const Flight& rhs);
    ~Flight() {destroy();}
    void add(const Passenger& new_pass);
    void remove(const int id_num);
    const Passenger* get_passenger(const int id_num) const;
    void print_passengers() const;
    
    void set_seat_map(int r, char s);
    Seat* get_seat(int r, char s) {return &(seatMap.at(r).at((int) (s - 'A')));}
    void print_seat_map() const;
    
    void set_flight_num(string flightN) {flight_num = flightN;}
    const string get_flight_num() const {return flight_num;}
    const int get_numRows() const {return numRows;}
    const int get_numSeats() const {return numSeats;}
    const Node* get_headM() const {return headM;}
    

private:
    Node* headM;
    void destroy();
    void copy(const Flight& src);
    
    string flight_num;
    int numRows;
    int numSeats;
    seat_map seatMap;
    
};


#endif /* FLIGHT_CLASS */
