#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	int butt[20]; //max button is 16
	int times[3610]; //max time is 3600 i.e one hour
	const int infinity = 1e9; //big constanti assume as infinity
	while(tc--) {
		int n, m; cin >> n >> m;
		for(int i = 0; i < n; i++) {
			cin >> butt[i]; //store the buttons inside array b
		}
		for(int i = 0; i < 3610; i++) {
			times[i] = infinity; //set all the values in array c to infinity
		}
		queue<int> cont; 
		cont.push(0); 
		times[0] = 0; 
		while(!cont.empty()) {
			int curr = cont.front(); cont.pop();
			for(int i = 0; i < n; i++) { //search for possible combinations of the time and store it inside c;
				int next = curr + butt[i]; 
				if(next < 0) {
					next = 0;
				}
				if(next > 3600) {
					next = 3600;
				}
				if(times[next] <= times[curr] + 1) {
					continue;
				}
				times[next] = times[curr] + 1;
				cont.push(next);
			}
		}
		int time, button;
		for(int i = m; i < 3610; i++) {
			if(times[i] != infinity) {
				time = i;
				button = times[i];
				break;
			}
		}
		cout << button << " " << time - m << endl;
	}
	return 0;
}
