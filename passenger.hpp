//
//  passenger.h
//  Final Project
//
//  Created by Robert Meyer on 2023-11-21.
//

#include "seat.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef PASSENGER_CLASS
#define PASSENGER_CLASS

class Passenger {

public:
//    Passenger(string First, string Last, string Phone, Seat * seat, int id_num);
    Passenger();
    Passenger(int id_num);
    Passenger(string first, string last, string phone, Seat* seat, int id_num);
    const string get_Fname() const;
    const string get_Lname() const;
    const string get_Pnum() const;
    Seat* get_Pseat() const;
    const int get_Passid() const;
    void set_Fname(string First);
    void set_Lname(string Last);
    void set_Pnum(string Phone);
    void set_Pseat(Seat* seat, bool occupation);
    void set_Pid(int ID);
    
private:
    string Fname;
    string Lname;
    string Pnum;
    Seat* Pseat;
    int Pid;
};



#endif /* passenger_h */
