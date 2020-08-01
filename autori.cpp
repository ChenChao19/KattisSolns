#include <bits/stdc++.h>

using namespace std;

int main()
{
	string letters;
	cin >> letters;
	cout << letters[0];
	for(int i = 0; i < letters.length(); i++) {
		if (letters[i] == '-') {
			cout << letters[i + 1];
		}
	}
	cout << endl;
	return 0;
}
