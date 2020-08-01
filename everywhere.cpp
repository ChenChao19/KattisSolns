#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T; cin >> T;
	while(T--) {
		int no; cin >> no;
		unordered_set<string> cities;
		cities.clear();
		int dupt = 0;
		for(int i = 0; i < no; i++) {
			string city;cin >> city;
			if(cities.empty()) {
				cities.insert(city);
			} else {
				if(cities.find(city) != cities.end()) {
					dupt++;
				} else {
					cities.insert(city);
				}
			}
		}
		cout << no - dupt << endl;
	}
	return  0;
}
