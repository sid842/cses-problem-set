#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, idx = 0;
	cin >> n;

	vector<pair<int, int>> arr(n);
	for(auto& a: arr) {
		cin >> a.first;
		a.second = idx++;
	}

	sort(arr.begin(), arr.end());

	int prev_picked_idx = -1, round = 1;

	for(auto& a: arr) {
		if(prev_picked_idx > a.second) {
			round++;
		}
		prev_picked_idx = a.second;
	}

	cout << round << "\n";

	return 0;

}
