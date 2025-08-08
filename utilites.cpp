#include "utilites.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix_func(const string& substr) {
	vector<int> arr(substr.size());
	arr[0] = 0;

	int i = 1, j = 0;

	while (i < substr.size()) {
		if (substr[i] == substr[j]) {
			arr[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0) {
			arr[i] = 0;
			i++;
		}
		else {
			j = arr[j - 1];
		}
	}

	return arr;
}

