#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<string, string>> sg; 
	vector<pair<string, string>> other;
	set<string> input; 
	while(n--) {
		string a,b;
		cin >> a >> b;
		if(a == "SINGAPORE") {
			input.insert(b);
			sg.push_back({a,b});
		}
		if(b == "SINGAPORE") {
			input.insert(a);
			sg.push_back({b,a});
		}
		if(a != "SINGAPORE" && b != "SINGAPORE") {
			other.push_back({a,b});
		}
	} //output stores all direct flight now, sg stores all transit from singapore
	for(auto &i : sg) {
		for(auto &j : other) {
			if(i.second == j.first) {
				input.insert(j.second);
			}
			if(i.second == j.second) {
				input.insert(j.first);
			}
		}
	}
	vector<string> output;
	for(auto &i : input) {
		output.push_back(i);
	}
	//sort(output.begin(), output.end());
	for(auto &i : output) {
		cout << i << endl;
	}
	return 0;
}
