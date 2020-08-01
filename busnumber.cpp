#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> bus;
	for(int i = 0; i < n; ++i) {
		int num; cin >> num;
		bus.push_back(num);
	}
	sort(bus.begin(), bus.end());
	int i = 0;
	while(i < n) {
		cout << bus[i];
		int j = i+1;
		while(j < n && bus[j] == bus[j-1]+1) {
			j++;
		}
		if(j>i+2) {
			cout << "-" << bus[j-1] << " ";
			i = j;
		} else {
			i++;
			cout << " ";
		}
	}
}

