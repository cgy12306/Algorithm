// https://www.acmicpc.net/problem/1717
// 집합의 표현

#include<iostream>
using namespace std;
int N, M;
int parent[1000002];

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
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	while (M) {
		int a, b, c;
		cin >> c >> a >> b;
		if (c == 0) {
			Union(a, b);
		}
		else if (c == 1) {
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
		M--;
	}
}