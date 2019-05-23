#pragma once
#include "Point.h"
#include "Binary_heap.h"
#include <vector>
#include <algorithm>

namespace LR {
	class Binary_heap_point  : public LR::Binary_heap<LR::Point>
	{
	private:
		LR::Point _origin;
		class comparator// functor: lh<rh?
		{
		private:
			LR::Point _origin;
		public:
			void set_origin(LR::Point origin)
			{
				_origin = origin;
			}
			comparator() : _origin{ Point(0,0) }
			{
			}
			comparator(LR::Point& origin) : _origin{ origin }
			{
			}
			~comparator()
			{
			}
			bool operator ()(LR::Point& lhPoint, LR::Point& rhPoint)// lh < rh
			{
				Point lhVectorX(lhPoint.get_X() - _origin.get_X(), lhPoint.get_Y() - _origin.get_Y());
				Point rhVectorX(rhPoint.get_X() - _origin.get_X(), rhPoint.get_Y() - _origin.get_Y());
				if (LR::Point::cross_product(lhVectorX, rhVectorX) > 0) return false;
				else if (LR::Point::cross_product(lhVectorX, rhVectorX) == 0)
				{
					if (lhVectorX.get_R() < rhVectorX.get_R())return false;
				}
				else return true;
				return true;
			}
		} comparator;
	public:
		Binary_heap_point();
		Binary_heap_point(std::vector<LR::Point>&);
		~Binary_heap_point();
		const LR::Point& get_origin() const;
		void pop();
		virtual void push(LR::Point&);
	protected:
		virtual void _heapify(size_t);
		virtual void _erase(size_t);
	};
}