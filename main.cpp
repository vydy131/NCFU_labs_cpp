#include <iostream>
#include <string>
using namespace std;

class Food {
private:
	float cals_per_100 = 0;
	float weight = 0;
	float cals = 0;
public:
	float get_per_100() { return cals_per_100; }
	void change_per_100() { 
		cout << "Calories per 100 gramms: ";
		cin >> cals_per_100;
	}

	float get_weight() { return weight; }
	void change_weight(){
		cout << "Weight in gramms: ";
		cin >> weight;
	}

	float get_cals() { return cals_per_100*0.01*weight; }
};

class Time {
private:
	int second = 0;
	int minute = 0;
	int hour = 0;
public:
	Time() {}
	Time(int sec, int min, int hou) {
		second = sec;
		minute = min;
		hour = hou;
	}
	int get_inseconds() { return second + minute * 60 + hour * 3600; }
	void increase() { second += 5; }
	void change() {
		cout << "Hours minutes seconds: ";
		cin >> hour >> minute >> second;
	}

	~Time(){}
};

void program_1();
void program_2();

int main() {
	int program;

	cout << "Enter the program to run: ";
	cin >> program;

	
	switch (program) {
	case 1:
		program_1();
		break;
	case 2:
		program_2();
		break;

	default:
		cout << "ERROR: wrong input\n";
	}
	cout << "Enter the program to run: ";
	
}

void program_1(){
	string input;
	Food something;
	cout << "Enter the command: ";
	cin >> input;

	while (true) {
		if (input == "new") {
			something.change_per_100();
			something.change_weight();
			cout << "There is " << something.get_cals() << " calories\n";
		}

		if (input == "show") {
			cout << "Calories per 100: " << something.get_per_100() << endl;
			cout << "Weight: " << something.get_weight() << endl;
			cout << "Calories: " << something.get_cals() << endl;
		}

		if (input == "exit") { return; }
		cout << "Enter the command: ";
		cin >> input;
	}
}

void program_2(){
	string input;
	int sec, min, hour;

	cout << "Seconds: "; cin >> sec;
	cout << "Minutes: "; cin >> min;
	cout << "Hours: "; cin >> hour;
	Time something(sec, min, hour);

	cout << "Enter the command: ";
	cin >> input;

	while (true) {
		if (input == "change") {
			something.change();
		}

		if (input == "increase") {
			something.increase();
		}

		if (input == "show") {
			cout << "Time in seconds: " << something.get_inseconds() << endl;
		}

		if (input == "exit") { return; }
		cout << "Enter the command: ";
		cin >> input;
	}
}
