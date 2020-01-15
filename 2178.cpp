#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector< vector< bool > > g;
vector< vector< bool > > visited;
vector< vector< int > > dist;

int offset[4][2] = {
    {+1, 0},
    {-1, 0},
    {0, +1},
    {0, -1}
};

void dijkstra() {

    queue< pair<int, int> > q;
    q.push(make_pair(1, 1));

    while (!q.empty()) {
        pair<int, int> current_node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> target_node;
            target_node.first = current_node.first + offset[i][0];
            target_node.second = current_node.second + offset[i][1];

            if (0 < target_node.first && target_node.first <= N &&
                0 < target_node.second && target_node.second <= M) {
                    if (!visited[target_node.first][target_node.second] &&
                        g[target_node.first][target_node.second]) 
                    {
                        dist[target_node.first][target_node.second] = min(
                            dist[target_node.first][target_node.second], 
                            dist[current_node.first][current_node.second] + 1);

                        visited[target_node.first][target_node.second] = true;
                        q.push(target_node);
                    }
                }

        }
        

    }
}

int main() {

    string row;

    cin >> N >> M;
    g.assign(N+1, vector< bool > (M+1, false));
    visited.assign(N+1, vector< bool > (M+1, false));
    dist.assign(N+1, vector< int > (M+1, 99999));

    visited[1][1] = true;
    dist[1][1] = 1;

    for (int i = 1; i <= N; i++) {
        cin >> row;
        for (int j = 1; j <= M; j++) {
            g[i][j] = row[j-1] == '1' ? true : false;
        }
    }

    dijkstra();

    cout << dist[N][M] << "\n";

    return 0;
}