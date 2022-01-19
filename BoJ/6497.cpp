// https://www.acmicpc.net/problem/6497
// Àü·Â³­
#include<iostream>
#include<vector>
#include<tuple>
#include<cstring>
#include<algorithm>

using namespace std;
int M, N, parent[200001], Msum;
vector<tuple<int, int, int>> city;
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<2>(a) < get<2>(b);
}
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
	for (auto c : city) {
		int a = get<0>(c);
		int b = get<1>(c);
		int cost = get<2>(c);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << Msum - sum << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> M >> N;
		if (M == 0 && N == 0) break;

		city.clear();
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < M; i++) {
			parent[i] = i;
		}
		Msum = 0;
		for (int i = 0; i < N; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			city.push_back(make_tuple(x, y, z));
			Msum += z;
		}
		
		sort(city.begin(), city.end(), cmp);
		
		kruskal();
	}
	
}
