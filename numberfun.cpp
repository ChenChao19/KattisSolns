#include <bits/stdc++.h>

using namespace std;

bool add(int x, int y, int z)
{
	return (x + y == z);
}

bool subtract(int x, int y, int z)
{
	return (x - y == z || y - x == z);
}

bool multiply(int x, int y, int z)
{
	return (x * y == z);
}

bool divide(int x, int y, int z)
{
	return ((x % y == 0 || y % x == 0) && (x / y == z || y / x == z));
}
	
int main()
{
	int no;
	cin >> no;
	for(int i = 0; i < no; i++) {
		int no1;
		int no2;
		int no3;
		cin >> no1 >> no2 >> no3;
		if(add(no1, no2, no3) || subtract(no1, no2, no3) || multiply(no1, no2, no3) || divide(no1, no2, no3)) {
			cout << "Possible" << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}

