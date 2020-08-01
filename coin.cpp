#include<bits/stdc++.h>

using namespace std;

int main() {
	int coins[8] = {1,4,7,13,28,52,91,365};
	int k; cin >> k;
	int count = 0;
	int counter = 7;
	while(k) {
		if(coins[counter] > k) {
			counter--;
		} else {//coins[counter] <= k
			k -= coins[counter];
			count++;
		}
	}
	cout << count << endl;
}
