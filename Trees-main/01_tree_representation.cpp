#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        int data=val;
        left=right=nullptr;
    }
};
int main()
{
    struct Node* root=new Node(1);
    root->right=new Node(4);
    root->left=new Node(2);
    root->right->right=new Node(1);
}