#include <bits/stdc++.h>

using namespace std;

int main()
{
	int R;
	int C;
	cin >> R >> C;
	char map[R][C];
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	int counter = 0;
	int row = 0;
	int col = 0;
	while(map[row][col] != 'T' && counter <= R * C  ) {
		if (row == -1 || col == -1 || row == R || col == C) {
			cout << "Out" << endl;
			break;
		}

		if(map[row][col] == 'N') {
			row -= 1;
			counter += 1;
		}

		if(map[row][col] == 'S') {
			row += 1;
			counter += 1;
		}
		
		if(map[row][col] == 'W') {
			col -= 1;
			counter += 1;
		}
		
		if(map[row][col] == 'E') {
			col += 1;
			counter += 1;
		}
	}

	if (counter >= R * C) {
		cout << "Lost" << endl;
	}

	if(map[row][col] == 'T') {
		cout << counter << endl;
	}
	return 0;
}
