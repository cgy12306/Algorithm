#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N 여자, M 남자, K 인턴
	int N, M, K, team = 0;
	cin >> N >> M >> K;

	while (N > 1 && M > 0 && N+M-K>2) {
		N -= 2;
		M--;
		team++;
	}
	cout << team;


	return 0;
}