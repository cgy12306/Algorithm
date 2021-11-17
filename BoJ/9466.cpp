// https://www.acmicpc.net/problem/9466
// ∆¿ «¡∑Œ¡ß∆Æ
#include<iostream>
#include<cstring>
using namespace std;
int T, n, cnt = 0;
int student[100002];
bool visited[100002], done[100002];

void dfs(int start) {
	visited[start] = true;
	int next = student[start];

	if (!visited[next]) {
		dfs(next);
	}
	else if (!done[next]) {
		for (int i = next; i != start; i = student[i]) {
			cnt++;
		}
		cnt++;
	}
	
	done[start] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - cnt <<"\n";
		cnt = 0;
	}
	
}