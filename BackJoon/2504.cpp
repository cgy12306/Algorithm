#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i = 0, sum = 0, tmp = 1, flag = 0;

	stack<char> s;
	string str;
	
	cin >> str;
	
	while (str[i] != 0) {
		if (str[i] == '(') {
			s.push(str[i]);
			tmp *= 2;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			tmp *= 3;
		}
		else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
			flag = 1;
			break;
		}
		else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
			flag = 1;
			break;
		}
		else if(str[i] == ')'){
			if (str[i - 1] == '(') {
				sum += tmp;
			}
			s.pop();
			tmp /= 2;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				sum += tmp;
			}
			s.pop();
			tmp /= 3;
		}
		
		else {
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1 || !s.empty()) {
		cout << '0';
	}
	else {
		cout << sum;
	}
	return 0;
}