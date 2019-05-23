#include "Binary_Heap.h"
/*

LR::Binary_heap::Binary_heap() : LR::Binary_heap(15)
{
}

LR::Binary_heap::Binary_heap(int size) : _capacity{ 0 }
{
	if (size < 0) throw "incorrect size";
	_size = size;
	int sizeMask{ size };
	while (sizeMask != 0)
	{
		sizeMask >>= 1;
		_capacity <<= 1;
		++_capacity;
	}
	if (_capacity < 15) _capacity = 15;
	array = new int[_capacity];
}

LR::Binary_heap::~Binary_heap()
{

}

size_t LR::Binary_heap::get_capacity()
{
	return _capacity;
}*/