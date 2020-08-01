#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); // I hope C++ users don't get accidental TLE due to missing this line
	int n, k; // 1 <= n <= 30 (number of students), 1 <= k <= 100 (number of commands from the teacher)
	cin >> n >> k; // just read
	stack<int> commands;
	while (k--) { // now we throw the eggs around (or undo)
		int m;
		string cmd; // we do not really know what comes next, is it a command "undo m" or a single integer, we read as string first
		cin >> cmd;
		if (cmd == "undo") { // if we see a word "undo", then the format will be "undo m"
			cin >> m; // so we read m next
			for(int i = 0; i < m; i++) {
				commands.pop();
			}
		} else { // this "cmd" is actually integer m :o
			m = stol(cmd); // there is a built-in command to convert string to integer
			commands.push(m);
			// what should we do with this throw command with parameter m?
		}
	}
	int sum  = 0;
	while(!commands.empty()) {
		sum += commands.top();
		commands.pop();
	}

	int ans = sum % n;
	while(ans < 0) {
		ans = ans + n;
	}
	cout << ans << endl;
	return 0;
}

