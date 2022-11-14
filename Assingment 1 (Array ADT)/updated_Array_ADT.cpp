#include<iostream>
using namespace std;

class Array
{
   private :
   int capacity;
   int lastIndex;
   int *ptr;

   public :

   Array(int);
//    Array();
//    void create_array(int);
   bool isEmpty();
   void append(int);
   void insert(int,int);
   void edit(int,int);
   void Delete(int);
   bool IsFull();
   int get_element(int);
   int count_element();
   ~Array();
   int find(int);

//    int get_lastIndex()
//    {
//     return lastIndex;
//    }
};

// void Array :: create_array(int size)
// {
//     capacity = size;
//     lastIndex = -1;
//     ptr = new int[capacity];
// }

// Array :: Array()
// {
//    capacity = 0;
//    lastIndex = -1;
//    ptr = NULL;
// }

Array :: Array(int size)
{
    capacity = size;
    lastIndex = -1; //because array is empty;
    ptr = new int[capacity];
}

bool Array :: isEmpty()
{
    return (lastIndex == -1);
}

void Array :: append(int data)
{
    if(lastIndex == capacity-1)
    cout<<"Array is already full"<<endl;

    else
    {
        lastIndex++;
        ptr[lastIndex] = data;
    }
}

void Array :: insert(int index ,int data)
{
    if(lastIndex == capacity-1)
    cout<<"Array is already Full"<<endl;

    else if(index < 0 || index > lastIndex + 1)
    cout<<"Invalid Index"<<endl;

    else
    {
        int i;
        for ( i = lastIndex; i >= index; i--) //shift logic
        {
            ptr[i+1] = ptr[i];
        }
        ptr[i+1] = data;
        lastIndex++;
    }
}

void Array :: edit(int index,int data)
{
    if(index < 0 || index > lastIndex)
    cout<<"Invalid Index"<<endl;

    else
    ptr[index] = data;
}

void Array :: Delete(int index)
{
    if(index < 0 || index > lastIndex)
    cout<<"Invalid Index"<<endl;

    else
    {
        int i ;
        for (i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i+1];
        }
        lastIndex--;
    }

}

bool Array :: IsFull()
{
    return (lastIndex == capacity-1);
}

int Array ::  get_element(int index)
{
    if(index > -1 && index <= lastIndex )
    return ptr[index];

    else
    cout<<"Invalid Index"<<endl;
    return -1;
}

int Array :: count_element()
{
    return (lastIndex+1);
}

Array :: ~Array()
{
    delete[] ptr;
}

int Array :: find(int data)
{
   for (int i = 0; i <= lastIndex; i++)
   {
    if(ptr[i] == data)
    return i;
   }

   return -1;
}
