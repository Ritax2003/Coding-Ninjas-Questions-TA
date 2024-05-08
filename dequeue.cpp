
#include<iostream>
using namespace std;
class Deque {
    int* data;
    int capacity;
    int size;
    int frontIndex;
    int rearIndex;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
        this->frontIndex = 0;
        this->rearIndex = capacity - 1;
    }

    void insertFront(int element) {
        if (size == capacity) {
            cout << "-1" << endl;
            return;
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = element;
        size++;
    }

    void insertRear(int element) {
        if (size == capacity) {
            cout << "-1" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = element;
        size++;
    }

    void deleteFront() {
        if (size == 0) {
            cout << "-1" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    void deleteRear() {
        if (size == 0) {
            cout << "-1" << endl;
            return;
        }
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        size--;
    }

    int getFront() {
        if (size == 0) {
            return -1;
        }
        return data[frontIndex];
    }

    int getRear() {
        if (size == 0) {
            return -1;
        }
        return data[rearIndex];
    }
};



// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
             case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
  return 0;
}