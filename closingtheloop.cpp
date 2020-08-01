#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		int S; cin >> S;
		string segments[S];
		for(int j = 0; j < S; j++) {
			cin >> segments[j];
		}
		
		vector<int>array_R;
		vector<int>array_B;
		for(int j = 0; j < S; j++) {
			int amount = 0;
			int length = segments[j].length();
			for(int k = 0; k < length - 1; k++) {
				amount *= 10;
				amount += segments[j][k] - '0';
			}
			if(segments[j][length - 1] == 'R') {
				array_R.push_back(amount);
			} else {
				array_B.push_back(amount);
			}
		}
		
		sort(array_R.begin(), array_R.end(), greater<int>());
		sort(array_B.begin(), array_B.end(), greater<int>());	
		
		int sum = 0;
		
		if(array_R.size() == 0 || array_B.size() == 0 ) {
			cout << "Case #" << i + 1 << ": " << 0 << endl;
		} else if(array_R.size() <= array_B.size()) {
			for(int j = 0; j < array_R.size(); j++) {
				sum += array_R[j];
				sum += array_B[j];
			}
			cout << "Case #" << i + 1 << ": " << sum - (2 * array_R.size()) << endl;
		} else if(array_B.size() < array_R.size()) {
			for(int j = 0; j < array_B.size(); j++) {
				sum += array_B[j];
				sum += array_R[j];
			}
			cout << "Case #" << i + 1 << ": " << sum - (2 * array_B.size()) << endl;
		}
	}
	return 0;
}
