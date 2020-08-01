#include<bits/stdc++.h>

using namespace std;

int main() {
	string movement;
	stack<string> move;
	int count[4] = {0};
	while(cin >> movement && !cin.eof()) {
		if(movement == "up") {
			count[0]++;
			move.push("down");
		} else if(movement == "down") {
		       	count[1]++;
			move.push("up");
		} else if(movement == "left") {
		       	count[2]++;
			move.push("right");
		} else {
			count[3]++;
			move.push("left");
		}
	}
	int vertical = count[0] - count[1];//+ve means net up movement
	int horizontal = count[2] - count[3];//+ve means net left movement
	int row_length = max(count[0], count[1]);
	int col_length = max(count[2], count[1]);
