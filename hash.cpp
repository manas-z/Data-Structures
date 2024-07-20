#include <iostream>

using namespace std;

class student{
    public:
    int rollno;
    string name;
    char grade;
};

class hash{
    int hashtable[10];
    public:
    hash(){
        for(int i=0; i<10; i++){
            hashtable[i] = -1;
        }
    }
    
};

 int insert_linearprob(int hashtable[],int key){
  int loc = key%10;
    if(hashtable[loc] == -1){
        hashtable[loc] = key;
        return loc;
    }
    else{
        int i = (loc+1)%10;
        while(i != loc){
            if(hashtable[i] == -1){
                hashtable[i] = key;
                return i;
            }
            i = (i+1)%10;
        }
        if(i = loc)
            cout << "Hash table is full";
    }
}

int main(){
    int n;
    student s;
    int hashtable[10];
    cout << "Enter the number of students: ";
    cin >> n;
    for(int i = 0 ; i < n; i ++ ){
        cout << "Enter the roll number: ";
        cin >> s.rollno;
        cout << "Enter name of student: ";
        cin >> s.name;
        cout << "Enter the grade: ";
        cin >> s.grade;
    }
    insert_linearprob(hashtable, s.rollno);
}
