#pragma once

int* RemoveAdjacentDups(int* arr) {
	int* newArr = new int[8];
	int curr = arr[0];
	int newArrSize = 1;
	newArr[0] = curr;

	for (int i = 0; i < 8; i++) {
		if (curr == arr[i]) {
			continue;
		}
		else {
			newArr[newArrSize] = arr[i];
			newArrSize++;
			curr = arr[i];
		}
	}
	return newArr;
}