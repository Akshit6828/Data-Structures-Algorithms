#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void addEdge(std::vector<vector<int>> &graph, int source, int dest, bool bidirectional = true){
    graph[source].push_back(dest);
    if(bidirectional)
        graph[dest].push_back(source);
}

void DFS(std::vector<vector<int>> &graph, std::vector<bool> &isVisited,  int source){

    isVisited[source] = true;
    cout<<source<<" ";

    for(int neighbour : graph[source]){
        if( isVisited[neighbour] == false)
            DFS(graph, isVisited, neighbour);
    }

}
int main(){
    int edges;
    cin >> edges;

    std::vector<vector<int>> graph(edges,std::vector<int>(0));

    for (int i = 1; i <= edges; i++)
    {
        int source, dest;
        cin >> source >> dest;
        addEdge(graph, source, dest);
    }
    int totalNodes = graph.size();
    vector<bool> isVisited(edges);
    DFS(graph, isVisited, 0);
    
    return 0;
}