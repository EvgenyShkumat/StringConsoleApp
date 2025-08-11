#include <iostream>
#include "utilites.h"
using namespace std;

int main() {
	string s1;
	cin >> s1;
	
	for (auto i : z_func(s1)) {
		cout << i;
	}

	return 0;
}