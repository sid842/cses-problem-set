#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int sum = 0;

	vector<int> coins(n);
	for(int& c: coins) {
		cin >> c;
		sum += c;
	}

	//dp[i] -> is it possible to build i using coins
	vector<bool> dp(sum+1);
	int count = 0;
	dp[0] = true;
	for(int i = 0; i < n; ++i) { //Outer loop of coins so that we don't consider the same coin again.
		for(int j = sum; j >= coins[i]; --j) { // starting from sum to coins[i], since the current coin shouldn't be used for previous sums.
			if(dp[j])
				continue;
			if(coins[i] <= j && dp[j-coins[i]]) {
				dp[j] = dp[j] || dp[j-coins[i]];
				count++;
			}
		}
	}
	cout << count <<"\n";
	for(int i = 1; i <= sum; ++i) {
		if(dp[i])
			cout << i << " ";
	}

	return 0;

}
