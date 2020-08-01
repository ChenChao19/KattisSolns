// Grid
// // BFS with modification of move distance based on the value of current cell
// // this code is WA, do you know what is the bug? can you fix it to get AC?

#include <bits/stdc++.h>
using namespace std;

const int MAX_NM = 510;

typedef pair<int, int> ii;

int d[MAX_NM][MAX_NM];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m; cin.get();
	string grid[n];
	for (int r = 0; r < n; ++r) cin >> grid[r];
	queue<ii> q; q.push({0, 0}); // source is the top left
	memset(d, -1, sizeof d); d[0][0] = 0;
	int dr[] = { 0, 1, 0,-1}; // E/S/W/N
	int dc[] = { 1, 0,-1, 0};
	while (!q.empty()) {
		int r = q.front().first, c = q.front().second; q.pop();
		if ((r == n-1) && (c == m-1)) break;
		int k = grid[r][c]-'0';
		for (int dir = 0; dir < 4; ++dir) {
			int nr = r+k*dr[dir], nc = c+k*dc[dir]; // jump according to direction and value k of current cell (r, c)
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue; // outside the grid
			if (d[nr][nc] != -1) continue; // already visited, do not go into a cycle
			d[nr][nc] = d[r][c]+1;
			q.push({nr, nc});
		}
	}

	cout << d[n-1][m-1] << endl; // if unreachable, the answer will be -1
	return 0;
}

