//Matric No: A0188318U
//Name: Chen Chao
//Lab Group Number: 14
//Lab Group TA: Prof Steven Halim

#include <bits/stdc++.h>

using namespace std;

struct priority
{
	int population, box, min;
	bool operator < (const priority &a) const //custom comparison function for priority queue
	{
		return a.min > min;
	}
};

int main()
{
	int N, B;
	while(cin >> N >> B) {
		if(N == -1 || B == -1) {
			break;
		}
		priority_queue<priority> pq;
		priority temp1, temp2;
		for(int i = 0; i < N; i++) {
			cin >> temp1.population;
			temp1.box = 1; //assign 1 box to all cities
			temp1.min = temp1.population; //currently minimum number for voting per box is the entire population as there is only 1 box
			pq.push(temp1);
		}
		B -= N;
		while(B--) {
			temp2 = pq.top();
			pq.pop();
			temp1.population = temp2.population;
			temp1.box = temp2.box + 1;
			if(temp1.population % temp1.box == 0) {
				temp1.min = temp1.population/temp1.box;
			} else {
				temp1.min = temp1.population/temp1.box + 1;
			}
			pq.push(temp1);
		}
		temp2 = pq.top();
		int x = temp2.min;
		cout << x << endl;
	}
	return 0;
}
