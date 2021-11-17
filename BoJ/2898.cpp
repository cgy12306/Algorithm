#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, num;
	vector<int> v;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int Max=0, sum=0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = v[i] + v[j] + v[k];
				if (sum > Max && sum <= M) {
					Max = sum;
				}
			}
		}
	}
	cout << Max;
}