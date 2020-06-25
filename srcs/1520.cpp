// https://www.acmicpc.net/problem/1520

#include <bits/stdc++.h>

using namespace std;

int board[501][501];
int visited[501][501];
int n, m;

int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y) {

	if (visited[x][y] != -1) return visited[x][y];
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (x == 0 && y == 0) return 1;

	visited[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + offset[i][0], ny = y + offset[i][1];
		if (board[nx][ny] > board[x][y]) {
			visited[x][y] += dfs(nx, ny);

		}
	}
	return visited[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	memset(visited, -1, sizeof(visited));
	cout << dfs(n-1, m-1) << "\n";;

}