#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};
int balanced(Node* root)
{
    if(root==nullptr)return 0;
    int lh=balanced(root->left);
    int rh=balanced(root->right);
    if(lh==-1 || rh==-1)
    return -1;
    if(abs(rh-lh)>1)
    return -1;
    return 1+max(rh, lh);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(4);
    if(balanced(root)==-1)
    {
        cout<<"Not a balance binary tree.";
    }
    else
    {
        cout<<"It is a balanced binary tree.";
    }
}