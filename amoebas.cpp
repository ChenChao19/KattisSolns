// there is 1 character bug in this code, submitting it verbatim will be WA
#include <bits/stdc++.h>
using namespace std;

#define MAX_RC 110

int m, n;
int dr[] = {0, 1, 0, -1, -1, -1, 1, 1}; // Left/Up/Right/Down/top-right/top-left/bottom-right/bottom-left
int dc[] = {-1, 0, 1, 0, 1, -1, 1, -1};
char grid[MAX_RC][MAX_RC];

void floodFill(int r, int c) {
	if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '.') {
		return;
	}
	grid[r][c] = '.';
	for(int d = 0; d < 8; d++) {
		floodFill(r+dr[d], c+dc[d]);
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> grid[i];
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '#') {
				ans++;
				floodFill(i, j);
			}
		}
	}
	cout <<  ans << endl;
	return 0;
}

