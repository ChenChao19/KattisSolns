#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	unordered_map<int, vector<long>> language;
	long awkward = n;
	for(int i = 0; i < n; i++) {
		int key; cin >> key;
		language[key].push_back(i);
	}
	for(auto i : language) {
		for(long j = 1; j < i.second.size(); j++) {
			awkward = min(awkward, (i.second[j] - i.second[j - 1]));
		}
	}
	cout << awkward << endl;
	return 0;
}
