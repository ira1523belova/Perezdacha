#include <iostream>
#include <string>

using namespace std;

typedef struct TNode* PNode;

int t = -1e7;

typedef struct TNode {
	string data;
	PNode left;
	PNode right;
} TNode;

int Pr(char op) {
	if (op == '+' || op == '-')
		return 1;
	else
		if (op == '/' || op == '*')
			return 2;
	return 100;
}

int znak(string s) {
	int res = -1, mp = 50, k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			k++;
		else
			if (s[i] == ')')
				k--;
			else
				if (Pr(s[i]) <= mp && !k) {
					mp = Pr(s[i]);
					res = i;
				}
	}
	return res;
}

PNode Dot(string s) {
	int k;
	PNode tree;
	tree = new struct TNode;
	k = znak(s);
	if (k == -1 && s[0] == '(') {
		while (s[0] == '(' && s.back() == ')')
			s = s.substr(1, s.size() - 2);
		k = znak(s);
	}
	if (k == -1) {
		tree->data = s;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		tree->data = s.substr(k, 1);
		tree->left = Dot(s.substr(0, k));
		tree->right = Dot(s.substr(k + 1));
	}
	return tree;
}

int Calc(PNode tree) {
	int n1, n2, res;
	if (tree->left == NULL)
		res = atoi(tree->data.c_str());
	else {
		n1 = Calc(tree->left);
		n2 = Calc(tree->right);
		switch (tree->data[0]) {
		case '+': res = n1 + n2; break;
		case '-': res = n1 - n2; break;
		case '/': res = n1 / n2; break;
		case '*': res = n1 * n2; break;
		default: res = 99999;
		}
	}
	return res;
}

int main() {
	PNode T;
	string s;
	cin >> s;
	T = Dot(s);
	cout << Calc(T);
}

