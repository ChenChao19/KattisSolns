#include <bits/stdc++.h>

using namespace std;

int main()
{
	string name; cin >> name;
	queue<char> ans;
	ans.push(name[0]);
	for(int i = 1; i < name.length(); i++) {
		if(name[i] == name[i - 1]) {
			continue;
		} else {
			ans.push(name[i]);		
		}
	}
	while(!ans.empty()) {
		cout << ans.front();
		ans.pop();
	}
	cout << endl;
	return 0;
}
