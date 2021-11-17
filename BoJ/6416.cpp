#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[1000001];
int rootchk[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int u, v, cnt = 0;

	while (cin >> u >> v) {
		if (u < 0 && v < 0) break;

		while (1) {
			if (u == 0 && v == 0) break;

			tree[u].push_back(v);
			tree[v].push_back(u);
			rootchk[v]++;
		}

		
	}
}