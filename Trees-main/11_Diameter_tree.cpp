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
int maxht(Node* root, int &maxi)
{
    if(root==nullptr)return 0;
    int lht=maxht(root->left, maxi);
    int rht=maxht(root->right, maxi);
    maxi=max(maxi, lht+rht);
    return 1+max(lht, rht);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    int maxi=0;
    int temp=maxht(root, maxi);
    cout<<"Diameter:"<<maxi;
}