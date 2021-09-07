#include <iostream>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num_tickets, num_customers;
	cin >> num_tickets >> num_customers;

	//There can be tickets of same prices.
	//Simple set would just consider them as 1.
	multiset<int> tickets;
	for(int i = 0; i < num_tickets; ++i) {
		int ticket;
		cin >> ticket;
		tickets.insert(ticket);
	}

	for(int i = 0; i < num_customers; ++i) {
		int price_limit;
		cin >> price_limit;
		//Lower bound returns first value greater than or equal to.
		auto itr = tickets.lower_bound(price_limit);
		
		if(itr != tickets.begin()) {
			if(itr == tickets.end() || *itr > price_limit)
				--itr;
			cout << *itr << "\n";
			tickets.erase(itr);
		} else {
			if(*itr == price_limit) {
				cout << *itr << "\n";
				tickets.erase(itr);
			} else {
			cout << "-1\n";
			}
		}
	}

	return 0;

}
