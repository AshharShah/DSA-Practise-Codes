#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

class tree{

    private:
    node* root = new node;

    public:
    tree(int x){
        root->val = x;
        root->right = NULL;
        root->left = NULL;
    }

    void insert(int x){
        node* newnode = new node;
        node* temp = new node;
        temp = root;

        newnode->left = NULL;
        newnode->right = NULL;
        newnode->val = x;

        while(temp != NULL){
            // check left node
            if(x < temp->val && temp->left != NULL){
                temp = temp->left;
            }
            // insert at left node
            else if(x < temp->val && temp->left == NULL){
                temp->left = newnode;
                return;
            }
            // check right node
            else if(x > temp->val && temp->right != NULL){
                temp = temp->right;
            }
            // insert at right node
            else if(x > temp->val && temp->right == NULL){
                temp->right = newnode;
                return;
            }
        }
    }

    node* gethead(){
        return root;
    }

};


void preorder(node* t){
    if(t == NULL){
        return;
    }
    cout << t->val << endl;
    preorder(t->left);
    preorder(t->right);
}

void inorder(node* t){
    if(t == NULL){
        return;
    }
    inorder(t->left);
    cout << t->val << endl;
    inorder(t->right);
}

void postorder(node* t){
    if(t == NULL){
        return;
    }
    inorder(t->left);
    inorder(t->right);
    cout << t->val << " ";
}

int main(){

    tree t(1);

    t.insert(12);
    t.insert(10);

    node* treeRoot = new node;
    treeRoot = t.gethead();

    cout << "Pre-Order Traversal" << endl;
    preorder(treeRoot);
    cout << endl << endl;
    
    cout << "In-Order Traversal:" << endl;
    inorder(treeRoot);
    cout << endl << endl;

    cout << "Post-Order Traversal:" << endl;
    postorder(treeRoot);
    cout << endl << endl;

}