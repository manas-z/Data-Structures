/*A business house has several offices in different countries; they want to lease phone lines
to connect them with each other and the phone company charges different rent to connect different
pairs of cities.(Create and display of Graph). Solve the problem using Prim's Algorithm*/

#include <iostream>

using namespace std;

class graph{
    int cost[10][10];
    int tcities;
    public:
        graph();
        void create();
        void display();
        void prims();
};
graph::graph(){
    tcities = 0;
    cout << "\nEnter the number of cities: ";
    cin >> tcities;
    for(int i = 0; i < tcities; i++){
        for(int j = 0; j < tcities; j++){
            cost[i][j] = 999;
        }
    }   
}

void graph::create(){
    char ch;
    for(int i = 0;i<tcities;i++){
        for(int j = i+1;j<tcities;j++){
            cout << "Is there a connection between city " << i << " and city " << j << " (y/n): ";
            cin >> ch;
            if(ch == 'y'){
                cout << "Enter the cost of the edge "<<i<<" "<<j<<": ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }
}

void graph::display(){
    for(int i = 0; i < tcities; i++){
        for(int j = 0; j < tcities; j++){
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}

void graph::prims(){
    int nearest[10];
    int t[10][2];
    int r = 0;
    int mincost = 0;
    int start_v = 0;
    int j;
    cout << "\nEnter the starting vertex: ";
    cin >> start_v; 
    
    nearest[start_v] = -1;
    for(int i = 0; i < tcities; i++){
        if(i != start_v){
            nearest[i] = start_v;
        }
    }

    for(int i = 1; i < tcities; i++){
        int min = 999;
        
        for(int k = 0; k < tcities; k++){
            if(nearest[k] != -1 && cost[k][nearest[k]] < min){
                j = k;
                min = cost[k][nearest[k]];
            }
        }

        
        t[r][0] = j;
        t[r][1] = nearest[j];
        r = r + 1;
        mincost = mincost + cost[j][nearest[j]];
        nearest[j] = -1;

       
        for(int k = 0; k < tcities; k++){
            if(nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j]){
                nearest[k] = j;
            }
        }
        
    }
    
    cout << "\nMinimal spanning tree: " << endl;
    for(int i = 0; i < r; i++){
        cout << t[i][0] << " - " << t[i][1] << endl;
    }
    cout << "Minimum Cost: "<<mincost;
}
int main(){
    graph g;
    char ch;
    
    do{
        cout << "Operations:";
        cout <<"\nWhat operations would you like to perform: ";
        cout << "\n1.Create Graph"; 
        cout << "\n2.Display Graph";
        cout << "\n3.Prim's Algorithm";
        cout << "\n4.Exit\n";
        int choice;
        cin >> choice;
        
        switch(choice){
            case 1: g.create();
                    break;
            case 2: g.display();
                    break;
             case 3: g.prims();
                    break;
            case 4: exit(0);
                    break;
            default: cout << "Invalid choice";
        }
        cout << "\nDo you want to continue(y/n): ";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}