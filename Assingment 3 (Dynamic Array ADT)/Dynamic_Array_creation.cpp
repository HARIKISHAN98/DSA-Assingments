#include<iostream>
using namespace std;

class Dynamic_Array
{
  private :
  int capacity;
  int lastIndex;
  int *ptr;

  public :
 
Dynamic_Array(int);
void double_array();
void half_array();
int Curr_capacity();
bool IsEmpty();
void append(int);
void insert(int,int);
void edit(int,int);
void Delete(int); 
bool isFull(); 
int getElement(int);
int count_element();
~Dynamic_Array();
int find(int);
};

Dynamic_Array :: Dynamic_Array(int size)
{
  capacity = size;
  lastIndex = -1;
  ptr = new int[capacity];
}

void Dynamic_Array :: double_array()
{
    int *temp_ptr = new int[capacity*2];
    for (int i = 0; i <=lastIndex ; i++)
    temp_ptr[i] = ptr[i];
    delete[] ptr; //clear memory of point by ptr 
    ptr = temp_ptr; //now ptr point the new array (double of its size)
    capacity*=2;
}

void Dynamic_Array :: half_array()
{
    int *temp_ptr = new int[capacity/2];

    for (int i = 0; i <= lastIndex; i++)
    temp_ptr[i] = ptr[i];

    delete[] ptr; //clear memory of point by ptr 
    ptr = temp_ptr;
    capacity/=2;
}

int Dynamic_Array :: Curr_capacity()
{
  return capacity;
}

bool Dynamic_Array :: IsEmpty()
{
  return (lastIndex == -1) ;
}

void Dynamic_Array :: append(int data)
{
  if(lastIndex == capacity-1)
  double_array();
  
  lastIndex++;
  ptr[lastIndex] = data;
}

void Dynamic_Array :: insert(int index,int data)
{
  if(lastIndex == capacity-1)
  double_array();

  if(index < 0 || index > lastIndex + 1)
  {
    cout<<"Invalid Index"<<endl;
  }

  else 
  {
    int i;
    for ( i = lastIndex ; i >= index; i--)
    {
      ptr[i+1] = ptr[i];
    }
    ptr[i+1] = data;
    lastIndex++;
  }

}

void Dynamic_Array :: edit(int index,int data)
{
  if(index > -1 && index <= lastIndex)
  ptr[index] = data;

  else
  cout<<"Invalid Index"<<endl;
}

void Dynamic_Array :: Delete(int index)
{
  if(index < 0 || index > lastIndex)
  cout<<"Invalid Index"<<endl;

  else
  {
    int i;
    for (i = index ; i < lastIndex ; i++)
      ptr[i] = ptr[i+1];

    lastIndex--;
    if(lastIndex+1 <= capacity/2 && capacity > 1)
    half_array();
  }
}

bool Dynamic_Array :: isFull()
{
  return (lastIndex == capacity-1);
}

int Dynamic_Array :: getElement(int index)
{
  if(index > -1 && index <= lastIndex)
  return ptr[index];

  else
  cout<<"Invalid Index"<<endl;
  return -1;
}

int Dynamic_Array :: count_element()
{
  return lastIndex+1;
}

Dynamic_Array :: ~Dynamic_Array()
{
  delete []ptr;
  // cout<<endl <<"Destructor called sucessfully"<<endl;
}

int Dynamic_Array :: find(int data)
{
  for (int i = 0; i <=lastIndex ; i++)
  {
    if(ptr[i] == data)
    return i;
  }

  return -1;
  
}


