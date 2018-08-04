/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge
is a pair of nodes), write a function to find the number of connected components
in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are
undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

*/

#include <vector>
#include <unordered_set>

void _DFS(vector<vector<int>> & graph, vector<bool>& visited, int idx){

    visited[idx] = true;

    for(auto i : graph[idx]){
        if(!visited[i])
         _DFS(graph, visited, i);
    }
    return;
}

void _BFS(vector<vector<int>>& graph, vector<bool>& visited, int idx){

    queue<int> que;
    que.push(idx);
    visited[idx] = false;

    while(!que.empty()){
        int node = que.front();
        que.pop();

        for(auto i : graph[node]){
            if(visited[i]) continue;
            visited[i] = true;
            que.push(i);
        }
    }
    return;
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n);
    for(auto &e : edges){
        graph[e.second].push_back(e.first);
        graph[e.first].push_back(e.second);
    }

    vector<bool> visited(n, false);
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ret++;
            _BFS(graph, visited, i);
            // _DFS(graph, visited, i);
        }
    }
    return ret;
}
