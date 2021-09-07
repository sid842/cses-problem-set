#include <cstdio>

using namespace std;

#define IsValid(a) (a >= 0 && a < 7)

#define RIGHT 0
#define LEFT  1
#define DOWN  2
#define UP    3

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int GRID_SIZE = 7; 


char str[49];
int vis[7][7];


int CountPaths(int y, int x, int pos) {
	if(pos == 48)
		return y == 6 && x == 0; //Bottom left corner or not.

	if(y == 6 && x == 0)
		return 0;

	if(vis[y][x])
		return 0;

	bool visited[4] = {0};

	for(int k = 0; k < 4; k++) {
		if(IsValid(y + dy[k]) && IsValid(x + dx[k]))
			visited[k] = vis[y + dy[k]][x + dx[k]];
	}

	//Grid partitioning - cannot traverse other half
	if(!visited[DOWN] && !visited[UP]
	 && visited[LEFT] && visited[RIGHT])
		return 0;

	if(visited[DOWN] && visited[UP]
	 && !visited[LEFT] && !visited[RIGHT])
		return 0;


	if(IsValid(y-1) && IsValid(x+1) && vis[y-1][x+1])
		if(!visited[RIGHT] && !visited[UP])
			return 0;

	if(IsValid(y+1) && IsValid(x+1) && vis[y+1][x+1])
		if(!visited[RIGHT] && !visited[DOWN])
			return 0;

	if(IsValid(y-1) && IsValid(x-1) && vis[y-1][x-1])
		if(!visited[LEFT] && !visited[UP])
			return 0;

	if(IsValid(y+1) && IsValid(x-1) && vis[y+1][x-1])
		if(!visited[LEFT] && !visited[DOWN])
			return 0;

	vis[y][x] = 1;
	int num_of_paths = 0;

	if(str[pos] == '?') {
		for(int k = 0; k < 4; ++k) {
			if(IsValid(y + dy[k]) && IsValid(x + dx[k]) && !vis[y+dy[k]][x+dx[k]]) {
				num_of_paths += CountPaths(y + dy[k], x + dx[k], pos+1);
			}
		}
	} else {
		if(str[pos] == 'R' && x + 1 < 7) 
			num_of_paths += CountPaths(y, x + 1, pos+1);
		else if(str[pos] == 'L' && x - 1 >= 0)
			num_of_paths += CountPaths(y, x - 1, pos+1);
		else if(str[pos] == 'U' && y - 1 >= 0)
			num_of_paths += CountPaths(y - 1, x, pos+1);
		else if(str[pos] == 'D' && y + 1 >= 7)
			num_of_paths += CountPaths(y + 1, x, pos+1);
			
	}

	vis[y][x] = 0;
	return num_of_paths;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%s", str);
	printf("%d\n", CountPaths(0, 0, 0));

	return 0;

}
