//
//  flight.cpp
//  Final Project
//
//  Created by Robert Meyer on 2023-11-22.
//

#include "flight.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

Flight::Flight(string num, int rows, int seats): headM(nullptr), flight_num(num), numRows(rows), numSeats(seats){
    
    seatMap.resize(numRows);
    
    for (int i = 0; i < numRows; i++) {
        seatMap.at(i).resize(numSeats);
        
        for (int j = 0; j < numSeats; j++) {
            seatMap.at(i).at(j).set_row(i);
            seatMap.at(i).at(j).set_seat((char) (j + 'A'));
        }
        
    }
    
}

void Flight::set_seat_map(int r, char s) {
    numRows = r;
    numSeats = s;
    
    seatMap.resize(numRows);
    
    for (int i = 0; i < numRows; i++) {
        seatMap.at(i).resize(numSeats);
        
        for (int j = 0; j < numSeats; j++) {
            seatMap.at(i).at(j).set_row(i);
            seatMap.at(i).at(j).set_seat((char) (j + 'A'));
        }
        
    }

}

void Flight::add(const Passenger& new_pass) {
    Node *new_node = new Node;
    new_node->item = new_pass;
    
    if (headM == 0 || new_pass.get_Passid() <= headM->item.get_Passid()) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && new_pass.get_Passid() > after->item.get_Passid()) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void Flight::remove(const int id_num) {
    if (headM == 0 || id_num < headM->item.get_Passid()) {
        cout << "That passenger does not exist" << endl;
        return;
    }
    
    Node* doomed_node = nullptr;
    if (id_num == headM->item.get_Passid()) {
        doomed_node = headM;
        headM = headM->next;
    }
    
    else {
        Node* before = headM;
        Node* maybe_doomed = headM->next;
        
        while (maybe_doomed != 0 && id_num > maybe_doomed->item.get_Passid()) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->item.get_Passid() == id_num) {
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
    }
    if (doomed_node == nullptr) {
        cout << "That passenger does not exist" << endl;
        return;
    }
    doomed_node->item.set_Pseat(doomed_node->item.get_Pseat(), false);
    delete doomed_node;
}

void Flight::destroy() {
    Node* p = headM;
    
    while (p != nullptr) {
        p = p->next;
        delete headM;
        headM = p;
    }
        
}

void Flight::copy(const Flight &src) {
    
    flight_num = src.flight_num;
    numRows = src.numRows;
    numSeats = src.numSeats;
    seatMap = src.seatMap;
    
    if (src.headM == nullptr)
        return;
    
    for (Node* p = src.headM; p != nullptr; p = p->next)
        add(p->item.get_Passid());
}

const Passenger* Flight::get_passenger(const int id_num) const {
    for (Node* p = headM; p != nullptr; p = p->next) {
        if (p->item.get_Passid() == id_num)
            return &(p->item);
    }
    
    cout << "Passenger with id: " << id_num << "not found." << endl;
    return nullptr;
}

Flight& Flight::operator=(const Flight& rhs) {
    if (this == &rhs)
        return *this;
    
    destroy();
    copy(rhs);
    
    return *this;
}

void Flight::print_passengers() const {
    cout << left << setw(20) << setfill(' ') << "First Name" << setw(20) << "Last Name" << setw(16) << "Phone" << setw(6) << "Row" << setw(6) << "Seat" << setw(5) << "ID" << endl;
    cout << setfill('-') << setw(73) << '-' << endl;
    
    for (Node* p = headM; p != nullptr; p = p->next) {
        cout << left << setfill(' ') << setw(20) << p->item.get_Fname() << setw(20) << p->item.get_Lname() << setw(16) << p->item.get_Pnum() << setw(6) << p->item.get_Pseat()->get_row() << setw(6) <<  p->item.get_Pseat()->get_seat() << setw(5) << p->item.get_Passid() << endl;
        cout << setfill('-') << setw(73) << '-' << endl;
    }
}

void Flight::print_seat_map() const{
    cout << "Aircraft Seat Map" << endl;
    cout << "      ";
    for (char c = 'A'; c - 'A' < numSeats; c++)
        cout << c <<  "   ";
    cout << endl;
    cout << "    ";
    for (int i = 0; i < numSeats; i++)
        cout << "+---";
    cout << "+" << endl;
    for (int j = 0; j < numRows; j++) {
        cout << left << setw(4) << setfill(' ') << j << "| ";
        for (int k = 0; k < numSeats; k++) {
            if (seatMap.at(j).at(k).get_occupation() == true)
                cout << "X | ";
            else
                cout << "  | ";
        }
        cout << endl << "    ";
        for (int i = 0; i < numSeats; i++)
            cout << "+---";
        cout << "+" << endl;
    }

}
