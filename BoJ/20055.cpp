// https://www.acmicpc.net/problem/20055
// 컨베이어 벨트 위의 로봇

#include<iostream>
#include<vector>
using namespace std;
int N, K, belt[201];
bool robot[201];


void curl() {
	int tmp1, tmp2;
	
	tmp1 = belt[2 * N];
	tmp2 = robot[2 * N];
	for (int i = N * 2 ; i > 1; i--) {
		belt[i] = belt[i - 1];
		robot[i] = robot[i - 1];
	}

	belt[1] = tmp1;
	robot[1] = tmp2;
	
	robot[N] = false;
}

void move() {
	
	for (int i = N - 1; i > 0 ; i--) {
		if (!robot[i + 1] && robot[i] && belt[i+1] > 0) {
			robot[i + 1] = true;
			robot[i] = false;
			belt[i + 1]--;
		}
	}

	robot[N] = false;
}
void load() {
	if (belt[1] > 0 && !robot[1]) {
		robot[1] = true;
		belt[1]--;
	}
	return;
}

int check() {
	int durability = 0;
	for (int i = 1; i <= N * 2; i++) {
		if (belt[i] == 0) {
			durability++;
		}
	}
	return durability;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N * 2; i++) {
		cin >> belt[i];
	}
	int cnt = 1;
	while (1) {
		curl();
		move();
		load();
		if (check() >= K) break;
		cnt++;
	}
	cout << cnt;
}