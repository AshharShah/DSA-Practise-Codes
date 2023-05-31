#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

class list{
    private:
        node* head = new node;

    public:    
    list(int value){
        head->val = value;
        head->next = NULL;
    }

    node* getHead(){
        return head;
    }

    void insert(int v){

        node* newnode = new node;
        newnode->val = v;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
        }

        node* temp = new node;
        temp = getHead();

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newnode;
    }

    void print(){
        node* temp = new node;
        temp = getHead();

        cout << "Start Of List" << endl;

        while(temp != NULL){
            cout << temp->val << endl;
            temp = temp->next;
        }

        cout << "End Of List" << endl << endl;
    }

    node* kthLastElement(int k){
        node* fast = new node;
        node* slow = new node;

        fast = getHead();
        slow = getHead();

        for(int i = 0; i < k; i++){
            fast = fast->next;
        }

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main(){
    list linkedList(12);
    linkedList.insert(1);
    linkedList.insert(9);
    linkedList.insert(4);
    linkedList.insert(7);
    linkedList.insert(3);

    linkedList.print();

    node* kthLast = new node;

    kthLast = linkedList.kthLastElement(2);

    cout << "Kth Last Element: " << kthLast->val << endl;

    return 0;
}