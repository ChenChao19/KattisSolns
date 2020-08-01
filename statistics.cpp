#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int case_no = 1;
	while(cin >> n) {
		int max_no = -1e9;
		int min_no = 1e9;
		for(int i = 1; i <= n; i++) {
			int no;
			cin >> no;
			max_no = max(max_no, no);
			min_no = min(min_no, no);
		}
		cout << "Case " << case_no++ << ": " << min_no << " " << max_no << " " << max_no - min_no << endl;
	}
	return 0;
}	
