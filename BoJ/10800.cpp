// https://www.acmicpc.net/problem/10800
// ÄÃ·¯º¼
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int cdp[200001], sdp[200001];
struct ball {
	int number, size, color, psum;
};
bool cmp(ball a, ball b) {
	if (a.size == b.size) return a.color < b.color;
	return a.size < b.size;
}
bool cmp2(ball a, ball b) {
	return a.number < b.number;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<ball> balls(N);
	for (int i = 0; i < N; i++) {
		balls[i].number = i;
		cin >> balls[i].color >> balls[i].size;
	}

	sort(balls.begin(), balls.end(), cmp);
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int curcolor = balls[i].color;
		int cursize = balls[i].size;

		cdp[curcolor] += cursize;
		sdp[cursize] += cursize;
		sum += cursize;
		balls[i].psum = sum - cdp[curcolor] - sdp[cursize] + cursize;
		if ( i!= 0 && balls[i].size == balls[i - 1].size && balls[i].color == balls[i - 1].color) {
			balls[i].psum = balls[i - 1].psum;
		}
	}
	
	sort(balls.begin(), balls.end(), cmp2);
	for (int i = 0; i < N; i++) {
		cout << balls[i].psum << "\n";
	}
}