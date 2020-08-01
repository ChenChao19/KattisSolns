#include <bits/stdc++.h>

using namespace std;

//define a structure containing an array containing 4 value, link to its index and its rank,tabulate a final score as well, checked
typedef struct
{
	int array[4];
	int index;
	int rank;
	int final_score;
}a_i_r;

//checked
int num_tie(a_i_r *array_index, int i, int n) {
	if(i == n) {
		return 0;
	}
	if(array_index[i].array[0] != array_index[i + 1].array[0] || array_index[i].array[1] != array_index[i + 1].array[1] || array_index[i].array[2] != array_index[i + 1].array[2]) {	
		return 1;
	} else {
		return 1 + num_tie(array_index, i + 1, n);
	}
}

//not checked
int rank_tie(a_i_r *array_index, int i, int n) {
	if(i == n) {
		return 0;
	}
	if(array_index[i].rank != array_index[i + 1].rank) {
		return 1;
	} else {
		return 1 + rank_tie(array_index, i + 1, n);
	}
}

int main()
{
	//read in value into an array of a_i_r. checked
	int n; cin >> n;
	a_i_r array_index[1000];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> array_index[i].array[j];
		}
		array_index[i].index = i;
	}

	//create a table of scores for reference, checked
	const int score[1000] = {100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

	//stable sort the arrays into their respective sequence according to s,f,p, checked;
	stable_sort(array_index, array_index + n, [](a_i_r A, a_i_r B) {
			if(A.array[0] != B.array[0]) {
			return A.array[0] > B.array[0];
			} else if(A.array[1] != B.array[1]) {
			return A.array[1] < B.array[1];
			} else {
			return A.array[2] < B.array[2];
			}
			});

	//assign them rank without considering ties yet, checked
	for(int i = 0; i < n; i++) {
		array_index[i].rank = i;
	}

	//consider for tie situations for a particular rank, checked
	for(int i = 0; i < n; i++) {
		int number = num_tie(array_index, i, n);
		if(number > 1) {
			for(int j = i; j < number + i; j++) {
				array_index[j].rank = i;
			}
			i += number - 1;
		}
	}

	for(int i = 0; i < n; i++) {
		int rank_num = rank_tie(array_index, i, n);
		if(i < 30) {
			int sum = 0;
			for(int j = i; j < rank_num + i; j++) {
				sum += score[j];
			}
			for(int j = i; j < rank_num + i; j++) {
				if(sum % rank_num == 0) {
					array_index[j].final_score = sum / rank_num + array_index[j].array[3];
				} else {
					array_index[j].final_score = sum / rank_num + array_index[j].array[3] + 1;
				}
			}
			i += rank_num - 1;
		} else {
			array_index[i].final_score = array_index[i].array[3];
		}
	}

	//sort them according to how they were input
	stable_sort(array_index, array_index + n, [](a_i_r A, a_i_r B) {
			return A.index < B.index;
			});

	//print out the final score
	for(int i = 0; i < n; i++) {
		cout << array_index[i].final_score << endl;
	}
	return 0;
}
