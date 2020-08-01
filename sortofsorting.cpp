#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin >> n && n != 0) {
		string names[n];
		for(int i = 0; i < n; i++) {
			cin >> names[i];
		}
		stable_sort(names, names + n, [](string A, string B) {
				if(A[0] != B[0]) {
				return A[0] < B[0];
				} else {
				return A[1] < B[1];
				}
				});
		for(int i = 0; i < n; i++) {
			cout << names[i] << endl;
		}
		cout << endl;
	}
	return 0;
}

