#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int linearSearch(int array[], int x, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		if (array[i] == x) {
			return i;
		}
	}
	return -1;
}
/*linear search find an element in a array by itterating through the
list starting with the first element until the value is found*/

int binarySearch(int array[], int l, int r, int x) {
	if (r >= l) {
		int midpoint = l + (r - l) / 2;
		if (array[midpoint] == x) {
			return midpoint;
		}
		if (array[midpoint] > x) {
			return binarySearch(array, l, midpoint - 1, x);
		}
		return binarySearch(array, midpoint + 1, r, x);
	}
	return -1;
}
/*binary search diveds an array in half, it then checks the middle
element and than narrows down the search range based on the value of
the middle element*/

int ternarySearch(int l, int r, int x, int array[]) {
	if (r >= l) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (array[mid1] == x) {
			return mid1;

		}
		if (array[mid2] == x) {
			return mid2;
		}
		if (x < array[mid1]) {
			return ternarySearch(l, mid1 - 1, x, array);
		}
		else if (x > array[mid2]) {
			return ternarySearch(mid2 + 1, r, x, array);
		}
		else {
			return ternarySearch(mid1 + 1, mid2 - 1, x, array);
		}
	}
	return -1;
}
/*ternnary search is like binary search, but it divides the array into 3
parts and checks the range of the boundaires to narrow its search range*/

int interpolationSearch(int array[], int lo, int hi, int x) {
	int pos;

	if (lo <= hi && x >= array[lo] && x <= array[hi]) {
		pos = lo + (((double)(hi - lo) / (array[hi] - array[lo])) * (x - array[lo]));
		if (array[pos] == x)
			return pos;
		if (array[pos] < x)
			return interpolationSearch(array, pos + 1, hi, x);
		if (array[pos] > x)
			return interpolationSearch(array, lo, pos - 1, x);
	}
	return -1;
}
/*interpolation works with a sorted list/array, it estimates the postion of the target
using an interpolation formula. It uses this with the range to divide the array into sub arrays
where it can compare the ranges and narrow the search*/


void runAlgo(int first, int sum, int size, int array[], string name) {

	cout << name << endl << "-----------------------------" << endl;

	for (int i = 0; i < 10; i++) { //loop through 10 values in array

		cout << "Looking for value " << first << ". "; //looking for this value

		if (name == "Algorithm: Linear Search") {
			auto start = chrono::steady_clock::now(); //start clock
			linearSearch(array, first, size); //perform linear search
			auto end = chrono::steady_clock::now(); // end clock
			cout << "It took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl << endl;

			first += 990; //increment index in array by 990
			sum += chrono::duration_cast<chrono::nanoseconds>(end - start).count(); //increment sum as a value is searched for, will be used for average
		}
		if (name == "Algorithm: Binary Search") {
			auto start = chrono::steady_clock::now(); // start clock
			binarySearch(array, 0, size - 1, first); //perform Binary search
			auto end = chrono::steady_clock::now(); //end clock
			cout << "It took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl << endl;

			first += 990; //increment index in array by 990
			sum += chrono::duration_cast<chrono::nanoseconds>(end - start).count(); //increment sum as a value is searched for, will be used for average
		}
		if (name == "Algorithm: Ternary Search") {
			auto start = chrono::steady_clock::now(); // start clock
			ternarySearch(0, size - 1, first, array); //perform Ternary search
			auto end = chrono::steady_clock::now(); //end clock
			cout << "It took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl << endl;

			first += 990; //increment index in array by 990
			sum += chrono::duration_cast<chrono::nanoseconds>(end - start).count(); //increment sum as a value is searched for, will be used for average
		}
		if (name == "Algorithm: Interpolation Search") {
			auto start = chrono::steady_clock::now(); // start clock
			interpolationSearch(array, 0, size - 1, first); // perform Interpolation search
			auto end = chrono::steady_clock::now(); //end clock
			cout << "It took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl << endl;

			first += 990; //increment index in array by 990
			sum += chrono::duration_cast<chrono::nanoseconds>(end - start).count(); //increment sum as a value is searched for, will be used for average 
		}
	}
	cout << "Average time it took to find the 10 values I searched for: " << sum / 10 << " nanoseconds" << endl << endl << endl << endl << endl; //display how long it look to do the search on average 10 values
}

int main() {

	int array[10000];
	int arraySize = sizeof(array) / sizeof(array[0]);

	// populate array with values 0-10,000 (this array is sorted)
	for (int i = 0; i < 10000; i++) {
		array[i] = i;
	}

	int base = 100; //array will start searching from this value
	int sum = 0; //counter will begin at 0

	// LINEAR SEARCH
	runAlgo(base, sum, arraySize, array, "Algorithm: Linear Search");

	// BINARY SEARCH
	int xBinary = 100;
	int binarySum = 0;
	runAlgo(base, sum, arraySize, array, "Algorithm: Binary Search");

	// TERNARY SEARCH
	int xTernary = 100;
	int ternarySum = 0;
	runAlgo(base, sum, arraySize, array, "Algorithm: Ternary Search");

	// INTERPOLATION SEARCH
	int xInterpolation = 100;
	int interpolationSum = 0;
	runAlgo(base, sum, arraySize, array, "Algorithm: Interpolation Search");

	while (1); //keep console running
	return EXIT_SUCCESS;
}