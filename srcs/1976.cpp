// https://www.acmicpc.net/problem/1976

#include <bits/stdc++.h>

using namespace std;

const int MAX = 201;

int link[MAX];
// int sizes[MAX];

int find(int x) {
	if (x == link[x])
		return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) link[b] = a;
	else link[a] = b;
}

int main() {
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) link[i] = i;
	vector<int> arr(m, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (x)
				unite(i, j);
		}
	}
		
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	bool flag = true;
	int prev = arr[0];
	for (int i = 1; i < m; i++) {
		if (find(prev) != find(arr[i])) {
			flag = false;
			break;
		}
		prev = arr[i];
	}

	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

}