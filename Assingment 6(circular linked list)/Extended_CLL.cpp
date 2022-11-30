#include"circular_linked_list.cpp"

class Extended_cll : public CLL 
{
  public :
  int len_cycle();

};

int Extended_cll :: len_cycle()
{
  int count = 0;
  node *temp = get_last();
  node *start = get_last()->next;
  if(temp)
  {
    if(temp->next == start)
    {
      do
      {
       count++;
       temp = temp->next;
      } while (temp != get_last());
      
      return count;
    }

    else
    return 0;
  }

return 0;

}

