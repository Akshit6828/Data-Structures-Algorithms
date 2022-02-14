#include<bits/stdc++.h>
#include<iostream>
//using namespace std;
void AddEdge(std::vector<std::vector<int>> &graph, int source, int dest, bool bidirectional = true){
    graph[source].push_back(dest);
    if(bidirectional)
        graph[dest].push_back(source);
        
}

int ShortestPath(std::vector<std:: vector<int>> &graph,  
    int source,
    std::vector<int> &distances){
  
  std:: vector<bool> is_visited_(graph.size());
  is_visited_[source] = true;
  std::queue<int> current_processing_nodes_;
    current_processing_nodes_.push(source);

  while(!current_processing_nodes_.empty()){
      int currentNode = current_processing_nodes_.back();
      current_processing_nodes_.pop();
      
      for(int neighbour : graph[currentNode]){

          if(is_visited_[neighbour] == false){
            distances[neighbour] = distances[currentNode] + 1;
            current_processing_nodes_.push(neighbour);
            is_visited_[neighbour] = true;
            }

      }
  }

  return 0;
}
int main(){
    int edges;
    std::cin >> edges;

    std::vector<std::vector<int>> graph(edges,std::vector<int>(0));

    for (int i = 1; i <= edges; i++)
    {
        int source, dest;
        std::cin >> source >> dest;
        AddEdge(graph, source, dest);
    }
    
    int totalNodes = graph.size();
    
    double inf = std::numeric_limits<double>::infinity();
    std::vector<int> distances(totalNodes, inf);
    distances[0] = 0;
    ShortestPath(graph, 0, distances);

    for(int i = 0; i< distances.size() -1 ; i++)
        std::cout<<" "<<distances[i]<<" ";
    
    
    return 0;
}

/*
Input:
5
0 1
0 2
1 2
1 3
2 3
*/