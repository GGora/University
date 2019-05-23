#pragma once

namespace LR 

{
	class Priority_queue
	{
	private:
		LR::Binary_heap<LR::Point> * _binary_heap;
		Priority_queue();
	public:
		
		Priority_queue(LR::Binary_heap<LR::Point>&);
		~Priority_queue();
		const LR::Point& top() const;
		void pop();
		virtual void push(LR::Point&);
		virtual bool is_empty()const;
		virtual size_t size()const;
	};
	
}