#include <bits/stdc++.h>

using namespace std;

void swap(int a, int b, int *array)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int main()
{
	int number[5];
	for(int i = 0; i < 5; i++) {
		cin >> number[i];
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 1; j < 5; j++) {
			if(number[j - 1] > number[j]) {
				swap(j - 1, j, number);
				for(int k = 0; k < 5; k++) {
					cout << number[k] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
