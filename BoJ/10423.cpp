// https://www.acmicpc.net/problem/10423
// 전기가 부족해

#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;
int N, M, K;
int parent[1002];

vector<tuple<int, int, int>> city;
vector<int> powerPlant;
int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
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
		int cost = get<0>(c);
		int a = get<1>(c);
		int b = get<2>(c);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) parent[i] = i;
	
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		powerPlant.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		city.push_back({ cost, from, to });
	}

	for (int i = 0; i < powerPlant.size() - 1; i++) {
		Union(powerPlant[i], powerPlant[i + 1]);
	}
	sort(city.begin(), city.end());

	kruskal();

}