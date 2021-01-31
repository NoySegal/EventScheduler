#ifndef NODE_H
#define NODE_H

namespace mtm {

	template <class T>
	class Node
	{
	public:

		Node(T* new_value, Node* new_next = NULL, Node* new_prev = NULL);
		~Node();

		T& getValue() const;
		Node<T>* getNext() const;
		Node<T>* getPrev() const;
		void setNext(Node* node);
		void setPrev(Node* node);

	private:
		T* value;
		Node* next;
		Node* prev;
	};

	template <class T>
	Node<T>::Node(T* new_value, Node* new_next, Node* new_prev) : 
		value(new_value) 
	{
		next = new_next;
		prev = new_prev;
	}

	template <class T>
	Node<T>::~Node()
	{
		delete value;
	}

	template <class T>
	T& Node<T>::getValue() const {
		return *value;
	}

	template <class T>
	Node<T>* Node<T>::getNext() const {
		return next;
	}

	template <class T>
	Node<T>* Node<T>::getPrev() const {
		return prev;
	}

	template <class T>
	void Node<T>::setNext(Node* node) {
		next = node;
	}

	template <class T>
	void Node<T>::setPrev(Node* node) {
		prev = node;
	}
}

#endif