// https://www.acmicpc.net/problem/1991
// 트리 순회

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct TreeNode{
	char name;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode *init(char name) {
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) return NULL;
	node->name = name;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert(TreeNode *node, char name, char right, char left) {
	if (right == '.') node->right = NULL;
	else node->right = init(right);

	if (left == '.') node->left = NULL;
	else node->left = init(left);
}

TreeNode *search(TreeNode *node, char name) {
	if (node == NULL) return NULL;
	if (node->name == name) {
		return node;
	}
	else {
		TreeNode *tmp = search(node->left, name);
		if (tmp) return tmp;
		tmp = search(node->right, name);
		return tmp;
	}
	return NULL;
}

void preorder(TreeNode *node) {
	cout << node->name;
	if(node->left)preorder(node->left);
	if(node->right)preorder(node->right);
}

void inorder(TreeNode *node) {
	if (node->left)inorder(node->left);
	cout << node->name;
	if (node->right)inorder(node->right);
}
void postorder(TreeNode *node) {
	if (node->left)postorder(node->left);
	if (node->right)postorder(node->right);
	cout << node->name;
}

void freedom(TreeNode *node) {
	if (node != NULL) {
		freedom(node->left);
		freedom(node->right);
		free(node);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	TreeNode *root;
	root = NULL;

	for (int i = 0; i < N; i++) {
		char name, right, left;
		cin >> name >> left >> right;
		if (root == NULL) {
			root = init(name);
			insert(root, name, right, left);
		}
		else {
			TreeNode *node = search(root, name);
			insert(node, name, right, left);
		}
	}

	preorder(root);
	cout << "\n";
	inorder(root);
	cout << "\n";
	postorder(root);

	freedom(root);
}