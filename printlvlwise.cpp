#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
using namespace std;
BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
 cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
             }
    }
    return root;
}
#include<queue>
void printLevelWise(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
       cout << front->data << ":";
        if (front->left) {
            cout << "L:" << front->left->data;
             q.push(front->left);
        } 
        else{
        cout << "L:-1";
        }
        cout << ",R:";
        if (front->right) {
            cout << front->right->data;
            q.push(front->right);
        }
        else {
        cout << "-1";
        }
        cout << endl;
    }
    }
int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}