#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	const int MOD = static_cast<int>(1e9 + 7);

	int n;
	cin >> n;

	//dp[i] -> number of ways to form score i.
	vector<int> dp(n+1);
	dp[0] = 1;

	for(int i = 1; i <= n; ++i) {
		for(int d = 1; d <= 6 && d <= i; ++d) {
			dp[i] = (dp[i] + dp[i-d])%MOD;
		}
	}

	cout << dp[n] <<"\n";

	return 0;

}
