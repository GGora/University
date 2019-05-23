#pragma once

namespace LR
{
	const int BELOW_THE_RANGE = -1;


	template <typename T1>
	class Stack 
	{
	private:
		size_t _size;
		T1* _ptr;
		int _position;
	public:
		Stack();
		Stack(size_t);
		Stack(const Stack<T1>&);
		void push(const T1&);
		T1& top();
		int top_index() const;
		size_t size() const;
		//int position()const;// удалить
		bool empty() const;
		void pop();
		~Stack();
	};
	template <typename T1>
	int Stack<T1>::top_index() const
	{
		return _position;
	}

	template <typename T1>
	Stack<T1>::Stack() : _size(8), _position{ BELOW_THE_RANGE }
	{
		_ptr = new T1[_size];
	}

	template <typename T1>
	Stack<T1>::Stack(size_t size) : _size(size), _position{ BELOW_THE_RANGE }
	{
		_ptr = new T1[_size];
	}
	
	template <typename T1>
	Stack<T1>::Stack(const Stack<T1>& rhStack) : _size{ rhStack._size}, _position{ rhStack._position}
	{
		_ptr = new T1[_size];
		for (int index = 0; index < _position; ++index)
		{
			_ptr[index] = rhStack._ptr[index];
		}
	}
	template <typename T1>
	Stack<T1>::~Stack()
	{
		_size = 0;
		_position = BELOW_THE_RANGE;
		delete[] _ptr;
	}



	template <typename T1>
	void Stack<T1>::push(const T1& rhMember)
	{
		if (++_position == _size)
		{
			_size *= 2;
			T1 *newPtr = new T1[_size];
			for (int index = 0; index < _position; ++index)
			{
				newPtr[index] = _ptr[index];
			}

			delete[]_ptr;
			_ptr = newPtr;
		}
		//else
		//{
			_ptr[_position] = rhMember;
		//}
	}

	template <typename T1>
	T1& Stack<T1>::top()
	{
		if (_position == BELOW_THE_RANGE) throw "Stack is empty";
		else return _ptr[_position];
	}

	template <typename T1>
	size_t Stack<T1>::size()const
	{
		return _size;
	}

	//template <typename T1>
	//int Stack<T1>::position()const
	//{
	//	return _position;
	//}
	
	template <typename T1>
	void Stack<T1>::pop()
	{
		if (_position > BELOW_THE_RANGE)
		{
			--_position;
		}
		else
		{
			throw "stack is empty";
		}
	}

	template <typename T1>
	bool Stack<T1>::empty()const
	{
		if (_position == BELOW_THE_RANGE) return true;
		else return false;
	}
}
