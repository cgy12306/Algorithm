#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E, S;
bool visited[1002];
vector<vector<int>> Edges;
queue<int> q;

void BFS(int start) {
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << "visit : " << current << "\n";
		for(auto next : Edges[current]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> V >> E >> S;
	Edges.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		Edges[from].push_back(to);
	}

	BFS(S);
}
