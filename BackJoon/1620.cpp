#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string pok;

	map<int, string> dic;
	map<string, int> dic2;

	cin >> N >> M;
	
	
	for (int i = 1; i <= N; i++) {
		cin >> pok;
		dic[i] = pok;
		dic2[pok] = i;
	}
	

	for (int i = 0; i < M; i++) {
		cin >> pok;	
		if (pok[0] >= 'A' && pok[0] <= 'Z') {
			cout << dic2[pok] << "\n";
		}
		else {
			cout << dic[stoi(pok)] << "\n";
		}
	}	
}