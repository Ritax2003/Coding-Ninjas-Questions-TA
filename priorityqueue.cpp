#include <bits/stdc++.h>
using namespace std;

class MaxPriorityQueue {
private:
    vector<int> pq;

public:
    MaxPriorityQueue() {}

    int getSize() {
        return pq.size();
    }

    bool isEmpty() {
        return pq.empty();
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex]) {
                swap(pq[childIndex], pq[parentIndex]);
                childIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    int getMax() {
        if (isEmpty()) {
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        if (isEmpty()) {
            return INT_MIN;
        }
        int maxElement = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int parentIndex = 0;
        while (true) {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int maxIndex = parentIndex;
            if (leftChildIndex < pq.size() && pq[leftChildIndex] > pq[maxIndex]) {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex]) {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex) {
                break;
            }
            swap(pq[parentIndex], pq[maxIndex]);
            parentIndex = maxIndex;
        }
        return maxElement;
    }
};

int main() {
    MaxPriorityQueue pq;
    pq.insert(3);
    pq.insert(2);
    pq.insert(15);
    cout << pq.getMax() << endl; // Output: 15
    cout << pq.removeMax() << endl; // Output: 15
    cout << pq.getMax() << endl; // Output: 3
    cout << pq.getSize() << endl; // Output: 2
    cout << pq.isEmpty() << endl; // Output: 0 (false)
    return 0;
}
