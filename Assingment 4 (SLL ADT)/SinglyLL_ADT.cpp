#include<iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class SLL
{
    private :
    node *start;

    public :

    SLL();
    void insert_at_start(int);
    void insert_at_last(int);
    node* search(int);
    void insert_after(node* ,int);
    void delete_at_beg();
    void delete_last();
    void delete_at_specific(node*);
    void show_list();
    ~SLL();
};

SLL :: SLL()
{
    start = NULL;
}

void SLL :: insert_at_start(int data)
{
   node *n = new node ;
   n->item = data;
   n->next = start;
   start = n;
}

void SLL :: insert_at_last(int data)
{
    node *n = new node;
    n->item = data;
    n->next = NULL;

    if(start)
    {
        node *temp = start;

        while(temp->next != NULL)
        temp = temp -> next;
        
        temp-> next = n;

    }

    else
    start = n;
}

node* SLL :: search(int data)
{
        node *temp = start;
        while(temp != NULL)
        {
            if(temp->item == data)
            return temp;

            temp = temp->next;
        }
        
        return NULL;
}

void SLL :: insert_after(node *ptr , int data)
{ 
    node *n = new node;
    n->item = data;
    n->next = ptr->next;
    ptr->next = n;
}

void SLL :: delete_at_beg()
{
    if(start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }

    else
    cout<<"List is already Empty"<<endl;
}

void SLL :: delete_last()
{
    if(start == NULL)
    cout<<"List is Empty"<<endl;
    
    else if(start->next == NULL)
    {
    delete start;
    start = NULL;
    }
      
    else
    {
        node *temp = start;

        while( (temp->next)->next != NULL)
        temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }
    //  using two pointer approach 
    //   else
    //   {
    //     node *temp1 = start ;
    //     node *temp2 = start ;
    //     while(temp1->next != NULL)
    //     {
    //         temp2 = temp1;
    //         temp1 = temp1->next;
    //     }
    //     temp2->next = NULL;
    //     delete temp1;
    //   }
}

void SLL :: delete_at_specific(node *ptr)
{
    if(ptr)
    {
        if(ptr == start)
        {
            start = start->next;
            delete ptr;
        }

        else
        {
            node *temp = start;

            while(temp->next != ptr)
            temp = temp->next;
            
            temp->next = ptr->next;
            delete ptr;
        }
    }

    else
    cout<<"List is already Empty"<<endl;

}

SLL :: ~SLL()
{

while(start)
  delete_at_beg();
    
// cout<<"Deallocation sucessfull"<<endl;

    // if(start)
    // {
    // node *temp = start;
    // while(start->next != NULL)
    // {
    //     start = start->next;
    //     delete temp;
    //     temp = start;
    // }
    // delete temp;
    // start = NULL;
    // }

}

void SLL :: show_list()
{
    node *ptr = start;
    if(ptr)
    {
        while (ptr->next != NULL)
        {
            cout<<ptr->item <<" ";
            ptr = ptr->next;
        }

        cout<<ptr->item <<" ";
        cout<<endl;
        
    }
    
    else
    cout<<"list is empty"<<endl;
}




