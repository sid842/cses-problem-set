#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//Knapsack problem

	struct Book {
		int price;
		int pages;
	};

	int n, cap;
	cin >> n >> cap;

	vector<Book> books(n);
	for(int i = 0; i < n; ++i)
		cin >> books[i].price;

	for(int i = 0; i < n; ++i)
		cin >> books[i].pages;

	vector<int> max_pages(cap+1);

	for(int i = 0; i < n; ++i) {
		//Iterating from reverse helps reduce the space complexity
		for(int c = cap; c >= books[i].price; c--) {
			max_pages[c] = max(max_pages[c], max_pages[c-books[i].price] + books[i].pages);
		}
	}

	cout << max_pages[cap];

	return 0;

}
