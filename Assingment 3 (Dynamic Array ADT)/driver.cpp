#include"Dynamic_Array_creation.cpp"

int main()
{
  Dynamic_Array d(3) ;
  cout<<"Is Empty : "<<d.IsEmpty();
  d.append(10);
  d.append(20);
  d.append(30);

  cout<<endl;
  
  for (int i = 0; i < d.count_element(); i++)
    cout<<d.getElement(i) <<" ";

  cout<<endl;
  cout<<"Before ,current capacity : "<<d.Curr_capacity() <<endl;
  d.append(40);
  cout<<"After ,current capacity : "<<d.Curr_capacity() <<endl;

  for (int i = 0; i < d.count_element(); i++)
    cout<<d.getElement(i) <<" ";

    cout<<endl <<"Total element : "<<d.count_element() <<endl;
   
    cout<<endl <<"Total element : "<<d.Curr_capacity() <<endl;
    d.Delete(0);
    cout<<"After ,current capacity : "<<d.Curr_capacity() <<endl;
    
    d.edit(2,60);

    for (int i = 0; i < d.count_element(); i++)
    cout<<d.getElement(i) <<" ";

    cout<<endl <<"60 at index : "<<d.find(60) <<endl;
    d.Delete(1);
    cout<<"Is Full : "<<d.isFull() <<endl;
 return 0;
}
 
