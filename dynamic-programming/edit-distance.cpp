#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string word1, word2;
	cin >> word1;
	cin >> word2;

	auto m = word1.size(), n = word2.size();

	vector<vector<size_t>> cost(m+1, vector<size_t>(n+1));

	for(auto i = 0; i <= m; ++i)
		cost[i][0] = i;

	for(auto i = 0; i <= n; ++i)
		cost[0][i] = i;

	for(auto i = 1; i <= m; ++i) {
		for(auto j = 1; j <= n; ++j) {
			if(word1[i-1] == word2[j-1])
				cost[i][j] = cost[i-1][j-1];
			else
				cost[i][j] = 1 + min(cost[i-1][j-1], min(cost[i-1][j], cost[i][j-1]));
		}
	}

	cout << cost[m][n];

	return 0;

}
