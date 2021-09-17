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

	vector<pair<int, int>> val_idx_vec;
	for(int i = 0; i < k; ++i)
		val_idx_vec.push_back({values[i], i});
	
	sort(val_idx_vec.begin(), val_idx_vec.end());
	
	//Left set contains left half of sorted arr, while Right set contains right half.
	set<pair<int, int>> left_set, right_set;
	ll left_sum = 0, right_sum = 0;

	for(int i = 0; i < k/2 + k%2; ++i) {
		left_set.insert(val_idx_vec[i]);
		left_sum += val_idx_vec[i].first;
	}
	for(int i = k/2 + k%2; i < k; ++i) {
		right_set.insert(val_idx_vec[i]);
		right_sum += val_idx_vec[i].first;
	}

	ll median = left_set.rbegin()->first;
	cout << median * left_set.size() - left_sum + right_sum - median*right_set.size() << " ";

	for(int j = 1; j < n - k + 1; ++j) {
		pair<int, int> prev_pair = {values[j-1], j-1};
		pair<int, int> cur_pair = {values[k-1+j], k-1+j};
		
		//Remove value outside window
		if(left_set.count(prev_pair)) {
			left_sum -= prev_pair.first;
			left_set.erase(prev_pair);
		} else {
			right_sum -= prev_pair.first;
			right_set.erase(prev_pair);
		}

		//Insert new value in the window
		if(*(left_set.rbegin()) < cur_pair) {
			right_sum += cur_pair.first;
			right_set.insert(cur_pair);
		} else {
			left_sum += cur_pair.first;
			left_set.insert(cur_pair);
		}

		//Balance the sets
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
