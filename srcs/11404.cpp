/*
 * floyd-warshall shortest path algorithm
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 9999999

vector< vector< int > > g;
int n;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && k != j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

void print_graph() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == MAX) {
                cout << 0 << " ";
            } else {
                cout << g[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {

    int m;
    int from, to, weight;

    cin >> n >> m;

    g.assign(n+1, vector< int >(n+1, MAX));

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        if (g[from][to] > weight) {
            g[from][to] = weight;
        }
    }

    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    floyd();

    print_graph();
    
    return 0;
}