#include <bits/stdc++.h>
using namespace std;
struct  Node
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
bool equalTree(Node* p, Node* q)
{
    if(p==nullptr||q==nullptr)
    {
        return p==q;
    }
    return (p->data==q->data) && equalTree(p->left, q->left) && equalTree(p->right, q->right);
}
int main()
{
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->left->left=new Node(4);
    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    Node* root3=new Node(1);
    root3->left=new Node(2);
    root3->right=new Node(3);
    root3->left->left=new Node(5);
    if(equalTree(root1, root2))
    cout<<"Tree_1==Tree_2\n";
    else
    cout<<"Tree_1!=Tree_2\n";
    if(equalTree(root1, root3))
    cout<<"Tree_1==Tree_3\n";
    else
    cout<<"Tree_1!=Tree_3\n";  
}