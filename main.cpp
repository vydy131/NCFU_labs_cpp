#include <iostream>
#include <deque>
#include <string>
#include <stack>

using namespace std;


struct MyList {
	string value;
	MyList* ptr = nullptr;
};


struct MyStack {
	int value;
	MyStack* ptr = nullptr;
};


struct MyCycle {
	float value;
	MyCycle* ptr = nullptr;
};


void erase_all_list(MyList* orig);
void erase_all_stack(MyStack* orig);
void erase_all_cycle(MyCycle* orig, int counter);


void way_1();
void way_2();
void way_3();
void way_4();
void way_5();
void way_6();


int main() {
	int way;
	cout << "Select the program to run: ";
	cin >> way;

	switch (way)
	{
	case 1: way_1();
		break;
	case 2: way_2();
		break;
	case 3: way_3();
		break;
	case 4: way_4();
		break;
	case 5: way_5();
		break;
	case 6: way_6();
		break;

	default:
		break;
	}
}


void way_1() {

	// Make deque and fill it, also find the smallest element
	deque<float> dq;
	string s;
	cout << "Enter the command: ";
	int counter = 0;
	float elem, small_elem;
	while (cin >> s) {
		if (s == "new"){
			cout << "Enter the elem: ";
			cin >> elem;
			dq.push_back(elem);
			if (counter == 0) {
				small_elem = elem;
			}
			else if (small_elem > elem) {
				small_elem = elem;
			}
			counter++;
		}

		if (s == "show" && counter != 0) {
			break;
		}
		cout << "Enter the command: ";
	}

	// Print the whole deque
	cout << "All queue: ";
	for (float& p_elem : dq) {
		cout << p_elem << ' ';
	}
	cout << endl;

	// Print the smallest element
	cout << "The smallest elem: " << small_elem << "\n";
}


void way_2() {

	deque<string> names;
	deque<int> memory;
	string s, name;
	int number, sum;

	// Make input
	cout << "Enter the command: ";
	while (cin >> s) {

		// Enter values
		if (s == "new") {
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
			return;
		}
		cout << "Enter the command: ";
	}
}


void way_3() {
	MyList* orig = nullptr,
		* last = nullptr,
		* tmp = nullptr,
		* show = nullptr;

	string s, str, word;
	int sum = 0;

	// Make input
	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the value: ";
			cin >> str;

			if (orig == nullptr) {
				orig = new MyList;
				orig->value = str;
				last = orig;
			}
			else {
				tmp = new MyList;
				last->ptr = tmp;
				tmp->value = str;
				last = tmp;
			}
		}

		if (s == "show") {
			show = orig;
			while (show != nullptr) {
				cout << show->value << ' ';
				show = show->ptr;
			}
			cout << endl;
		}

		if (s == "erase") {
			if (orig == nullptr) {
				printf("ERROR: create an object for erase one\n");
				cout << "Enter the command: ";
				continue;
			}
			tmp = orig->ptr;
			delete orig;
			orig = tmp;
		}

		if (s == "exit") {
			erase_all_list(orig);
			return;
		}

		if (s == "sum") {
			show = orig;
			sum = 0;
			while (show != nullptr) {
				word = show->value;
				sum += word.length();
				show = show->ptr;
			}
			cout << "The sum is " << sum << endl;
		}

		cout << "Enter the command: ";
	}
}

void erase_all_list(MyList* orig) {
	if (orig != nullptr){
		MyList* tmp = orig->ptr;
		delete orig;
		erase_all_list(tmp);
	}
}

void way_4() {
	MyStack* orig = nullptr;
	MyStack* tmp = nullptr;
	MyStack* show = nullptr;

	string s;
	int number;
	int counter = 0, sum = 0;

	// Make input
	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the value: ";
			cin >> number;

			if (orig == nullptr) {
				orig = new (MyStack);
				orig->value = number;
			}
			else {
				tmp = new (MyStack);
				tmp->value = number;
				tmp->ptr = orig;
				orig = tmp;
			}
		}

		if (s == "show") {
			show = orig;
			while (show != nullptr) {
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
			tmp = orig->ptr;
			delete orig;
			orig = tmp;
		}

		if (s == "exit") {
			if (orig != nullptr) {
				erase_all_stack(orig);
			}
			return;
		}
		cout << "Enter the command: ";

		if (s == "sum") {
			show = orig;
			while (show != nullptr) {
				if (show->value > 0) {
					sum += show->value;
				}
				show = show->ptr;
			}
			cout << "The sum of >0 is " << sum << endl;
		}
	}
	return;
}


void erase_all_stack(MyStack* orig) {
	if (orig == nullptr) {
		return;
	}
	MyStack* tmp = orig->ptr;
	delete orig;
	erase_all_stack(tmp);
}



stack<int> que, reque;
bool is_in_que = true;
int tmp;

void second_first();
void first_second();

void way_5() {

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



void way_6() {

	MyCycle* orig = nullptr,
		* last = nullptr,
		* show = nullptr,
		* tmp = nullptr,
		* tmp_2 = nullptr,
		* tmp_3 = nullptr;

	
	string s;
	float number;
	int counter = 0,
		position = 0,
		diff = 0;
	bool circled = false;

	cout << "Enter the command: ";
	while (cin >> s) {

		if (s == "new") {
			cout << "Enter the value: ";
			cin >> number;

			if (orig == nullptr) {
				orig = new (MyCycle);
				orig->value = number;
				orig->ptr = orig;
				last = orig;
			}
			else {
				tmp = new (MyCycle);
				tmp->value = number;
				tmp->ptr = orig;
				last->ptr = tmp;
				last = tmp;
			}
			counter++;
		}

		if (s == "show") {
			show = orig;
			while (true) {
				if (show == orig && circled == true) {
					break;
				}
				if (show == orig) {
					circled = true;
				}
				cout << show->value << ' ';
				show = show->ptr;
			}
			circled = false;
			cout << endl;
		}


		if (s == "exit") {
			if (orig != nullptr) {
				erase_all_cycle(orig, counter);
			}
			return;
		}

		if (s == "2.5") {
			if (orig == nullptr){
				cout << "ERROR: you have to create an object first\n";
				cout << "Enter the command: ";
				continue;
			}
			show = orig;
			position = 0;
			while (true) {
				diff = 0;
				if (show == orig && circled == true) {
					break;
				}
				if (show == orig) {
					circled = true;
				}
				
				if (show->value > 0) {
					tmp_2 = orig;
					for (int i = 0; i < position; i++) { tmp_2 = tmp_2->ptr; }
					tmp_3 = new (MyCycle);
					tmp_3->value = 2.5;
					tmp_3->ptr = tmp_2->ptr;
					tmp_2->ptr = tmp_3;
					diff++;
				}

				show = show->ptr;
				for (int i = 0; i < diff; i++) {
					show = show->ptr;
				}
				position += 1 + diff;
			}
			circled = false;
			cout << endl;
		}
		cout << "Enter the command: ";
	}
}


void erase_all_cycle(MyCycle* orig, int counter) {
	if (counter != 0) {
		counter--;
		MyCycle* tmp = orig->ptr;
		delete orig;
		erase_all_cycle(tmp, counter);
	}
}
