#include <iostream>
#include <vector>

using namespace std;

namespace {
	static const int BOARD_SIZE = 8;
}

bool IsValidPlacement(const vector<int>& cols) {
	int last = cols.size()-1;
	//from 0 to last-1 -> all queens are non-attacking

	for(int i = 0; i < last; ++i) {
		if((cols[i] == cols[last]) || (abs(cols[i]-cols[last]) == last-i))
			return false;
	}

	return true;
}

void NQueens(const vector<string>& board, vector<int>& cols, int idx, int& ans) {
	if(idx == BOARD_SIZE) {
		//Found valid placement of 8 queens.
		ans++;
		return;
	}

	for(int i = 0; i < BOARD_SIZE; ++i) {
		if(board[idx][i] == '*')
			continue;
		cols.push_back(i);
		if(IsValidPlacement(cols)) {
			NQueens(board, cols, idx+1, ans);
		}
		cols.pop_back();
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string> board(BOARD_SIZE);
	for(int i = 0; i < BOARD_SIZE; ++i)
		cin >> board[i];

	int ans = 0;

	//So no need to place queens within the same row.
	//So cols[i] tells us the column of the queen at row i. 
	vector<int> cols;

	NQueens(board, cols, 0, ans);

	cout << ans << "\n";

	return 0;
}