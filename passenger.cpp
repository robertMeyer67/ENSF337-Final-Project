//
//  passenger.cpp
//  Final Project 2
//
//  Created by Robert Meyer on 2023-11-25.
//

#include "passenger.hpp"

Passenger::Passenger(): Fname(" "), Lname(" "), Pnum(" "), Pseat(nullptr), Pid(0){ }

Passenger::Passenger(int id_num): Fname(" "), Lname(" "), Pnum(" "), Pseat(nullptr), Pid(id_num) { }

Passenger::Passenger(string first, string last, string phone, Seat* seat, int id_num) {
    Pid = id_num;
    Fname = first;
    Lname = last;
    Pnum = phone;
    Pseat = seat;
    
    Pseat->set_occucation(true);
}

const string Passenger::get_Fname() const {return Fname;}

const string Passenger::get_Lname() const {return Lname;}

const string Passenger::get_Pnum() const {return Pnum;}

Seat* Passenger::get_Pseat() const {return Pseat;}

const int Passenger::get_Passid() const {return Pid;}

void Passenger::set_Fname(string First) {Fname = First;}

void Passenger::set_Lname(string Last) {Lname = Last;}

void Passenger::set_Pnum(string Phone) {Pnum = Phone;}

void Passenger::set_Pseat(Seat* seat, bool occupation) {
    seat->set_occucation(occupation);
    Pseat = seat;
}

void Passenger::set_Pid(int ID) {Pid = ID;}


