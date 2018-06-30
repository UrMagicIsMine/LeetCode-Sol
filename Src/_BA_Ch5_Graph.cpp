/*
In this chapter, we discuss the problem of graph
*/

#include <queue>

struct Edge{
  int from;
  int to;
};

struct Wedge{
  int from;
  int to;
  int cost;
};

/******************************************************************************/
// Topological sort
//

bool _DFS(vector<vector<int>>& graphs, int i, vector<bool>& visited,
  vector<int>& resl, vector<bool>& paths){

  visited[i] = true;
  paths[i] = true;
  for(auto iNxt : graphs[i]){
    if(paths[iNxt] == true)  // loop exists
      return false;
    if(!visited[iNxt] && !_DFS(graphs, iNxt, visited, resl, paths)){
      return false;
    }
  }
  paths[i] = false; // clear bit, backtracking
  resl.push_back(i);
  return true;
}

vector<int> TopologicalSort(int N, vector<Edge>& edges){
  vector<int> resl;
  resl.reserve(N);
  vector<vector<int>> graphs(N);
  for(auto & e : edges)
    graphs[e.first].push_back(e.second);

  vector<bool> visited(N, false);
  vector<bool> paths(N, false);
  for(int i = 0; i < N; i++){
    if(!visited[i] && !_DFS(graphs, i, visited, resl, paths)){
      return vector<int>();
    }
  }
  reverse(resl.begin(), resl.end());
  return resl;
}

/******************************************************************************/
// Single-Source Shortest Path: Dijkstra algorithm
// run-time O(ElogV), memory O(E)

#define INF 0x3fffffff;

void dijkstra(const vector<Wedge>& edges, int s, int N, vector<int>& dist){
  typedef pair<int, int> PII_t;
  vector<vector<PII_t>> graphs(N);
  for(auto &e: edges)
    graphs[e.from].push_back(make_pair(e.to, e.cost));

  fill(dist.begin(), dist.end(), INF);
  dist[s] = 0;
  priority_queue<PII_t, vector<PII_t>, greater<PII_t>> heap;
  heap.push(make_pair(0, s));

  int u, v, w;
  while(!heap.empty()){
    PII_t p = heap.top();
    heap.pop();
    u = p.second;
    if(dist[u] < p.first) continue;
    for(auto &pNxt : graphs[u]){
      v = pNxt.first;
      w = pNxt.second;
      if(dist[v] > dist[u] + w){
        // relaxation;
        dist[v] = dist[u] + w;
        heap.push(make_pair(dist[v], v));
      }
    }
  }
  return;
}

/******************************************************************************/
// Single-Source Shortest Path: Bellman-Ford algorithm
// run-time O(EV), memory O(1)

void BellmanFord(const vector<Wedge>& edges, int s, int N, vector<int>& dist){
  fill(dist.begin(), dist.end(), INF);
  dist[s] = 0;

  while(true){
    bool update = false;

    for(auto& e : edges){
      if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost)
        dist[e.to] = dist[e.from] + e.cost;
        update = true;
    }

    if(!update)
      break;
  }
  return;
}

bool findNegativeLoop(const vector<Wedge>& edges, int N, vector<int>& dist){
  fill(dist.begin(), dist.end(), 0);

  for(int i = 0; i < N; i++){
    for(auto & e: edges){
      if(dist[e.to] > dist[e.from] + e.cost){
        dist[e.to] = dist[e.from] + e.cost;

        // if still relaxed in N-th loop, then negative cycle exists;
        if(i == N - 1)
          return true;
      }
    }
  }
  return false;
}

/******************************************************************************/
// All-Pairs Shortest Path: Floyd-Warshall algorithm
// run-time , memory
void FloydWarshall(){
  return;
}

/******************************************************************************/
// Minimum Span Tree:
// run-time , memory
void Prime(){
  return;
}
