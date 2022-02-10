// https://www.acmicpc.net/problem/2887
// 행성 터널

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cmath>
using namespace std;
int N;
int parent[100002];

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, long long>> nebula;
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
void kruscal() {
	long long sum = 0;
	for (auto n : nebula) {
		int a = get<0>(n);
		int b = get<1>(n);
		long long cost = get<2>(n);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
bool cmp(tuple<int, int, long long> a, tuple<int, int, long long> b) {
	return get<2>(a) < get<2>(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < N; i++) {
		int x, y, z;

		cin >> x >> y >> z;
		X.push_back(make_pair(x, i));
		Y.push_back(make_pair(y, i));
		Z.push_back(make_pair(z, i));
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		nebula.push_back(make_tuple(X[i].second, X[i + 1].second, abs(X[i + 1].first - X[i].first)));
		nebula.push_back(make_tuple(Y[i].second, Y[i + 1].second, abs(Y[i + 1].first - Y[i].first)));
		nebula.push_back(make_tuple(Z[i].second, Z[i + 1].second, abs(Z[i + 1].first - Z[i].first)));
	}

	sort(nebula.begin(), nebula.end(), cmp);

	kruscal();
}