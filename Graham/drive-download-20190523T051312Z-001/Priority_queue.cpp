#include "priority_queue.h"
#include "Binary_heap.h"
#include "Point.h"

LR::Priority_queue::Priority_queue()
{

}


LR::Priority_queue::Priority_queue(LR::Binary_heap<LR::Point>& heap) : _binary_heap{ &heap }
{

}

LR::Priority_queue::~Priority_queue()
{
	delete _binary_heap;
}

const LR::Point& LR::Priority_queue::top() const
{
	return (*_binary_heap).top();
}

void  LR::Priority_queue::pop()
{
	(*_binary_heap).pop()
}