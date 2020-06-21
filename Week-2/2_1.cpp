#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

class DiGraph
{
  vector<vector<int>> adj;
  size_t _size{0};


  void explore(const int node, set<int> &visited, set<int> &path)
  {
    visited.insert(node);
    path.insert(node);

    for(auto a: this->adj[node])
    {
      if(path.find(a) != path.end())
      {
        throw logic_error("This is a cycle!");
      }

      if(visited.find(a) == visited.end())
      {
        this-> explore(a,visited,path);
      }
    }

    path.erase(node);
  }

public:
  DiGraph(size_t size):adj(size,vector<int>()), _size(size) {}

  void add_edges(const size_t m) 
  {
        for (size_t j = 0; j < m; j++) 
        {
            size_t s,t;
            cin >> s >> t;
            this->adj[s - 1].push_back(t - 1);
            
        }
  }


  void display() 
  {
        cout << "# nodes = " << this->_size << endl;
        cout << "Adjacencies: " << endl;
        for (size_t node = 0; node < this->_size; node++) 
        {
            cout << node + 1 << " -> ";
            for (auto a : this->adj[node]) 
            {
                cout << a + 1 << " ";
            }
            cout <<endl;
        }
  }

  bool empty() 
  { 
    return this->_size == 0; 
  }

   bool is_acyclic() 
   {
        
        set<int> visited;
        set<int> path;
        
        for (int node = 0; node < this->_size; node++) 
        {
            if (visited.find(node) == visited.end()) 
            {
                
                try 
                {
                    this->explore(node, visited, path);
                } catch (std::logic_error &err) 
                {
                    
                    return false;
                }
            }
        }
        return true;
    }

};

int main()
{
  IOS;
  size_t n,m;
  cin >> n >> m;
  DiGraph graph(n);
  graph.add_edges(m);
  cout << not graph.is_acyclic() << endl;
  return 0;
}

 
 

 

