// https://www.acmicpc.net/problem/2211

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	vector<pair<int, int>> adj[n+1];
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}

	priority_queue<pair<int, int>> q;
	vector<long long> distance(n+1, 1e6);
	bool visited[n+1];
	memset(visited, 0, n+1);

	q.push({0, 1});
	distance[1] = 0;

	vector<int> ans(n+1, -1);

	while (!q.empty()) {
		int a = q.top().second; q.pop();
		
		if (visited[a]) continue;
		visited[a] = true;

		for (auto nn : adj[a]) {
			int b = nn.first, w = nn.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				q.push({-distance[b], b});
				ans[b] = a;
			}
		}
	}

	cout << n-1 << "\n";
	for (int i = 2; i <= n; i++) {
		cout << i << " " << ans[i] << "\n";
	}
	
}