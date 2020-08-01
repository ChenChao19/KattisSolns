//Matric No: A0188318U
//Name: Chen Chao
//Lab Group Number: 14
//Lab Group TA: Prof Steven Halim

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int no;
	while(cin >> no, !cin.eof()) {
		//read in the commands after reading in the no of commands, checked
		int commands[no][2];
		for(int i = 0; i < no; i++) {
			for(int j = 0; j < 2; j++) {
				cin >> commands[i][j];
			}
		}

		//create 3 lists of stack queue and priority queue separately
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		//count the numbers of commands executed
		int s_counter = 0;
		int q_counter = 0;
		int pq_counter = 0;
		
		for(int i = 0; i < no; i++) {
			if(commands[i][0] == 1) { //type 1 command
				s.push(commands[i][1]);
				q.push(commands[i][1]);
				pq.push(commands[i][1]);
				s_counter++; q_counter++; pq_counter++;
			} else { //type 2 command
				if(!s.empty() && s.top() == commands[i][1]) {//not empty and top is the same. ie stack
					s.pop();
					s_counter++;
				}
				if (!q.empty() && q.front() == commands[i][1]) {//not empty and front is the same. ie queue
					q.pop();
					q_counter++;
				}
				if(!pq.empty() && pq.top() == commands[i][1]) {//not empty and top is the same. ie priority queue(since it is already sorted
					pq.pop();
					pq_counter++;
				}
			}
		}
		//check for separate test cases
		if((s_counter == no && q_counter == no) || (s_counter == no && pq_counter == no) || (q_counter == no && pq_counter  == no)) { //if any two of them are fully executed means can be either
			cout << "not sure" << endl;
		} else if(s_counter != no && q_counter != no && pq_counter != no) { //if none of them are the same means none is executed fully
			cout << "impossible" << endl;
		} else if(s_counter == no) { //else its a stack
			cout << "stack" << endl;
		} else if(q_counter == no) { //or a queue
			cout << "queue" << endl;
		} else { //else its a priority queue
			cout << "priority queue" << endl;
		}
	}
	return  0;
}
