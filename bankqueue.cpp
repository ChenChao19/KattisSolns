#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, T; cin >> N >> T;
	vector<int> person(T+1, 0);
	for(int i = 0; i < N; i++) {
		int cash, time; cin >> cash >> time;
		for(int j = time; j >= 0; j--) {
			if(cash > person[j]) {
				swap(cash, person[j]);
			}
		}
	}
	int sum = 0;
	for(auto i : person) {
		sum += i;
	}
	cout << sum << endl;
}
