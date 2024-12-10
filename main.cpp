#include "container.h"
#include "train.h"
#include "zadanie.h"
#include "iostream"
#include "fstream"
#include "string"
#include "limits"

using namespace std;

void display_menu() {
    cout << "\n===== Menu =====" << endl;
    cout << "1. Add train" << endl;
    cout << "2. Delete train" << endl;
    cout << "3. Edit train" << endl;
    cout << "4. All train" << endl;
    cout << "5. Sort train" << endl;
    cout << "6. Find train" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

int trains_program() {
    Container trains;
    int choice;

    while (true) {
        display_menu();
        cin>>choice;
        switch (choice) {
            case 1: {
                string destination, time;
                int number, index;
                cout << "destination: ";
                getline(cin>>ws, destination);
                cout << "number: ";
                cin>>number;
                cout << "time: ";
                getline(cin>>ws, time);
                cout << "index: ";
                cin>>index;

                Train* new_train = new Train(destination, number, time);
                try {
                    trains.add_train(new_train, index - 1);
                    cout << "Train add." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                    delete new_train;
                }
                break;
            }
            case 2: {
                int index;
                cout << "index: ";
                cin>>index;
                try {
                    trains.delete_train(index - 1);
                    cout << "Train delete." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "index: ";
                cin>>index;
                try {
                    trains.edit_train(index - 1);
                    cout << "Train edit." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                trains.display_trains();
                break;
            }
            case 5: {
                trains.sort_trains_by_number();
                cout << "Train sort." << endl;
                trains.display_trains();
                break;
            }
            case 6: {
                cout << "Enter the train destination time to search for: ";
                string time;
                cin >> time;
                trains.printTrainsToTime(time);
                break;
            }
            case 0: {
                cout << "Exit." << endl;
                return 0;
            }
            default: {
                cout << "Error." << endl;
                break;
            }
        }
    }

    return 0;
}

int words_program() {
    try {
        int choice;
        cout << " 1 - string, 2 - file): ";
        if (!(cin >> choice)) {
            throw invalid_argument("Invalid input. Please enter a number.");
            //clean up cin stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline

        if (choice == 1) {
            string text;
            cout << "Text: ";
            getline(cin, text); //Correct way to get a line of text

            SentenceFilter filter(text, 0, true); //Use correct constructor
            filter.result();
        } else if (choice == 2) {
            string filename;
            cout << "File name: ";
            getline(cin, filename); // Correctly read filename as a string

            SentenceFilter filter(filename, 0); //Use correct constructor
            filter.result();
        } else {
            throw out_of_range("Invalid choice.");
        }
    } catch (const exception& e) { //Catch any exception
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}


int main() {
    int choice;
    while (true) {
        cout << "Select type task:" << endl;
        cout << "1 - Standard streams" << endl;
        cout << "2 - File and string streams" << endl;
        cout << "3 - Exit" << endl;
        cin>>choice;
        switch (choice) {
            case 1:
                trains_program();
                break;
            case 2:
                words_program();
                break;
            case 3:
                cout << "Exit." << endl;
                return 0;
            default:
                cout << "Error." << endl;
                break;
        }
    }
}