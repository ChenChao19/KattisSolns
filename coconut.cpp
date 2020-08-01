#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, n; cin >> s >> n;
	vector<pair<int, string>> input;
	for(int position = 0; position < n; position++) {
		input.push_back(make_pair(position, "folded"));
	}

	int counter = 0;

	while(input.size() != 1) {
		counter = (counter + s - 1) % n;

		if(input[counter].second == "folded") {
			input[counter].second = "fist";
			input.insert(input.begin() + counter + 1, make_pair(input[counter].first, "fist"));
			n++;
		} else if(input[counter].second == "fist") {
			input[counter].second = "palm";
			counter++;
		} else if(input[counter].second == "palm") {
			input.erase(input.begin() + counter);
			n--;
		}
	}
	cout << input[0].first + 1 << endl;
	return 0;
}
