#include<stdio.h>
#include<iostream>
using namespace std;

class node 
{
  public :
    node *prev;
    int item ;
    node *next;
};

class CDLL
{
  node *start;

  public :

  CDLL(); 
  void insert_at_start(int);
  void show_list();
  void insert_at_last(int);
  node* search(int);
  void insert_after(node *,int);
  void delete_first();
  void delete_last();
  void delete_specific(node *);
  ~CDLL();

};

CDLL :: CDLL()
{
    start = NULL;
}

void CDLL :: insert_at_start(int data)
{
node *n = new node ;
 if(start)
 {   
  n->prev = start->prev;
  n->item = data;
  n->next = start;

  start->prev->next = n;
  start->prev = n;

 }

 else
 {
   n->prev = n;
   n->item = data;
   n->next = n;

 }

  start = n;

}

void CDLL :: show_list()
{
    if(start)
    {
        node *temp = start;
        
        do
        {
           cout<<temp->item <<" ";
           temp = temp->next;
        } while(temp != start);
    }
    cout<<endl;
}

void CDLL :: insert_at_last(int data)
{
  node *n = new node;

  if(start)
  {
    n->prev = start->prev;
    n->item = data;
    n->next = start;

    start->prev->next = n;
    start ->prev = n;
  }

  else
  {
    n->prev = n;
    n->item = data;
    n->next = n;

    start = n;
  }

}

node* CDLL :: search(int data)
{
  if(start)
  {
    node *temp = start;

    do
    {
    if(temp->item == data)
    return temp;

    else
    temp = temp->next;
    }while(temp != start);

  }
  return NULL;
}

void CDLL :: insert_after(node *ptr,int data)
{
  if(ptr)
  {
    node *n = new node;
    n->prev = ptr;
    n->item = data;
    n->next = ptr->next;

    ptr->next->prev = n;
    ptr->next = n;
  }
}

void CDLL :: delete_first()
{
  if(start)
  {
    node *temp = start;

    if(start == start->next) //only 1 node is present
      start = NULL;
    
    else  //more then 1 node is present
    {
      start->prev->next = start->next;
      start->next->prev = start->prev;

      start = start->next;
    }

    delete temp;
  }

  else //if list is empty
  cout<<"Underflow"<<endl;

}

void CDLL :: delete_last()
{
  if(start)
  {
    node *temp = start->prev;

    if(start == start->next)
    start = NULL;
    
    else
    {
    temp->prev->next = start;
    start->prev = temp->prev;
    }
    
    delete temp;
  }

  else
  cout<<"Underflow"<<endl;
}

void CDLL :: delete_specific(node *ptr)
{
  if(start && ptr)
  {
     ptr->prev->next = ptr->next;
     ptr->next->prev = ptr->prev;

     if(ptr == ptr->next)
     start = NULL;

     else if(ptr == start)
     start = start->next;

     delete ptr;
  }

  else if(start == NULL)
  cout<<"List is empty"<<endl;

  else
  cout<<"Element Not exist ,Can't able to delete"<<endl;
  
}

CDLL :: ~CDLL()
{

  while(start)
  delete_first();
  
  cout<<"Memory deallocate sucessfully"<<endl;
}





