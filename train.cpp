#include "train.h"

Train::Train() : destination(""), number(0), time_of_departure("") //{cout << "The constructor without parameters for the Train class is called\n";}

Train::Train(const string& d, const int& n, const string& t) : destination(d), number(n), time_of_departure(t) //{
    //cout << "The constructor with parameters for the Train class is called\n";
//}

Train::Train(const Train& other) : destination(other.destination), number(other.number), time_of_departure(other.time_of_departure) 
//{cout << "The copy constructor for the Train class is called\n";}

Train::~Train() //{cout << "The destructor for the Train class is called\n";}

string Train::get_destination() {
    return this->destination;
}

void Train::set_destination(const string& d) {
    this->destination = d;
}

int Train::get_number() {
    return this->number;
}

void Train::set_number(const int& n) {
    this->number = n;
}

string Train::get_time() {
    return this->time_of_departure;
}

void Train::set_time(const string& t) {
    this->time_of_departure = t;
}

void Train::display_train() {
    cout << "destination: " << this->get_destination() << endl;
    cout << "number: " << this->get_number() << endl;
    cout << "time: " << this->get_time() << endl; 
    cout << endl;
}

void Train::edit_train() {
    int choice;
    cout << "Choose what you want to changeь:\n";
    cout << "1. destination\n";
    cout << "2. number\n";
    cout << "3. time\n";
    cout << "choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_destination;
            cout << "new destination: ";
            cin.ignore();
            getline(cin, new_destination);
            set_destination(new_destination);
            break;
        }
        case 2: {
            int new_number;
            cout << "new number: ";
            cin >> new_number;
            set_number(new_number);
            break;
        }
        case 3: {
            string new_time;
            cout << "new time: ";
            cin.ignore();
            getline(cin, new_time);
            set_time(new_time);
            break;
        }
        default:
            cout << "Error!" << endl;
    }
}