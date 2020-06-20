// https://www.acmicpc.net/problem/1987

#include <bits/stdc++.h>

using namespace std;

char adj[22][22];
bool alpha[26];
int n, m;
int ans;

pair<int, int> moves[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int cnt)
{

	ans = max(ans, cnt);
	alpha[adj[x][y] - 'A'] = true;

	for (auto m : moves)
	{
		int nx = m.first + x;
		int ny = m.second + y;
		if (adj[nx][ny] && !alpha[adj[nx][ny] - 'A'])
		{
			dfs(nx, ny, cnt + 1);
			alpha[adj[nx][ny] - 'A'] = false;
		}
	}
}

int main()
{

	cin >> n >> m;

	int c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			while ((c = cin.get()) == '\n')
				;
			adj[i][j] = c;
		}
	}

	dfs(1, 1, 1);

	cout << ans << "\n";

	return 0;
}