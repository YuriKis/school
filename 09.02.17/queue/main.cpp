// Example program
#include <iostream>
#include <string>
#include <map>
using namespace std;

template<class T>
class Queue {
private:
    struct Node {
        Node():next(0), data(0) {}
        Node* next;
        T data;
    };
    Node* head;
    Node* tail;
public:
    Queue():tail(0), head(0) {}
    ~Queue() {
        while(head) {
            tail=head->next;
            delete head;
            head=tail;
        }
    }

    void push(T val) {
        Node* Temp=new Node;
        Temp->data=val;
        if(head==0)
        {
            head=Temp;
            tail=Temp;
            return;
        }
        tail->next=Temp;
        tail=Temp;
    }
    T pop() {
        Node* tmp=head;
        while (tmp->next->next != 0) tmp=tmp->next;
        int a = tmp->next->data;
        delete(tmp->next);//tmp->next=0;
        return a;
    }
    void print() {
        if(head==0) throw 0;
        for(Node* ptr=head; ptr!=0; ptr=ptr->next)
            std::cout<<ptr->data<<' ';
        std::cout<<'\n';
    }

};
int main() {
    map <string, int> commands;			//list of commands
    commands["Queue"]=1;
    commands["end"]=2;
    commands["push"]=3;
    commands["pop"]=4;
    commands["print"]=0;
    string s;
    Queue<int> A;					//creating an empty Queue
    // this zero will be popped in "Queue"-case of input

    do{						//command handler

        cin>>s;

        int tmp;

        switch ( commands[s] ){
            case 0:				// input "Queue" - creating the first dataent of Queue:
                // deleting tmporal zero from Queue
                cin>>tmp;		// and create first dataent from input
                A.print();
                break;
            case 1:				// input "Queue" - creating the first dataent of Queue:
                // deleting tmporal zero from Queue
                cin>>tmp;		// and create first dataent from input
                A.pop();
                A.push(tmp);
                break;

            case 2: 			// input - "end" - ending of inputting
                break;

            case 3:        			// input "push" - reading dataent for pushing to Queue from input
                cin>>tmp;
                A.push(tmp);
                break;

            case 4:   		     	// input "pop" - writing popped dataent to output
                cout<<A.pop()<<endl;
                break;
        }
    }
    while (s!="end");

    return 0;
}
