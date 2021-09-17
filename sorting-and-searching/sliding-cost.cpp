//Solution Reference: https://www.youtube.com/watch?v=rMK_or9QNrg
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	set<pair<int, int>> left_set, right_set;
	vector<int> values(n);

	for(int i = 0; i < n; ++i)
		cin >> values[i];

	if(k == 1) {
		for(int i = 0; i < n; ++i)
			cout << 0 << " ";
		return 0;
	} if(k == 2) {
		for(int i = 1; i < n; ++i)
			cout << abs(values[i]-values[i-1]) << " ";
		return 0;
	}

	vector<pair<int, int>> st;
	for(int i = 0; i < k; ++i)
		st.push_back({values[i], i});
	sort(st.begin(), st.end());
	ll left_sum = 0, right_sum = 0;

	for(int i = 0; i < k/2 + k%2; ++i) {
		left_set.insert(st[i]);
		left_sum += st[i].first;
	}
	for(int i = k/2 + k%2; i < k; ++i) {
		right_set.insert(st[i]);
		right_sum += st[i].first;
	}

	ll median = left_set.rbegin()->first;
	cout << median * left_set.size() - left_sum + right_sum - median*right_set.size() << " ";

	for(int j = 1; j < n - k + 1; ++j) {
		pair<int, int> prev_pair = {values[j-1], j-1};
		pair<int, int> cur_pair = {values[k-1+j], k-1+j};
		
		if(left_set.count(prev_pair)) {
			left_sum -= prev_pair.first;
			left_set.erase(prev_pair);
		} else {
			right_sum -= prev_pair.first;
			right_set.erase(prev_pair);
		}

		if(*(left_set.rbegin()) < cur_pair) {
			right_sum += cur_pair.first;
			right_set.insert(cur_pair);
		} else {
			left_sum += cur_pair.first;
			left_set.insert(cur_pair);
		}

		while(left_set.size() < (k/2 + (k%2))) {
			auto z = (*right_set.begin());
			left_set.insert(z);
			left_sum += z.first;
			right_set.erase(z);
			right_sum -= z.first;
		}

		while(left_set.size() > (k/2 + (k%2))) {
			auto z = (*left_set.rbegin());
			right_set.insert(z);
			right_sum += z.first;
			left_set.erase(z);
			left_sum -= z.first;
		}

		median = left_set.rbegin()->first;
		cout << median * left_set.size() - left_sum +
			 right_sum - median*right_set.size() << " ";
	}

	return 0;

}
