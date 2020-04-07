#include "Exception.h"

template <typename T>
class List {
    public:
        List();
        ~List();

        bool isEmpty() const;
        int getLength() const;

        //The three main operations of List ADT
        void insert(int index, const T& newItem)
            throw (SimpleException);

        void remove(int index)
            throw (SimpleException);

        void retrieve(int index, T& dataItem) const
            throw (SimpleException);

private:
 	 struct ListNode {
   	T item;         //note the "T"
        ListNode *next;
    };

    int _size;

    ListNode* _head;
    
    ListNode* find(int index) const;


};  // end List class

