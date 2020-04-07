// std::unordered_map 
#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Unordered map 
    unordered_map<int, int> order; 
    // Mapping values to keys 
    order[5] = 10; 
    order[3] = 5; 
    order[20] = 100; 
    order[1] = 1; 
    // Iterating the map and printing unordered values 
    //for (auto i = order.begin(); i != order.end(); i++) { 
    //   cout << i->first << " : " << i->second << '\n'; 
    for (auto i : order) {
    	cout << i.first << " : " << i.second << endl;
	}
}

