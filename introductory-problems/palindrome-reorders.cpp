#include <iostream>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;

	set<char> odd_freq_char;

	int cnt[26] = {0};

	for(char c: str) {
		cnt[c - 'A']++;
		if(!odd_freq_char.count(c))
			odd_freq_char.insert(c);
		else
			odd_freq_char.erase(c);
	}

	if(odd_freq_char.size() > 1)
		cout << "NO SOLUTION\n";
	else {
		int l = 0, r = str.size()-1;
		for(int i = 0; i < 26; ++i) {
			while(cnt[i] > 1) {
				str[l] = str[r] = (i + 'A');
				cnt[i]-=2;
				l++; r--;
			}
		}
		if(l == r) 
			str[l] = *odd_freq_char.begin();
		cout << str << "\n";
	}


	return 0;

}
