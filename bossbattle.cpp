#include <bits/stdc++.h>

using namespace std;

int battle(int n)
{
	if(n <= 3) {
		return 1;
	}
	int after_blast = n - 3;
	int after_move = after_blast + 2;
	return 1 + battle(after_move);
}

int main()
{
	int n; cin >> n;
	int bomb_no = battle(n);
	cout << bomb_no << endl;
	return 0;
}
