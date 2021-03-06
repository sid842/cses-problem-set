#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	map<int, int> compress;

	vector<int> a(n), b(n), p(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> p[i];
		b[i]++;
		compress[a[i]] = 0;
		compress[b[i]] = 0;	
	}

	int coords = 0;
	for(auto& v: compress) {
		v.second = coords++;
	}

	vector<vector<pair<int,int>>> project(coords);
	for (int i = 0; i < n; i++) {
		project[ compress[b[i]] ].emplace_back( compress[a[i]], p[i] );
	}

	vector<long long> dp(coords, 0);
	for (int i = 0; i < coords; i++) {
		if (i > 0) {
			dp[i] = dp[i-1];
		}
		for (auto p : project[i]) {
			dp[i] = max(dp[i], dp[p.first]+p.second);
		}
	}
	cout << dp[coords-1] << endl;

	return 0;

}
