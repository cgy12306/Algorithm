// https://www.acmicpc.net/problem/5014
// 스타트링크
#include<iostream>
#include<queue>

using namespace std;
int F, S, G, U, D;

int dx[2];
int visited[1000002];
queue<int> q;

int bfs(int start) {
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int x = q.front();

		q.pop();

		if (x == G) return visited[x] - 1;

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			
			if (nx < 1 || nx > F) continue;

			if (visited[nx] == 0) {
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	dx[0] = U; dx[1] = -D;
	
	int ans = bfs(S);
	if (ans != -1) cout << ans;
	else cout << "use the stairs";

	
}