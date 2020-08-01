#include <bits/stdc++.h>

using namespace std;

int min_pos(int len, int *arr)
{
	int min_no = 1e9;
	int pos = 0;
	for(int i = 0; i < len; i++) {
		if(arr[i] < min_no) {
			min_no = arr[i];
			pos = i;
		}
	}
	return pos;
}

int main()
{
	int no;
	cin >> no;
	int arr[no];
	for(int i = 0; i < no; i++) {
		cin >> arr[i];
	}
	int position = min_pos(no, arr);
	cout << position << endl;
	return 0;
}
