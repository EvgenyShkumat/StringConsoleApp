#include "utilites.h"

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

vector<int> z_func(const string& s) {
	vector<int> zarr(s.size());
	int left = 0, right = 0;

	for (int i = 1; i < s.size(); i++) {
		if (i <= right) { 
			zarr[i] = min(right - i + 1, zarr[i - left]);
		}

		while (i + zarr[i] < s.size() && s[zarr[i]] == s[zarr[i] + i]) {
			zarr[i]++;
		}

		if (i + zarr[i] - 1 > right) {
			left = i;	
			right = i + zarr[i] - 1;
		}
	}

	return zarr;
}

int search(const string& base, const string& substr) {
	int pos = -1;

	vector<int> arr = prefix_func(substr);

	for (int i = 0, j = 0; i < base.size();) {
		if (base[i] == substr[j]) {
			i++;
			j++;
		}
		
		if (j == substr.size()) {
			pos = i - j;
			break;
		}
		else if (i < base.size() && base[i] != substr[j]) {
			if (j != 0) {
				j = arr[j - 1];
			}
			else {
				i++;
			}
		}
	}

	return pos;
}

int count(const string& base, const string& substr) {
	int count = 0;

	vector<int> arr = prefix_func(substr);

	for (int i = 0, j = 0; i < base.size();) {
		if (base[i] == substr[j]) {
			i++;
			j++;
		}

		if (j == substr.size()) {
			count++;
			j = arr[j - 1];
		}
		else if (i < base.size() && base[i] != substr[j]) {
			if (j != 0) {
				j = arr[j - 1];
			}
			else {
				i++;
			}
		}
	}

	return count;
}


