#include <bits/stdc++.h>
using namespace std;
vector<int> inorder;
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
void inorder_iter(Node* root)
{
    stack<Node*> st;
    Node* node=root;
    while (true)
    {
        if(node!=nullptr)
        {
            st.push(node);
            node=node->left;
        }
        else
        {
            if(st.empty())break;
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    inorder_iter(root);
    for(auto x: inorder)
    cout<<x<<" ";
}