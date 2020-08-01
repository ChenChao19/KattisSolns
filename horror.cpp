// I put one character typo in this live code, so submitting it verbatim will give you WA

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef vector<int> neighbors;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, H, L; cin >> N >> H >> L;
	vector<neighbors> AL(N+1, neighbors()); // if we use super_source (additional of 1 vertex), don't forget to declare N+1 rows in AL

	int super_source = N; // vertex [0..N-1] are the movies, so we use vertex N to be our super_source
	for (int i = 0; i < H; ++i) {
		int x; cin >> x; // one of the horror movie
		AL[super_source].push_back(x);
	}

	for (int i = 0; i < L; ++i) {
		int a, b; cin >> a >> b;
		AL[a].push_back(b);
		AL[b].push_back(a); // don't forget, bidirectional
	}

	// run BFS on the unweighted undirected graph constructed above
	vector<int> dist(N+1, INF); // if we use super_source (additional of 1 vertex), don't forget to declare N+1 cells in dist
	dist[super_source] = 0; // set to -1 also can, will fix everything to normal
	queue<int> q;
	q.push(super_source);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto &v : AL[u]) {
			if (dist[v] == INF) { // for BFS for SSSP on unweighted graph, the first time we touch vertex v is also the shortest :)
				dist[v] = dist[u]+1; // 1 hop away only
				q.push(v);
			}
		}
	}

	cout << (max_element(dist.begin(), dist.end()) - dist.begin()) << endl;
	return 0;
}

