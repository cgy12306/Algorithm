#include<iostream>
#include<string>
using namespace std;
char arr[9][9];
int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	int check = 0;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (check % 2 == 0 && arr[i][j] == 'F') cnt++;
			check++;
		}
		check++;
	}
	cout << cnt;
}