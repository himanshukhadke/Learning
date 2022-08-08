// Author - Himanshu.Khadke
#include<bits/stdc++.h>
using namespace std;

class graph{
	map<int,vector<int>> adj;
	int parent[10]={-1};
	int distance[10]={0};
	public:
	void addEdge(int u,int v,int direction){
		adj[u].push_back(v);
		if(!direction)
			adj[v].push_back(u);
	}
	void printGraph(){
		for(auto i:adj){
			cout<<i.first<<" : ";
				for(int j:i.second){
					cout<<j<<" ,";
				}
			cout<<endl;
		}
	}

	void bfs(int n){
		int visited[n+1]={0};
		queue<int> q;
		q.push(1);
		visited[1]=1;
		parent[1]=-1;
		while(!q.empty()){
			int element=q.front();
			cout<<element<<" ,";
			q.pop();
			for(auto neigh:adj[element]){
				if(!visited[neigh]){
					q.push(neigh);
					parent[neigh]=element;
					distance[neigh]=distance[element]+1;
					visited[neigh]=1;
				}
			}
		}
	}
 	void printPath(int n){
		vector<int> path;
		for(int i=1;i<=n;++i){
			for(int v=i;v!=-1;v=parent[v]){	
				path.push_back(v);
			}
			reverse(path.begin(),path.end());
			cout<<"distance : "<<distance[i]<<" path of "<<i<<" from source(1) : ";
			for(auto k:path){
				cout<<k<<" ";
			}
			path.clear();
			cout<<endl;
		}
	}	
};

int main(){
	graph g;
	int nodes,edges;
    cout<<"Enter no. of Node "<<endl;
	cin>>nodes;
	cout<<"Enter no. of edges "<<endl;
	cin>>edges;
	for(int i=0;i<edges;++i){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v,0);
	}

	g.printGraph();
	cout<<endl;
	g.bfs(nodes);
	cout<<endl;
	g.printPath(nodes);
	return 0;
}
