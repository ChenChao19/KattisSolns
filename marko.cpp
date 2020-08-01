#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N; cin >> N;
	unordered_map<char, char> c;
	c['a'] = '2';
	c['b'] = '2';
	c['c'] = '2';
	c['d'] = '3';
	c['e'] = '3';
	c['f'] = '3';
	c['g'] = '4';
	c['h'] = '4';
	c['i'] = '4';
	c['j'] = '5';
	c['k'] = '5';
	c['l'] = '5';
	c['m'] = '6';
	c['n'] = '6';
	c['o'] = '6';
	c['p'] = '7';
	c['q'] = '7';
	c['r'] = '7';
	c['s'] = '7';
	c['t'] = '8';
	c['u'] = '8';
	c['v'] = '8';
	c['w'] = '9';
	c['x'] = '9';
	c['y'] = '9';
	c['z'] = '9';
	vector<string> words;
	for(int i = 0; i < N; i++) {
		string word; cin >> word;
		words.push_back(word);
	}
	string number; cin >> number;
	int counter = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < number.size(); j++) {
			if(number[j] != c[words[i][j]]) {
				counter++;
				break;
			}
		}
	}
	cout << N - counter << endl;
	return 0;
}
