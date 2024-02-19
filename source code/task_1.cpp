#include <iostream>
#include <deque>
#include <string>
#include "task_1.h"

using namespace std;

void way_1(){

    // Make deque and fill it, also find the smallest element
    deque<float> dq;
    cout << "Enter the elements: ";
    int counter = 0;
    float elem, small_elem;
    while (cin >> elem) {
        dq.push_back(elem);
        if (counter == 0) {
            small_elem = elem;
        }
        else if (small_elem > elem) {
            small_elem = elem;
        }
        counter++;
    }

    // Print the whole deque
    cout << "All queue: ";
    for (float& p_elem : dq) {
        cout << p_elem;
    }
    cout << endl;

    // Print the smallest element
    cout << "The smallest elem: " << small_elem << "\n";
}


int way_2() {

    deque<string> names;
    deque<int> memory;
    string s, name;
    int number, sum;

    // Make input
    cout << "Enter the command: ";
    while (cin >> s) {

        // Enter values
        if (s == "input") {
            cout << "Name/memory: ";
            cin >> name;
            cin >> number;
            names.push_back(name);
            memory.push_back(number);
        }

        // Delete first element
        if (s == "pop") {
            if (names.empty()) {
                cout << "ERROR: Can't find any name of a computer\n";
            }
            else {
                names.pop_front();
                memory.pop_front();
            }  
        }

        // Show all elements
        if (s == "show") {
            cout << "Name/memory: ";
            for (int i = 0; i < names.size(); i++) {
                cout << names[i] << '/' << memory[i] << ' ';
            }
            cout << endl;
        }

        // Print the sum of all memories
        if (s == "sum") {
            sum = 0;
            for (auto& elem : memory) {
                sum += elem;
            }
            cout << "Total memory: " << sum << endl;
        }

        // Exit command
        if (s == "exit") {
            return 0;
        }
        cout << "Enter the command: ";
        return 0;
    }
}