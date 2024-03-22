//
//  Header.h
//  Final Project
//
//  Created by Robert Meyer on 2023-11-21.
//

#include <iostream>
#include <string>
using namespace std;


#ifndef SEAT_CLASS
#define SEAT_CLASS
class Seat {
    
public:
    Seat();
    Seat(int r, int s);
    const int get_row() const;
    const char get_seat() const;
    const bool get_occupation() const;
    void set_row(int r);
    void set_seat(char s);
    void set_occucation(bool set);
    
private:
    int row;
    char seat;
    bool occupied;
};
#endif

