#include<bits/stdc++.h>

using namespace std;

struct car_tp{
	int time, position;
	car_tp(int x, int y) {
		time = x;
		position = y; //in terms of time sequence of arrival regardless of side. ie according to input
	}
};

int main()
{
	int c; cin >> c;
	int n, t, m;
	while(cin >> n >> t >> m, !cin.eof()) {
		int time; string side;
		queue<car_tp> left, right; //create 2 queue for left side and right side
		for(int i = 0; i < m; i++) {
			cin >> time >> side;
			if (side == "left") {
				left.push(car_tp(time, i)); //push to left queue
			} else {
				right.push(car_tp(time, i)); //push to right queue
			}
		}
		int curr_time = 0; int curr_side = 0;//current time and current side of the ferry, 0 for left side and 1 for right side
		int output[10000]; //create an array that can store up to 10000 elements as per maximum of the question
		while(true) { //continuous looping till terminated
			if(left.empty() && right.empty()) { //terminate only when both sides of the queue are empty
				break;
			}

			int counter = 0; // counter for number of cars
			if(curr_side == 0) { // currently at left side
				//case 1 when theres car waiting at the curr_side
				while(counter < n && !left.empty() && left.front().time <= curr_time) { //load up at most n number of ferry if left side is not empty && the car arrives before the currrent time
					output[left.front().position] = curr_time + t;
					left.pop();
					counter++;
				}
				if(counter != 0) { //if the ferry did pick up some cars
					curr_time += t; // takes t time to travel to the other side
					curr_side = 1 - curr_side; // curr_side change to the other side
					continue; //break out of this round of if else statement
				}

				//case 2a when there is no car on both side and the first car to arrive is on the current side
				if(right.empty() || (!left.empty() && left.front().time <= right.front().time)) { //if it did not pick up any car at current time, it will wait as long as right side is empty or when the first car arrival time on left is less than that on the right and that left is not empty
					curr_time = left.front().time;
					while(counter < n && !left.empty() && left.front().time <= curr_time) { //same as above
						output[left.front().position] = curr_time + t;
						left.pop();
						counter++;
					}
					curr_time += t;
					curr_side = 1 - curr_side;
				//case 2b when there is no car on both sides and the first car to arrive is on the other side
				} else {
					if(!right.empty() || (left.empty() && left.front().time > right.front().time)) {
						curr_time = max(curr_time, right.front().time) + t; // account for the time that the other side could be waiting while the ferry travels
						curr_side = 1 - curr_side;
					} else { //else just travel to the other side and wait
						curr_time += t;
						curr_side = 1 - curr_side;
					}
				}
			} else { //currently at right side, everything opposite
				while(counter < n && !right.empty() && right.front().time <= curr_time) {
					output[right.front().position] = curr_time + t;
					right.pop();
					counter++;
				}
				if(counter != 0) {
					curr_time += t;
					curr_side = 1 - curr_side;
					continue;
				}

				if(left.empty() || (!right.empty() && right.front().time <= left.front().time)) {
					curr_time = right.front().time;
					while(counter < n && !right.empty() && right.front().time <= curr_time) {
						output[right.front().position] = curr_time + t;
						right.pop();
						counter++;
					}
					curr_time += t;
					curr_side = 1 - curr_side;
				} else {
					if(!left.empty() || (right.empty() && right.front().time > left.front().time)) {
						curr_time = max(curr_time, left.front().time) + t;
						curr_side = 1 - curr_side;
					} else {
						curr_time += t;
						curr_side = 1 - curr_side;
					}
				}
			}
		}
		for(int i = 0; i < m; i++) {
			cout << output[i] << endl;
		}
		cout << endl;
	}
	return 0;
}
