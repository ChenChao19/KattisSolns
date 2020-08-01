// Style 1: passing big variables around as function parameter using & to pass by reference
//
#include <bits/stdc++.h>
using namespace std;

// try submitting the code with and without & at AL
// note that this               --> & <-- is super important (much slower otherwise)
void dfs(int u, vector<vector<int>> &AL, vector<int> &visited) { // for the visited vector, you really need to pass by reference as you will modify its content!!
	visited[u] = 1;
	for (auto &v : AL[u])
		if (!visited[v])
			dfs(v, AL, visited);
}

int main() {
	// freopen("in_reachableroads.txt", "r", stdin);
	int n;
	cin >> n; // n test cases
	while (n--) {
		int m, r;
		cin >> m;
		cin >> r;
		vector<vector<int>> AL;
		AL.assign(m, vector<int>());
		while (r--) {
			int u, v;
			cin >> u >> v;
			AL[u].push_back(v);
			AL[v].push_back(u); // very frequent common mistake among beginners: forgot bidirectional edge
		}
		int CC = 0; // O(min(m(m-1)/2, 10m)) here as that is the maximum number of edges/roads
		vector<int> visited;
		visited.assign(m, 0);
		for (int u = 0; u < m; ++u) { // the classic routine for counting number of connected components
			if (!visited[u]) {
				++CC;
				dfs(u, AL, visited);
			}
		}
		cout << CC-1 << endl;
	}
	return 0;
}




// Style 2 (as live-demo-ed): using global variable for AL and visited
/*
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AL;
vi visited;

void dfs(int u) {
	visited[u] = 1;
	for (auto &v : AL[u])
		if (!visited[v])
			dfs(v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n; // n is # of test cases :O
	while (n--) {
		int m; cin >> m; // m is # of vertices
		int r; cin >> r; // r is # of edges
		// discuss: what graph ds is needed?
		AL.assign(m, vi());
		while (r--) {
			int a, b; cin >> a >> b;
			// this time it is different from /flyingsafely :p
			// we need to actually store and process the graph :O
			AL[a].push_back(b);
			AL[b].push_back(a); // bidirectional
		}
		// discuss: what graph problem is this? find #CC, output #CC-1
		// discuss: what graph algorithm to use? 
		visited.assign(m, 0);
		int CC = 0;
		for (int u = 0; u < m; ++u) {
			if (!visited[u]) {
				++CC;
				dfs(u);
			}
		}
		cout << CC-1 << endl;
	}
	return 0;
}
*/

