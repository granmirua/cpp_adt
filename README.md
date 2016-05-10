# cpp_adt
The goal is to crate a big set of data structure made in c++


Actually I implemented Binary Tree in C++ with this interface:
    - 	Tree(T elem);                                            is the constructor;
    -   ~Tree();                                                 is the destructor;
    -   Node<T>& add_right_child(Node<T> &parent, T child);      add the right child to a node
    -   Node<T>& add_left_child(Node<T> &parent, T child);       add the left child to a node
    -   T get_element(Node <T> node);                            get the element from a node
    -   Node<T>& get_left_child(Node<T> & parent);               get the left child
    -   Node<T>& get_right_child(Node<T> & parent);              get the right child
    -   Node<T>& get_root();                                     get the root of the tree
    -   print_all_depth_first(Node <T> node);                    prints - left - right - father
    -   void print_all_depth_first();
    -   void print_all(Node <T> node);                           prints - left - father - right
    -   void print_all();
    -   void print_all_depth(Node <T> node);                     prints - father - left -right
    -   void print_all();
