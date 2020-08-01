#include<bits/stdc++.h>

using namespace std;

int main()
{
	string command;	
	unordered_map<string, int>mapper;
	while(cin >> command) {
		if(command == "define") {
			int val; string key;
			cin >> val >> key;
			mapper[key] = val;
		} else {
			string key1; char operation; string key2;
			cin >> key1 >> operation >> key2;
			if((mapper.find(key1) == mapper.end()) || (mapper.find(key2) == mapper.end())) {
				cout << "undefined" << endl;
			} else {
				if(operation == '<') {
					if(mapper[key1] < mapper[key2]) {
						cout << "true" << endl;
					} else {
						cout << "false" << endl;
					}
				} else if(operation == '>') {
					if(mapper[key1] > mapper[key2]) {
						cout << "true" << endl;
					} else {
						cout << "false" << endl;
					}
				} else {
					if(mapper[key1] == mapper[key2]) {
						cout << "true" << endl;
					} else {
						cout << "false" << endl;
					}
				}

			}
		}
	}
	return 0;
}
