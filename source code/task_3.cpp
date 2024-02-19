#include <iostream>
#include <stack>
#include <string>
#include "task_3.h"

using namespace std;

stack<int> que, reque;
bool is_in_que = true;
int tmp;

void second_first();
void first_second();

void way_5(){

	string s;
	int number, tmp_1, tmp_2;

	// Make input
	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the element: ";
			cin >> number;
			if (!is_in_que) {
				second_first();
			}
			que.push(number);
		}

		if (s == "show") {
			if (is_in_que) {
				first_second();
			}
			tmp_1 = reque.size();
			for (int i = 0; i < tmp_1; i++) {
				tmp_2 = reque.top();
				cout << tmp_2 << ' ';
				que.push(tmp_2);
				reque.pop();
			}
			is_in_que = true;
			cout << endl;
		}

		if (s == "erase") {
			if (is_in_que) {
				first_second();
			}
			reque.pop();
		}

		if (s == "exit") {
			return;
		}
		cout << "Enter the command: ";
	}
}

void second_first() {
	int tmp_1 = reque.size();
	for (int i = 0; i < tmp_1; i++) {
		tmp = reque.top();
		que.push(tmp);
		reque.pop();
	}
	is_in_que = true;
}

void first_second() {
	int tmp_1 = que.size();
	for (int i = 0; i < tmp_1; i++) {
		tmp = que.top();
		reque.push(tmp);
		que.pop();
	}
	is_in_que = false;
}