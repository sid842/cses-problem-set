#include <iostream>
#include <vector>
#include <map>

using namespace std;

void permute(map<char, int>& freq, string& str, size_t i, vector<string>& res) {
	if(i >= str.size()) {
		res.push_back(str);
		return;
	}

	for(auto& f: freq) {
		if(f.second > 0) {
			str[i] = f.first;
			f.second--;
			permute(freq, str, i+1, res);
			f.second++;
		}	
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str;
	cin >> str;

	map<char, int> freq;

	for(char& s: str)
		freq[s]++;

	vector<string> res;

	permute(freq, str, 0, res);

	cout << res.size() << "\n";
	for(auto& s: res)
		cout << s << "\n";

	return 0;

}
