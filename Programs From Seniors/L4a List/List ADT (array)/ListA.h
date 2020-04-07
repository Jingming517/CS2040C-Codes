#include "Exception.h"

const int MAX_LIST = 50;

template <typename T>
class List {
public:
   List();
	bool isEmpty() const;
	int getLength() const;
    void insert(int index, const T& newItem)
         throw (SimpleException);

    void remove(int index)
         throw (SimpleException);

    void retrieve(int index, T& dataItem) const
         throw (SimpleException);

private:
   
	T _items[MAX_LIST];

   int _size;

};  // end List class

