#include <bits/stdc++.h>

using namespace std;

int main()
{
	int instructions[1000] = {0};
	for(int j = 0; !cin.eof();j++) {
		int ins;
		cin >> ins;
		instructions[j] = ins;
	}

	int i = 0;
	int counter = 0;
	int reg[10] = {0};
	while(instructions[i] / 100 != 1) {
		int head_no = instructions[i] / 100;
		int mid_no = (instructions[i] / 10) % 10;
		int last_no = instructions[i] % 10;
		if (head_no == 2) {
			reg[mid_no] = last_no;
		} else if(head_no == 3) {
			reg[mid_no] = (reg[mid_no] + last_no) % 1000;
		} else if(head_no == 4) {
			reg[mid_no] = (reg[mid_no] * last_no) % 1000;
		} else if(head_no == 5) {
			reg[mid_no] = reg[last_no];
		} else if(head_no == 6) {
			reg[mid_no] = (reg[mid_no] + reg[last_no]) % 1000;
		} else if(head_no == 7) {
			reg[mid_no] = (reg[mid_no] * reg[last_no]) % 1000;
		} else if(head_no == 8) {
			reg[mid_no] = instructions[reg[last_no]];
		} else if(head_no == 9) {
			instructions[reg[last_no]] = reg[mid_no];
		} else if(head_no == 0) {
			if(reg[last_no] != 0) {
				i = reg[mid_no] - 1;
			}
		}
		i++;
		counter++;
	}
	counter++;
	cout << counter << endl;
	return 0;
}

