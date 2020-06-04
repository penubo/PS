// https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>

using namespace std;
int arr[13];
int ans[6];
int k;

void dfs(int s, int c) {
	if (c == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = s; i < k; i++) {
		ans[c] = arr[i];
		dfs(i+1, c+1);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> k && k) {
		
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		dfs(0, 0);
		cout << "\n";
	}
}
