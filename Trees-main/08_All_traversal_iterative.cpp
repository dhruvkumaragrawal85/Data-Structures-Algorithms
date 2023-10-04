#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
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
void trav(Node* root)
{
    if(root==nullptr)return;
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(st.size()>0)
    {
        auto x=st.top();
        st.pop();
        if(x.second==1)
        {
            pre.push_back(x.first->data);
            x.second++;
            st.push(x);

            if(x.first->left!=nullptr)
            st.push({x.first->left, 1});
        }
        else if (x.second==2)
        {
            in.push_back(x.first->data);
            x.second++;
            st.push(x);

            if(x.first->right!=nullptr)
            st.push({x.first->right, 1});
        }
        else
        {
            post.push_back(x.first->data);
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
    trav(root);
    for(auto x: pre)
    cout<<x<<" ";
    cout<<endl;
    for(auto x: in)
    cout<<x<<" ";
    cout<<endl;
    for(auto x: post)
    cout<<x<<" ";
    cout<<endl;  
}