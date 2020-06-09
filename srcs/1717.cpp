#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int link[MAX+2];

int find(int a) {
	if (a == link[a])
		return a;
	return link[a] = find(link[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) link[a] = b;
	else if (a < b) link[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t, a, b;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		link[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> t >> a >> b;
		if (t == 0) {
			unite(a, b);
		} else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}