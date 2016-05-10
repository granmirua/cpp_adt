#include <iostream>
#include <stdexcept>

template <typename T> struct Node{
	T element;
	Node * left;
	Node * right;
	Node * parent;
};

template <typename T>
class Tree{
	private:
		
	    Node <T> * root = NULL;
	    
		void destroy_all(Node<T> * node){
	    	if(node == NULL)
			   return;
			
			destroy_all(node->right);
			destroy_all(node->left);
			delete node;	
		}
	
	
	public:
	
		Tree(T elem){
			root = new Node<T>;
			
			root->element = elem;
			root->parent = root->right = root->left = NULL;

		}
		
		~Tree(){
			destroy_all(root);
		}
		
		Node<T>& add_right_child(Node<T> &parent, T child){
			if(&parent == NULL)
			   throw std::invalid_argument("Parent is null");;
			
			if(parent.right != NULL)
			   destroy_all(parent.right);
		    
			parent.right = new Node<T>;
			parent.right->parent = &parent;
			parent.right->right = parent.right->left = NULL;
			parent.right->element = child;
			
			return *parent.right;
		}
		
		Node<T>& add_left_child(Node<T> &parent, T child){
			if(&parent == NULL)
			   throw std::invalid_argument("Parent is null");;
			   
			if(parent.left != NULL)
			   destroy_all(parent.left);
		    
			parent.left = new Node<T>;
			parent.left->parent = &parent;
			parent.left->right = parent.left->left = NULL;
			parent.left->element = child;
			
			return *parent.left;
		}
		
		T get_element(Node <T> node){
			return node.element;
		}
		
		Node<T>& get_left_child(Node<T> & parent){
			if(parent != NULL)
				return parent.left;
			throw std::invalid_argument("Parent is null");
		} 
		
		Node<T>& get_right_child(Node<T> & parent){
			if(parent != NULL)
				return parent.right;
			throw std::invalid_argument("Parent is null");
		}
		
		Node<T>& get_root(){
			if(root)
			   return *root;
			throw std::invalid_argument("Root is null");
		}
		
		void print_all_depth_first(Node <T> node){
			if(node.left != NULL)
			   print_all_depth_first(*node.left);
			if(node.right != NULL)
			   print_all_depth_first(*node.right);
			   
			std::cout << node.element << " ";
		}
		
		
		void print_all_depth_first(){
			print_all_depth_first(*root);
		}
		
		void print_all(Node <T> node){
			if(node.left != NULL)
			   print_all(*node.left);
			std::cout << node.element << " ";
			if(node.right != NULL)
			   print_all(*node.right);
			   
		}
		
		
		void print_all(){
			print_all(*root);
		}
		
		
		void print_all_depth(Node <T> node){
			std::cout << node.element << " ";
			if(node.left != NULL)
			   print_all_depth(*node.left);
			if(node.right != NULL)
			   print_all_depth(*node.right);
			   
		}
		
		
		void print_all_depth(){
			print_all_depth(*root);
		}
		
};



