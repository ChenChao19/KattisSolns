#include<bits/stdc++.h>

using namespace std;

void merge(int a[], int low, int mid, int high, long long& counter) {
	// subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
	int N = high-low+1;
	int b[N]; // discuss: why do we need a temporary array b?
	int left = low, right = mid+1, bIdx = 0;
	while (left <= mid && right <= high) { // the merging
		if(a[left] <= a[right]) {
		       b[bIdx++] = a[left++];
		} else {
		       b[bIdx++] = a[right++];
		       counter += right - bIdx - low;
		}
	}
	while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
	while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
	for (int k = 0; k < N; k++) a[low+k] = b[k]; // copy back
}

void mergeSort(int a[], int low, int high, long long& counter) {
	// the array to be sorted is a[low..high]
	int x = 0, y = 0, z = 0;
	if (low < high) { // base case: low >= high (0 or 1 item)
		int mid = (low+high) / 2; 
		mergeSort(a, low , mid, counter); // divide into two halves
		mergeSort(a, mid+1, high, counter); // then recursively sort them
		merge(a, low, mid, high, counter); // conquer: the merge routine
	}
}

int main()
{
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long counter = 0;
	mergeSort(a, 0 , n - 1, counter);
	cout << counter << endl;
}
