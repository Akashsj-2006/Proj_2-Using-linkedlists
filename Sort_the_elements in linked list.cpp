#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data= val;
        next = nullptr;
    }
};
class Linkedlist
{
    Node *head;
public:
    void insert_e(int val)
    {
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void sort_e()
    {
        if(head==NULL)
        {
            cout<<"\nNo elements are there";
            return;
        }
        bool swapped;
        do
        {
            swapped=false;
            Node *current=head;
            while(current->next)
            {
                if(current->data > current->next->data)
                  {
                      swap(current->data,current->next->data);
                      swapped=true;
                   }
                   current=current->next;
            }
        }while(swapped );
    }
    void display() const {
        Node *temp = head;
        while (temp!=nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main() {
    Linkedlist list;
    int num;

    cout << "Enter the number of terms: ";
    cin >> num;

    for (int i = 1; i <= num; i++) {
        int value;
        cout << "Enter number " << i << ": ";
        cin >> value;
        list.insert_e(value);
    }

    cout << "Original list: ";
    list.display();

    list.sort_e();

    cout << "Sorted list: ";
    list.display();

    return 0;
}
