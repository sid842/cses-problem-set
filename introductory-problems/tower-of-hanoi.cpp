#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> steps;

void TowerOfHanor(int n, int from, int aux, int to) {
	if(n > 0) {
		TowerOfHanor(n-1, from, to, aux);
		steps.push_back(make_pair(from, to));
		TowerOfHanor(n-1, aux, from, to);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	TowerOfHanor(n, 1, 2, 3);

	cout << steps.size() << "\n";
	for(auto& step: steps) {
		cout << step.first << " " << step.second << "\n";
	}

	return 0;

}
