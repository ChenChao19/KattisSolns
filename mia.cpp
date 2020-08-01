#include <bits/stdc++.h>

using namespace std;

bool mia(int w, int x)
{
	return ((w == 1 && x == 2) || (w == 2 && x == 1));
}

bool dub(int y, int z)
{
	return (y == z);
}

bool tie(int w, int x, int y, int z)
{
	return ((w == y && x == z) || (w == z && x == y));
}

int number(int x, int y)
{
	int no;
	if(x > y) {
		no = x * 10 + y;
	} else {
		no = y * 10 + x;
	}
	return no;
}

int main()
{
	int s0;
	int s1;
	int r0;
	int r1;
	do {
		cin >> s0 >> s1 >> r0 >> r1;
		if(s0 == 0) {
			break;
		}
		if(tie(s0, s1, r0, r1)) {
			cout << "Tie." << endl;
		} else if(mia(s0, s1)) {
			cout << "Player 1 wins." << endl;
		} else if(mia(r0, r1)) {
			cout << "Player 2 wins." << endl;
		} else if(dub(s0, s1)) {
			if(dub(r0, r1)) {
				if(s0 > r0) {
					cout << "Player 1 wins." << endl;
				} else {
					cout << "Player 2 wins." << endl;
				}
			} else {
				cout << "Player 1 wins." << endl;
			}
		} else if(dub(r0, r1)) {
			cout << "Player 2 wins." << endl;
		} else {
			int no1 = number(s0, s1);
			int no2 = number(r0, r1);
			if(no1 > no2) {
				cout << "Player 1 wins." << endl;
			} else {
				cout << "Player 2 wins." << endl;
			}
		}
	} while (s0 != 0); 
	return 0;
}

