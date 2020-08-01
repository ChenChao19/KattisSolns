#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int n)
{
	int sum = 0;
	while(n != 0) {
		sum = sum  + (n % 10);
		n = n / 10;
	}
	return sum;
}

int main()
{
	int L, D, X; cin >> L >> D >> X;
	int N, M;
	for(int i = L; i <= D; i++) {
		int sum = sum_of_digits(i);
		if(sum == X) {
			M = i;
		}
	}
	for(int i = D; i >= L; i--) {
		int sum = sum_of_digits(i);
		if(sum == X) {
			N = i;
		}
	}
	cout << N << endl << M << endl;
	return 0;
}
