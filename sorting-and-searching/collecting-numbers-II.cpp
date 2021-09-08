/**
 * 
 * My solution was giving TLE.
 * Reference: https://www.youtube.com/watch?v=LEL3HW4dQew 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<int> arr(n+1), pos(n+1);
	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	int ans = 1;
	for(int i = 1; i < n; ++i) {
		ans += (pos[i] > pos[i+1] ? 1 : 0);
	}

	int l, r;
	set<pair<int, int>> pairs_to_check;

	while(m--) {
		cin >> l >> r;
		//If we swap the position, we just need to consider the adjacent values only.
		if(arr[l] + 1 <= n)
			pairs_to_check.insert({arr[l], arr[l]+1});
		if(arr[l] - 1 >= 1)
			pairs_to_check.insert({arr[l]-1, arr[l]});
		if(arr[r] + 1 <= n)
			pairs_to_check.insert({arr[r], arr[r]+1});
		if(arr[r] - 1 >= 1)
			pairs_to_check.insert({arr[r]-1, arr[r]});
	
		for(auto& p: pairs_to_check) {
			ans -= (pos[p.first] > pos[p.second] ? 1 : 0);
		}

		swap(arr[l], arr[r]);
		pos[arr[l]] = l;
		pos[arr[r]] = r;

		for(auto& p: pairs_to_check) {
			ans += (pos[p.first] > pos[p.second] ? 1: 0);
		}

		cout << ans << "\n";
		pairs_to_check.clear();
	}

	return 0;

}
