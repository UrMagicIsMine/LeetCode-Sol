/*
In this chapter, we discuss the problem of sorting an array of elements.
*/

#include <vector>

/******************************************************************************/
// insertion sort
// run-time: 1) O(N^2), if reverse sorted, 2) O(N), if sorted already
template<typename Comparable>
void insertionSort(vector<Comparable> & array){

  for(int i = 1; i < array.size(); i++){
    Comparable tmp = std::move(array[p]);

    int j = p;
    for(; j > 0 && tmp < a[j-1]; j--){
      array[j] = std::move(array[j-1]);
    }
    array[j] = std::move(tmp);
  }
}

/******************************************************************************/
// merge sort, divide and conquer
// run-time: O(NlogN); memory: O(N)
template<typename Comparable>
void merge(vector<Comparable> & array, vector<Comparable> & arraytmp, int lPos, int rPos, int rEnd){
  int lBegin = lPos;
  int lEnd = rPos - 1;
  int pos = lPos;
  // merge two sorted halves of a subarray;
  while(pos <= rEnd){
    if(lPos <= lEnd && array[lPos] <= array[rPos])
      arraytmp[pos++] = std::move(array[lPos++]);
    else
      arraytmp[pos++] = std::move(array[rPos++]);
  }
  // copy temp array back;
  for(int i = lBegin; i <= rEnd; i++)
    array[i] = std::move(arraytmp[i]);
}

template<typename Comparable>
void mergesort(vector<Comparable> & array, vector<Comparable> & arraytmp, int left, int right){

  if(left < right){
    int center = left + (right - left)/2;
    mergesort(array, arraytmp, left, center);
    mergesort(arraym arraytmp, center+1, right);
    merge(array, arraytmp, left, center+1, right);
  }
  return;
}

template<typename Comparable>
void mergesort(vector<Comparable>& array){

  int N = array.size();
  vector<Comparable> arraytmp(N);
  mergesort(array, arraytmp, 0, N-1);
  return;
}

/******************************************************************************/
// heap sort
/*
1) 堆最重要的性质是： 儿子的值一定不小于父亲；树的节点是按照从上到下，从左到右的顺利紧凑排列的；
2）向堆中插入数值时，首先在堆的末尾插入该数值，然后不断向上提升直到没有大小颠倒为止；
3）从堆中删除最小值时，首先把堆的最后一个节点的数值复制到根节点上，并且删除最后一个节点，
然后不断向下交换直到没有大小颠倒为止。
4）用数值来存储：左儿子 l = 2*p + 1, 右儿子 r = 2*p + 2, 父亲 p = (child - 1)/2
// run-time: O(NlogN); memory: O(1)
*/

int leftchild(int i){
  return 2*i + 1;
}

/*
* i is the position from which to proceed down;
* N is the logical size of the binary heap;
*/

template<typename Comparable>
void precDown(vector<Comparable> & array, int i, int N){
  int child;
  Comparable tmp = std::move(array[i]);
  for(; leftchild(i) < N; i = child){

    child = leftchild(i);
    if(i != N-1 && array[child] < array[child+1])
      child++;
    if( tmp < array[child] )
      array[i] = std::move(array[child]);
    else
      break;
  }
  array[i] = std::move(tmp);
}

template<typename Comparable>
void heapsort(vector<Comparable> & array){
  int N = array.size();
  // build heap;
  for(int i = N/2 - 1; i >= 0; i--){
    percDown(array, i, N);
  }
  // delete max
  for(int i = N-1; i > 0; i--){
    std::swap(array[0], array[i]);
    percDown(array, 0, i);
  }
  return;
}

/******************************************************************************/
// quick sort
template<typename Comparable>
void quicksort(vector<Comparable>& array){

}
