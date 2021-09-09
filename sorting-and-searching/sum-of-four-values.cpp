#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	ll target;
	cin >> n >> target;

	vector<ll> arr(n);

	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	map<ll, pair<int, int>> sum_to_indices;

	for(int i = 0; i < n-1; ++i) {
		for(int j = i+1; j < n; ++j) {
			sum_to_indices[arr[i] + arr[j]] = {i, j};
		}
	}

	for(int i = 0; i < n-1; ++i) {
		for(int j = i+1; j < n; ++j) {
			auto itr = sum_to_indices.find(target - arr[i] - arr[j]);
			if(itr != sum_to_indices.end()) {
				set<int> indices;
				indices.insert(itr->second.first);
				indices.insert(itr->second.second);
				indices.insert(i);
				indices.insert(j);
				if(indices.size() == 4) {
					cout << (i+1) << " " << (j+1) << " " << (itr->second.first + 1) << " " << (itr->second.second + 1) << "\n";
					return 0;
				} 
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;

}
