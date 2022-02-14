#include<iostream>
using namespace std;

double p[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, point, max = 0;
	double avg, sum=0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> point;
		p[i] = point;
		if (max < point) max = point;
	}

	for (int i = 0; i < N; i++) {
		p[i] = (p[i] / max) * 100;
		sum += p[i];
	}
	avg = sum / N;
	cout << avg;
}