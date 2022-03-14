/**
 * @file Seat.cpp
 * @author Elgiz Abbasov (elgizabbasov2001@gmail.com)
 * @brief Responsible for getting and setting the passenger's seat, row info.
 * @version 0.1
 * @date 2020-06-15
 * 
 * @copyright Elgiz Abbasov (c) 2022
 * 
*/

#include "Seat.h"
using namespace std;

Seat::Seat() : row(""), seat(""), mark(" ") {}

Seat::Seat(string seat) {
    set_seat(seat);
}

string Seat::get_seat() {
    return seat;
}

string Seat::get_row() {
    return row;
}

string Seat::get_mark() {
    return mark;
}

void Seat::set_seat(string seat) {
    this->seat = seat;
}

void Seat::set_row(string r) {
    row = r;
}

void Seat::set_mark(string m) {
    mark = m;
}

/**
 * @brief 
 * Responsible for setting up the
 * row and seat chosen by the passenger.
 * 
 * @param str contains row and seat information
*/
void Seat::set(string str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (isdigit(str.at(i)))
            row.push_back(str.at(i));
        else
            seat.push_back(str.at(i));
    }
}
