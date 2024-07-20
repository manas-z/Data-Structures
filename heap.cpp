#include <iostream>

using namespace std;

class heap{
    int marks[10];
    public:
        void accept(int n);
        void display(int n);
        void heapsort(int n);
        void adjust(int n, int i);
};

void heap::accept(int n){
    cout << "Enter the marks of " << n << " students: ";
    for(int i = 0; i < n; i++){
        cin >> marks[i];
    }
}

void heap::display(int n){
    cout << "\nThe marks are: ";
    for(int i = 0; i < n; i++){
        cout << endl << marks[i] << " ";
    }
    cout << endl;
    cout << "Minimum marks: "<< marks[0] << endl;
    cout << "Maximum marks: "<< marks[n-1] << endl;
}

void heap::adjust(int n, int i){
    while(2 * i + 1 <= n){
        int j = 2 * i + 1;
        if(j + 1 <= n && marks[j] < marks[j + 1]){
            j = j + 1;
        }
        if(marks[i] < marks[j]){
            int temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
            i = j;
        }
        else{
            break;
        }
    }
}

void heap::heapsort(int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        adjust(n-1, i);
    }
    cout<<"\n Heap : \n";
    for(int i = 0; i < n; i++){
        cout << marks[i] << endl;
    }
    for(int i = n - 1; i > 0; i--){
        int temp = marks[0];
        marks[0] = marks[i];
        marks[i] = temp;
        adjust(i - 1, 0);
    }
}



int main(){
    heap h;
    int choice;
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    do {
        cout << "Enter your choice:\n";
        cout << "1. Accept marks\n";
        cout << "2. Display marks\n";
        cout << "3. Sort marks\n";
        cout << "4. Exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                h.accept(n);
                break;
            case 2:
                h.display(n);
                break;
            case 3:
                h.heapsort(n);
                h.display(n);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);
}
    
    