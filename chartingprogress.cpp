#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input;
	int star_counter = 0;
	while(getline(cin,input), !cin.eof()) {
		if(input == "") {
			cout << endl;
			star_counter = 0;
		}
		int length = input.length();
		for(int i = 0; i < length; i++) {
			if(input[i] == '*') {
				star_counter++;
			}
		}
		sort(input.begin(), input.end(), greater<int>());
		sort(input.begin() + length - star_counter, input.end());

		cout << input << endl;
	}

}
