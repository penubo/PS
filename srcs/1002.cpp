// https://www.acmicpc.net/problem/1002

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		if (r1 < r2)
			swap(r1, r2);

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << "\n";
		}
		else
		{
			double cd = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			if (r1 > cd) {
				double r3 = r1 - cd;
				if (r2 == r3)
					cout << "1\n";
				else if (r2 < r3)
					cout << "0\n";
				else 
					cout << "2\n";
			} else {
				if (cd == r1 + r2)
					cout << 1 << "\n";
				else if (cd < r1 + r2)
					cout << 2 << "\n";
				else 
					cout << 0 << "\n";
			}
			
		}
	}
}