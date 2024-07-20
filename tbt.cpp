#include <iostream>

using namespace std;

class tbtnode{
    char data;
    bool rbit;
    bool lbit;
    tbtnode *leftc;
    tbtnode *rightc;
    friend class tbt;
    public:
        tbtnode();
};

class tbt {
tbtnode *head;
public:
void create();
void preorder();
void inorder();
tbtnode* insuccr(tbtnode *temp);
tbt();
};

tbt::tbt() {
    head = new tbtnode;
    head->rbit = 1;
    head->leftc = head;
    head->rightc = head;
}
tbtnode::tbtnode(){
    lbit = 0 ;
    rbit = 0 ;
}

void tbt::create() {
    char ch;
    tbtnode *root = new tbtnode;
    cout << "Enter data for root: ";
    cin >> root->data;
    head->lbit = 1;
    head->leftc = root;
    root->leftc = head;
    root->rightc = head;
    int flag = 0;
    do {
        flag = 0;
        tbtnode *curr = new tbtnode;
        tbtnode *temp = root;
        cout << "Enter data for new node: ";
        cin >> curr->data;
        while(flag == 0){
        char choice;
        cout << "Enter choice (l/r) for left or right: ";
        cin >> choice;
        if (choice == 'l') {
            if (temp->lbit == 0) {
                curr->rightc = temp;
                curr->leftc = temp->leftc;
                temp->leftc = curr;
                temp->lbit = 1;
                flag = 1;
            } 
            else {
                temp = temp->leftc;
            }
        } 
        if (choice == 'r') {
            if (temp->rbit == 0) {
                curr->leftc = temp;
                curr->rightc = temp->rightc;
                temp->rightc = curr;
                temp->rbit = 1;
                flag = 1;
            } 
            else {
                temp = temp->rightc;
            }
        }
    }
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void tbt::inorder() {
    tbtnode *temp = head;
    while (1) {
        temp = insuccr(temp);
        if (temp == head) break;
        cout << temp->data << " ";
    }
}

tbtnode* tbt::insuccr(tbtnode *temp) {
    tbtnode *x = temp->rightc;
    if (temp->rbit == 1)
     {
        while (x->lbit == 1)
            x = x->leftc;
    }
    return x;
}

void tbt::preorder() {
    tbtnode *temp = head->leftc;
    while (temp != head) {
        cout << temp->data << " ";
        while (temp->lbit != 0) {
            temp = temp->leftc;
            cout << temp->data << " ";
        }
        while (temp->rbit == 0) {
            temp = temp->rightc;
        }
        temp = temp->rightc;
    }
}

int main() {
    tbt tree;
    int choice;

    do { 
        cout << endl;
        cout << "\n1. Create Threaded Binary Tree" << endl;
        cout << "2. Inorder" << endl;
        cout << "3. Preorder" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.create();
                break;
            case 2:
                tree.inorder();
                break;
            case 3:
                tree.preorder();
                break;
        }
    } while (choice != 4);

    return 0;
}
