#include <iostream>
#include "LinkedList.h"
#include "Other.h"
using namespace std;



int main() {


	int* arr = new int[8];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 2;
	arr[4] = 2;
	arr[5] = 3;
	arr[6] = 1;
	arr[7] = 1;

	int* resultArr = RemoveAdjacentDups(arr);
	for (int i = 0; i < 8; i++) {
		cout << resultArr[i] << endl;
	}

	return 0;
}