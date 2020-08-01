#include  <bits/stdc++.h>

using namespace std;

int main()
{
	int ini_y = 2018, ini_m = 3;
	int year; cin >> year;
	while(ini_y < year) {
		ini_y += 2;
		ini_m += 2;
		if(ini_m >= 12) {
			ini_m = ini_m % 12;
			ini_y++;
		}
	}
	if(ini_y == year) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
}
