// Example program
#include <iostream>
#include <string>
#include <map>
using namespace std;

template<class T>
class Stack {
private:
    struct Node {
        Node():data(0), next(0) {}
        Node* next;
        T data;
    };
    Node* head;
    Node* tail;
public:
    Stack():tail(0), head(0) {}
    ~Stack() {
        while(head) {
            tail=head->next;
            delete head;
            head=tail;
        }
    }

    void push(T val) {
        Node* Temp;
        Temp=new Node;
        Temp->data=val;
        if(tail==0) {
            tail=Temp;
        } else {
            Temp->next=tail;
            tail=Temp;
        }
    }
    T pop() {
        if(tail==0) throw 0;
        Node* delptr=tail;
        tail=tail->next;
        delete delptr;
        return tail->data;
    }
    void print() {
        if(tail==0) throw 0;
        for(Node* ptr=tail; ptr!=0; ptr=ptr->next) {
            std::cout<<ptr->data<<' ';
        }
        std::cout<<'\n';
    }

};

int main()
{
    map <string, int> commands;			//list of commands
    commands["stack"]=1;
    commands["end"]=2;
    commands["push"]=3;
    commands["pop"]=4;
commands["print"]=0;
    string s;
    Stack<int> A;					//creating an empty stack
    // this zero will be popped in "stack"-case of input

    do{						//command handler

        cin>>s;

        int temp;

        switch ( commands[s] ){
            case 0:				// input "stack" - creating the first element of stack:
              // deleting temporal zero from stack
              cin>>temp;		// and create first element from input
              A.print();
              break;
            case 1:				// input "stack" - creating the first element of stack:
                // deleting temporal zero from stack
                cin>>temp;		// and create first element from input
                A.pop();
                A.push(temp);
                break;

            case 2: 			// input - "end" - ending of inputting
                break;

            case 3:        			// input "push" - reading element for pushing to stack from input
                cin>>temp;
                A.push(temp);
                break;

            case 4:   		     	// input "pop" - writing popped element to output
                cout<<A.pop()<<endl;
                break;
        }
    }
    while (s!="end");

    return 0;
}
