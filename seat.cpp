//
//  seat.cpp
//  Final Project 2
//
//  Created by Robert Meyer on 2023-11-25.
//

#include "seat.hpp"

Seat::Seat(): row(0), seat(0), occupied(false) { }

Seat::Seat(int r, int s): row(r), seat(s), occupied(false) { }

const int Seat::get_row() const {return row;}

const char Seat::get_seat() const {return seat;}

const bool Seat::get_occupation() const {return occupied;}

void Seat::set_row(int r) {row = r;}

void Seat::set_seat(char s) {seat = s;}

void Seat::set_occucation(bool set) {occupied = set;}


