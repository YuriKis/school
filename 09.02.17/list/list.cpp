// Example program
#include <iostream>
#include <string>
#include <map>
using namespace std;

template<class T>
class List
{
private:
    struct Node
    {
        Node():next(0), data(0) {}
        Node* next;
        T data;
    };

    Node* head;
    Node* tail;
public:
    size_t leng;
    List():head(0), tail(0),leng(0) {}
    ~List() {
        while(head) {
            tail=head->next;
            delete head;
            head=tail;
        }
    }

    void push_back(T val) {
        Node* Temp;
        Temp=new Node;
        Temp->data=val;
        if(head==0) {
            head=Temp;
            tail=Temp;
            return;
        }
        tail->next=Temp;
        tail=Temp;leng++;
    }

    void push_front(T val){
    Node* Temp;
    Temp=new Node;
    Temp->data=val;
    Temp->next=head;
    head=Temp;leng++;
}

    void print() {
        if(head==0) {
            throw -2;
        }
        for(Node* ptr=head; ptr!=0; ptr=ptr->next)
        {
            std::cout<<ptr->data<<' ';
        }
        std::cout<<'\n';
    }

    void erase() {
        if(head==0) { throw -2; }
        Node* delptr=head->next;
        head=head->next;
        delete delptr;leng--;
    }

    void erase(T val) {
        Node* ptrPrev;
        ptrPrev=new Node;
        if(head==0) { throw -2; }
        for(Node* ptr=head; ptr!=0; ptr=ptr->next) {
            if(ptr->data==val) {
                ptrPrev->next=ptr->next;
                delete ptr;
                leng--;
                break;
            }
            ptrPrev=ptr;
        }
        if(ptrPrev->next==0)
            std::cout<<"There are no dataents in list equal to "<< val <<'\n';
    }

    void clear() {
        while(head!=0)
            erase();
    }

    bool find(T val) {
        if(head==0) {
            throw -2;
        }
        for(Node* ptr=head; ptr!=0; ptr=ptr->next) {
            if(ptr->data==val)
            return 1;
        }
        return 0;
    }

    void set(T val, size_t i){
        if(head==0) { throw -2; }
        size_t j = 0;
        for(Node* ptr=head; ptr!=0; ptr=ptr->next) {
            j++;
            if(j==i)
                ptr->data = val;
        }
    }
    T get(size_t val)const {
        if(head==0) { throw -2; }
        size_t i = 0;
        for(Node* ptr=head; ptr!=0; ptr=ptr->next) {
            i++;
            if(i==val)
                return ptr->data;
        }
    }
    T operator[](size_t index){
        return get(index);
    }
    const T& operator[](size_t index) const{
        return get(index);
    }//*/
};
int main()
{
    List<int> Lst;
    Lst.push_back(5);
    Lst.push_back(10);
    Lst.push_back(15);
    Lst.push_front(1);
    Lst.push_front(25);
    Lst.push_back(4);
    Lst.set(9);
    Lst.set(6);
    Lst.set(4);
    Lst.set(5);
    Lst.set(55);
    Lst.set(40);
    Lst.set(0);
    Lst.set(70);
    Lst.set(56);
    Lst.erase(5);
    try
    {
        Lst.print();
    }
    catch(const std::string& e)
    {
        std::cout<<e<<'\n';
    }
    return 0;
}
