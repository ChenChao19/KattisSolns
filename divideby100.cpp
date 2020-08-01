#include <bits/stdc++.h>

using namespace std;

int main() {
	string N, M;
	cin >> N >> M;
	vector<char> output;
	if(N.length() < M.length()) {
		output.push_back('0');
		output.push_back('.');
		for(long i = 0; i < M.length() - N.length() - 1; i++) output.push_back('0');
	}
	long counter = 0;
	for(long i = N.length()-1; i >= 0; i--) {
		if(N[i] == '0') counter++;
		else break;
	}
	if(counter >= M.length() - 1) counter  = M.length() - 1;
	if(counter != 0) {
		N = N.substr(0, N.length() - counter);
		M = M.substr(0, M.length() - counter);
	}

	for(long i = 0; i < N.length(); i++) {
		if(i == N.length() - (M.length() - 1)) {
			if(N.length() < M.length() && M.length() - N.length() == 1);
			else output.push_back('.');
		}
		output.push_back(N[i]);
	}
	for(long i = 0; i < output.size(); i++) {
		cout << output[i];
	}
	cout << endl;
	return 0;
}
