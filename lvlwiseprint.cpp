#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
     while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
     return root;
}
void printLevelWise(TreeNode<int>* root) {
   queue<TreeNode<int>*>q;
   q.push(root);
   while(!q.empty()){
          TreeNode<int>*front=q.front();
             cout << front->data <<":";
             int size=front->children.size();
          for(int i=0;i<front->children.size();i++){
              cout << front->children[i]->data;
              q.push(front->children[i]);
               if(size-1==i){
                   break;
               } 
               else{
                   cout << ",";
               }
          }
          cout << endl;
            q.pop();
   }


}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}

