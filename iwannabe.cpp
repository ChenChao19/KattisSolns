#include<bits/stdc++.h>

using namespace std;

int main()
{
	long N, K; cin >> N >> K;
	vector<pair<long, long>> a, d, h;
	for(long i = 0; i < N; i++) {
		long  A, D, H;
		cin >> A >> D >> H;
		a.push_back({A, i});
		d.push_back({D, i});
		h.push_back({H, i});
	}
	sort(a.rbegin(), a.rend());
	sort(d.rbegin(), d.rend());
	sort(h.rbegin(), h.rend());
	set<long> team;
	for(long i = 0; i < K; i++) {
		team.insert(a[i].second);
		team.insert(d[i].second);
		team.insert(h[i].second);
	}
	cout << team.size() << endl;
	return 0;
}
