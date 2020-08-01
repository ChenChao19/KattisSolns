#include <bits/stdc++.h>

using namespace std;

int main() {
	int length,height;
	cin >> length >> height;
	vector<int> bottom;
	vector<int> top;
	for(int i = 0; i < length / 2; i++) {
		int temp;
		cin >> temp;
		bottom.push_back(temp);
		cin >> temp;
		top.push_back(height - temp);
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());
	int collide[height] = {0};
	vector<int>:: iterator iter;
	for(int i = 0; i < height; i++) {
		iter = lower_bound(bottom.begin(), bottom.end(), i + 1);
		collide[i] += bottom.size() - (iter - bottom.begin());
		iter  = upper_bound(top.begin(), top.end(), i);
		collide[i] += iter - top.begin();
	}
	/**for(int i = 0; i < height; i++) {
		cout << collide[i] << " ";
	}*/
	vector<int> v(collide, collide + height);
	sort(v.begin(), v.end());
	vector<int>::iterator count  = upper_bound(v.begin(), v.end(), v.front());
	cout << v.front() << " " << (count-v.begin()) << endl;
}
