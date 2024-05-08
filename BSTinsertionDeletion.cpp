#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *L;
        Node *R;

        Node(int val){
            this->val = val;
            L=R=NULL;
        }

};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(root->val < val){
        Node* temp = insert(root->R,val);
        root->R=temp;
        return root;
    }
    else{
        Node* temp = insert(root->L,val);
        root->L=temp;
        return root;
    }
}
Node* remove(Node* p,int val){
    if(p==NULL) return p;
    if(p->val <val){
        p->R = remove(p->R,val);
        return p;
    }
    else if(p->val > val){
        p->L = remove(p->L,val);
        return p;
    }
    // found value
    if(p->L == NULL){  //left part is NULL
        Node* temp = p->R;
        delete p;
        return temp;
    }
    else if(p->R == NULL){ // right part is NULL
        Node* temp = p->L;
        delete p;
        return temp;
    }
    else{ // no part is NULL
    /*If both children of the current node are not NULL, 
    it finds the inorder successor (s) of the current node
     (the smallest node in the right subtree of the current node).*/
        Node* s = p->R;
        Node* sp = p;

        while(s->L!=NULL){
            sp = s;
            s = s->L;
        }
        if(sp == p){
            sp->R = s->R;
        }
        else{
            sp->L = s->R;
        }
        p->val = s->val;
        delete s;
        return p;
    }
}
bool search(Node* p, int key){
    if(p==NULL)return false;
    if(p->val == key ) return true;
    if(p->val < key) return search(p->R,key);
    if(p->val > key) return search(p->L,key);
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->L);
    cout<<root->val<<" ";
    inorder(root->R);
}

int main(){
    Node* root = NULL;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        root = insert(root,val);
        inorder(root);
        cout<<endl;
    }
    cin>>n;
    while(n--){
        cin>>val;
        root  = remove(root,val);
        inorder(root);
        cout<<endl;
    }
    cin>>n;
    while(n--){
        cin>>val;
        bool res = search(root,val);
        if(res==1) cout<<"Exists";
        else cout<<"Doesn't exists";
    }
}