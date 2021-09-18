#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	const int MOD = static_cast<int>(1e9) + 7;

	int n;
	cin >> n;

	vector<string> grid(n);
	for(auto& row: grid)
		cin >> row;

	vector<vector<int>> ways(n+1, vector<int>(n+1));

	ways[1][1] = grid[0][0] == '.' ? 1 : 0;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(grid[i-1][j-1] != '*' && (i != 1 || j != 1)) {
				ways[i][j] = (0LL + ways[i-1][j] + ways[i][j-1])%MOD; //0LL to avoid overflow
			}
		}
	}

	cout << ways[n][n] << "\n";

	return 0;

}
