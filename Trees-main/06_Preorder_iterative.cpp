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
void preorder(Node* root)
{
    stack<Node*> st;
    st.push(root);
    while(st.size()>0)
    {
        Node* node=st.top();
        st.pop();
        cout<<node->data<<" ";
        if((node->right)!=nullptr)st.push(node->right);
        if((node->left)!=nullptr)st.push(node->left);
    }
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);  
    preorder(root);
}