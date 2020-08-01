#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int no; cin >> no;
		int output = factorial(no);
		if(output >= 10) {
			output = output % 10;
		}
		cout << output << endl;
	}
	return 0;
}

