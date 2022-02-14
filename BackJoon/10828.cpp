// https://www.acmicpc.net/submit/10828
// [10828] Ω∫≈√
#include<iostream>
#include<string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, stack[100001] = { 0, }, top = -1, a;
	char cmd[6] = { 0, };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (!strcmp(cmd, "push")) {
			cin >> a;
			top++;
			stack[top] = a;
		}
		else if (!strcmp(cmd, "pop")) {
			if (top == -1) {
				cout << "-1" << "\n";
			}
			else {
				cout << stack[top] << "\n";
				stack[top] = 0;
				top--;
			}
		}
		else if (!strcmp(cmd, "size")) {
			cout << top + 1 << "\n";
		}
		else if (!strcmp(cmd, "empty")) {
			if (top == -1) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (!strcmp(cmd, "top")) {
			if (top == -1) {
				cout << "-1" << "\n";
			}
			else {
				cout << stack[top] << "\n";
			}
		}
	}
}