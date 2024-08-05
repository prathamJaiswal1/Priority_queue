// min Heap class
#include <bits/stdc++.h>
using namespace std;

class My_Priority_queue {
public:
    vector<int> pq;
    My_Priority_queue() {}

    int getSize() {
        return pq.size();
    }

    int top() {
        if (pq.size()) {
            return pq[0];  // Return the root of the min-heap
        } else {
            cout << "No element" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    void push(int ele) {
        pq.push_back(ele);
        int childindex = pq.size() - 1;
        while (childindex > 0) {
            int parentindex = (childindex - 1) / 2;
            if (pq[parentindex] > pq[childindex]) {
                swap(pq[parentindex], pq[childindex]);
            } else {
                break;
            }
            childindex = parentindex;
        }
    }

    void pop() {
        if (pq.size() == 0) return;  // Handle edge case if the heap is empty

        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();

        int parentindex = 0;
        int leftchildindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;

        while (leftchildindex < pq.size()) {
            int minindex = parentindex;
            if (pq[minindex] > pq[leftchildindex]) {
                minindex = leftchildindex;
            }
            if (rightchildindex < pq.size() && pq[minindex] > pq[rightchildindex]) {
                minindex = rightchildindex;
            }

            if (minindex == parentindex) {
                break;
            }

            swap(pq[parentindex], pq[minindex]);

            parentindex = minindex;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
    }
};

int main() {
    My_Priority_queue minheap;
    cout << minheap.getSize() << endl;
    minheap.push(1);
    minheap.push(2);
    minheap.push(6);
    minheap.push(4);
    minheap.push(3);
    minheap.push(8);
    cout << minheap.top() << endl;
    while (minheap.getSize()) {
        cout << minheap.top() << " ";
        minheap.pop();
    }
    return 0;
}
