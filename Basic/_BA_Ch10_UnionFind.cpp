/*
In this chapter, we discuss the problem of Disjoint Set (Or Union-Find)
*/

void init(vector<int>& par, vector<int>& rank){
  assert(par.size() == rank.size());
  for(int i = 0; i < par.size(); i++){
    par[i] = i;
    rank[i] = 0;
  }
}

void find(int x, vector<int>& par){
  if(x == par[x])
    return x;
  else
    return par[x] = find(par[x], par); // find parrent and compression
}

void same(int x, int y, vector<int>& par){
  return find(x, par) == find(y, par);
}

void union(int x, int y, vector<int>& par, vector<int>& rank){
  x = find(x, par);
  y = find(y, par);
  if(x == y)
    return;

  if(rank[x] < rank[y])
    par[x] = par[y];
  else{
    par[y] = par[x];
    if(rank[x] == rank[y])
      rank[x]++;
  }
  return;
}
