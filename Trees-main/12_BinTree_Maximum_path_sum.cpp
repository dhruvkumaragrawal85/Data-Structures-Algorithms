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
int maxsum(Node* root, int &res)
{
    if(root==nullptr)return 0;
    int lsum=max(0, maxsum(root->left, res));
    int rsum=max(0, maxsum(root->right, res));
    res=max(res, root->data+lsum+rsum);
    return root->data+max(lsum, rsum);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(-5);
    root->right->left->left=new Node(8);
    int ans=-1e9;
    int temp=maxsum(root, ans);  
    cout<<"Max path sum:"<<ans;
}