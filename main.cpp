#include <iostream>
#include <string>
using namespace std;

class Food {
private:
	float cals_per_100 = 0;
	float weight = 0;
	float cals = 0;
public:
	void change_per_100(float number) { cals_per_100 = number; }
	float get_per_100() { return cals_per_100; }
	void change_weight(float number) { weight = number; }
	float get_weight() { return weight; }
	float get_cals() { return cals_per_100*weight; }
};

void program_1();
void program_2();

int main() {
	int program;

	cout << "Enter the program to run:";
	cin >> program;

	while (true) {
		switch (program) {
		case 1:
			program_1();
			break;
		case 2:
			program_2;
			break;

		default:
			cout << "ERROR: wrong input\n";
		}
		cout << "Enter the program to run:";
	}
}

void program_1(){
	
}

void program_2(){

}
