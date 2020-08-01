#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r;
        int n;
	cin >> r >> n;
	int array[r] = {0};
	int room_no;
	for(int i = 0; i < n; i++) {
		cin >> room_no;
		array[room_no - 1] = 1;
	}
	int counter = 0;
	for(int i = 0; i < r; i++) {
		if(array[i] == 0) {
			cout << i + 1 << endl;
			break;
		}
		counter++;
	}
	if(counter == r) {
		cout << "too late" << endl;
	}
	return 0;
}

