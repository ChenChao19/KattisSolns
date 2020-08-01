#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	string s1;
	string s2;
	cin >> s1 >> s2;
	int r = 0;
	int s = 0;
	for(int i = 0; i < n; i++) {
		if(s1[i] == s2[i]) {
			r++;
			s1[i] = '0';
			s2[i] = '0';
		}
	}
	for(int i = 0; i < n; i++) {
		if(s1[i] == '0') {
			continue;	
		}
		for(int j = 0; j < n; j++) {
			if(s1[i] == s2[j]) {
				s1[i] = '0';
				s2[j] = '0';
				s++;
				break;
			}
		}
	}
	cout << r << " " << s << endl;
}
