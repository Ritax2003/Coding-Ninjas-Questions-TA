#include <iostream>
#include <queue>
#include <algorithm> // Include the algorithm header for min and max functions input 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
#include <climits>


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

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
         cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	pair<int,int>ans;
		if (root == nullptr) {
        ans.first = INT_MAX;
        ans.second = INT_MIN;
        return ans;
    }

                int mini = root->data;
                int maxi = root->data;
                pair<int, int> leftans = getMinAndMax(root->left);
                pair<int, int> rightans = getMinAndMax(root->right);

                ans.first = std::min(mini, min(leftans.first, rightans.first));
		
                ans.second = std::max(maxi, max(leftans.second, rightans.second));
                return ans;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}