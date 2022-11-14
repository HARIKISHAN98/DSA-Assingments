#include<iostream>
using namespace std;

struct node
{
  node *prev;
  int item;
  node *next;
};

class DLL
{
    private :
    node *start;

    public :

    DLL();
    void insert_at_first(int);
    void insert_at_end(int);
    node* search(int);
    void insert_after(node *,int);
    void show_list();
    void delete_first();
    void delete_last();
    void delete_specific(node *);
    ~DLL();
};

DLL :: DLL()
{
    start = NULL;
}

void DLL :: insert_at_first(int data)
{
    node *n = new node ;
    n->item = data;
    n->prev = NULL;
    n->next = start;

    if(start != NULL)
    start->prev = n;

    start = n;
}

void DLL :: insert_at_end(int data)
{
    node *n = new node ;
    n->item = data;
    n->next = NULL;

    if(start == NULL)
    {
        n->prev = start;
        start = n;
    }

    else
    {
        node *temp = start;
        
        while(temp->next != NULL )
        temp = temp->next;

        n->prev = temp;
        temp->next = n;
    }

}

node* DLL :: search(int data)
{
    node *temp = start;

    while(temp != NULL)
    {
        if(temp->item == data)
        return temp;

        temp = temp->next;
    }
    return temp;
}

void DLL :: insert_after(node *ptr,int data)
{
    node *n = new node;
    n->item = data;
    n->prev = ptr;

    if(ptr == NULL)
    {
        n->next = ptr;
        start = n;
    }

    else
    {
        n->next = ptr->next;

        if(ptr->next != NULL)
        {
            (ptr->next)->prev = n;
        }

        ptr->next = n;
    }
}

void DLL :: show_list()
{
    node *temp = start;

    while(temp != NULL)
    {
        cout<<temp->item <<" ";
        temp = temp->next ;
    }
    cout<<endl;
}

void DLL :: delete_first()
{
    if(start == NULL)
    cout<<"Underflow"<<endl;

    else if(start->next == NULL)
    {
        delete start;
        start = NULL;
    }

    else
    {
       start = start->next;
       delete start->prev;
       start->prev = NULL;
    }
}

void DLL :: delete_last()
{
    if(start == NULL)
    cout<<"Underflow"<<endl;

    else if(start->next == NULL)
    {
      delete start;
      start = NULL;
    }

    else
    {
        node *temp = start;
        while((temp->next)->next != NULL)
        temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }
}

void DLL :: delete_specific(node *ptr)
{
    if(ptr == NULL)
    {
    if(start == NULL )    
    cout<<"Underflow"<<endl;

    else
    cout<<"Address ,out of bound"<<endl;

    }

    else if(ptr == start)
    {
        if(ptr->next == NULL)
        {
            delete ptr;
            start = NULL;
        }

        else
        {
            start = start->next;
            delete start->prev;
            start->prev = NULL;
        }
    }

    else
    {
        (ptr->prev)->next = ptr->next;
        delete ptr;
    }
}

DLL :: ~DLL()
{
    while(start)
    delete_first();

    // cout<<"Deallocation sucessfull"<<endl;
}

