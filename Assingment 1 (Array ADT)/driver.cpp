#include"updated_Array_ADT.cpp"

int main()
{
    Array a(5);
    // Array obj; //for default constructor 
    // obj.create_array(4); //using create array function
    cout<<"Is empty : "<<a.isEmpty() <<endl;
    a.append(5);
    a.append(10);
    a.append(15);

    a.insert(1,50);

    cout<<endl <<"Count : "<<a.count_element() <<endl;

    for (int i = 0; i < a.count_element(); i++)
    {
        cout<<a.get_element(i) <<" ";
    }

    cout<<endl <<"Find at : "<<a.find(5) <<endl;

    a.edit(1,20);

    for (int i = 0; i < a.count_element(); i++)
        cout<<a.get_element(i) <<" ";

    a.Delete(2);
    cout<<endl;

       for (int i = 0; i < a.count_element(); i++)
        cout<<a.get_element(i) <<" ";

    a.insert(0,50);
    a.Delete(1);
    cout<<endl;
    
       for (int i = 0; i < a.count_element(); i++)
        cout<<a.get_element(i) <<" ";
    return 0;
}
