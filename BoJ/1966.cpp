// https://www.acmicpc.net/problem/1966
// 프린터 큐
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	
	queue<pair<int, int>> grade, result;
	priority_queue<int> pq;

	for (int a = 0; a < T; a++) {
		int N, M, Max = 0;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			grade.push({ num, i });
			pq.push(num);
		}
		
		while (1) {
			if (grade.empty()) break;
			if (grade.front().first != pq.top()) {
				grade.push({ grade.front().first, grade.front().second });
				grade.pop();
			}
			else {
				result.push({ grade.front().first, grade.front().second });
				grade.pop();
				pq.pop();
			}
		}
		int cnt = 1;
		while (M != (result.front().second)) {
			cnt++;
			result.pop();
		}
		cout << cnt << "\n";

		cnt = 0;
		while(!grade.empty()) grade.pop();
		while(!pq.empty()) pq.pop();
		while (!result.empty()) result.pop();
		
	}
}
