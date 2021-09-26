#include <iostream>
#include <vector>

using namespace std;

void fillWaysTableAtGivenRow(vector<vector<int>>& ways, int i, int v, int m, int MOD) {
	if(i <= 0)
		throw -1; //Assert

	ways[i][v] = (ways[i][v] + ways[i-1][v])%MOD;
	if(v-1 >= 1)
		ways[i][v] = (ways[i][v] + ways[i-1][v-1])%MOD;
	if(v+1 <= m)
		ways[i][v] = (ways[i][v] + ways[i-1][v+1])%MOD;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	const int MOD = static_cast<int>(1e9) + 7;

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);

	for(int& a: arr)
		cin >> a;

	//ways[i][j] to fill incomplete array till ith index with value j
	vector<vector<int>> ways(n, vector<int>(m+1));

	//Initialization 
	if(arr[0] == 0) {
		for(int v = 1; v <= m; ++v)
				ways[0][v] = 1;
	} else {
		ways[0][arr[0]] = 1;
	}

	for(int i = 1; i < n; ++i) {
		if(arr[i] != 0) {
			fillWaysTableAtGivenRow(ways, i, arr[i], m, MOD);
		} else {
			for(int v = 1; v <= m; ++v) {
				fillWaysTableAtGivenRow(ways, i, v, m, MOD);
			}
		}
	}

	int total_ways = 0;
	for(auto& v: ways[n-1]) {
		total_ways = (total_ways + v)%MOD;
	}

	cout << total_ways << "\n";

	return 0;

}
