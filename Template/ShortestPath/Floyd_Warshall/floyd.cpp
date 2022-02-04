#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, city[102][102], INF = 99999999;

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (city[i][k] != INF && city[k][j] != INF) {
                    city[i][j] = min(city[i][k] + city[k][j], city[i][j]);
                }
                if (i == j) city[i][j] = 0;
            }
        }
    }
}
int main() {
    cin >> n;
    cin >> m;

    fill(city[0], city[102], INF);

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (city[from][to] > cost) {
            city[from][to] = cost;
        }
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == INF) cout << "0 ";
            else cout << city[i][j] << " ";
        }
        cout << "\n";
    }
}
