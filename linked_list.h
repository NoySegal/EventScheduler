#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "node.h"

namespace mtm {

	template <class T>
	class List
	{
	public:
		List();
		~List();
		
		int getSize() const;
		Node<T>* getFirst() const;
		Node<T>* getNext(Node<T>& node) const;
		Node<T>* getPrev(Node<T>& node) const;
		void insertStart(T* data);
		void insertLast(T* data);
		void insertAfter(Node<T>& target, T* data);
		void insertBefore(Node<T>& target, T* data);
		void removeNode(Node<T>& node);
		bool contains(const T data);


	private:
		Node<T>* head;
		int size;
	};

	template <class T>
	List<T>::List() : head(NULL), size(0)
	{
	}

	template <class T>
	List<T>::~List()
	{
		Node<T>* temp;
		while (head)
		{
			temp = head;
			head = head->getNext();
			delete temp;
			size--;
		}
	}

	template <class T>
	int List<T>::getSize() const {
		return size;
	}

	template <class T>
	Node<T>* List<T>::getFirst() const {
		if (size == 0)
		{
			return NULL;
		}

		return head;
	}

	template <class T>
	Node<T>* List<T>::getNext(Node<T>& node) const {
		return node.getNext();
	}

	template <class T>
	Node<T>* List<T>::getPrev(Node<T>& node) const {
		return node.getPrev();
	}

	template <class T>
	void List<T>::insertStart(T* data) {
		if (size == 0)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* temp = new Node<T>(data, head);
			head->setPrev(temp);
			head = temp;
		}

		size++;
	}

	template <class T>
	void List<T>::insertLast(T* data) {
		if (size == 0)
		{
			head = new Node<T>(data);
			size++;
			return;
		}

		Node<T>* curr = head;
		while (curr->getNext() != NULL)
		{
			curr = curr->getNext();
		}

		insertAfter(*curr, data);
	}

	template <class T>
	void List<T>::insertAfter(Node<T>& target, T* data) {
		Node<T>* newNode = new Node<T>(data, target.getNext(), &target);
		if (target.getNext() != NULL)
		{
			target.getNext()->setPrev(newNode);
		}
		target.setNext(newNode);
		size++;
	}

	template <class T>
	void List<T>::insertBefore(Node<T>& target, T* data) {
		if (head == &target)
		{
			return insertStart(data);
		}

		Node<T>* newNode = new Node<T>(data, &target, target.getPrev());
		target.getPrev()->setNext(newNode);
		target.setPrev(newNode);
		size++;
	}

	template <class T>
	void List<T>::removeNode(Node<T>& node) {
		Node<T>* temp = &node;
		Node<T>* previousNode = node.getPrev();
		Node<T>* nextNode = node.getNext();

		if (head == temp)
		{
			head = temp->getNext();
		}
		if (previousNode != NULL)
		{
			previousNode->setNext(nextNode);
		}
		if (nextNode != NULL)
		{
			nextNode->setPrev(previousNode);
		}
		
		delete temp;
		size--;
	}

	template <class T>
	bool List<T>::contains(const T data) {
		Node<T>* curr = head;
		while (curr)
		{
			if (curr->getValue() == data)
			{
				return true;
			}
			curr = curr->getNext();
		}
		return false;
	}
}

#endif