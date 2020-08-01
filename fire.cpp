#include<bits/stdc++.h>

using namespace std;

#define wall '#'
#define space '.'
#define joe 'J'
#define fire 'F'

int R, C;
int dr[] = {0, 1, 0, -1}; //E/S/W/N
int dc[] = {-1, 0, 1, 0};
char maze[1010][1010];
int ans = 0;
bool flag = true;

void spreadfire(int rj, int cj, int rf, int cf ) {
	if(rj < 0 || rj >= R || cj < 0 || cj >= C || maze[rj][cj] == wall) return;
	maze[r][c] = fire;
	for(int d = 0; d < 4; d++) spreadfire(r + dr[d], c + dc[d]);
}

int main()
{
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		cin >> maze[R];
	}
	int ans;
	int rj, cj, rf, cf
	for(int r = 0; r < R; r++) {
		for(int c = 0 ; c < C; c++) {
			if(maze[r][c] == joe) {
				rj = r;
				cj = c;
			}
			if(maze[r][c] == fire) {
				rf = r;
				rj = c;
			}
		}
	}
	spreadfire(rj, cj, rf, cf);
	if(!flag) cout << "IMPOSSIBLE" << endl;
	else cout << ans << endl;
}
