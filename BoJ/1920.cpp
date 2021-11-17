// https://www.acmicpc.net/problem/1920
// ¼ö Ã£±â

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N, M, a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector <int> v1;
	vector<int>::iterator it;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a;
		v1.push_back(a);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a;
		it = find(v1.begin(), v1.end(), a);
		if (it != v1.end()) cout << "1" << "\n";
		else cout << "0" << "\n";
	}
}