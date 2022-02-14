#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void addEdge(vector<vector<int>> &graph, int source, int destination, bool bidirectional = true)
{
    graph[source].push_back(destination);
    if (bidirectional)
        graph[destination].push_back(source);
}

void printBFS(std::vector<vector<int>> &graph, vector<bool> &isVisited, int source)
{

    // The queue will store all the nodes visited.
    queue<int> visitedNodes;
    visitedNodes.push(source);
    isVisited[source] = true;
    while (visitedNodes.empty() == false)
    {
        int currentElement = visitedNodes.front();
        visitedNodes.pop();
        cout << currentElement <<" ->";
        
        for (int &neighbour : graph[currentElement])
        {
            if (isVisited[neighbour] == false)
            {
                visitedNodes.push(neighbour);
                isVisited[neighbour] = true;
            }
        }
    }
}
int main()
{
    int edges;
    cin >> edges;
    int numberOfDisconnectedislands = 0;
    std::vector<vector<int>> graph(edges,std::vector<int>(0));

    for (int i = 1; i <= edges; i++)
    {
        int source, dest;
        cin >> source >> dest;
        addEdge(graph, source, dest);
    }
    int totalNodes = graph.size();
    vector<bool> isVisited(edges);
    for (int node = 0; node <totalNodes-1; node++){
        if (isVisited[node] == false){
            printBFS(graph, isVisited, node);
            numberOfDisconnectedislands++;
        }
    }
    cout<<"Total no of disconnected islands  = "<<numberOfDisconnectedislands<<endl;
}

/*
Input:
7
2 3
1 2
1 3
2 4
3 5
2 6
4 5

7
1 2
0 1
0 2
1 3
2 4
1 5
3 4

7
0 1
0 2
1 2
3 4
5 6
5 7
7 8
*/