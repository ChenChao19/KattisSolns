#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N; cin >> N;
	set<string> names;
	for(int i = 0; i < N; i++) {
		string name; cin >> name;
		names.insert(name);
	}
	int M; cin >> M;
	string dw;//name that ssteven dont want
	for(int i = 0; i < M; i++) {
		cin >> dw;
		if(names.find(dw) != names.end()) {//found
			names.erase(dw);
		}
	}
	vector<string> first;
	for(auto &i : names) {
		if(i[0] == 'J') {
			first.push_back(i);
		}
	}
	vector<string> output;
	for(auto & j : first) {
		for(auto & i : names) {
			if(i != j) {
				string temp = j + ' ' + i;
				output.push_back(temp);
			}
		}
	}
	sort(output.begin(), output.end(), [](string a, string b) {
			if(a.size() == b.size()) {
			return a < b;
			} else {
			return a.size() > b.size();
			}
			});
	for(int i = 0; i < output.size() && i < 100; i++) {
		cout << output[i] << endl;
	}
	return 0;
}
