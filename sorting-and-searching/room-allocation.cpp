#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	using Duration = pair<int, int>;

	int n;
	cin >> n;

	vector<pair<Duration, int>> customers(n);

	for(int i = 0; i < n; ++i) {
		cin >> customers[i].first.first >> customers[i].first.second;
		customers[i].second = i;
	}

	sort(customers.begin(), customers.end());

	int roomId = 1;
	vector<int> roomAssigned(n);

	//Pair - leaving time and roomId
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rooms;

	for(int i = 0; i < n; ++i) {
		if(rooms.empty()) {
			rooms.push(make_pair(customers[i].first.second, roomId));
			roomAssigned[customers[i].second] = roomId++;
		} else {
			if(rooms.top().first < customers[i].first.first) {
				auto room = rooms.top();
				rooms.pop();
				rooms.push(make_pair(customers[i].first.second, room.second));
				roomAssigned[customers[i].second] = room.second;
			} else {
				rooms.push(make_pair(customers[i].first.second, roomId));
				roomAssigned[customers[i].second] = roomId++;
			}
		}
	}

	cout << (roomId-1) << "\n";
	for(auto ra: roomAssigned)
		cout << ra << " ";

	return 0;

}
