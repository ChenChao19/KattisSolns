#include <bits/stdc++.h>

using namespace std;

int SSD(int base, int no)
{
	int sum = 0;
	while(no != 0) {
		sum = sum + pow(no % base, 2);
		no = no / base;
	}
	return sum;
}


int main()
{
	int P; cin >> P;
	for(int i = 0; i < P; i++) {
		int K, b, n; cin >> K >> b >> n;
		int sum = SSD(b, n);
		cout << K << " " << sum << endl;
	}
	return 0;


}
