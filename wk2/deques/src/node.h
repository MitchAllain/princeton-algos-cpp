template<typename T>
struct Node
{
  Node(T new_item) : item(new_item) {}

  T item;
  Node* next;
  Node* prev;
};
