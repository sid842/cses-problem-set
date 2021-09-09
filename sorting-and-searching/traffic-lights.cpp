#include <iostream>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, n;
	cin >> x >> n;

	set<int> lights;
	multiset<int> answers;
	lights.insert(0);
	lights.insert(x);

	answers.insert(x);

	for(int i = 0; i < n; ++i) {
		int l;
		cin >> l;

		//returns iterator and bool
		auto inserted_ele = lights.insert(l);

		//if already present, ignore
		if(inserted_ele.second) {
			auto p = std::prev(inserted_ele.first);
			auto n = std::next(inserted_ele.first);

			int prev_range = (*n) - (*p);
			
			// https://stackoverflow.com/questions/9167745/in-stdmultiset-is-there-a-function-or-algorithm-to-erase-just-one-sample-unic
			auto delete_itr = answers.find(prev_range);
			answers.erase(delete_itr);

			answers.insert(l-(*p));
			answers.insert((*n)-l);
		}
		
		cout << *answers.rbegin() << " ";
	}

	cout << "\n";

	return 0;

}
