// https://www.acmicpc.net/problem/2357

#include <bits/stdc++.h>

using namespace std;

int n, m;

pair<long long, long long> mquery(vector<pair<long long, long long>> &tree, int a, int b) {
	a += n; b += n;
	pair<long long, long long> ans = {0, INT32_MAX};
	while (a <= b) {
		if (a%2==1) {
			ans.first = max(ans.first, tree[a].first);
			ans.second = min(ans.second, tree[a++].second);
		}
		if (b%2==0){
			ans.first = max(ans.first, tree[b].first);
			ans.second = min(ans.second, tree[b--].second);
		}
		a /= 2; b /= 2;
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<pair<long long, long long>> tree(2*n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree[n+i].first = x; tree[n+i].second = x;
	}

	for (int i = n-1; i >= 1; --i) {
		tree[i].first = max(tree[2*i].first, tree[2*i+1].first);
		tree[i].second = min(tree[2*i].second, tree[2*i+1].second);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pair<long long, long long> res = mquery(tree, a-1, b-1);
		cout << res.second << " " << res.first << "\n";
	}
}