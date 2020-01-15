#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector< bool > > g;
vector< vector< bool > > visited;
vector< int > ans;

int n, cnt;

pair<int, int> offset[4] = {
    make_pair(+1, 0),
    make_pair(-1, 0),
    make_pair(0, +1),
    make_pair(0, -1)
};

void bfs(int i, int j) {

    queue< pair<int, int> > q;

    q.push(make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()) {

        pair<int, int> current_node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> target_node;
            target_node.first = current_node.first + offset[i].first;
            target_node.second = current_node.second + offset[i].second;

            if (0 < target_node.first && target_node.first <= n &&
                0 < target_node.second && target_node.second <= n) {
                    if (g[target_node.first][target_node.second] && !visited[target_node.first][target_node.second]) {
                        q.push(make_pair(target_node.first, target_node.second));
                        visited[target_node.first][target_node.second] = true;
                        cnt++;
                    }
                }
        }


    }

}

int main() {

    string str;

    cin >> n;

    cnt = 1;

    g.assign(n+1, vector< bool > (n+1, false));
    visited.assign(n+1, vector< bool > (n+1, false));

    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= n; j++) {
            g[i][j] = str[j-1] == '0' ? false : true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] && !visited[i][j]) {
                bfs(i, j);
                ans.push_back(cnt);
                cnt = 1;
            }
        }
    }


    cout << ans.size() << "\n";

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}