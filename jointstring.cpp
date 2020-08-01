#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N; cin >> N; cin.get();
	if(N==1) {
		string s;
		cin >> s; 
		cout << s;
	} else {
		map<int, list<string>> mapper; 
		for(int i = 1; i <= N; i++) {
			string s; getline(cin, s);
			mapper[i].push_back(s);
		}
		int last_a;
		for(int i = 1; i <= N-1; i++) {
			int a,b; cin >> a >> b;
			last_a = a;
			mapper[a].splice(mapper[a].end(), mapper[b]);
		}
		for(auto &i : mapper[last_a]) {
			cout << i;
		}
	}
	return 0;
}

