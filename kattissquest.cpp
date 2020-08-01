#include<bits/stdc++.h>

using namespace std;

struct priority
{
	int energy, gold;
	bool operator < (const priority &a) const //custom comparison function for priority queue
	{
		return (a.energy == energy) ? a.gold > gold : a.energy > energy; // return biggest energy, if tie, return biggest gold
	}
};

int main()
{
	int N; cin >> N;
	string command;
	map<int, priority_queue<priority>> input;
	while(N--) {
		cin >> command;
		if(command == "add") {
			int E, G; cin >> E >> G;
		}
	}


}
