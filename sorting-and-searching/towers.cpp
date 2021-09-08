#include <iostream>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	multiset<int> towers;
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		auto itr = towers.upper_bound(x);
		if(itr == towers.end()) {
			towers.insert(x);
		} else {
			towers.erase(itr);
			towers.insert(x);
		}
	}

	cout << towers.size() << "\n";

	return 0;

}
