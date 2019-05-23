#pragma once
#include "Binary_heap.h"

//it's used for binary heap class and it's children only
namespace LR {
	template <typename T1>
	class Priority_queue
	{
	private:
		LR::Binary_heap<T1> *_BH;

	public:
		Priority_queue();
		Priority_queue(LR::Binary_heap<T1>&);
		~Priority_queue();
		T1& top() const;
		void pop();
		size_t size() const;
		void push(T1&);

	};

	template <typename T1>
	Priority_queue<T1>::Priority_queue()
	{
		_BH = nullptr;
	}

	template <typename T1>
	Priority_queue<T1>::Priority_queue(LR::Binary_heap<T1>& BH)
	{
		_BH = &BH;
	}
	
	template <typename T1>
	Priority_queue<T1>::~Priority_queue()
	{
	}

	template <typename T1>
	T1& Priority_queue<T1>::top() const
	{
		return (*_BH).top();
	}
	
	template <typename T1>
	void Priority_queue<T1>::pop()
	{
		 (*_BH).pop();
	}

	template <typename T1>
	size_t Priority_queue<T1>::size() const
	{
		return (*_BH).get_size();
	}
	
	template <typename T1>
	void Priority_queue<T1>::push(T1& newMember)
	{
		(*_BH).push(newMember);
	}

}