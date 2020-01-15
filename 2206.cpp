#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int N, M;

vector<vector<bool> > g;
vector<vector<vector<int > > > dist;

static int offset[4][2] = {
    {+1, 0},
    {-1, 0},
    {0, +1},
    {0, -1}
};


void bfs()
{
    queue<pair<pair<int, int>, int > > q;

    dist[1][1][0] = 1;
    q.push(make_pair(make_pair(1, 1), 0));

    while (!q.empty()) {
        pair<int, int> cn = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> nn;
            nn.first = cn.first + offset[i][0];
            nn.second = cn.second + offset[i][1];

            if (0 < nn.first && nn.first <= N && 0 < nn.second && nn.second <= M) {
                if (g[nn.first][nn.second] && b == 0) {
                    // can go
                    dist[nn.first][nn.second][b+1] = dist[cn.first][cn.second][b] + 1;
                    q.push(make_pair(make_pair(nn.first, nn.second), b+1));
                } else if (!g[nn.first][nn.second] && !dist[nn.first][nn.second][b]) {
                    dist[nn.first][nn.second][b] = dist[cn.first][cn.second][b] + 1;
                    q.push(make_pair(make_pair(nn.first, nn.second), b));
                }
            }
        }
    }
}

int main()
{

    cin >> N >> M;

    string row;

    g.assign(N + 1, vector<bool>(M + 1, false));
    dist.assign(N + 1, vector<vector <int> >(M + 1, vector<int>(2, 0)));

    for (int i = 1; i <= N; i++)
    {
        cin >> row;
        for (int j = 1; j <= M; j++)
        {
            g[i][j] = row[j - 1] == '1' ? true : false;
        }
    }

    bfs();

    if (dist[N][M][0] == 0 && dist[N][M][1] == 0) {
        cout << -1 << "\n";
    } else if (dist[N][M][0] == 0 && dist[N][M][1] != 0) {
        cout << dist[N][M][1] << "\n";
    } else if (dist[N][M][0] != 0 && dist[N][M][1] == 0) {
        cout << dist[N][M][0] << "\n";
    } else {
        cout << min(dist[N][M][0], dist[N][M][1]) << "\n";
    }

    return 0;
}