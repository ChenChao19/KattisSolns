#include<bits/stdc++.h>

using namespace std;

int countRecursive(int coins[3], int index, int k) {
	if(k == 0) return 1;
	if(k < 0) return 0;
	if(k > 0 && index  == 3) return 0;
	return countRecursive(coins, index, k-coins[index]) + countRecursive(coins, index+1, k);
}

int main() {
	int coins[3] = {2,3,5};
	int k; cin >> k;
	int count = 0;
	int output = countRecursive(coins, 0, k);
	cout << output << endl;
}
