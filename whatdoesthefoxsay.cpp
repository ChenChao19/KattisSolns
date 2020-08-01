#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T; cin >> T; cin.get();
	while(T--) {
		string line;
		getline(cin, line);
		unordered_set<string> not_fox;
		while(1) {
			string animal_goes_sound, sound;
			getline(cin, animal_goes_sound);
			if(animal_goes_sound == "what does the fox say?") break;
			istringstream iss1(animal_goes_sound);
			iss1 >> sound;
			iss1 >> sound;
			iss1 >> sound;
			not_fox.insert(sound);
		}
		istringstream iss2(line);
		string sound;
		while(iss2 >> sound) {
			if(not_fox.find(sound) != not_fox.end()) continue;
			cout << sound << " ";
		}
		cout << endl;
	}
	return 0;
}







