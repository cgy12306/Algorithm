// https://www.acmicpc.net/problem/1647
// 도시 분할 계획
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N, M, parent[100002];
vector<tuple<int, int, int>> town;
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
void kruskal() {
	int sum = 0;
	int Max = 0;
	for (auto t: town) {
		int a = get<0>(t);
		int b = get<1>(t);
		int cost = get<2>(t);
		if (Find(a) != Find(b)) {
			sum += cost;
			Max = max(cost, Max);
			Union(a, b);
		}
	}
	cout << sum - Max;
}
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<2>(a) < get<2>(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		town.push_back(make_tuple(A, B, C));
	}
	sort(town.begin(), town.end(), cmp);
	kruskal();
}