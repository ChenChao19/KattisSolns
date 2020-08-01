#include<bits/stdc++.h>

using namespace std;

int main()
{
	int F; cin >> F;
	vector<int> input;
	while(F--) {
		int a, b;
		cin >> a >> b;
		if(a == 0) {
			input.push_back(b);
		}
		if(b == 0) {
			input.push_back(a);
		}
	}
	sort(input.begin(), input.end());
	for(auto &i : input) {
		cout << i << endl;
	}
	return 0;
}
