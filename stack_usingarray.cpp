#include<iostream>
#include<stack>
using namespace std ;

class Stack 
{
    int size , *arr , top ;

    //*arr array for stack. it is dynamically array of unfixed size
 public:
    void printStack(){
        if(top == -1){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printStack_bottom_up(){
        if(top == -1){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (bottom to top): ";
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
   
    Stack(){
        top = -1 ;
        size = 1000 ;
        arr = new int[size];

        //dynamiclly allocates memory for an array of integers of length 'size'.
    }
    void push(int x){
        top ++ ;
        arr[top] = x ;
    }

    int pop(){
        if(top == -1){
            return -1 ;
        }
        int x = arr[top] ;
        top -- ;
        return x ;
    }
    int getTop(){
        if(top == -1){
            return -1 ;
        }
        return arr[top] ;
    }
    int getSize(){
        return top + 1 ;
    }
};

int main(){
    Stack s ;
    s.push(25);
    s.push(05) ;
    s.push(2005) ;
    s.printStack();
    s.printStack_bottom_up();
    cout<<"top before deleting any element : "<<s.getTop()<<endl;
    cout<<"Size before deleion: "<<s.getSize()<<endl;
    cout<<"Element deleted is : "<<s.pop()<<endl;
    cout<<"top after deleting any element : "<<s.getTop()<<endl;
    cout<<"Size after deleion: "<<s.getSize()<<endl;
}