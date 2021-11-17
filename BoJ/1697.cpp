// https://www.acmicpc.net/problem/1697
// ¼û¹Ù²ÀÁú

#include<iostream>
#include<queue>

using namespace std;
int N, K, map[100001], visited[100001];

void bfs(int x) {
	
	visited[x] = 1;

	queue<int> que;
	que.push(x);

	while (!que.empty()) {
		int x = que.front();
		que.pop();

		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = visited[x] + 1;
			que.push(x - 1);
		}
		
		if (x + 1 <= 100000 && !visited[x + 1]) {
			visited[x + 1] = visited[x] + 1;
			que.push(x + 1);
		}
		
		if (x * 2 <= 100000 && !visited[x * 2]) {
			visited[x * 2] = visited[x] + 1;
			que.push(x * 2);
		}

	}
	cout << visited[K] - 1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	bfs(N);

}