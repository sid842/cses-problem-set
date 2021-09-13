#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	//Similar to shortest job first.

	vector<pair<ll, ll>> tasks(n);
	for(auto& t: tasks) {
		cin >> t.first >> t.second;
	}

	sort(tasks.begin(), tasks.end());

	ll start = 0, reward = 0;
	for(auto& t: tasks) {
		start += t.first;
		reward += t.second - start;
	}

	cout << reward << "\n";

	return 0;

}
