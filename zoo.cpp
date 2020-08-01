#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; int caseno = 0;
	while(cin >> n) {
		cin.get();
		if (n == 0) {
			break;
		}
		map<string, int> output;
		for(int i = 0; i < n; i++) {
			string line; getline(cin, line);
			istringstream iss(line);
			vector<string> tokens;
			string intermediate;
			while(getline(iss, intermediate, ' ')) {
				tokens.push_back(intermediate);
			}
			for (int i = 0; i < tokens.back().length(); i++) {
				if(tokens.back()[i] >= 'A' && tokens.back()[i] <= 'Z') {
					tokens.back()[i] -= 'A';
					tokens.back()[i] += 'a';
				}
			}
			if(output.find(tokens.back()) == output.end()) {
				output.insert({tokens.back(), 1});
			} else {
				output[tokens.back()]++;
			}
		}

		cout << "List " << ++caseno << ":" << endl;
		for(auto i : output) {
			cout << i.first << " | " << i.second << endl;
		}
	}
	return 0;
}
