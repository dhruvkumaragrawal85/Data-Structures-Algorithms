#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node *left;
	Node *right;
	Node *parent;
	Node()
	{
		val = 0;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Node(int arg)
	{
		val = arg;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Node(int arg, Node *leftarg, Node *rightarg)
	{
		val = arg;
		left = leftarg;
		right = rightarg;
		parent = nullptr;
	}
	Node(int arg, Node *leftarg, Node *rightarg, Node *parentarg)
	{
		val = arg;
		left = leftarg;
		right = rightarg;
		parent = parentarg;
	}
};
class BST
{
public:
	Node *root = nullptr;
	int maxVal() { return maxVal(root); }
	int minVal() { return minVal(root); }
	Node *maxNode() { return maxNode(root); }
	Node *minNode() { return minNode(root); }
	void showPre()
	{
		cout << "Preorder: ";
		vector<int> vec;
		preorder(root, vec);
		for (auto &x : vec)
			cout << x << " ";
		cout << endl;
	}

	void showIn()
	{
		cout << "Inorder: ";
		vector<int> vec;
		inorder(root, vec);
		for (auto &x : vec)
			cout << x << " ";
		cout << endl;
	}

	void showPost()
	{
		cout << "Postorder: ";
		vector<int> vec;
		postorder(root, vec);
		for (auto &x : vec)
			cout << x << " ";
		cout << endl;
	}

	BST() {}
	BST(int rootval)
	{
		root = new Node(rootval);
	}
	void search(int val)
	{
		Node *temp = root;
		while (temp != nullptr)
		{
			if (temp->val == val)
			{
				cout << "Value exists in the tree";
				return;
			}
			if (temp->val > val)
			{
				temp = temp->left;
			}
			else if (temp->val < val)
			{
				temp = temp->right;
			}
		}
		cout << "Value isn't present in the tree";
	}
	int maxVal(Node *x)
	{
		while (x->right)
			x = x->right;
		return x->val;
	}
	int minVal(Node *x)
	{
		while (x->left)
			x = x->left;
		return x->val;
	}
	Node *maxNode(Node *x)
	{
		while (x->right)
			x = x->right;
		return x;
	}
	Node *minNode(Node *x)
	{
		while (x->left)
			x = x->left;
		return x;
	}
	Node *successor(Node *x)
	{
		if (x->right)
			return minNode(x->right);
		Node *y = x->parent;
		while (y && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	Node *predecessor(Node *x)
	{
		if (x->left)
		{
			return maxNode(x->left);
		}
		Node *y = x->parent;
		while (y && x == y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	void insertion(Node *z)
	{
		Node *y = nullptr;
		Node *x = root;
		while (x)
		{
			y = x;
			if (x->val > z->val)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		z->parent = y;
		if (!y)
			root = z;
		else if (z->val < y->val)
			y->left = z;
		else
			y->right = z;
	}
	void insertion(int val)
	{
		Node *z = new Node(val);
		insertion(z);
	}

	void preorder(Node *curr, vector<int> &hold)
	{
		if (!curr)
			return;
		hold.push_back(curr->val);
		preorder(curr->left, hold);
		preorder(curr->right, hold);
	}
	void inorder(Node *curr, vector<int> &hold)
	{
		if (!curr)
			return;
		inorder(curr->left, hold);
		hold.push_back(curr->val);
		inorder(curr->right, hold);
	}
	void postorder(Node *curr, vector<int> &hold)
	{
		if (!curr)
			return;
		postorder(curr->left, hold);
		postorder(curr->right, hold);
		hold.push_back(curr->val);
	}
	void shift_nodes(Node *u, Node *v)
	{
		if (u->parent == nullptr)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		if (!v)
			v->parent = u->parent;
	}
	void delete_node(int val)
	{
		Node *z = get_node(val);
		if (!z)
			return;
		if (z->left == nullptr)
		{
			shift_nodes(z, z->right);
		}
		else if (z->right == nullptr)
		{
			shift_nodes(z, z->left);
		}
		else
		{
			Node *y = successor(z);
			if (y->parent != z)
			{
				shift_nodes(y, y->right);
				y->right = z->right;
				if (y->right)
					y->right->parent = y;
			}
			shift_nodes(z, y);
			y->left = z->left;
			if (y->left)
				y->left->parent = y;
		}
	}
	Node *get_node(int val)
	{
		Node *temp = nullptr;
		search(root, temp, val);
		return temp;
	}

	bool search(Node *trav, Node *&temp, int val)
	{
		if (trav == nullptr)
			return false;

		if (val == trav->val)
		{
			//val searched found, set temp to it
			temp = trav;
			return true;
		}
		else if (val < trav->val)
			return search(trav->left, temp, val);
		else
			return search(trav->right, temp, val);
	}
	void destroy(Node *curr)
	{
		if (!curr)
			return;
		destroy(curr->left);
		destroy(curr->right);
		delete curr;
	}
	~BST()
	{
		destroy(root);
	}
};
int main()
{
	BST mybst;
	vector<int> temp = {1, 4, 5, 6, 3, -4, -2, 12, 4};
	for (auto &x : temp)
	{
		mybst.insertion(x);
	}
	mybst.showIn();
	mybst.delete_node(-4);
	mybst.showIn();
}
