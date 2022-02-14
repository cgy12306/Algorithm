#include<iostream>
using namespace std;
int map[51][51];
bool visited[51][51];
int r, c, x, y, dir;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int cnt = 0;
void clear(int x, int y) {
	visited[x][y] = true;
	map[x][y] = 2;
	cnt++;
}

bool turn_go() {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	//cout << dir;
	// 合
	if (dir == 0) {		
		dir = 3;
	}
	// 悼
	else if (dir == 1) {
		dir = 0;
	}
	else if (dir == 2) {
		dir = 1;
	}
	else if (dir == 3) {
		dir = 2;
	}
	
	if (map[nx][ny] == 0 && !visited[nx][ny]) {
		x = nx;
		y = ny;
		return true;
	}
	else {
		return false;
	}
}
void direction() {
	dir += 1;
	if (dir == 4) dir = 0;
}
bool check() {
	int nx, ny;
	bool check_room = false;

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (!(map[nx][ny] == 1 || visited[nx][ny])) {
			// 没家 代凳
			check_room = true;
		}
		//if(map[nx][ny] == 0)
	}
	// 饶柳
	if (!check_room) {
		// 缔 规氢
		//cout << dir <<"\n";
		//dir += 1;
		//direction();
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (map[nx][ny] == 1) {
			return true;
		}
		else {
			x = nx;
			y = ny;
			direction();

		}
	}
	return false;
}
void print() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	cin >> x >> y >> dir;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) visited[i][j] = true;
		}
	}
	do {
		//cout << x << " " << y <<" " << dir << "\n";
		if (x == 9 && y == 3) {}
		if(!visited[x][y] && map[x][y] == 0) clear(x, y);
		//print();
		// 合 : 0, 悼 : 1, 巢 : 2, 辑 : 3
		if (turn_go()) continue;
		
		if (check()) break;
	} while (1);

	cout << cnt;
}