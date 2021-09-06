#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num_children, max_weight_allowed;
	cin >> num_children >> max_weight_allowed;

	vector<int> weights;
	for(int i = 0; i < num_children; ++i) {
		int w;
		cin >> w;
		if(w > max_weight_allowed)
			continue;

		weights.push_back(w);
	}

	sort(weights.begin(), weights.end());

	int ans = 0;
	int i = 0, j = weights.size()-1;
	while(i < j) {
		if(weights[j] + weights[i] <= max_weight_allowed) {
			//Fit the small child in the same container
			i++;
		} 
		ans++;
		j--;
	}
	if(i == j)
		ans++;

	cout << ans << "\n";

	return 0;

}
