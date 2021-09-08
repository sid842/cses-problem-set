#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int& a: arr)
		cin >> a;

	set<int> distinct_songs;

	int max_unique_songs = 0;

	for(int left = 0, right = 0; right < n; ++right) {
		while(distinct_songs.count(arr[right])) {
			distinct_songs.erase(arr[left]);
			left++;
		}

		max_unique_songs = max(max_unique_songs, right-left+1);
		distinct_songs.insert(arr[right]);
	}

	cout << max_unique_songs << "\n";

	return 0;

}
