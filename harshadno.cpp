#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int n)
{
	int sum = 0;
	while(n != 0) {
		sum = sum + (n % 10);
		n = n / 10;
	}
	return sum;
}

bool harshad(int n)
{
	return (n % sum_of_digits(n) == 0);
}

int main()
{
	int no; cin >> no;
	while(!harshad(no)) {
		no++;
	}
	cout << no << endl;
	return 0;
}
