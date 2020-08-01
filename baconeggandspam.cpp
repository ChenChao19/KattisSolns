#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin >> n, n > 0) {
		cin.get();
		map<string, vector<string>> mapper;
		for(int i = 0; i < n; i++) {
			string line; getline(cin, line);
			istringstream iss(line);
			vector<string> token;
			string intermediate;
			while(getline(iss, intermediate, ' ')) {
				token.push_back(intermediate);
			}
			for(int j = 1; j < token.size(); j++) {
				mapper[token[j]].push_back(token.front());
			}
		}
		for(auto i : mapper) {
			sort(i.second.begin(), i.second.end());
			cout << i.first <<  " ";
			for(int j = 0; j < i.second.size(); j++) {
				cout << i.second[j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
