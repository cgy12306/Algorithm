#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

bool visited[101][101];
int N, map[101][101];

int dy[] = { -1, 1 , 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int mapcnt = 2;

void check(int x, int y) {
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));
	visited[y][x] = true;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		map[y][x] = mapcnt;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax < 0 || ay < 0 || ax >= N || ay >= N) continue;


			if (!map[ay][ax] || visited[ay][ax] == true) continue;

			visited[ay][ax] = true;
			que.push(make_pair(ax, ay));

		}
	}
}


int bfs(int mapnum) {

	queue<pair<int, int>>que;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == mapnum) {
				visited[i][j] = true;
				que.push(make_pair(j, i));
			}
		}
	}

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {

			int x = que.front().first;
			int y = que.front().second;

			que.pop();

			for (int i = 0; i < 4; i++) {
				int ax = x + dx[i];
				int ay = y + dy[i];

				if (ax < 0 || ay < 0 || ax >= N || ay >= N) continue;


				if (map[ay][ax] != mapnum) {
					if (map[ay][ax] != 0) {
						return sum;
					}
					else if (map[ay][ax] == 0 && !visited[ay][ax]) {
						visited[ay][ax] = true;
						que.push(make_pair(ax, ay));
					}
				}
			}
		}
		sum++;
	}
	return sum;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				check(j, i);
				mapcnt++;
			}
		}
	}
	int bridge = 987654321;

	
	for (int i = 2; i < mapcnt; i++) {
		memset(visited, false, sizeof(visited));

		bridge = min(bridge, bfs(i));
	}
	

	cout << bridge;

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	*/


}