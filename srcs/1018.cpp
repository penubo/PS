#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool> > arr;

int simulate(char c, int row, int col)
{

    int cnt = 0, start;

    switch (c)
    {
    case 'B':
        start = 1;
        break;

    case 'W':
        start = 0;
        break;

    default:
        break;
    }

    for (int i = row; i < row + 8; i++)
    {
        for (int j = col; j < col + 8; j++)
        {
            if (arr[i][j] != start % 2) {
                cnt++;
            }
            start++;
        }
        start++;
    }

    return cnt;
}

int main()
{

    int N, M, tmp_cnt, ans = 64;
    string tmp;

    cin >> N >> M;

    arr.assign(N, vector<bool>(M, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = tmp[j] == 'B' ? 1 : 0;
        }
    }

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            tmp_cnt = min(simulate('B', i, j), simulate('W', i, j));
            ans = min(tmp_cnt, ans);
        }
    }

    cout << ans << "\n";

    return 0;
}