#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N; cin >> N;
	int i = 0;
	while(N--) {
		int G; cin >> G;
		unordered_set<int> guest;
		guest.clear();
		while(G--) {
			int number; cin >> number;
			if(guest.empty()) {
				guest.insert(number);
			} else {
				if(guest.find(number) == guest.end()) {
					guest.insert(number);
				} else {
					guest.erase(number);
				}
			}
		}
		i++;
		for(auto  &v : guest) {
			cout << "Case #" << i << ": " << v << endl;
		}
	}
	return 0;
}
