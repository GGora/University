#pragma once
#include <functional>

namespace LR {
	template <typename T1>
	class Binary_heap
	{
	private:
		size_t _capacity;// capacity of the heap
		void _extend();// increases capasity
	public:
		bool is_empty() const;
		size_t get_capacity();
		size_t get_size();
		Binary_heap();
		Binary_heap(int);
		void push(T1&, std::function<bool(T1&, T1&)>);
		virtual void push(T1&);
		T1 get(int index);
		T1& top() const;
		virtual void pop();
		~Binary_heap();
	protected:
		virtual void _erase(size_t);
		virtual void _heapify(size_t);
		size_t _size;
		T1* _ptr;
		void _swap(T1&, T1&);
	};

	template <typename T1>
	void LR::Binary_heap<T1>::pop()
	{
		if (!is_empty()) _erase(0);
	}
	
	template <typename T1>
	void LR::Binary_heap<T1>::_heapify(size_t position)//sorting the heap
	{
		size_t lhPosition = position * 2 + 1;
		size_t rhPosition = position * 2 + 2;
		if (lhPosition < _size)
		{
			if (rhPosition >= _size)
			{
				if (_ptr[position] < _ptr[lhPosition])
				{
					_swap(_ptr[position], _ptr[lhPosition]);
				}
			}
			else
			{
				if (_ptr[rhPosition] > _ptr[lhPosition])
				{
					if (_ptr[rhPosition] < _ptr[position])
					{
						swap(_ptr[rhPosition], _ptr[position]);
						_heapify(rhPosition);
					}
					else
					{
						if (_ptr[lhPosition] < _ptr[position])
						{
							swap(_ptr[lhPosition], _ptr[position]);
							_heapify(lhPosition);
						}
					}
				}
				else
				{
					if (_ptr[lhPosition] < _ptr[position])
					{
						swap(_ptr[lhPosition], _ptr[position]);
						_heapify(lhPosition);
					}
					else
					{
						if (_ptr[rhPosition] < _ptr[position])
						{
							swap(_ptr[rhPosition], _ptr[position]);
							_heapify(rhPosition);
						}
					}
				}
			}
		}
	}

	template <typename T1>
	bool LR::Binary_heap<T1>::is_empty() const
	{
		return (_size == 0);
	}

	template <typename T1>
	void LR::Binary_heap<T1>::_erase(size_t position)
	{
		--_size;
		swap(_ptr[position], _ptr[_size]);
		_heapify(position);
	}

	template <typename T1>
	T1& LR::Binary_heap<T1>::top() const
	{
		if (_size < 1) throw "Heap is empty";
		return _ptr[0];
	}

	template <typename T1>
	T1 LR::Binary_heap<T1>::get(int index)
	{
		return _ptr[index];
	}

	template <typename T1>
	void LR::Binary_heap<T1>::push(T1& newMember)
	{
		int new_el_pos = _size;
		int compared_el_pos;
		if ((++_size) == _capacity)
		{
			_extend();
		}
		_ptr[new_el_pos] = newMember;

		while (new_el_pos != 0)
		{
			if ((new_el_pos & 1))// is uneven?
			{
				compared_el_pos = (new_el_pos - 1) / 2;
			}
			else
			{
				compared_el_pos = (new_el_pos - 2) / 2;
			}

			if (_ptr[compared_el_pos]< _ptr[new_el_pos])// need to swap?
			{
				_swap(_ptr[compared_el_pos], _ptr[new_el_pos]);
				new_el_pos = compared_el_pos;
			}
			else
			{
				break;
			}
		}
	}

	template <typename T1>
	void LR::Binary_heap<T1>::push(T1& newMember, std::function<bool(T1&, T1&)> comparator)
	{
		int new_el_pos = _size;
		int compared_el_pos;
		if ((++_size) == _capacity)
		{
			_extend();
		}
		_ptr[new_el_pos] = newMember;
		
		while (new_el_pos != 0)
		{
			if ((new_el_pos & 1))// is uneven?
			{
				compared_el_pos = (new_el_pos - 1) / 2;
			}
			else
			{
				compared_el_pos = (new_el_pos - 2) / 2;
			}

			if (comparator(_ptr[compared_el_pos], _ptr[new_el_pos]))// need to swap?
			{
				_swap(_ptr[compared_el_pos], _ptr[new_el_pos]);
				new_el_pos = compared_el_pos;
			}
			else
			{
				break;
			}
		}
	}

	template <typename T1>
	LR::Binary_heap<T1>::Binary_heap() : LR::Binary_heap<T1>(15)
	{}

	template <typename T1>
	LR::Binary_heap<T1>::Binary_heap(int size) : _capacity{ 0 }, _size{0}
	{
		if (size < 0) throw "incorrect size";
		int sizeMask{ size };
		while (sizeMask != 0)
		{
			sizeMask >>= 1;
			_capacity <<= 1;
			++_capacity;
		}
		if (_capacity < 15) _capacity = 15;
		_ptr = new T1[_capacity];
	}

	template <typename T1>
	LR::Binary_heap<T1>::~Binary_heap()
	{
		delete[] _ptr;
	}

	template <typename T1>
	size_t LR::Binary_heap<T1>::get_capacity()
	{
		return _capacity;
	}

	template <typename T1>
	size_t LR::Binary_heap<T1>::get_size()
	{
		return _size;
	}

	template <typename T1>
	void Binary_heap<T1>::_extend()
	{
		_capacity = (_capacity + 1) * 2;
		T1* newptr = new T1[_capacity];
		for (size_t index = 0; index < _size; ++index)
		{
			newptr[index] = _ptr[index];
		}
		delete[] _ptr;
		_ptr = newptr;
	}

	template <typename T1>
	void Binary_heap<T1>::_swap(T1& lhMember, T1& rhMember)
	{
		T1 buf = lhMember;
		lhMember = rhMember;
		rhMember = buf;
	}

}