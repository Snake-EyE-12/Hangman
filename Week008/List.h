#pragma once
#include <initializer_list>
#include <limits>
#include <iostream>

namespace nc
{
	template<typename T>
	class list
	{
		struct node_t
		{
			node_t(const T& value) : _value{ value } {}

			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};

	public:
		list() {}
		list(const std::initializer_list<T>& ilist);
		//list(const list& other);
		//~list();

		list& operator = (const list& other);

		T& front() { // --returns value of first object
			return _head->_value;
		}
		const T& front() const { // --returns value of first object
			return _head->_value;
		}

		T& back() { // --value of last record
			return tail()->_value;
		}
		const T& back() const { // --value of last record
			return tail()->_value;
		}

		void push_front(const T& value); //-- add record to front
		void pop_front(); //-- take first record off list

		void push_back(const T& value); //-- add record to back
		void pop_back(); //-- remove last record

		void remove(const T& value); //-- remove first record of value
		void reverse(); // see references for implementation -- reverse order of list
		void clear(); // search online for implementation -- 

		bool empty() { return (size() == 0); }
		size_t size(); // see references for implementation -- amount of list items

		std::ostream& write(std::ostream& stream); //-- display numbers to console

	private:
		node_t* tail();

	private:
		node_t* _head{ nullptr };
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	size_t list<T>::size() {
		int count = 0;
		node_t* tempNode = _head;
		while (tempNode != nullptr) {
			count++;
			tempNode = tempNode->_next;
		}
		return count;
	}
	template<typename T>
	void list<T>::clear() {
		node_t* tempNode = _head;
		while (tempNode != nullptr) {
			delete tempNode;
			tempNode = tempNode->_next;
		}
		_head = nullptr;
	}
	template<typename T>
	list<T>& list<T>::operator = (const list& other) {
		clear();
		node_t* tempNode = other._head;
		while (tempNode) {
			push_back(tempNode->_value);
			tempNode = tempNode->_next;
		}
		return *this;
	}
	template<typename T>
	typename list<T>::node_t* list<T>::tail() {
		node_t* tempNode = _head;
		while (tempNode->_next != nullptr) {
			tempNode = tempNode->_next;
		}
		return tempNode;
	}
	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist) {
		node_t* prevNode = nullptr;
		for (auto iterator = ilist.begin(); iterator != ilist.end(); iterator++) {
			node_t* newNode = new node_t(*iterator);
			if (iterator == ilist.begin()) _head = newNode;
			newNode->_prev = prevNode;
			if(prevNode != nullptr) prevNode->_next = newNode;
			prevNode = newNode;
		}
	}
	template<typename T>
	std::ostream& list<T>::write(std::ostream& stream) {
		node_t* tempNode = _head;
		while (tempNode != nullptr) {
			stream << " " << (tempNode->_value);
			tempNode = tempNode->_next;
		}
		return stream << "\n";
	}
	template<typename T>
	void list<T>::push_back(const T& value) {
		if (_head == nullptr) {
			_head = new node_t(value);
		}
		else {
			node_t* tail = list<T>::tail();
			node_t* newTail = new node_t(value);
			tail->_next = newTail;
			newTail->_prev = tail;
		}
	}
	template<typename T>
	void list<T>::push_front(const T& value) {
		node_t* newHead = new node_t(value);
		newHead->_next = _head;
		_head = newHead;
	}
	template<typename T>
	void list<T>::pop_front() {
		node_t* tempNode = _head;
		_head = _head->_next;
		delete tempNode;
	}
	template<typename T>
	void list<T>::pop_back() {
		node_t* tail = list<T>::tail();
		tail->_prev->_next = nullptr;
		delete tail;
	}
	template<typename T>
	void list<T>::remove(const T& value) {
		node_t* tempNode = _head;
		while (tempNode->_next != nullptr) {
			if (tempNode->_value == value) {
				if (tempNode == _head) {
					tempNode->_next->_prev = nullptr;
					_head = tempNode->_next;
					delete tempNode;
					return;
				}
				tempNode->_prev->_next = tempNode->_next;
				tempNode->_next->_prev = tempNode->_prev;
				delete tempNode;
				return;
			}
			tempNode = tempNode->_next;
		}
	}
	template<typename T>
	void list<T>::reverse() {
		node_t* temp = nullptr;
		node_t* prev = nullptr;
		node_t* current = _head;
		while (current != nullptr) {
			temp = current->_next;
			current->_next = prev;
			prev = current;
			current = temp;
		}
		_head = prev;
	}
}

