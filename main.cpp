#include <iostream>
#include <fstream>
#include <sstream>
#include "flight.hpp"
#include "seat.hpp"
#include "passenger.hpp"
#include "global_functs.h"
//#include "seat_map.hpp"
#include <string>


using namespace std;


int main()
{
   // Create objects for Flight and Seat_map
   Flight flight;

    string file_name = "flight_info.txt";
    
   // Read flight information from the file
   readFlightFile(file_name, flight);

    display_header();
//    cleanbuffer();

   int choice;
   do
   {
       displayMenu();
       cout << "Enter your choice: ";

//       cleanbuffer();
       // ensuring that choice is a valid input
       while (!(cin >> choice)) {
           cout << "\nInvalid choice. Please enter a valid option: ";
           cleanbuffer();
       }

       switch (choice)
       {
       case 1:
            showSeatMap(flight);
           break;
       case 2:
           showPassengerInfo(flight);
           break;
       case 3:
           addPassenger(flight);
           break;
       case 4:
               cout << "remove chosen" << endl;
           removePassenger(flight);
           break;
       case 5:
           saveToFile(file_name, flight);
           break;
       case 6:
           // Terminate the program
           cout << "Exiting the program. Goodbye!" << endl;
           break;
       default:
           cout << "Invalid choice. Please enter a valid option." << endl;
       }
   } while (choice != 6);

   return 0;
}


void readFlightFile(const string &filename, Flight &flight)
{
   ifstream file(filename);

    //checking if the file is open or not
   if (!file.is_open())
   {
       cerr << "Error opening file: " << filename << endl;
       exit(1);
   }


   string flightNumber;
   int numRows, numSeats;
    
   file >> flightNumber >> numRows >> numSeats;

    flight.set_flight_num(flightNumber);
    
   // Update Seat_map with the correct number of rows and seats
    flight.set_seat_map(numRows, numSeats);

   // Read passenger information and add them to the Flight object
   string line;
   while (getline(file, line))
   {
       if (line.empty())
       {
           // Skip empty lines
           continue;
       }
       stringstream ss(line);
       

       string firstName, lastName, phoneNumber;
       char seat;
       int row, idNumber;
       
       
       char ch1 = ss.get();
       char ch2 = ss.get();
              
       while (ch1 != ' ' || ch2 != ' ') {
           firstName.append(1, ch1);
           
           ch1 = ch2;
           ch2 = ss.get();
       }
       
       while (ch1 == ' ') {
           ch1 = ch2;
           ch2 = ss.get();
       }
       
       while (ch1 != ' ' || ch2 != ' ') {
           lastName.append(1, ch1);
           
           ch1 = ch2;
           ch2 = ss.get();
       }
       
       
       ss >> phoneNumber >> row >> seat >> idNumber;
       
       // Create a new Passenger object
       Passenger passenger(idNumber);
       passenger.set_Fname(firstName);
       passenger.set_Lname(lastName);
       passenger.set_Pnum(phoneNumber);


       passenger.set_Pseat(flight.get_seat(row, seat), true);


       // Add the passenger to the Flight
       flight.add(passenger);
   }


   file.close();
}


void displayMenu()
{
   cout << "\nMenu:\n";
   cout << "1. Show flight seat map\n";
   cout << "2. Show passenger information\n";
   cout << "3. Add a new passenger\n";
   cout << "4. Remove an existing passenger\n";
   cout << "5. Save passenger information to file\n";
   cout << "6. Terminate the program\n";
}


void showSeatMap(const Flight &flight)
{
   // Implementation to display the seat map (use seatMap.display())
    flight.print_seat_map();
}


void showPassengerInfo(const Flight &flight)
{
   // Implementation to display passenger information (use flight.print())
    flight.print_passengers();
}


void addPassenger(Flight &flight)
{
   // Implementation to add a new passenger (prompt user for input)
    string first, last, phone;
    int row, ID;
    char seat;
    
    cout << "Please enter the passenger id: ";
    while (!(cin >> ID) || ID > 99999 || ID < 0) {
        cout << "That Id number is invalid, please enter another: ";
        cleanbuffer();
    }
    
    cleanbuffer();
    cout << "Please enter the passenger first name: ";
    while (!(cin >> first) || first.length() > 20) {
        cout << "That first name is invalid, please enter another: ";
        cleanbuffer();
    }
    
    cleanbuffer();
    cout << "Please enter the passenger last name: ";
    while (!(cin >> last) || last.length() > 20) {
        cout << "That last name is invalid, please enter another: ";
        cleanbuffer();
    }

    cleanbuffer();
    cout << "Please enter the passenger phone number: ";
    while (!(cin >> phone) || phone.length() > 20) {
        cout << "That phone number is invalid, please enter another: ";
        cleanbuffer();
    }

    cleanbuffer();
    cout << endl << "Enter the passenger's desired row: ";
    while (!(cin >> row) || row >= flight.get_numRows() || row < 0) {
        cout << "\nThat is an invalid row, please enter another: ";
        cleanbuffer();
    }

    cleanbuffer();
    cout << "Enter the passenger's desired seat: ";
    while (!(cin >> seat) || seat - 'A' >= flight.get_numSeats() || seat - 'A' < 0) {
        cout << "\nThat is an invalid seat, please enter another: ";
        cleanbuffer();
    }
    cout << endl;
    
    flight.add(Passenger(first, last, phone, flight.get_seat(row, seat), ID));
    cout << "passenger added" << endl;
}


void removePassenger(Flight &flight)
{
   // Implementation to remove an existing passenger (prompt user for input)
    int ID;
    
    cout << "Please enter the id of the passenger that needs to be removed: ";
        while (!(cin >> ID)) {
        cout << "That Id number is invalid, please enter another: ";
        cleanbuffer();
    }
    
    flight.remove(ID);
}


void saveToFile(const string &filename, const Flight &flight)
{
   // Implementation to save passenger information to file
    ofstream outfile(filename);
    
    if (outfile.fail()) {
        cout << "Error opening file" << endl;
        return;
    }
    
    outfile << flight.get_flight_num() << "    " << flight.get_numRows() << "  " << flight.get_numSeats() << endl;
    for (const Node* p = flight.get_headM(); p != nullptr; p = p->next) {
        outfile << left << setw(20) << p->item.get_Fname() << setw(20) << p->item.get_Lname() << setw(20) << p->item.get_Pnum() << p->item.get_Pseat()->get_row() << p->item.get_Pseat()->get_seat() << setw(3) << " " << setw(8) << p->item.get_Passid() << endl;

    }
    outfile.close();
}

void cleanbuffer() {
    
    cin.clear();
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void display_header()
{
   // Display the program title
   cout << "\nVersion: 1.0" << endl;
   cout << "Term Project – Flight Management Program in C++" << endl;
   cout << "Produced by: Robert Meyer and Arnav Mittal" << endl;
    cout << "\n <<< Press Return to Continue >>> \n ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
