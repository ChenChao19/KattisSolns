#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	string num;
	long sum = 0;
	while(n--) {
		cin >> num;
		int power  = num.back() - '0';
		num.pop_back();
		int number = stoi(num);
		sum += pow(number, power);
	}
	cout << sum << endl;
}
