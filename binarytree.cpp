#include <iostream>
#include <string>
using namespace std;

class treenode {
    int data;
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree {
    treenode *root;

public:
    tree();
    void create_nr();
    void create_nr(treenode* );
    void inorder_r();
    void inorder_r(treenode* temp);
    void preorder_r();
    void preorder_r(treenode* temp);
    void postorder_r();
    void postorder_r(treenode* temp);
};

tree::tree(){
    root = NULL;
}

void tree::create_nr(){
    if (root == NULL){
        root = new treenode();
        int data;
        cout << "Enter data of root node: ";
        cin >> data;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    char choice = 'y';
    do {
        treenode* temp = root;
        int flag = 0;
        treenode* curr = new treenode();
        int data;
        cout << "Enter data of node: ";
        cin >> data;
        curr->data = data;
        curr->left = NULL;
        curr->right = NULL;
        while(flag == 0){
            char c;
            cout << "Enter node to left or right? (l/r): ";
            cin >> c;
            if (c == 'l'){
                if (temp->left == NULL){
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }else{
                if (temp->right == NULL){
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }
        cout << "Add more nodes? (y/n): ";
        cin >> choice;
    } while(choice == 'y');
}

void tree::inorder_r() {
inorder_r(root);
}
void tree::inorder_r(treenode* temp){
    if (temp != NULL){
        inorder_r(temp->left);
        cout << temp->data << " ";
        inorder_r(temp->right);
    }
}

void tree::preorder_r(){
    preorder_r(root);
}

void tree::preorder_r(treenode* temp){
    if (temp != NULL){
        cout << temp->data << " ";
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void tree::postorder_r(){
    postorder_r(root);
}

void tree::postorder_r(treenode* temp){
    if (temp != NULL){
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout << temp->data << " ";
    }
}


int main() {
    tree bt;
    bt.create_nr();
    cout << "\n";
    int ch;
    cout  << "1. Inorder" << endl;
    cout  << "2. Preorder" << endl;
    cout  << "3. Postorder" << endl;
    cout  << "0. Exit" << endl;
    cin >> ch;
    do{
    switch(ch) {
    case 1:
   cout << "\nInorder traversal: \n";
   bt.inorder_r();
case 2:
   cout << "\nPreorder traversal: \n";
   bt.preorder_r();
 
case 3:
   cout << "\nPostorder traversal: \n";
   bt.postorder_r();
 
case 0:
   cout << "\nExiting" << endl;
   break;
default:
cout <<"\nWrong input" << endl;
break;
}
} while(ch == 0);
   
    return 0;
}
