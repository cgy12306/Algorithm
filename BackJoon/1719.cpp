#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[202][202], path[202][202];
int INF = 999999999;
int n, m;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (path[i][j] == 0) cout << "- ";
			else cout << path[i][j]<<" ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from][to] = cost;
		arr[to][from] = cost;
		path[from][to] = to;
		path[to][from] = from;

	}
	floyd();

}