#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	while(cin >> n) {
		if(n == -1) break;
		long long counter = 0;
		for(long long i = 0; i <= n; i++) {
			int count_5 = 0;
			if(i % 5 == 0) count_5++;
			if(count_5 % 2 == 0) counter++;
		}
		cout << counter << endl;
	}
}
