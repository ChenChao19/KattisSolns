#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
		unordered_map<string, int> input;
		input.clear();
		for(int i = 0; i < N; i++) {
			string toy;
			int amount;
			cin >> toy >> amount;
			if(input.empty()) {
				input.insert({toy, amount});
			} else {
				if(input.find(toy) != input.end()) {
					input[toy] += amount;
				} else {
					input.insert({toy, amount});
				}
			}
		}
		vector<pair<int, string>> output;
		for(auto i : input) {
			output.push_back({i.second, i.first});
		}
		
		sort(output.begin(), output.end(), [](pair<int, string> a, pair<int, string> b) {
				if(a.first != b.first) {
				return a.first > b.first;
				} else {
				return a.second < b.second;
				}
				});

		cout << output.size() << endl;
		for(auto i : output) {
			cout << i.second << " " << i.first << endl;
		}
	}
}
