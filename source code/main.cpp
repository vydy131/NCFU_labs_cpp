#include <iostream>
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"

using namespace std;

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