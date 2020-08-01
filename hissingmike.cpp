#include <bits/stdc++.h>

using namespace std;

int main()
{
	string letters;
	cin >> letters;
	for(int i = 0; i < letters.length(); i++) {
		if (letters[i] == 's') {
			if(letters[i + 1] == 's') {
				cout << "hiss" << endl;
				return 0;
			}
		}
	}
	cout << "no hiss" << endl;
	return 0;
}
