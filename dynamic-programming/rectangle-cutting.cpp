#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int h, w;
	cin >> h >> w;

	//dp[i][j] = min cuts required to make i*j into squares.
	vector<vector<int>> dp(h+1, vector<int>(w+1));

	for(int i = 1; i <= h; ++i) {
		for(int j = 1; j <= w; ++j) {
			if(i == j)
				dp[i][j] = 0;
			else {
				dp[i][j] = 1e9;
				//Cutting horizontally
				for(int k = 1; k < i; ++k) {
					dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
				}
				//Cutting vertically
				for(int k = 1; k < j; ++k) {
					dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
				}
			}
		}
	}

	cout << dp[h][w] << "\n";

	return 0;

}
