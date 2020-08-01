#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	stack<int> aux;
	int sock;
	int count = 0;
	for(int i = 0; i < 2 * n; i++) {
		cin >> sock;
		if(aux.empty()) {
			aux.push(sock);
			count++;
		} else {
			if(aux.top() == sock) {
				aux.pop();
				count++;
			} else {
				aux.push(sock);
				count++;
			}
		}
	}
	if(!aux.empty()) {
		cout << "impossible" << endl;
	} else {
		cout << count << endl;
	}
	return 0;
}
