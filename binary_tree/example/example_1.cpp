#include "../binary_tree.cpp"

int main(){
	Tree<int> *t = new Tree<int>(10);
	t->add_left_child(t->get_root(),5);
	t->add_right_child(t->get_root(),15);
	
	t->print_all();
	
	delete t;
}
