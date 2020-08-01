#include <bits/stdc++.h>

using namespace std;

int main()
{
	int no; cin >> no;
	stack<int> cards;
	int counter = 0;
	for(int i = 0; i < no; i++) {
		int x; cin >> x;
		
		if(cards.empty()) {
			cards.push(x);
			continue;
		}

		if((cards.top() + x) % 2 == 0) {
			cards.pop();
		} else {
			cards.push(x);
		}
	}
	
	cout << cards.size() << endl;
	return 0;
}
