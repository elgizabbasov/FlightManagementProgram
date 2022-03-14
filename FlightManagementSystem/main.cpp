/**
 * @file main.cpp
 * @author Elgiz Abbasov (elgizabbasov2001@gmail.com)
 * @brief ENSF 337 Term Project
 * @version 0.1
 * @date 2020-06-15
 * 
 * @copyright Elgiz Abbasov (c) 2022
 * 
*/

#include "Flight.h"
#include <limits>
#include <string>
using namespace std;

/**
 * @brief 
 * Responsible for starting the program with Return key
 * @return void 
*/
void press_return() {
    cout << "\n<<< Press Enter to Continue>>>\n";
    cout << "\n<<< Press Enter to Continue>>>\n";
    cin.get();
}

/**
 * @brief 
 * Responsible for displaying the header
 * information.
*/
void display_head() {
    cout << "\nTerm Project - Flight Management Program in C++\n";
    cout << "Created by: Elgiz Abbasov\n";
    cout << "Date: June 15, 2020\n";
    cout << "Email: elgizabbasov2001@gmail.com\n";
    press_return();
}

int str_to_int(string number) {
    int result = 0;
    for (int i = 0; i < (int)number.length(); i++)
        result = 10 * result + ((int)number.at(i) - 48);
    return result;
}

/**
 * @brief 
 * Responsible for checking if str is a number
 * @param str user selection
 * @return true
 * If str the passed string is a number 
 * @return false
 * If its not a number 
*/
bool is_number(const string& str){
    string::const_iterator it = str.begin();

    while (it != str.end() && isdigit(*it))
        ++it;
    return !str.empty() && it == str.end();
}

/**
 * @brief 
 * Responsible for clearing the input
 * 
 * @return void 
*/
void clean_input() {
    int res;
    
    do {
        res = cin.get();
    } while (res != EOF && res != '\n');
}

/**
 * @brief 
 * Responsible for displaying the main menu
 * of the flight system.
 * 
 * @return int 
*/
int demo() {
    string choice;
    
    cout << "\nPlease select one of the following options:\n";
    cout << "\n[1] Display Flight Seat Map. \n";
    cout << "[2] Display Passengers Information.\n";
    cout << "[3] Add a New Passenger. \n";
    cout << "[4] Remove an Existing Passenger. \n";
    cout << "[5] Save data. \n";
    cout << "[6] Quit. \n";
    cout << "\nEnter your choice: (1, 2, 3, 4, 5 or 6): ";
    cin >> choice;

    while ((is_number(choice) && str_to_int(choice) <= 0) || !is_number(choice) || (is_number(choice) && str_to_int(choice) > 6)) {
        clean_input();
        cout << "\nPlease only enter numbers from 1 to 6: ";
        cin >> choice;
        cout << "\n";
    }

    return str_to_int(choice);
}

/**
 * @brief 
 * Responsible for populating the flight 
 * with the information from a passed .txt file.
 * @param file_name Text file with data
 * @return Flight instance 
*/
Flight populate_flight_from_file(string file_name) {
    ifstream inFile(file_name, ios::in);

    if (inFile.fail()) {
        cout << "Unable to open file... quitting \n";
        exit(1);
    }

    Flight f;
    int flight_row, flight_seat;
    string flight_name;

    inFile >> flight_name >> flight_row >> flight_seat;
    
    f.set_flight_name(flight_name);
    f.set_flight_row(flight_row);
    f.set_flight_seat(flight_seat);

    string line, first_name, last_name, phone, seat, row, id;

    while (!inFile.eof()) {
        getline(inFile, line);
        first_name = line.substr(0, 19);
        last_name = line.substr(first_name.length(), 20);
        phone = line.substr(first_name.length() + last_name.length(), 21);
        seat = line.substr(first_name.length() + last_name.length() + phone.length(), 4);
        id = line.substr(first_name.length() + last_name.length() + phone.length() + seat.length(), 6);
        f.set_passenger(first_name, last_name, id, phone, seat);
    }

    inFile.close();
    return f;
}

/**
 * @brief 
 * The Start
 * Call appropriate function based on user selection
*/
int main() {
    Flight flight_i;
    
    display_head();
    
    flight_i = populate_flight_from_file("..\\FlightManagementSystem\\flight-info.txt");
    
    int selection;

    while ((selection = demo())) {
        switch (selection) {
        case 1:
            flight_i.show_map();
            press_return();
            break;
        case 2:
            flight_i.display_passenger(flight_i);
            press_return();
            break;
        case 3:
            flight_i.add_passenger(flight_i);
            break;
        case 4:
            flight_i.remove_passenger(flight_i);
            break;
        case 5:
            flight_i.save_info(flight_i, "..\\FlightManagementSystem\\flight-info.txt");
            break;
        case 6:
            cout << "\nProgram terminated. Thanks for using the Flight Management System.\n";
            exit(1);
            break;
        }
    }
    return 0;
}
