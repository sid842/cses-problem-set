#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	const int MOD = static_cast<int>(1e9) + 7;
	int n, x;
	cin >> n >> x;

	vector<int> coins(n);

	for(int& c: coins)
		cin >> c;

	vector<int> dp(x+1);

	dp[0] = 1;

	/**
	 * In coin-combinations-i, order matters, so we have to place
	 * coins loop inside as last coin can be anything.
	 * Here order doesn't matter so we can go coin by coin.
	 */ 
	for(int c : coins) {
		for(int val = 1; val <= x; ++val)  {
			if(c <= val)
				dp[val] = (dp[val] + dp[val-c])%MOD;
		}
	}

	cout << dp[x] << "\n";

	return 0;

}
