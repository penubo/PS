// https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>

using namespace std;
int arr[50];
bool visited[50];

void dfs(int i, int c, int n) {
	
	visited[arr[i]] = true;

	if (c == 6) {
		for (int j = 1; j < 50; j++) {
			if (visited[j])
				cout << j << " ";
		}
		cout << "\n";
		return ;
	}

	visited[arr[i]] = true;


	for (int j = i+1; j <= n; j++) {
		dfs(j, c+1, n);
		visited[arr[j]] = false;
	}

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)
			break;

		memset(arr, 0, sizeof(int) * 50);
		for (int i = 1; i <= k; i++) {
			int x;
			cin >> x;
			arr[i] = x;
		}

		for (int i = 1; i <= k; i++) {
			dfs(i, 1, k);
			visited[arr[i]] = false;
		}
		cout << "\n";
	}
}
