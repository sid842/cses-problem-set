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

	for(int i = 1; i <= x; ++i) {
		for(int c: coins) {
			if(c <= i) {
				dp[i] = (dp[i] + dp[i-c])%MOD;
			}
		}
	}

	cout << dp[x] << "\n";
	
	return 0;

}
