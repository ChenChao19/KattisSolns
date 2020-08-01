#include <bits/stdc++.h>

using namespace std;

#define max_RC 110 

int N;
int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int infinity = 1e9;
char grid[max_RC][max_RC];
int dist[max_RC][max_RC];

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({r,c});
	dist[r][c] = 0;
	while(!q.empty()) {
		int u = q.front().first; int v = q.front().second; q.pop();
		for(int d = 0; d < 8; d++) {
			if(u + dr[d] < 0 || u + dr[d] >= N || v + dc[d] < 0 || v + dc[d] >= N || grid[u+dr[d]][v+dc[d]] == '#') continue;
			int x = dist[u+dr[d]][v+dc[d]];
			dist[u+dr[d]][v+dc[d]] = min(dist[u+dr[d]][v+dc[d]], dist[u][v] + 1);
			if(x == dist[u+dr[d]][v+dc[d]]) continue;
			q.push({u+dr[d], v+dc[d]});
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> grid[i];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			dist[i][j] = infinity;
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(grid[i][j] == 'K') {
				bfs(i, j);
			}
		}
	}
	if(dist[0][0] == infinity) cout << -1 << endl;
	else cout << dist[0][0] << endl;
	return 0 ;
}
