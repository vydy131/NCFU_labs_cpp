#include <iostream>
#include <deque>
#include <string>
#include "task_2.h"

using namespace std;

struct MyList{
	string value;
	MyList* ptr = NULL;
};

struct MyStack {
	int value;
	MyStack* ptr = NULL;
};

struct MyCycle {
	float value;
	MyCycle* ptr = NULL;
};

void new_node(MyList** latest, string data);
MyCycle new_node_cycle(MyCycle** latest, float data);
MyList* erase(MyList** orig_ptr);
void erase_all(MyList** orig_ptr);
void erase_all_stack(MyStack** orig_ptr);
void erase_all_cycle(MyCycle** orig_ptr);

int way_3(){
	MyList* orig = nullptr;
	MyList* show = nullptr;
	MyList** last = nullptr;
	
	string s, str;
	int counter = 0;

	// Make input
	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the value: ";
			cin >> str;

			if (counter == 0) {
				orig = new (MyList);
				orig->value = str;
				last = &(orig->ptr);
			}
			else {
				new_node(last, str);
			}
			counter++;
		}

		if (s == "show") {
			show = orig;
			for (int i = 0; i < counter; i++) {
				cout << show->value << ' ';
				show = show->ptr;
			}
			cout << endl;
		}

		if (s == "erase") {
			if (counter == 0) {
				printf("ERROR: list is empty\n");
			}
			else {
				orig = erase(&orig);
			}
		}

		if (s == "exit") {
			if (counter != 0) {
				erase_all(&orig);
			}
			return 0;
		}
		cout << "Enter the command: ";
	}
	return 0;
}

int way_4() {
	MyStack* orig = nullptr;
	MyStack* tmp = nullptr;
	MyStack* show = nullptr;

	string s;
	int number;
	int counter = 0;

	// Make input
	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the value: ";
			cin >> number;
			if (counter == 0) {
				orig = new(MyStack);
				orig->value = number;
			}
			else {
				tmp = new(MyStack);
				tmp->ptr = orig;
				tmp->value = number;
				orig = tmp;
			}
			counter++;
		}

		if (s == "show") {
			show = orig;
			for (int i = 0; i < counter; i++) {
				cout << show->value << ' ';
				show = show->ptr;
			}
			cout << endl;
		}

		if (s == "erase") {
			if (orig == nullptr) {
				cout << "ERROR: can't find element\n";
				cout << "Enter the command: ";
				continue;
			}
			tmp = orig;
			orig = tmp->ptr;
			delete tmp;
		}

		if (s == "exit") {
			if (counter != 0) {
				erase_all_stack(&orig);
			}
			return 0;
		}
		cout << "Enter the command: ";
	}
	return 0;
}

void way_6() {
	MyCycle* orig = nullptr, *tmp = nullptr, *tmp_2 = nullptr, *show = nullptr;
	MyCycle** last = nullptr;

	string s;
	float number;
	int counter = 0;
	int position = 0;

	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the value: ";
			cin >> number;

			if (counter == 0) {
				orig = new (MyCycle);
				orig->value = number;
				last = &(orig->ptr);
				orig->ptr = orig;
			}
			else {
				tmp = &new_node_cycle(last, number);
				tmp->ptr = orig;
			}
			counter++;
		}

		if (s == "show") {
			show = orig;
			for (int i = 0; i < counter; i++) {
				cout << show->value << ' ';
				show = show->ptr;
			}
			cout << endl;
		}

		if (s == "exit") {
			if (counter != 0) {
				erase_all_cycle(&orig);
			}
			return;
		}
		if (s == "2.5") {
			show = orig;
			for (int i = 0; i < counter; i++) {

				if (show->value > 0) {
					position = i - 1;
				}

				show = show->ptr;
			}
		}
		cout << "Enter the command: ";
	}
}

void new_node(MyList** latest, string data) {
	MyList* node = new (MyList);
	node->value = data;
	*latest = node;
	latest = &(node->ptr);
}

MyList* erase(MyList** orig_ptr) {
	if (*orig_ptr == nullptr) {
		printf("ERROR: pointer is null\n");
		return *orig_ptr;
	}
	MyList* tmp = *orig_ptr;
	MyList* tmp_2 = tmp->ptr;
	delete tmp;
	*orig_ptr = tmp_2;
	return *orig_ptr;
}

void erase_all(MyList** orig_ptr){
	MyList* tmp = *orig_ptr;
	MyList* tmp_2 = tmp->ptr;
	delete tmp;
	if (tmp_2 != nullptr) {
		erase_all(&tmp_2);
	}
}

void erase_all_stack(MyStack** orig_ptr) {
	MyStack* tmp = *orig_ptr;
	MyStack* tmp_2 = tmp->ptr;
	delete tmp;
	if (tmp_2 != nullptr) {
		erase_all_stack(&tmp_2);
	}
}

MyCycle new_node_cycle(MyCycle** latest, float data) {
	MyCycle* node = new (MyCycle);
	node->value = data;
	*latest = node;
	latest = &(node->ptr);
	return **latest;
}

void erase_all_cycle(MyCycle** orig_ptr) {
	MyCycle* tmp = *orig_ptr;
	MyCycle* tmp_2 = tmp->ptr;
	delete tmp;
	if (tmp_2 != nullptr) {
		erase_all_cycle(&tmp_2);
	}
}