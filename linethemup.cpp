#include <bits/stdc++.h>

using namespace std;

bool check(string* names,int i, int j, int N,int counter) {
	if(names[i][counter] == names[j][counter]) {
		return check(names, i, j, N, counter + 1);
	}
	return(names[i][counter] > names[j][counter]);
}

int main()
{
	int N; cin >> N;

	string names[N];
	for(int i = 0; i < N; i++) {
		cin >> names[i];
	}

	int counter = 0;
	int i = 0;
	while(i != N - 1) {
		if(!check(names, i, i + 1, N, 0)) {
			counter += 1;
		}
		if(check(names, i, i + 1, N, 0)) {
			counter -= 1;
		}
		i++;
	}
	if(counter == N - 1) {
		cout << "INCREASING" << endl;
	} else if(counter == 1 - N) {
		cout << "DECREASING" << endl;
	} else {
		cout << "NEITHER" << endl;
	}
	return 0;
}
