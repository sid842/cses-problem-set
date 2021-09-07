#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	struct EndPoint {
		int time;
		bool isEnd;
		bool operator<(const EndPoint& rhs) const {
			if(time != rhs.time)
				return time < rhs.time;
			return !isEnd && rhs.isEnd;
		}
	};

	vector<EndPoint> endpoints;
	int num_customers;
	cin >> num_customers;

	for(int i = 0; i < num_customers; ++i) {
		int s, e;
		cin >> s >> e;
		endpoints.push_back(EndPoint{s, false});
		endpoints.push_back(EndPoint{e, true});
	}

	sort(endpoints.begin(), endpoints.end());

	int max_customers_at_a_point = 0, cur_customers = 0;

	for(auto& e: endpoints) {
		if(e.isEnd) {
			cur_customers--;
		} else {
			cur_customers++;
			max_customers_at_a_point = max(max_customers_at_a_point, cur_customers);
		}
	}

	cout << max_customers_at_a_point << "\n";

	return 0;

}
