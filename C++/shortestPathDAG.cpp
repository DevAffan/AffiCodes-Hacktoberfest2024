#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

class graph{
    public:
        unordered_map<int,list<pair<int,int>> > adj;

        void addEdge(int u, int v, int weight){
            pair<int,int> p = make_pair(v,weight);
            //adjacency list mai push krdo
            adj[u].push_back(p);

        }

        //print kara lo bahiya list ko
        void printList(){
            for(auto i: adj){
                cout<<i.first<<"-->";
                for(auto j: i.second){
                    cout<<"(" <<j.first << "," <<j.second <<"),"; 
                }cout<<endl;
            }
        }

        void dfs(int node,  unordered_map<int,bool> &visited, stack<int> &s){
            //step1
            visited[node] = true;

            //neighbour ko traverse kro
            for(auto neighbour: adj[node]){
                if(!visited[neighbour.first]){
                    dfs(neighbour.first,visited,s);
                }
            }
            s.push(node);
        }

        void sortestPath(int src, vector<int> &dist, stack<int> &s){
            dist[src] = 0;

            //till ur stack gets empty
            while(!s.empty()){
                int top = s.top();
                s.pop();

                //agar distance apka infinite nhi hai
                if(dist[top] != INT_MAX){
                    for(auto i: adj[top]){
                        if(dist[top] + i.second < dist[i.first]){
                            //distance update krdo
                            dist[i.first] = dist[top] + i.second;
                        }
                    }
                }
            }
        }

};

int main(){
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    //print toh kar ke dekh lo bhaiu
    g.printList();

    //toposort ka function likho
    unordered_map<int,bool> visited;
    stack<int> s;
    int n = 6;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for(int i=0; i<n; i++)
        dist[i] = INT_MAX;

    g.sortestPath(src,dist,s);

    cout<<"answer is:"<<endl;
    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }cout<<endl;

    return 0;
}