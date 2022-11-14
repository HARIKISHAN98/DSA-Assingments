#include"doubly_linked_list_ADT.cpp"

int main()
{
   DLL obj;
   obj.insert_at_first(5);
   obj.insert_at_first(50);
   obj.insert_at_first(16);
   obj.insert_at_first(23);
   obj.insert_at_first(39);
   obj.show_list();

   obj.insert_at_end(13);
   obj.insert_at_end(97);
   obj.show_list();
   
   cout<<obj.search(1) <<endl;

   obj.insert_after(obj.search(97),55);
   obj.show_list();

   obj.delete_first();
   obj.show_list();

 obj.delete_last();
 obj.delete_last();

   obj.show_list();

   obj.delete_specific(obj.search(50));
   obj.show_list();

   obj.delete_specific(obj.search(1));
   obj.show_list();
 
 obj.delete_last();

   obj.show_list();


    return 0;
}

