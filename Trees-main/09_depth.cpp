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
int maxht(Node* root)
{
    if(root==nullptr)return 0;
    int lht=maxht(root->left);
    int rht=maxht(root->right);
    return 1+max(lht, rht);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    root->left->right->left=new Node(5);
    cout<<"hv"<<maxht(root);
}