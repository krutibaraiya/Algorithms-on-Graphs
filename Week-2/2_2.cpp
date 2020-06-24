#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define int long long



const int N = 1e5 + 5;



void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) 
{
  used[x]=1;
  for(int i=0; i<adj[x].size();i++)
  {
    if(!used[adj[x][i]])
    {
        dfs(adj,used,order,adj[x][i]);
    }
  }

  order.insert(order.begin(),x);
} 

    

vector<int> toposort(vector<vector<int> > adj) 
{
  
  vector<int> used(adj.size(),0);
  vector<int> order;
  

  for(int i=0; i<adj.size();i++)
  {
    if(!used[i])
    {
        dfs(adj,used,order,i);
    }
  }
        
  return order;
}
        
        




int32_t main() 
{
  
  IOS;
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) 
  {
    int x, y;
    cin >> x >> y;
    adj[x-1].push_back(y-1);
  }
  vector<int> order = toposort(adj);
  for (int i = 0; i < order.size(); i++) 
  {
    cout << order[i] + 1 << " ";
  }

  return 0;
}


