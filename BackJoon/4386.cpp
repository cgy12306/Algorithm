// https://www.acmicpc.net/problem/4386
// 별자리 만들기

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cmath>
using namespace std;
int N;
int parent[101];

vector<pair<double, double>> star;
vector<tuple<int, int, double>> nebula;
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
	double sum = 0;
	for (auto n : nebula) {
		int a = get<0>(n);
		int b = get<1>(n);
		double cost = get<2>(n);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
void difference(pair<double, double> a, pair<double, double> b, int i, int j) {
	double distance = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
	nebula.push_back(make_tuple(i, j, distance));
}
bool cmp(tuple<int, int, double> a, tuple<int, int, double> b) {
	return get<2>(a) < get<2>(b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) parent[i] = i;
	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		star.push_back(make_pair(x, y));
	}

	for (int i = 0; i < star.size(); i++) {
		for (int j = i; j < star.size(); j++) {
			if (i == j) continue;
			difference(star[i], star[j], i, j);
		}
	}
	sort(nebula.begin(), nebula.end(), cmp);
	kruskal();
}