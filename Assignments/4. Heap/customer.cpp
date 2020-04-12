#include "customer.h"
#include "heap.h"
#include <iostream>
using namespace std;
int comparisonWay = 0; // 0 for arrival time, 1 for processing time


bool Customer::operator>(const Customer& c) {
	return comparisonWay ? processing_time < c.processing_time : arrival_time < c.arrival_time; // a customer is "greater" if his time is shorter
};

bool Customer::operator<(const Customer& c) {
    return comparisonWay ? processing_time > c.processing_time : arrival_time > c.arrival_time;
};


bool Customer::operator==(const Customer& c) {
    return comparisonWay ? processing_time == c.processing_time : arrival_time == c.arrival_time;
};

void customerQueueTest(int n_cust) {
    int current_time = 0;
    int totalWaitingTime = 0;
    int i;
    int WT = 0; // waiting time for each customer
    Heap<Customer> queue;
    Customer* custList = new Customer[n_cust];
    cout << endl << endl << "Setup" << endl;
    cout << "List of customers and their arrival and processing times" << endl;
    for (i = 0; i<n_cust; i++)
    {
        custList[i].setAT(i);
        custList[i].setPT((n_cust - i) % (n_cust / 2) + 1 + (i % 2)*(n_cust / 2));
        cout << "Customer " << i << " will arrive at time " << custList[i].AT() << " with PT=" << custList[i].PT() << endl;
    }
    cout << endl;
    for (int round = 0; round<2; round++) {
        cout << endl << endl;
        cout << "Test Round " << round + 1 << endl;
        cout << (round == 0 ? "First come first serve" : "Customer with the least PT served first") << endl;
        comparisonWay = round;
        current_time = 0;
        totalWaitingTime = 0;
        i = 0;
        int totalPT = 0;  //total processing time needed befor can serve next customer
        int totalQT = 0;  //total queue time
        while (current_time <= totalQT)
        {
            Customer c;
            if (i < n_cust)
            {
                c = custList[i];
                queue.insert(c);
                cout << "Customer arrives at time " << c.AT() << " with PT=" << c.PT() << endl;
                totalQT += c.PT();
                i++;
                if (i == n_cust) totalQT -= c.PT();
            }
            if (current_time == totalPT)
            {
                c = queue.extractMax();
                WT = current_time - c.AT();
                totalPT += c.PT();
                totalWaitingTime += WT;
                if (WT == 0) cout << "Customer arrives when no one is waiting" << endl;
                cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for "
                        << WT << " min." << endl;
            }
            current_time++;
        }
        cout << "Total Waiting Time: " << totalWaitingTime << endl;
        cout << "Average Waiting Time: " << totalWaitingTime / (float)n_cust << endl;
    }
    delete[] custList;
}
