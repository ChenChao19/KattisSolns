#include <bits/stdc++.h>

using namespace std;

//checked
struct timer
{
	int time_arr, time_left, time_lock;
	bool operator < (const timer &a) const
	{
		return(a.time_arr == time_arr) ? a.time_left < time_left : a.time_arr < time_arr;
	}
};

struct work
{
	int t_left, t_lock;
	bool operator < (const work &b) const
	{
		return b.t_left < t_left;
	}
};

int main()
{
	int n, m; cin >> n >> m;
	int a, s;
	priority_queue<timer> pq;
	timer temp;
	for(int i = 0; i < n;i++) {
		cin >> a >> s;
		temp.time_arr = a;
		temp.time_left = a + s;
		temp.time_lock = a + s + m;
		pq.push(temp);
	}

	priority_queue<work> stations;
	work temp2;
	int counter = 0;
	while(!pq.empty()) {
		if(stations.empty()) {
			temp = pq.top();
			stations.push({temp.time_left, temp.time_lock});
			pq.pop();
		} else {
			temp = pq.top();
			temp2 = stations.top();
			while(temp.time_arr > temp2.t_lock && !stations.empty()) {
				stations.pop();
				if(!stations.empty()) {
					temp2 = stations.top();
				}
			}
			if(temp.time_arr < temp2.t_left) {
				stations.push({temp.time_left, temp.time_lock});
			} else if(temp.time_arr > temp2.t_lock) {
				stations.push({temp.time_left, temp.time_lock});
			} else {
				stations.pop();
				stations.push({temp.time_left, temp.time_lock});
				counter++;
			}
			pq.pop();
		}
	}
	cout << counter << endl; 
}
