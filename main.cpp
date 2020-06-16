
#include <iostream>

using namespace std;

template <typename T>

struct node
{
    T data;
    node* next;

};

template <typename T>

class linked_list
{
private:
    node<T> *head , *tail;

public:
    linked_list()
    {
        head = tail = NULL;
    }

    void insert(T element) //insert function
    {
        node<T> *newNode = new node<T>;
        newNode->data = element;
        if (head == NULL) //insert head if the linked list is empty
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode; //insert tail
            newNode->next = NULL;
            tail = newNode;
        }

    }

    node<int> * getHead() //get the head of the linked list
    {
        return head;
    }

    static void concatenate(node<T> *aHead, node<T> *bHead)
    {

        node<T> *current = aHead;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = bHead;
    }


    static void printLL(node<T> *h) //display all the elements by given the head of the linked list
    {
        node<T> *Current = h;

        while(Current != NULL)
        {
            cout<<Current->data<<" ";
            Current = Current->next;
        }
        cout<<endl;
    }

    void deletePos(int pos)
    {
        node<T> *check = head;
        int checkTimes = 0;
        while (check != NULL) //to check if the position is in the length
        {
            check = check->next;
            checkTimes++;
        }
        if(pos < 0 || pos > checkTimes-1) // error if the position is less than 0 or grater than the length of the linked list
        {
            cout<<"Deletion out of bound !"<<endl;
        }
        else if(pos == 0) //if the position is the head of the linked list
        {
            if(head == NULL)
            {
                cout<<"Linked List is empty !"<<endl;
            }
            else if(head != NULL && head->next == NULL)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                node<T> *current = head;
                head = head->next;
                delete current;
            }
        }
        else
        {
            if(head == NULL)
            {
                cout<<"Linked List is empty !"<<endl;
            }
            node<T> *Curr = head->next;
            node<T> *Prev = head;
            for(int i = 1 ; i < pos ; i++)
            {
                Curr = Curr->next;
                Prev = Prev->next;
            }
            Prev->next = Curr->next;
            delete Curr;
        }
    }


    void deleteVal(T element)
    {
        node<T> *Current;
        node<T> *Previous;
        node<T>*Cur = head;
        int check = 0; // variable to check if the element is in the linked list or not
        while(Cur != NULL)
        {
            if(Cur->data == element)
            {
                check++;
                break;
            }
            Cur = Cur->next;
        }
        if(head == NULL) //check if linked list is empty
        {
            cout<<"Linked List is empty! "<<endl;
        }
        else if(check == 0) //check if the element is not found to break the function
        {
            return;
        }
        else if(head->data == element) // check if the element is the head of the linked list
        {
            Current = head;
            head = head->next;
            delete Current;
            if(head == NULL)
            {
                tail = NULL;
            }
        }
        else
        {
            Current = head->next;
            Previous = head;
            while (Current != NULL)
            {
                if(Current->data == element)
                {
                    break;
                }
                Previous = Current;
                Current = Current->next;
            }
            Previous->next = Current->next;
            if(tail == Current)
            {
                tail = Previous;
            }
            delete Current;

        }
    }

    void insertPos(T element , int pos)
    {
        node<T> *newNode = new node<T>;
        newNode->data = element;
        node<T> *check = head; // variable to check if the position is in the length
        int checkTimes = 0;
        while (check != NULL)
        {
            check = check->next;
            checkTimes++;
        }
        if(pos < 0 || pos > checkTimes -1) // error if the position is less than 0 or grater than the length of the linked list
        {
            cout<<"Insertion out of bound !"<<endl;
        }
        else if (pos == 0) //if the position is the head of the linked list
        {
            newNode->next = head;
            head = newNode;

        }
        else
        {
            node<T> *Cur = head;
            for (int i = 1; i < pos; i++)
            {
                Cur = Cur->next;
            }
            newNode->next = Cur->next;
            Cur->next = newNode;
        }
    }
};



int main()
{
    linked_list<int> firstLL;
    firstLL.insert(1);
    firstLL.insert(20);

    linked_list<int> secondLL;
    secondLL.insert(3);
    secondLL.insert(4);

    linked_list<int>::concatenate(firstLL.getHead(), secondLL.getHead());

    cout<<"--"<<endl;

    linked_list<int>::printLL(firstLL.getHead());
    firstLL.deletePos(1);
    cout<<"--"<<endl;

    linked_list<int>::printLL(firstLL.getHead());

    firstLL.deleteVal(20);
    cout<<"--"<<endl;

    linked_list<int>::printLL(firstLL.getHead());

    firstLL.insertPos(30, 1);
    cout<<"--"<<endl;
    linked_list<int>::printLL(firstLL.getHead());

    firstLL.deletePos(10);
    firstLL.insertPos(40 ,11);



    return 0;
}
