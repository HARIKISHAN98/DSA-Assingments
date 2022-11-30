#include"circular_linked_list.cpp"

int main()
{
  CLL obj;
  obj.insert_at_start(5);
  obj.insert_at_start(19);
  obj.insert_at_start(13);
  obj.insert_at_start(7);
  obj.insert_at_end(100);
obj.insert_After(obj.search(5),200);
obj.insert_After(obj.search(24),200);

obj.delete_first();
obj.delete_first();

obj.show_list();

obj.delete_specific(obj.search(200));
obj.delete_last();
obj.delete_specific(obj.search(19));
obj.delete_specific(obj.search(100));
obj.show_list();

obj.delete_specific(obj.search(5));
obj.delete_specific(obj.search(11));




  obj.show_list();
    return 0;
}