#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, M; cin >> N >> M;
	int shop[N][M];
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> shop[i][j];
		}
	}
	for(int i = 1; i < N; i++) {
		shop[i][0] += shop[i-1][0];
	}
	for(int i = 1; i < M; i++) {
		shop[0][i] += shop[0][i-1];
	}
	for(int i = 1; i < N; i++) {
		for(int j = 1; j < M; j++) {
			int x = shop[i-1][j];
			int y = shop[i][j-1];
			shop[i][j] += max(x, y);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << shop[i][M-1] << " ";
	}
	cout << endl;
	return 0;
}
