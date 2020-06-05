// https://www.acmicpc.net/problem/1697

#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

bool visited[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;

	q.push({n, 0});

	while (!q.empty()) {
		int x = q.front().first, cnt = q.front().second;
		q.pop();
		if (visited[x])
			continue;
		visited[x] = true;
		if (x == k) {
			cout << cnt << "\n";
			break;
		}
		int nx1 = x-1, nx2 = x+1, nx3 = 2*x;
		
		if (nx1 >= 0) {
			q.push({nx1, cnt+1});
		}
		if (nx2 <= MAX) {
			q.push({nx2, cnt+1});
		}
		if (nx3 <= MAX) {
			q.push({nx3, cnt+1});
		}
	}
}