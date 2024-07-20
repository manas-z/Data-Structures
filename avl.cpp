
#include<iostream>
using namespace std;

class avl{
    int key;
    avl *right;
    avl *left;
    int height;
    friend class atree;
};

class atree{
    public:
    avl* root;
    atree();
    int height(avl*);
    int max(int,int);
    avl* rightrotate(avl*);
    avl* leftrotate(avl*);
    int balancefactor(avl *);
    avl* insert(avl*,int);
    avl* balance(avl*,int);
    void inorder(avl*);
    void preorder(avl*);
    void postorder(avl*);
};

atree::atree(){
    root = NULL;
}

int atree::height(avl *node){
    if(node == NULL)
        return 0;
    return node->height;
}

int atree::max(int a,int b){
    return (a>b)?a:b;
}

avl* atree::rightrotate(avl* node){
    avl* x = node->left;
    avl* y = x->right;
    x->right = node;
    node->left = y;
    node->height = max(height(node->left),height(node->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

avl* atree::leftrotate(avl* node){
    avl* x = node->right;
    avl* y = x->left;
    x->left = node;
    node->right = y;
    node->height = max(height(node->left),height(node->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

int atree::balancefactor(avl* node){
    if(node == NULL)
        return 0;
    return (height(node->left)-height(node->right));
}

avl* atree::insert(avl* node,int key){
    if(node == NULL){
        avl* temp = new avl();
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    }
    if(key <= node->key){
        node->left = insert(node->left,key);
    }
    else if(key > node->key){
        node->right = insert(node->right,key);
    }
    node->height = 1+max(height(node->left),height(node->right));
    return node;
}

avl* atree::balance(avl* node,int key){
    int balance = balancefactor(node);
    if(balance > 1 && key < node->left->key){
        return rightrotate(node);
    }
    if(balance < -1 && key > node->right->key){
        return leftrotate(node);
    }
    if(balance > 1 && key > node->left->key){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance < -1 && key < node->right->key){
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}

void atree::inorder(avl* node){
    if(node != NULL){   
        inorder(node->left);
        cout<<node->key<<" ";
        inorder(node->right);
    }
}

void atree::preorder(avl* node){
    if(node!= NULL){
        cout<<node->key<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

void atree::postorder(avl* node){
    if(node != NULL){   
        postorder(node->left);
        postorder(node->right);
        cout<<node->key<<" ";
    }
}

int main(){
    atree a;
    int ch;
    do{
        int key;
        cout<<"\nEnter key : ";
        cin>>key;
        a.root = a.insert(a.root,key);
        a.root = a.balance(a.root,key);
        cout<<"\nEnter 0 to exit and any other number to continue : ";
        cin>>ch;
    }while(ch!=0);
    cout<<"\n Inorder :";
    a.inorder(a.root);
    cout<<"\n Preorder : ";
    a.preorder(a.root);
    cout<<"\n Postorder : ";
    a.postorder(a.root);
}
