#include <iostream>
#include <deque>
#include <string>
#include <stack>

using namespace std;

struct MyList {
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

void way_1();
int way_2();
int way_3();
int way_4();
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

	default:
		break;
	}
}



int way_3() {
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
	MyCycle* orig = nullptr, * tmp = nullptr, * tmp_2 = nullptr, * show = nullptr;
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
				*tmp = new_node_cycle(last, number);
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

void erase_all(MyList** orig_ptr) {
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

void way_1() {

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