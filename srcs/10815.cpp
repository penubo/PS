// https://www.acmicpc.net/problem/10815

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	int m;
	cin >> m;
	vector<int> b;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	
	sort(a.begin(), a.end());

	for(auto num : b) {
		int start = 0;
		int end = n - 1;
		int mid = 0;
		bool flag = false;
		while (start <= end) {
			mid = (start + end) / 2;
			if (a[mid] == num) {
				flag = true;
				break;
			}
			if (a[mid] > num)
				end = mid - 1;
			else
				start = mid + 1;
		}
		cout << flag << " ";
	}

}