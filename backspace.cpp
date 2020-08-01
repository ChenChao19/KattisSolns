#include <bits/stdc++.h>

using namespace std;

int main()
{
	string line; cin >> line;
	char c;
	istringstream iss(line);
	deque<char> input;
	while(iss.get(c)) {
		if(input.empty()) {
			if(c != '<') {
				input.push_back(c);
			}
			continue;
		} else {
			if(c !=  '<') {
				input.push_back(c);
			} else {
				input.pop_back();
			}
		}
	}
	while(!input.empty()) {
		cout << input.front();
		input.pop_front();
	}
	cout << endl;
	return 0;
}
