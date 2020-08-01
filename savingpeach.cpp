#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, Y; cin >> N >> Y;
	bool found[100]; memset(found, false, sizeof found);
	for(int i = 0; i < Y; i++) {
		int x; cin >> x;
		found[x] = true;
	}
	int counter = 0;
	for(int i = 0; i < N; i++) {
		if(!found[i]) {
			cout << i << endl;
		} else {
			counter++;
		}
	}
	cout << "Mario got " << counter << " of the dangerous obstacles." << endl;
	return 0;
}
