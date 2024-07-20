#include <iostream>
#include <string.h>
using namespace std;

class node
{
    string keyword, meaning;
    node *left;
    node *right;
    friend class tree;
};

class queue
{
    int front, rear;
    node *data[30];

    public :
    queue();
    void enqueue(node *);
    node* dequeue();
    int empty();
    friend class tree;
};

queue :: queue()
{
    front = rear = -1;
}

void queue:: enqueue(node *temp)
{
    rear++;
    data[rear] = temp;
}

node* queue::dequeue()
{
    front++;
    return (data[front]);
}

int queue::empty()
{
    if(front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


class tree
{
    node *root;

public :
    tree();
    void create_nr();
    void inorder_r();
    void inorder_r(node *temp);
    void copy_r();
    node* copy_r(node *);
    void breadth_first();
    void delete_nr();
    void mirror_r();
    void mirror_r(node *);
    void mirror_nr();
};

tree::tree()
{
    root = NULL;
}

void tree::create_nr() 
{

    int flag;
    node *temp;
    string choice;
     
    if(root == NULL)
    {
     	root = new node;
     	cout<<"\nEnter root keyword : ";
     	cin>>root->keyword;
     	cout<<"\nEnter meaning : ";
        cin>>root->meaning;
    }

    do
    {
        node*temp = root;
        flag = 0;

        node *curr = new node();
		cout<<"\nEnter new keyword : ";
     	cin>>curr->keyword;
     	cout<<"\nEnter meaning : ";
     	cin>>curr->meaning;
        curr->left = NULL;
        curr->right = NULL;

        while (flag == 0) 
        {
            if (curr->keyword < temp->keyword)  
            {
                if (temp->left == NULL) 
                {
                    temp->left = curr;
                    flag = 1;
                } 
                else 
                {
                    temp = temp->left;
                }
            } 
            else if (curr->keyword > temp->keyword)
            {
                if (temp->right == NULL) 
                {
                    temp->right = curr;
                    flag = 1;
                } 
                else 
                {
                    temp = temp->right;
                }
            }
        }

        cout << "Do you want to add more nodes?: ";
        cin >> choice;

    } while (choice == "y");
}


void tree:: inorder_r()
{
		inorder_r(root);
}

void tree::inorder_r(node *temp) {
    if (temp != NULL) 
    {
        inorder_r(temp->left);
        cout << "Keyword: " << temp->keyword << ", Meaning: " << temp->meaning << endl;
        inorder_r(temp->right);
    }
}

void tree:: copy_r()
{
    cout<<"\nOriginal Binary Search Tree : \n";
    inorder_r(root);
    node *root2;    
    root2 = copy_r(root);
    cout<<"\nCopied \n";
    cout<<"\nCopied Binary Search Tree : \n";
    inorder_r(root2);
}

node* tree::copy_r(node *root)
{
    node *temp = NULL;
    if(root != NULL)
    {
        temp = new node;
        temp->keyword = root->keyword;
        temp->meaning = root->meaning;
        temp->left = copy_r(root->left);
        temp->right = copy_r(root->right);
    }
    return temp;

}

void tree :: breadth_first()
{
    node *temp;
    queue q;
    if(root == NULL)
    {
        cout<<"Binary Search Tree Empty";
    }

    else
    {
        int p = 1, r = 0;
        temp = root;
        q.enqueue(temp);
        while(!q.empty())
        {
            for(int i = 0; i<p; i++)
            {
                temp = q.dequeue();
      
                cout<<temp->keyword<<":\t"<<temp->meaning<<"\t \t";
                if(temp->left!=NULL)
                {
                    q.enqueue(temp->left);
                    r++;
                }
                if(temp->right!=NULL)
                {
                    q.enqueue(temp->right);
                    r++;
                }
            }
            cout<<endl;
            p = r;
            r = 0;
        }
    }
}

void tree:: mirror_nr()
{
    node *temp, *temp1;
    queue q;
    temp = root;
    q.enqueue(temp);
	while(!q.empty())
	{
		temp = q.dequeue();
		temp1 = temp->left;
		temp->left = temp->right;
		temp->right = temp1;
		if(temp->left!=NULL)
		{
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.enqueue(temp->right);
		}
	}
	cout<<"\nNon-recursive mirror:"<<endl;
	breadth_first();
}

void tree:: mirror_r()
{
	mirror_r(root);
	cout<<"\nRecursive mirror:"<<endl;
	breadth_first();
}

void tree:: mirror_r(node*temp)
{
	node *temp2;
	if(temp!=NULL)
    {
	temp2 = temp->left;
	temp->left = temp->right;
	temp->right = temp2;
	if(root->left!= NULL)
	{
		mirror_r(temp->left);
	}
	if(root->right!= NULL)
	{
		mirror_r(temp->right);
	}
	}
}


void tree::delete_nr()
{
    int flag = 0;
    string key;
    node *temp, *parent, *curr, *s;
    cout << "\nEnter keyword to be deleted:";
    cin >> key;
    curr = root;
    while (curr != NULL)
    {
        if (curr->keyword == key)
        {
            flag = 1;
            break;
        }
        else if (key > curr->keyword)
        {
            parent = curr;
            curr = curr->right;
        }
        else
        {
            parent = curr;
            curr = curr->left;
        }
    }
    if (flag == 1)
    {
        if (curr == root) // deletion of root
        {
            if (curr->right == NULL)
                root = curr->left;
            else if (curr->left == NULL)
                root = curr->right;
            else if (curr->right != NULL && curr->left != NULL)
            {
                temp = curr->left;
                root = curr->right;
                s = curr->right;
                while (s->left != NULL)
                {
                    s = s->left;
                }
                s->left = temp;
            }
        }
        else if (curr != root) // deletion of node which is not root
        {
            if (curr->left == NULL && curr->right == NULL) // deletion of a leaf
            {
                if (parent->left == curr)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else if (curr->left == NULL) // deletion of a single child
            {
                if (parent->left == curr)
                    parent->left = curr->right;
                else
                    parent->right = curr->right;
            }
            else if (curr->right == NULL) // deletion of a single child
            {
                if (parent->left == curr)
                    parent->left = curr->left;
                else
                    parent->right = curr->left;
            }
            else // deletion of a node having two child
            {
                s = curr->right;
                temp = curr->left;
                while (s->left != NULL)
                {
                    s = s->left;
                }
                s->left = temp;
                if (parent->left == curr)
                    parent->left = curr->right;
                else
                    parent->right = curr->right;
            }
        }
    }
    curr->left = NULL;
    curr->right = NULL;
    delete curr;
}



int main() {
    tree bt;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Create Binary Search Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Copy\n";
        cout << "4. Breadth First Traversal\n";
        cout << "5. Mirror(NR)\n";
        cout << "6. Mirror(R)\n";
        cout << "7. Delete \n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bt.create_nr();
                break;
            case 2:
                cout << "\nInorder\n";
                bt.inorder_r();
                break;
            case 3:
                bt.copy_r();
                break;
            case 4:
                cout << "\nBreadth First Traversal\n";
                bt.breadth_first();
                break;
            case 5:
                bt.mirror_nr();
                break;
            case 6:
                bt.mirror_r();
                break;
            case 7:
                bt.delete_nr();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}