#include "container.h"
#include <sstream>
Container::Container() : head(nullptr), tail(nullptr), count(0) {cout << "The constructor without parameters for the Container class is called\n";}

Container::Container(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "The constructor with parameters for the Container class is called\n";
}

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "The copy constructor for the Container class is called\n";
}

Container::~Container() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "The destructor for the Container class is called" << endl;
}


Node* Container::get_head() {
    return this->head;
}

Node* Container::get_tail() {
    return this->tail;
}

void Container::add_train(Train* Tr, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    
    Node* node_to_add = new Node;
    node_to_add->data = Tr;
    node_to_add->next = nullptr;

    if (index == 0) {
        node_to_add->next = head;
        head = node_to_add;
        if (count == 0) {
            tail = node_to_add;
        }
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        node_to_add->next = prev->next;
        prev->next = node_to_add;
        
        if (node_to_add->next == nullptr) {
            tail = node_to_add;
        }
    }
    
    ++count;
}

Container& Container::delete_train(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}

void Container::display_trains() {
    Node* temp = head;
    if (count == 0) {
        cout << "There are no trains" << endl;
        return;
    }
    int index = 1;
    while (temp != 0) {
        cout << index << " -Information about the train:\n";
        temp->data->display_train();
        temp = temp->next;
        index++;
    }
}

void Container::sort_trains_by_number() {
    if (count < 2) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data->get_destination() > j->next->data->get_destination()) {
                Train* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}


Container& Container::edit_train(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->data->edit_train();
    return *this;
}

Container& Container::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return *this;
}



void Container::splitTime(const string& t, int& h, int& m) {

    stringstream ss(t);
    char colon;
    ss >> h >> colon >> m;
}

void Container::printTrainsToTime(const string& time) {

    Node* temp = head;
    int hourstemp, minutestemp, hours, minutes;
    splitTime(time, hours, minutes);
    while (temp != nullptr) {
        splitTime(temp->data->get_time(), hourstemp, minutestemp);
        if (hourstemp == hours && minutestemp >= minutes) {
            temp->data->display_train();
        }
        else if(hourstemp > hours){
            temp->data->display_train();
        }
        else if(hourstemp > hours){
            cout << "Train  not found." << endl;;
        }
        temp = temp->next;
    }
}