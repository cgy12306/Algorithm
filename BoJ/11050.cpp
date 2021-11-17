#include<iostream>
using namespace std;
int fact(int num) {
	int res =1;
	for (int i = 1; i <= num; i++) {
		res *= i;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	cout<<fact(N)/ (fact(N - K) * fact(K));

}