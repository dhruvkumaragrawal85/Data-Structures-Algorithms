#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
struct Node
{
    int data;
    struct Node* right;
    struct Node* left;
    Node(int val)
    {
        data=val;
        right=left=nullptr;
    }
};
void bfs(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (q.size()>0)
    {
        vector<int> level;
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            Node* node=q.front();
            q.pop();
            level.push_back(node->data);
            if((node->left)!=nullptr)q.push(node->left);
            if((node->right)!=nullptr)q.push(node->right);
        }
        ans.push_back(level);
    }
}
int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    bfs(root);
    for(auto vec: ans)
    {
        for(auto x: vec)
        cout<<x<<" ";
        cout<<endl;
    }
}