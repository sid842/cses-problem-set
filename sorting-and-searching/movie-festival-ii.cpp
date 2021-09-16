#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> movies(n);

	for(auto& m: movies) {
		cin >> m.second >> m.first;
	}

	//Sort by end times
	sort(movies.begin(), movies.end());

	//Initialize k club members
	multiset<int> end_times;
	for (int i = 0; i < k; ++i)
		end_times.insert(0);

	int ans = 0;

	for(int i = 0; i < n; ++i) {
		auto itr = end_times.upper_bound(movies[i].second);

		//No movie 
		if(itr == end_times.begin())
			continue;

		end_times.erase(--itr);
		end_times.insert(movies[i].first);
		ans++;
	}

	cout << ans << "\n";

	return 0;

}
