#include <iostream>

using namespace std;

class gnode
{
    int id;
    string username;
    gnode *next;
public:
    gnode(){
        id = 0;
        username = "\0";
        next = NULL;
    }
    friend class graph;
};

class graph{
    int n;
    gnode *head[10];
    public:
    graph(){
        n = 0;
        cout << "Enter the number of nodes: ";
        cin >> n;
        for(int i=0; i<n; i++){
            head[i] = new gnode;
            head[i]->id = i;
            cout << "Enter the username for node " << i << ": ";
            cin >> head[i]->username;
        }
    }
        void create();
        void display();
        void dfs_r();
        void dfs_r(int,int *);
        void dfs_nr();
        void bfs_nr();

        
};



void graph::create()
{   
    char ch;
    int v;
    for (int i = 0; i < n; i++){
        gnode *temp = head[i];
        do{
            cout << "Enter adjacent vertex for node " << i << ": ";
            cin >> v;
            if (v == i){
                cout << "Self loops are not allowed." << endl;
            }
            else{
                gnode *curr = new gnode;
                curr->id = v;
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Enter y to continue ";
            cin >> ch;
        } while (ch == 'y');
    }   
}

void graph::display(){
    gnode *temp;
    for(int i = 0; i < n; i++){
        temp = head[i];
        while(temp != NULL){
            cout<< temp->username << "\t"<<temp->id<<"\n";
            temp = temp->next;
        }
        cout << endl;
    }
}

void graph::dfs_r(){
    int visited[10],v;
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    cout<<"\n Enter starting vertex: ";
    cin >> v;
    dfs_r(v, visited);
}

void graph::dfs_r(int v, int visited[10]){
    cout << head[v]->username<<"\t";
    visited[v] = 1;
    gnode *temp = head[v]->next;
    while(temp != NULL){
        if(!visited[temp->id]){
            dfs_r(temp->id, visited);
        }
        temp = temp->next;
    } 
}

class stackt{
    int top;
    int stck[20];
    public:
        stackt(){
            top = -1;
        }
        void push(int);
        int pop();
        bool isfull();
        bool isempty();
        friend class graph;
};
bool stackt::isfull()
{
	if (top == 19 )
		return true;
	else 
		return false;
}

bool stackt::isempty()
{
	if (top == -1)
		return 1;
	else 
		return 0;
}

void stackt::push(int n)
{
    if(!isfull())
    {
        top = top+1;
        stck[top]=n;
    }
    else
        cout << "Stack is Full\n";
}

int stackt::pop()
{
	int temp;
	if(!isempty())
	{
		temp=stck[top];
		top = top - 1;
		return (temp);
	}
	else {
        cout << "Stack is empty\n";
        return 0;
    }
}

void graph::dfs_nr(){
    int visited[10];
    int v;
     stackt s;
    cout<<"\n Enter starting vertex: ";
    cin >> v;
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
   
    s.push(v);
    visited[v] = 1;
    do{
        v=s.pop();
        cout << head[v]->username << "\t";
        gnode *temp = head[v]->next;
        while(temp != NULL){
            if(!visited[temp->id]){
                s.push(temp->id);
                visited[temp->id] = 1;
            }
            temp = temp->next;
        }
    }while(!s.isempty());

}
    
class queue
{
    int front, rear;
    int q[20];

    public :
    queue(){
        front = rear = -1;
    };
    void enqueue(int temp);
    int dequeue();
    int empty();
    friend class graph;
};

void queue:: enqueue(int temp)
{
    rear++;
    q[rear] = temp;
}

int queue::dequeue()
{
    front++;
    return(q[front]);
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
void graph::bfs_nr(){
    int visited[10];
    int v;
    gnode *temp;
    queue q;
    cout<<"\n Enter starting vertex: ";
    cin >> v;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    q.enqueue(v);
    visited[v]=1;
    while(!q.empty()){
        v = q.dequeue();
        cout << v << "\t";
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                q.enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    graph g;
    int choice;
    int ch;
    int v;
    stackt s;
    
    do{
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Depth First Traversal"<<endl;
        cout << "4. Depth First Traversal Non recursive version"<<endl;
        cout <<" 5. Breadth First Traversal"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
    switch(choice){
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.dfs_r();
            break;
        case 4:
            g.dfs_nr();
            break;
        case 5:
            g.bfs_nr();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    cout << "\nDo want to continue? (1/0): ";
    cin >> ch;
    }while(ch == 1);
    return 0;
}