#include <bits/stdc++.h>

#define North 0
#define East 1
#define South 2
#define West 3

using namespace std;

bool movement(int no, int* commands, int final_x, int final_y)
{
	int x = 0, y = 0, direction = 0;
	for(int i = 0; i < no; i++) {
		if(commands[i] == 0) {
			if(direction == 0) y++;
			else if(direction == 1) x++;
			else if(direction == 2) y--;
			else x--;
		} else if(commands[i] == -1) {
			direction = (direction + 3) % 4;
		} else {
			direction = (direction + 1) % 4;
		}
	}
	return (x == final_x && y == final_y);
}


int main()
{
	int final_x, final_y; cin >> final_x >> final_y;
	int no; cin >> no;

	string instructions[50];
	for(int i = 0; i < no; i++) {
		cin >> instructions[i];
	}

	int commands[50] = {0};
	for(int i = 0; i < no; i++) {
		if(instructions[i] == "Forward") {
			commands[i] = 0;
		} else if (instructions[i] == "Left") {
			commands[i] = -1;
		} else {
			commands[i] = 1;
		}
	}

	for(int i = 0; i < no; i++) {
		int original = commands[i];
		int found = 0;
		for(int j = -1; j <= 1; j++) {
			if(j != original) {
				commands[i] = j;
				if(movement(no, commands, final_x, final_y)) {
					if(j == 0) {
						cout << i + 1 << " Forward" << endl;
					} else if(j == -1) {
						cout << i + 1 << " Left" << endl;
					} else {
						cout << i + 1 << " Right" << endl;
					}
					found = 1;
				}
			}
			if(found) {
				break;
			}
		}
		if(found) {
			break;
		}
		commands[i] = original;
	}
	return 0;
}


