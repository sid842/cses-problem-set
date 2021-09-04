#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str;
	cin >> str;

	int ans = 1;
	int cnt = 1;
	char prev = str[0];
	for(int i = 1; i < str.size(); ++i) {
		if(prev != str[i]) {
			ans = max(ans, cnt);
			cnt = 1; prev = str[i];
		} else {
			cnt++;
		}
	}

	ans = max(ans, cnt);
	cout << ans << "\n";

	return 0;

}
