#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Buyer {
	string sirname,
		name,
		fathername,
		sex,
		nationality,
		adress,
		phone,
		cardnumber,
		height,
		weight,
		born = "dd/mm/yyyy";
};

void way_1();
void way_2();
void way_3();
void way_4();
void way_5();
void way_6();
void way_7();
void way_8();
void way_9();
void way_10();

int main() {
	int way;
	cout << "Select the program: ";
	cin >> way;

	switch (way) {
	case 1: way_1(); break;
	case 2: way_2(); break;
	case 3: way_3(); break;
	case 4: way_4(); break;
	case 5: way_5(); break;
	case 6: way_6(); break;
	case 7: way_7(); break;
	case 8: way_8(); break;
	case 9: way_9(); break;
	case 10: way_10(); break;

	default: break;
	}
}


void way_1() {

	int x;
	int sum = 0,
		counter = 0;

	ifstream file("a.txt");
	if (!file.is_open()) {
		cerr << "ERROR: can't open a.txt\n";
		return;
	}

	while (file >> x) {
		if (x > 0) {
			sum += x;
		}
		if (x == 5) {
			counter++;
		}
	}

	cout << "Sum of >0: " << sum << "\t" 
		<< "Quantity of 5: " << counter << endl;
}


void way_2() {

	float sum = 0;
	float x;

	ifstream file_1("a1.txt");
	if (!file_1.is_open()) {
		cerr << "ERROR: can't open a1.txt\n";
		return;
	}

	ifstream file_2("a2.txt");
	if (!file_2.is_open()) {
		cerr << "ERROR: can't open a2.txt\n";
		return;
	}

	while (file_1 >> x) {
		if (x > 0) {
			sum += x;
		}
	}

	while (file_2 >> x) {
		if (x > 0) {
			sum += x;
		}
	}

	cout << "Sum: " << sum << endl;
}


void way_3() {
	
	string str, tmp, tmp_2;

	ifstream file_read("source_3.txt");
	if (!file_read.is_open()) {
		cerr << "ERROR: can't open source_3.txt\n";
		return;
	}
	
	ofstream file_write("out_3.txt");
	if (!file_write.is_open()) {
		cerr << "ERROR: can't create out_3.txt\n";
		return;
	}
	
	getline(file_read, str);
	for (auto& symbol : str) {
		if (symbol == ' ') {
			continue;
		}
		tmp.push_back(symbol);
	}

	file_write << tmp;
	file_write.close();

	ifstream file_check("out_3.txt");
	if (!file_check.is_open()) {
		cerr << "ERROR: can't read out_3 for checking.txt\n";
		return;
	}
	cout << "out_3.txt contains:\t";
	getline(file_check, tmp_2);
	cout << tmp_2 << endl;
	file_check.close();
}


void way_4() {
	int x;
	int counter = 0,
		position = 0;

	ifstream file_read("source_4.txt");
	if (!file_read.is_open()) {
		cerr << "ERROR: can't open source_4.txt\n";
		return;
	}

	while (file_read >> x) {
		if (position % 2 != 0) { position++; continue; }
		if (x >= 0) { continue; }
		counter++;
		position++;
	}
	cout << counter << endl;
}


void way_5() {

	string str;

	Buyer any;
	any.sirname = "90sir90";
	any.name = "90name90";
	any.fathername = "90father90";
	any.sex = "90sex90";
	any.nationality = "90natio90";
	any.adress = "90adress90";
	any.phone = "90phone90";
	any.cardnumber = "90card90";
	any.height = "90hei90";
	any.weight = "90wei90";
	any.born = "90/90/9090";

	ofstream file_write("source_5.txt", ios::binary);
	if (!file_write.is_open()) {
		cout << "ERROR: can't save a buyer\n";
		return;
	}
	file_write.write((char*)&any, sizeof(Buyer));
	file_write.close();


	ifstream file_read("source_5.txt", ios::binary);
	if (!file_read.is_open()) {
		cerr << "ERROR: can't open source_5.txt\n";
		return;
	}

	Buyer someone;
	file_read.read((char*)&someone, sizeof(Buyer));
	cout << someone.sirname << endl << someone.name << endl << someone.born << endl;
	file_read.close();
}


void way_6() {
	float min, max, x;
	int counter = 0;

	ifstream file_read("f.txt");
	if (!file_read.is_open()) {
		cerr << "ERROR: can't open f.txt\n";
		return;
	}
	
	while (file_read >> x) {
		if (counter == 0) {
			min = x;
			max = x;
			counter++;
			continue;
		}
		if (x > max) { max = x; }
		if (x < min) { min = x; }
	}
	cout << min + max << endl;
	file_read.close();
}


void way_7() {
	int number;
	string str, tmp;
	char symbol;
	bool founded;
	
	vector<vector<vector<int>>> main;
	vector<vector<vector<int>>> support;
	vector<vector<vector<int>>> write;
	
	vector<int> tmp_v;
	vector<vector<int>> tmp_v_v;
	
	ifstream file_read_main("source_7_1.txt");
	if (!file_read_main.is_open()) {
		cout << "ERROR: can't open source_7_1.txt\n";
		return;
	}
	ifstream file_read_support("source_7_2.txt");
	if (!file_read_support.is_open()) {
		cout << "ERROR: can't open source_7_2.txt\n";
		return;
	}
	ofstream file_write("out_7.txt");
	if (!file_write.is_open()) {
		cout << "ERROR: can't create out_7.txt\n";
		return;
	}
	
	while (!file_read_main.eof()) {
		getline(file_read_main, str);
		for (auto& symbol : str) {
			if (symbol == ',') {
				number = stoi(tmp);
				tmp_v.push_back(number);
				tmp.clear();
				tmp_v_v.push_back(tmp_v);
				tmp_v.clear();
				continue;
			}
			if (symbol == ' ' && *(&symbol - 1) == ',') {
				continue;
			}
			if (symbol == ' ') {
				number = stoi(tmp);
				tmp_v.push_back(number);
				tmp.clear();
				continue;
			}
			tmp.push_back(symbol);
		}
		main.push_back(tmp_v_v);
		tmp_v_v.clear();
	}
	while (!file_read_support.eof()) {
		getline(file_read_support, str);
		for (auto& symbol : str) {
			if (symbol == ',') {
				number = stoi(tmp);
				tmp_v.push_back(number);
				tmp.clear();
				tmp_v_v.push_back(tmp_v);
				tmp_v.clear();
				continue;
			}
			if (symbol == ' ' && *(&symbol - 1) == ',') {
				continue;
			}
			if (symbol == ' ') {
				number = stoi(tmp);
				tmp_v.push_back(number);
				tmp.clear();
				continue;
			}
			tmp.push_back(symbol);
		}
		support.push_back(tmp_v_v);
		tmp_v_v.clear();
	}

	founded = false;
	for (vector<vector<int>> vvm : main) {
		for (vector<vector<int>> vvs : support) {
			if (vvm != vvs) {
				founded = false;
			}
			else {
				founded = true;
				break;
			}
		}
		if (!founded) {
			support.push_back(vvm);
		}
	}


	for (vector<vector<int>> vv : support) {
		for (vector<int> v : vv) {
			for (int number : v) {
				cout << number << ' ';
			}
			cout << "\t";
		}
		cout << endl;
	}
}


void way_8() {

}


void way_9() {

}


void way_10() {

}