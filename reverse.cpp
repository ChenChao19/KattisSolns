#include<bits/stdc++.h>

using namespace std;

int reverse(int x) {
	if(x > pow(2, 31) - 1 || x < -pow(2, 31)) return 0;
	string str = to_string(x);
	vector<char> number;
	if(str[0] == '-') {
		for(int i = str.length() - 1; i >= 1; i--) {
			number.push_back(str[i]);
		}
	} else {
	        for(int i = str.length() - 1; i >= 0; i--) {
	                number.push_back(str[i]);
	        }
	}
	long output = 0;
	for(int i = 0; i < number.size(); i++) {
		output *= 10;
		output += number[i] - '0';
	}
	if(str[0] == '-') output *= -1;
	return output;
}

int main() {
	int n; cin >> n;
	int output = reverse(n);
	cout << output << endl;
}

