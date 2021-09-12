#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	struct Range {
		int l, r, idx;
		bool operator<(const Range& rhs) const {
			if(l == rhs.l)
				return r > rhs.r;
			return l < rhs.l;
		}
	};

	int n;
	cin >> n;

	vector<Range> ranges(n);

	for(int i = 0; i < n; ++i) {
		cin >> ranges[i].l >> ranges[i].r;
		ranges[i].idx = i;
	}

	sort(ranges.begin(), ranges.end());

	vector<bool> contained(n), contains(n);

	int maxEnd = 0, minEnd = static_cast<int>(1e9) + 5;

	for(int i = 0; i < n; ++i) {
		if(ranges[i].r <= maxEnd) {
			contained[ranges[i].idx] = true;
		}
		maxEnd = max(maxEnd, ranges[i].r);
	}

	for(int i = n-1; i >= 0; --i) {
		// cout << ranges[i].l << " " << ranges[i].r << "\n";
		if(ranges[i].r >= minEnd) {
			contains[ranges[i].idx] = true;
		}
		minEnd = min(ranges[i].r, minEnd);
	}

	for(auto v: contains)
		cout << v << " ";
	cout << "\n";
	for(auto v: contained) 
		cout << v << " ";

	return 0;

}
