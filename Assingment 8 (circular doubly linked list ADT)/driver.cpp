#include"CDLL.cpp"

int main()
{
CDLL obj;
obj.insert_at_start(5);
obj.insert_at_start(19);
obj.insert_at_start(13);
obj.insert_at_last(100);

// obj.insert_after(obj.search(100),50);
// obj.show_list();


obj.show_list();
// obj.delete_first();
obj.delete_last();
obj.delete_last();
obj.delete_last();
// obj.delete_last();



// obj.delete_specific(obj.search(13));
obj.show_list();

    return 0;
}



