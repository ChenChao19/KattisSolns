#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		float b;
		float p;
		cin >> b >> p;
		float min_ABPM = 60.0000 * (b - 1) / p;
		float BPM = 60.0000 * b / p;
		float max_ABPM = 60.0000 * (b + 1) / p;
		cout << min_ABPM << " " << BPM << " " << max_ABPM << endl;
	}
	return 0;
}
