#include<iostream>
using namespace std;
#include<stdio.h>

struct node
{
    int item;
    node *next;
};

class CLL
{
  node *last;

  public :

  CLL();
  node* get_last();
  void insert_at_start(int);
  void insert_at_end(int);
  node* search(int);
  void show_list();
  void insert_After(node *,int);
  void delete_first();
  void delete_last();
  void delete_specific(node *);
  ~CLL();

};

node* CLL :: get_last()
{
    return last;
}

CLL :: CLL()
{
    last = NULL;
}

void CLL :: insert_at_start(int data)
{
    node *n = new node;
    n->item = data;

    if(last)
    {
    n->next = last->next;
    last->next = n;
    }

    else
    {
      n->next = n;
      last = n;
    }

}

void CLL :: insert_at_end(int data)
{
    node *n = new node;
    n->item = data;

    if(last)
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }

    else
    {
        n->next = n;
        last = n;
    }

}

node* CLL :: search(int data)
{
    if(last)
    {
        node *temp = last->next;
        do
        {
           if(temp->item == data)
           return temp;
           
           else
           temp = temp->next;
        } while (temp != last->next);
    }
    return NULL;
}

void CLL :: show_list()
{
    if(last)
    {
        node *temp = last->next;
        do
        {
            cout<<temp->item <<" ";
            temp = temp->next;
        }while(temp != last->next);
        cout<<endl;
    }

    else
    cout<<"List is empty"<<endl;
}

void CLL :: insert_After(node *ptr,int data)
{
    if(ptr)
    {
        node *n = new node;
        n->item = data;
        n->next = ptr->next;
        ptr->next = n;

        if(ptr == last)
        last = n;
    }
}

void CLL :: delete_first()
{
    if(last)
    {
        node *temp = last->next;

        if(last == temp)
        last = NULL;

        else
        last->next = temp->next;

        delete temp;
    }

    else
    cout<<"List Empty"<<endl;
}

void CLL :: delete_last()
{
    if(last)
    {
        node *temp = last->next;

        while(temp->next != last)
        temp = temp->next;

        if(temp == last)
        {
        delete last;    
        last = NULL;
        }

        else
        {
        temp->next = last->next;
        delete last;    
        last = temp;
        }

    }

    else
    cout<<"List is Empty"<<endl;
}

void CLL :: delete_specific(node *ptr)
{
    if(ptr)
    {
        node *temp = last->next;

        while(temp->next != ptr)
        temp = temp->next;

        temp->next = ptr->next;

        if(ptr == ptr->next)
        last = NULL;

        else if(ptr == last)
        last = temp;

        delete ptr;
    }

    else
    cout<<"address Not exist"<<endl;

}

CLL :: ~CLL()
{
    while(last)
    delete_first();
    cout<<"Memory free sucessfullly"<<endl;
}


