#include<bits/stdc++.h>
using namespace std;


void addAdjacencyList(vector<vector<int>> &graph, int node1, int node2, bool bidirectional = true){
    graph[node1].push_back(node2);
    if(bidirectional)
        graph[node2].push_back(node1);
}

void printGraph(vector<vector<int>> &graph){
    for(int i = 0; i< graph.size(); i++){
        cout<<i <<": ";
        for(int x: graph[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

void printBFS(std::vector<vector<int>> &graph, int source){
    int totalNodes= graph.size();
    vector<bool> isProcessed(totalNodes, false);
    
    queue<int> processingNodes;
    isProcessed[source] = true;
    processingNodes.push(source);
    
    
    while(!processingNodes.empty()){
        int currentNode = processingNodes.front();
        processingNodes.pop();
        cout<<currentNode<<" -> ";
        for(int neighbour : graph[currentNode]){
            if(isProcessed[neighbour] == false){
                isProcessed[neighbour] = true;
                processingNodes.push(neighbour);
            }
        }
    }


}
int main(){
    int edges;
    cin>>edges;
    std::vector<vector<int>> graph(edges, std::vector<int>(0));
    for(int i = 1; i<=edges;i++){
        int node1, node2;
        cin>>node1>>node2;
        addAdjacencyList(graph,node1,node2);
    }
    cout<<"Printing Graph\n";
    printGraph(graph);
    cout<<"Printing BFS\n";
    printBFS(graph, 1);
    return 0;
}