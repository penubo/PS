#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

static int n, m, v;
static vector< vector<int> > g;
static vector< bool > visited;

void dfs(int s) {
    visited[s] = true;
    cout << s << " ";

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false && g[s][i]) {
            dfs(i);
        }
    }

}

void bfs(int s) {
    list< int > queue;
    int current_node;

    queue.push_back(s);
    visited[s] = true;

    while (!queue.empty()) {
        current_node = queue.front();
        queue.pop_front();
        cout << current_node << " ";
        for (int i = 1; i <= n; i++) {
            if (visited[i] == false && g[current_node][i] != 0) {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

int main() {

    int from, to;

    cin >> n >> m >> v;
    g.assign(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < m; i++) {
        cin >> from >> to;

        g[from][to] = 1;
        g[to][from] = 1;
    }

    visited.assign(n+1, false);
    dfs(v);
    cout << "\n";
    visited.assign(n+1, false);
    bfs(v);
    cout << "\n";

    return 0;

}
