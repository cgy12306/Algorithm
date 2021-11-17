#include<iostream>
#include<algorithm>
using namespace std;

int ground[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, B, time = 999999999, Max = 0, Min=999999999, Max_time = 0, Min_time = 0;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
	
			if (ground[i][j] > Max) {
				Max = ground[i][j];
			}
			if (ground[i][j] < Min) {
				Min = ground[i][j];
			}
		}
	}
	int tmp = 0, height = 0;
	for (int h = Min; h <= Max; h++) {
		int build = 0;
		int remove = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp = h - ground[i][j];

				if (tmp < 0) remove += tmp * -1; 
				else build += tmp;
			}
		}
		if (build <= remove + B) {
			tmp = build + remove * 2;
			if (time > tmp) {
				time = tmp;
				height = h; 
			}
			else if (time == tmp) {
				if (height < h) height = h;
			}
		}
	}
	
	cout << time << " " << height;

}