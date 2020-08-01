#include <bits/stdc++.h>

using namespace std;

int main() {
	long N; cin >> N;
	set<long> output;
	for(long i = 1; i <= sqrt(N); i++) {
		if(N % i == 0) {
			output.insert(i);
			output.insert(N / i);
		}
	}
	for(auto i = output.begin(); i != output.end(); i++) {
		cout << *i - 1 << " ";
	}
	cout << endl;
	return 0;
}
