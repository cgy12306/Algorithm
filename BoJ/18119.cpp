#include<iostream>
#include<string>

using namespace std;
int N, M;
int alp = 0;
int arr[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= 'z'-'a'; i++) {
		alp |= 1 << i;
	}

	string s;
	
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i] |= 1 << (s[j] - 'a');
		}
	}

	for (int i = 0; i < M; i++) {
		int o, cnt = 0;
		char x;
		cin >> o >> x;
		
		alp ^= 1 << (x - 'a');

		for (int j = 0; j < N; j++) {
			if ((alp & arr[j]) == arr[j]) cnt++;
		}
		cout << cnt << "\n";

	}

}