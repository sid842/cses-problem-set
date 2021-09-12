/**
 * This code does not compile on my local machine(macOS).
 * Throws file now found error.
 * Used ideone for this problem.
 */ 

//Solution reference: https://www.youtube.com/watch?v=ORdmSirqrMs
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

//Policy based Data structure
using namespace __gnu_pbds;

using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

	vector<int> contained(n), contains(n);

	ordered_set<pair<int, int>> right_boundaries;

	for(int i = 0; i < n; ++i) {
		right_boundaries.insert({ranges[i].r, -i});
		contained[ranges[i].idx] = right_boundaries.size() - 1 - right_boundaries.order_of_key({ranges[i].r, -i});
	}

	right_boundaries.clear();

	for(int i = n-1; i >= 0; --i) {
		right_boundaries.insert({ranges[i].r, -i});
		contains[ranges[i].idx] = right_boundaries.order_of_key({ranges[i].r, -i});
	}

	for(auto v: contains)
		cout << v << " ";
	cout << "\n";
	for(auto v: contained) 
		cout << v << " ";

	return 0;

}
