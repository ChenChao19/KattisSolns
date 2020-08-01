#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	string country; int year;
	unordered_map<string, vector<int>> mapper;
	while(n--) {
		cin >> country >> year;
		mapper[country].push_back(year);
	}
	for(auto &i : mapper) {
		sort(i.second.begin(), i.second.end());
	}
	int q; cin >> q;
	while(q--) {
		string country_req; int k;
		cin >> country_req >> k;
		cout << mapper[country_req][k - 1] << endl;
	}
	return 0;
}
