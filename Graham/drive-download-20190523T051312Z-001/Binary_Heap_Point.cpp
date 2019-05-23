#include "Binary_Heap_Point.h"

LR::Binary_heap_point::Binary_heap_point() : _origin (Point())
{

}

LR::Binary_heap_point::Binary_heap_point(std::vector<LR::Point>& inputVector) : Binary_heap<LR::Point>(inputVector.size())
{
	Point* origin = &(inputVector.at(0));
	for_each(inputVector.begin() + 1, inputVector.end(), [&origin](LR::Point& curPoint) mutable 
	{
		if (curPoint.get_X() < (*origin).get_X())
		{
			origin = &curPoint;
		}
		else if (curPoint.get_X() == (*origin).get_X())
		{
			if (curPoint.get_Y() < (*origin).get_Y())
			{
				origin = &curPoint;
			}
		}

	});
	
	_origin = *origin;
	comparator.set_origin(_origin);
	inputVector.erase(remove_if(inputVector.begin(), inputVector.end(), 
		[this](LR::Point& curPoint) 
		{
			return (curPoint == _origin);
		}), inputVector.end());

	for (size_t i = 0; i < inputVector.size(); ++i)
	{
		Binary_heap::push(inputVector[i], comparator);
	}
}

void LR::Binary_heap_point::push(LR::Point& point)
{
	if (point.get_X() < _origin.get_X())
	{
		Binary_heap::_swap(point, _origin);
		comparator.set_origin(_origin);
	}
	else if (point.get_X() == _origin.get_X())
	{
		if (point.get_Y() < _origin.get_Y())
		Binary_heap::_swap(point, _origin);
		comparator.set_origin(_origin);
	}
	Binary_heap::push(point, comparator);
}


LR::Binary_heap_point::~Binary_heap_point()
{

}


const LR::Point& LR::Binary_heap_point::get_origin()const
{
	return _origin;
}

void LR::Binary_heap_point::_erase(size_t position)
{
	--_size;
	swap(_ptr[position], _ptr[_size]);
	_heapify(position);
}

void LR::Binary_heap_point::pop()
{
	if (!is_empty()) _erase(0);
}

void LR::Binary_heap_point::_heapify(size_t position)//sorting the heap using external method of comparator
{
	
	size_t lhPosition = position * 2 + 1;
	size_t rhPosition = position * 2 + 2;
	if (lhPosition < _size)
	{
		if (rhPosition >= _size)
		{
			if (comparator(_ptr[position], _ptr[lhPosition]))
			{
				_swap(_ptr[position], _ptr[lhPosition]);
			}
		}
		else
		{
			if (comparator(_ptr[lhPosition], _ptr[rhPosition]))
			{
				if (comparator(_ptr[position], _ptr[rhPosition]))
				{
					swap(_ptr[rhPosition], _ptr[position]);
					_heapify(rhPosition);
				}
				else
				{
					if (comparator(_ptr[position], _ptr[lhPosition]))
					{
						swap(_ptr[lhPosition], _ptr[position]);
						_heapify(lhPosition);
					}
				}
			}
			else
			{
				if (comparator(_ptr[position], _ptr[lhPosition]))
				{
					swap(_ptr[lhPosition], _ptr[position]);
					_heapify(lhPosition);
				}
				else
				{
					if (comparator(_ptr[position], _ptr[rhPosition]))
					{
						swap(_ptr[rhPosition], _ptr[position]);
						_heapify(rhPosition);
					}
				}
			}
		}
	}
}