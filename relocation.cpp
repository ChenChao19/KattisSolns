#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, Q; cin >> N >> Q;
	int location[N];
	for(int i = 0; i < N; i++) {
		int ini_loc;
		cin >> ini_loc;
		location[i] = ini_loc;
	}
	for(int i = 0; i < Q; i++) {
		int query[3];
		for(int j = 0; j < 3; j++) {
			cin >> query[j];
		}
		if(query[0] == 1) {
			int position = query[1] - 1;
			location[position] = query[2];
		} 
	        if(query[0] == 2) {
			int diff = abs(location[query[1] - 1] - location[query[2] - 1]);
			cout << diff << endl;
		}
	}
	return 0;
}
