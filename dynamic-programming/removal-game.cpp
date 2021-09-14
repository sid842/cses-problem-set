#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<ll> arr(n);
	for(auto& a: arr)
		cin >> a;

	//dp[i][j] = max score for player 1 for numbers between [i, j]
	vector<vector<ll>> dp(n, vector<ll>(n));

	for(int i = 0; i < n-1; ++i) {
		dp[i][i] = arr[i];
		dp[i][i+1] = max(arr[i], arr[i+1]);
	}

	dp[n-1][n-1] = arr[n-1];

	for(int l = 3; l <= n; ++l) {
		for(int i = 0; i + l - 1 < n; ++i) {
			int j = i + l - 1;

			dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]),
						   arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
		}
	}

	cout << dp[0][n-1];

	return 0;

}
