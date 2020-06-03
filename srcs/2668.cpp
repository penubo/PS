// https://www.acmicpc.net/problem/2668

#include <bits/stdc++.h>

using namespace std;

bool visited[101];
int arr[101];
int cnt;
vector<int> ans;

// find cycle
void dfs(int s, int c) {
	if (visited[c]) {
		if (s == c)
			ans.push_back(s);
	} else {
		visited[c] = true;
		dfs(s, arr[c]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, i);
		memset(visited, 0, 101);
	}

	cout << ans.size() << "\n";
	for (auto a : ans) {
		cout << a << "\n";
	}

}