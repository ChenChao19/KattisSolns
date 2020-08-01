#include <bits/stdc++.h>

using namespace std;

int left(int i) {return i * 2;}
int right(int i) {return i * 2 + 1;}

int main()
{	
	int H; cin >> H;
	string path; cin >> path;
	int number = pow(2, H + 1) - 1;
	int index = 1;
	for(auto &cmd : path) {
		index = (cmd == 'L') ? left(index) : right(index);
	}
	cout << number - index + 1 << endl;
	return 0;




}
