#include"SinglyLL_ADT.cpp"

int main()
{
    SLL obj;
    obj.insert_at_start(20);
    obj.insert_at_start(50);
    obj.insert_at_start(90);
    obj.insert_at_start(23);
    obj.show_list();
    cout<<"Hello ji"<<endl;
    obj.insert_at_last(100);
    obj.show_list();
    obj.insert_after(obj.search(23),2000);
    obj.show_list();
    obj.delete_at_beg();
    obj.show_list();
    
    obj.delete_last();
    obj.show_list();

    obj.delete_at_specific(obj.search(50));
    obj.show_list();

    cout<<"50 at : "<<obj.search(10) <<endl;
    cout<<"Hello ji"<<endl;

    return 0;
}