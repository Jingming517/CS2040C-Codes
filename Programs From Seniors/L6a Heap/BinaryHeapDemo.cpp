// Binary Heap Demo. Note: the index of this heap starts at 1. heap[0] is unused
#include <bits/stdc++.h>
using namespace std;

class BasicBinaryHeap {
private:
  vector<int> heap;
  int heap_size;

  // three helper navigation function
  int p(int i) { return i>>1; } // i/2
  int l(int i) { return i<<1; } // i*2
  int r(int i) { return (i<<1)+1; } // i*2+1

  void shift_up(int i) {
    if (i == 1) return; // at root, do nothing
    if (heap[i] > heap[p(i)]) { // violate property with parent
      swap(heap[i], heap[p(i)]); // swap upwards
      shift_up(p(i)); // recurse
    }
  }

  void shift_down(int i) {
    if (i > heap_size) return; // beyond last element, do nothing
    int swap_id = i;
    if (l(i) <= heap_size && heap[i] < heap[l(i)]) swap_id = l(i); // compare with left child, if exists
    if (r(i) <= heap_size && heap[swap_id] < heap[r(i)]) swap_id = r(i); // compare with right child, if exists
    if (swap_id != i) { // need to swap with the larger of the two children
      swap(heap[i], heap[swap_id]); // swap downwards with the larger of the two children
      shift_down(swap_id); // recurse
    }
  }

public:
  BasicBinaryHeap() 
    heap.clear(); // clear the vector
    heap.push_back(-1); // remember to set index 0 to be 'dummy'
    heap_size = 0; // an empty Binary Heap
  }

  void Insert(int x) {
    if (heap_size+1 >= (int)heap.size()) heap.push_back(0); // enlarge the vector by one if needed
    heap[++heap_size] = x; // the only possible insertion point
    shift_up(heap_size); // shift upwards
  }

  int ExtractMax() {
    int taken = heap[1]; // this is the maximum value
    swap(heap[1], heap[heap_size--]); // swap with the last existing leaf
    shift_down(1); // fix heap property downwards
    return taken; // return the maximum value
  }

  int GetMax() {
    return heap[1]; // this is the root
  }

  bool IsEmpty() {
    return heap_size == 0; // the only condition for an empty heap
  }
};

int main() {
  BasicBinaryHeap pq;
  cout << pq.IsEmpty() << endl; // should be 1/true
  pq.Insert(5);
  cout << pq.IsEmpty() << endl; // should be 0/false
  pq.Insert(2);
  pq.Insert(7);
  pq.Insert(3);
  cout << pq.ExtractMax() << endl; // should be 7
  pq.Insert(1);
  cout << pq.GetMax() << endl; // should be 5
  cout << pq.ExtractMax() << endl; // should be 5
  pq.Insert(8);
  cout << pq.ExtractMax() << endl; // should be 8 now
  return 0;
}
