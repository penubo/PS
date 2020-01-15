#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector< vector< bool > > g;
vector< bool > visited;
int n, cnt;

void bfs(int s) {
    queue< int > q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && g[current_node][i]) {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main() {

    int m, from, to;

    cin >> n >> m;

    g.assign(n+1, vector< bool >(n+1, 0));
    visited.assign(n+1, false);

    for (int i = 1; i <= m; i++) {
        cin >> from >> to;
        g[from][to] = true;
        g[to][from] = true;
    }

    bfs(1);

    cout << cnt << "\n";

    return 0;
}