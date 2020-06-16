// https://www.acmicpc.net/problem/2357

#include <bits/stdc++.h>

using namespace std;

int n, m;

long long min_query(vector<long long> tree, int a, int b) {
	a += n; b += n;
	long long ans = INT32_MAX;
	while (a <= b) {
		if (a%2==1) ans = min(ans, tree[a++]);
		if (b%2==0) ans = min(ans, tree[b--]);
		a /= 2; b /= 2;
	}
	return ans;
}

long long max_query(vector<long long> tree, int a, int b) {
	a += n; b += n;
	long long ans = 0;
	while (a <= b) {
		if (a%2==1) ans = max(ans, tree[a++]);
		if (b%2==0) ans = max(ans, tree[b--]);
		a /= 2; b /= 2;
	}
	return ans;
}

int main() {

	cin >> n >> m;

	vector<long long> max_tree(2*n);
	vector<long long> min_tree(2*n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		max_tree[n+i] = x;
		min_tree[n+i] = x;
	}

	for (int i = n-1; i >= 1; --i) {
		max_tree[i] = max(max_tree[2*i], max_tree[2*i+1]);
		min_tree[i] = min(min_tree[2*i], min_tree[2*i+1]);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << min_query(min_tree, a-1, b-1) << " " << max_query(max_tree, a-1, b-1) << "\n";
	}
}