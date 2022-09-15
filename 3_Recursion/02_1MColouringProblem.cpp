#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printGraph(int graph[4][4]){
    for(int i = 0; i <4; i++){
        for(int j = 0; j < 4; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}

void addEdge(int source, int dest, int graph[4][4]){
    graph[source][dest] = 1;
    graph[dest][source] = 1;
}

bool isValidToColorCurrentNodeWithCurrentColor(int current_node, int current_color, int total_nodes, int total_colors, int coloredNodes[], int graph[4][4]){

    for(int node = 0; node < total_nodes; node++){
        //       1              &&           2                    &&            3             
        if(node != current_node && graph[node][current_node] == 1 && coloredNodes[node] == current_color)
            return false;
    }
    return true;
    /*
    1: Skipping the check of current node as current node cant be neighbour of itself.
    2: If graph[node][current_node] = 1 means checking if for the particular 'node' variable of loop, if the path exists between current_node than that node.
    3: Checking if the 'node' which is neighbour, if it coloured with same color of the current_color. If we found any adjacent node coloured with same color. Thus, we cannot color it with current_color. So returning false.
    */
}

bool solve(int current_node, int total_nodes, int total_colors, int coloredNodes[], int graph[4][4]){
    
    if(current_node == total_nodes){ // It means all nodes have been coloured and no node is left uncoloured.
        return true;
    }   

    // If we havent coloured all the nodes, lets try colouring the current node from [1 - total_colors] inclusive and check which one of them can be coloured.
    for(int current_color = 1; current_color <= total_colors; current_color++){

        if(isValidToColorCurrentNodeWithCurrentColor(current_node, current_color, total_nodes, total_colors, coloredNodes, graph)){
            coloredNodes[current_node] = current_color;
            // Moving to next node
            bool resultOfColouring = solve(current_node + 1 , total_nodes, total_colors, coloredNodes, graph);
            if(resultOfColouring)
                return true;
            else
                coloredNodes[current_node] = 0;
               
        }
    }
    return false; // If we cant colour any color. Then, returning false.
}

bool graphColoring(int graph[4][4], int total_colors, int total_nodes) {
    int coloredNodes[total_nodes] = {0};
    bool isPossible = solve(0 , total_nodes, total_colors, coloredNodes, graph);
    if(isPossible)
        return true;
    return false;
}

int main(){
    int graph[4][4] = {0};
    int total_nodes = 4;
    addEdge(0,1,graph);
    addEdge(0,2,graph);
    addEdge(0,3,graph);
    addEdge(1,2,graph);
    addEdge(1,3,graph);
   
    printGraph(graph);

    int total_colors;
    cin>>total_colors;

    bool possible = graphColoring(graph,total_colors, total_nodes);
   
    if(possible)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"NOT POSSIBLE"<<endl;
   
    return 0;
}