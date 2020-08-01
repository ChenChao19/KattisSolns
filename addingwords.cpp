#include<bits/stdc++.h>

using namespace std;

int main()
{
	string commands; unordered_map<string, int> mapper; unordered_map<int, string> mapper2;
	while(cin >> commands) {
		if(commands == "clear") {
			mapper.clear(); mapper2.clear();
		} else if(commands == "def") {
			string var; int val; cin >> var >> val;	
			if(mapper.find(var) != mapper.end()) {
			       	int old_val = mapper[var];	
				mapper.erase(var);
				mapper2.erase(old_val);
			}
			mapper[var] = val; 
			mapper2[val] = var;
		} else if(commands == "calc") {
			string temp; vector<string> function;
			while(1) {
				cin >> temp;
				if(temp == "=") {
					function.push_back(temp);
					break;
				} else {
					function.push_back(temp);
				}
			}
			bool flag = true;
			for(int i = 0; i < function.size(); i += 2) {
				if(mapper.find(function[i]) == mapper.end()) { //not found
					flag = false;
				}
			}
			int x = mapper[function.front()];
			if(flag == true) {
				for(int i = 1; i < function.size(); i += 1) {
					if(function[i] == "-") x -= mapper[function[i + 1]];
					else if(function[i] == "+") x += mapper[function[i + 1]];
					else if(function[i] == "=") break;
					else continue;
				}
				if(mapper2.find(x) != mapper2.end()) function.push_back(mapper2[x]);
				else function.push_back("unknown");
			} else {
				function.push_back("unknown");
			}
			for(auto &i : function) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
