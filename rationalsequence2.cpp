#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); // standard

	int P; // 1 <= P <= 1000, number of test cases
	cin >> P; // just read

	while (P--) { // process per test case...
		//Each data set consists of a single line of input
		// It contains the data set number, K, a single space, the numerator, p, a forward slash (/, graaahhh) and the denominator, q
		int K, p, q;
		char dummy; // ANOTHER I/O tip for CS2040C class, use this to skip the '/' symbol, to be ignored
		cin >> K >> p >> dummy >> q; // yeah, done, I/O problem gone :)
		// PART 1: Find the pattern based on the given information:
		stack<char> ins;
		while(p != 1 || q != 1) {
			bool left = false;
			if(p < q) {
				left = true;
			}
			if(left == true) {
				q = q - p;
				ins.push('L');
			} else {
				p = p - q;
				ins.push('R');
			}
		}
		// PART 2: Something similar before?
		int n = 1;
		while(!ins.empty()) {
			if(ins.top() == 'L') {
				n = n * 2;
				ins.pop();
			} else {
				 n = n * 2 + 1;
				 ins.pop();
			}
		}
		// For each data set there is a single line of output
		// It contains the data set number, K, followed by a single space which is then followed by the value of n for which F(n) is p/q
		// Inputs will be chosen so n will fit in a 32-bit integer.
		cout << K << " " << n << "\n";
	}

	return 0;
}

