/*
In this chapter, we discuss the problem of Disjoint Set (Or Union-Find)
*/

class UnionFindSet{

public:
  UnionFindSet(int n) : _par(n, 0), _rank(n, 0){

  }

  int find(int x){
    if (x == _par[x])
      return x;
    else
      return _par[x] = find(_par[x]); // path compression
  }

  bool Union(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(rx == ry) return false; // in the same set already

    if(_rank[rx] < _rank[ry])
      _par[rx] = ry;
    else{
      _par[ry] = rx;
      if(_rank[rx] == _rank[ry])
        _rank[rx]++;
    }
    return true;
  }

private:
  vector<int> _par;
  vector<int> _rank;
};
