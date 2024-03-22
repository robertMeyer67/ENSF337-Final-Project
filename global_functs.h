//
//  global_functs.h
//  Final Project 2
//
//  Created by Robert Meyer on 2023-12-03.
//

#ifndef GLOBAL_FUNCTS
#define GLOBAL_FUNCTS

void readFlightFile(const string &filename, Flight &flight);

void displayMenu();

void showSeatMap(const Flight &flight);

void showPassengerInfo(const Flight &flight);

void addPassenger(Flight &flight);

void removePassenger(Flight &flight);

void saveToFile(const string &filename, const Flight &flight);

void cleanbuffer();

void display_header();

#endif /* GLOBAL_FUNCTS */
