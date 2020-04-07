#include <iostream>
#include <queue>
using namespace std;

int main() {
   priority_queue<int> pq;
   pq.push(10);
   pq.push(20);
   pq.push(30);
   pq.push(5);
   while (!pq.empty()) { 
      cout << pq.top() << " ";	// 20 10
      pq.pop();
   }
   return 0;
}

