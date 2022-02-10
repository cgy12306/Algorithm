// https://www.acmicpc.net/problem/1976
// 여행 가자
#include<iostream>
using namespace std;

int N, M, city[202][202], parent[202];
int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> city[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (city[i][j]) {
				Union(i, j);
			}
		}
	}
	int start;
	bool flag = false;
	cin >> start;
	start = Find(start);
	for (int i = 1; i < M; i++) {
		int path;
		cin >> path;
		if (start != Find(path)) flag = true;
	}
	flag ? cout << "NO" : cout << "YES";
}