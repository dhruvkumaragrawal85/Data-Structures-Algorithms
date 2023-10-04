#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
void solve(int col, vector<int> &board, vector<vector<int>> &ans, int n,
vector<int> &side, vector<int> &ud, vector<int> &lw)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++)
    {
        if(side[row]==0 &&
           ud[n-1+col-row]==0 &&
           lw[col+row]==0)
           {
               side[row]=1;
               ud[n-1+col-row]=1;
               lw[col+row]=1;
               board[col]=row+1;
               solve(col+1, board, ans, n, side, ud, lw);
               side[row]=0;
               ud[n-1+col-row]=0;
               lw[col+row]=0;
               board[col]=0;
           }
    }
}
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<int> board(n, 0);
        vector<int> side(n, 0);//side check
        vector<int> ud(2*n-1, 0);//upper diagonal
        vector<int> lw(2*n-1, 0);//lower diagonal
        solve(0, board, ans, n, side, ud, lw);
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
