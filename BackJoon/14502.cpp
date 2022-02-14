// https://www.acmicpc.net/problem/14502
// ¿¬±¸¼Ò
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int res = 0;
int N, M, map[9][9], tmp[9][9];
bool visited[9][9], vtmp[9][9];
int dx[] = {-1, 1 , 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> check;
vector<pair<int,int>> new_wall;
queue<pair<int, int>> q;

void print() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tmp[i][j] <<" ";
		}
		cout << "\n";
	}
}
void bfs(int x, int y) {
	
	q.push(make_pair(x, y));

	while (!q.empty()) {
		//print();
		x = q.front().first;
		y = q.front().second;

		vtmp[x][y] = true;
		tmp[x][y] = 2;

		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (tmp[nx][ny] || vtmp[nx][ny]) continue;
			
			vtmp[nx][ny] = true;
			q.push(make_pair(nx, ny));
			
		}
		
	}
}
int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void brute_force() {
	do {
		memcpy(tmp, map, sizeof(map));
		memcpy(vtmp, visited, sizeof(visited));
		for (int i = 0; i < check.size(); i++) {
			if (check[i]) {
				tmp[new_wall[i].first][new_wall[i].second] = 1;
				vtmp[new_wall[i].first][new_wall[i].second] = true;
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] == 2 && !vtmp[i][j]) {	
					bfs(i, j);
				}
			}
		}

		res = max(count(), res);

	} while (next_permutation(check.begin(), check.end()));
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				new_wall.push_back(make_pair(i, j));
				check.push_back(0);
			}
		}
	}
	for (int i = 0; i < 3; i++) check[i] = 1;
	sort(check.begin(), check.end());

	brute_force();
	cout << res;

}