//https://www.acmicpc.net/problem/6549

#include <bits/stdc++.h>

using namespace std;

int n;

int find_min(vector<int> tree, int a, int b) {
	a += n; b += n;
	int res = INT32_MAX;
	while (a <= b) {
		if (a % 2)
	}
}

long long longest(vector<int> tree, int start, int end) {
	long long res = 0;

	find_min(tree, start, end);
}

int main() {

	while (true) {

		cin >> n;
		if (n == 0) break;

		vector<int> tree(2*n);
		for (int i = 0; i < n; ++i) {
			cin >> tree[n+i];
		}

		for (int i = n-1; i > 0; --i) {
			tree[i] = min(tree[2*i], tree[2*i+1]);
		}
		cout << longest(tree, 0, n-1) << "\n";
	}
}