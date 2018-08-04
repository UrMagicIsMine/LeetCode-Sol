/*
In this chapter, we discuss the problem of Binary Index Tree or Fenwick Tree
*/

class FenWickTree{

public:
  FenWickTree(int num) : _sum(num+1, 0){
  }

  int query(int x){
    int sum = 0;
    while(x > 0){
      sum += _sum[x];
      x -= lowbit(x);
    }
    return sum;
  }

  void update(int x, int delta){
    while(x < _sum.size()){
      _sum[x] += delta;
      x += lowbit(x);
    }
    return;
  }

private:

  inline static int lowbit(int x){
    return x & (-x);
  }
  vector<int> _sum;

};
