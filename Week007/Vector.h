#pragma once
#include <initializer_list>
#include <limits>

namespace nc
{
	template<typename T>
	class vector
	{
	public:
		// Constructors
		vector();
		vector(size_t capacity);
		vector(const std::initializer_list<T>& ilist);
		vector(const vector& other);
		// Destructor
		//~vector();
		// Operators
		//vector& operator = (const vector& other) { return other; }
		T& operator [] (size_t position) { return _elements[position]; }
		const T& operator [] (size_t position) const { return _elements[position]; }
		//// Methods
		//T& at(size_t position);
		//const T& at(size_t position) const;
		T& front() { return _elements[0]; } // First record
		T& back() { return _elements[_size - 1]; } // Last record
		//T* data();
		void push_back(const T& value); // Check capacity then add record
		void pop_back() { if (_size > 0) _size--; }
		void reserve(size_t capacity); // Increase array size
		//void resize(size_t new_size, const T& value = T{});
		void clear() { _size = 0; }
		//void swap(vector& other);
		bool empty() const { return _size == 0; }
		size_t size() const { return _size; } // Num of cells with data
		size_t capacity() const { return _capacity; }
		size_t max_size() const { return std::numeric_limits<size_t>::max() / sizeof(T); }
	private:
		// Properties
		T* _elements{ nullptr };
		size_t _size{};
		size_t _capacity{};
	};
	template<typename T>
	vector<T>::vector() {
		_capacity = 0;
		_size = 0;
	}
	template<typename T>
	vector<T>::vector(size_t capacity) {
		_capacity = capacity;
		_size = 0;
		_elements = new T[_capacity];
	}
	template<typename T>
	vector<T>::vector(const std::initializer_list<T>& ilist) {
		_size = ilist.size();
		_capacity = _size;
		_elements = new T[_capacity];

		size_t count = 0;
		for (auto iterator = ilist.begin(); iterator != ilist.end(); iterator++) {
			_elements[count] = *iterator;
			count++;
		}
	}
	template<typename T>
	vector<T>::vector(const vector& other) {
		_size = other.size();
		_capacity = other.capacity();
		_elements = new T[_capacity];

		
		for (size_t count = 0; count < _size; count++) {
			_elements[count] = other[count];
		}
	}

	template<typename T>
	void vector<T>::push_back(const T& value) {
		if (_size == _capacity) {
			reserve(_capacity * 2);
		}
		_elements[_size] = value;
		_size++;
	}
	template<typename T>
	void vector<T>::reserve(size_t capacity) {
		if (capacity <= _capacity) return;

		T* new_elements = new T[capacity];
		for (size_t count = 0; count < _size; count++) {
			new_elements[count] = _elements[count];
		}
		delete[] _elements;
		_elements = new_elements;
		_capacity = capacity;
	}
	
}