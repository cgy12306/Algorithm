// https://www.acmicpc.net/problem/10845
// [10845] ť
#include<iostream>
#include<string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, queue[100001], a, size = 0;
	char cmd[6] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (!strcmp(cmd, "push")) {
			cin >> a;
			queue[size] = a;
			size++;
		}
		else if (!strcmp(cmd, "pop")) {
			if (!size) {
				cout << "-1\n";
			}
			else if (size == 1) {
				cout << queue[0] << "\n";
				queue[0] = 0;
				size--;
			}
			else {
				cout << queue[0] << "\n";
				for (int j = 1; j < size; j++) {
					queue[j - 1] = queue[j];
				}
				size--;
				queue[size] = 0;
				
			}
		}
		else if (!strcmp(cmd, "size")) {
			cout << size << "\n";
		}
		else if (!strcmp(cmd, "empty")) {
			if (!size) {
				cout << "1\n";
			}
			else {
				cout << "0"<<"\n";
			}
		}
		else if (!strcmp(cmd, "front")) {
			if (!size) {
				cout << "-1\n";
			}
			else {
				cout << queue[0] << "\n";
			}
		}
		else if (!strcmp(cmd, "back")) {
			if (!size) {
				cout << "-1\n";
			}
			else {
				cout << queue[size-1] << "\n";
			}
		}
	}
}