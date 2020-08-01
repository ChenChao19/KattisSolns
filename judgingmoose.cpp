#include <bits/stdc++.h>

using namespace std;

bool is_moose(int x, int y)
{
	return ((x + y) != 0);
}

bool bigger(int x, int y)
{
	return (x > y);
}

int main()
{
	int left;
	int right;
	cin >> left >> right;
	if(is_moose(left, right)) {
		if(bigger(left, right)) {
			cout << "Odd " << 2 * left << endl;
		} else if(bigger(right, left)) {
			cout << "Odd " << 2 * right << endl;
		} else {
			cout << "Even " << 2 * left << endl;
		}
	} else {
		cout << "Not a moose" << endl;
	}
	return 0;
}

