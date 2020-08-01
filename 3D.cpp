#include <bits/stdc++.h>

using namespace std;

int days(int statues) {
	int printer = 1;
	int day = 0;
	while(printer < statues) {
		printer *= 2;
		day++;
	}
	day++;
	return day;

}

int main() {
	int n;
	cin >> n;
	int output = days(n);
	cout << output << endl;
}
