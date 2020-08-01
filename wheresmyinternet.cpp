// PS: THERE IS A MISSING PART INDICATED WITH "LAST PART"
// // SUBMITTING THIS FILE VERBATIM TO KATTIS SHOULD BE WA
//
// // Where's My Internet??
// // Simple Graph DS (Adjacency List), Simple Graph Traversal, connectivity on unweighted graph
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; // shortcut notation

vector<vi> AL; // Adjacency List, preferably put as global variable as it will be accessed by the recursive DFS routine
vi visited; // global variable for the same reason

void dfs(int u) { // the most basic standard DFS implementation, easy to memorize
	visited[u] = 1;
	for (auto &v : AL[u])
		if (!visited[v]) dfs(v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M; // 1 <= N, M <= 200000, rather big, but doable with correct graph ds/algo
	cin >> N >> M; // N vertices and M edges

	// STORE the graph
	AL.assign(N, vi()); // N rows, indexed [0..N-1]
	for (int i = 0; i < M; ++i) { // O(M)
		int a, b;
		cin >> a >> b; a--; b--; // convert to 0-based indexing (otherwise you need N+1 rows in your Adjacency List)
		AL[a].push_back(b); // O(1)
		AL[b].push_back(a); // bi-directional
	}
	// EXPLORE the graph
	visited.assign(N, 0); // O(N)
	dfs(0); // O(N+M)

	bool disconnected = false;
	// LAST PART START: PRINT the required answers (houses that are not connected to house 1) and adjust disconnected boolean flag accordingly
	for(int i = 0; i < N; i++) {
		if(visited[i] == 1) {
			continue;
		}
		disconnected = true;
		cout << i + 1 << endl;
	}

	// LAST PART END
	if (!disconnected) cout << "Connected" << endl;
	return 0;
}

