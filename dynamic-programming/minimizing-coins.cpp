#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, val;
	cin >> n >> val;

	vector<int> coins(n);
	for(int& c: coins)
		cin >> c;

	//dp[i] -> min coins needed to make sum i.
	vector<int> dp(val+1, numeric_limits<int>::max());
	dp[0] = 0;

	for(int i = 1; i <= val; ++i) {
		for(int c: coins) {
			if(c <= i && dp[i-c] != numeric_limits<int>::max()) {
				dp[i] = min(dp[i], 1 + dp[i-c]);
			}
		}
	}

	cout << (dp[val] == numeric_limits<int>::max() ? -1 : dp[val]) << "\n";

	return 0;

}
