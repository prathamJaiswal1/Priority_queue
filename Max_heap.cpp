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
            return pq[0];  // Return the root of the max-heap
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
            if (pq[parentindex] < pq[childindex]) {  // Change the condition here
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
            int maxindex = parentindex;
            if (pq[maxindex] < pq[leftchildindex]) {  // Change the condition here
                maxindex = leftchildindex;
            }
            if (rightchildindex < pq.size() && pq[maxindex] < pq[rightchildindex]) {  // Change the condition here
                maxindex = rightchildindex;
            }

            if (maxindex == parentindex) {
                break;
            }

            swap(pq[parentindex], pq[maxindex]);

            parentindex = maxindex;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
    }
};

int main() {
    My_Priority_queue maxheap;
    cout << maxheap.getSize() << endl;
    maxheap.push(1);
    maxheap.push(2);
    maxheap.push(6);
    maxheap.push(4);
    maxheap.push(3);
    maxheap.push(8);
    cout << maxheap.top() << endl;
    while (maxheap.getSize()) {
        cout << maxheap.top() << " ";
        maxheap.pop();
    }
    return 0;
}
