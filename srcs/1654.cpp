// https://www.acmicpc.net/problem/1654

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	vector<long long> arr(k);
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	long long end = *max_element(arr.begin(), arr.end());
	long long start = 1;
	
	long long mid = 0;
	long long ans = 0;
	while (start <= end) {
		long long cnt = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= n) {
			ans = max(ans, mid);
			start = mid+1;
		} else {
			end = mid-1;
		}
	}
	cout << ans << "\n";
}