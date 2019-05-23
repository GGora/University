#include "Point.h"

namespace LR {


	
	Point::Point():Point(0, 0)
	{}

	Point::Point(double x, double y) : xVal{ x }, yVal{ y }
	{
		if (x == 0 && y == 0)
		{
			radius = 0;
			cosine = 0;
			sine = 0;
			acos = 0;
			asin = 0;
		}
		else
		{
			radius = sqrt(x*x + y * y);
			cosine = x / radius;
			sine = y / radius;
			LR::Point::acos = std::acos(cosine);
			LR::Point::asin = std::asin(sine);
		}
	}

	Point::Point(const Point& rhPoint) : xVal{ rhPoint.xVal }, yVal{ rhPoint.yVal },
		radius{ rhPoint.radius }, sine{ rhPoint.sine },
		cosine{ rhPoint.cosine }, acos{ rhPoint.acos },
		asin{ rhPoint.asin }{}
		

	double Point::get_Y() const
	{
		return yVal;
	}
	double Point::get_X() const
	{
		return xVal;
	}
	double Point::get_R() const
	{
		return radius;
	}
	double Point::get_cos() const
	{
		return cosine;
	}
	double Point::get_sin() const
	{
		return sine;
	}
	double Point::get_asin() const
	{
		return LR::Point::asin;
	}
	double Point::get_acos() const
	{
		return LR::Point::acos;
	}
	ostream& Point::show_attrs(ostream& os) const
	{
		os << "X = " << xVal << endl;
		os << "Y = " << yVal << endl;
		os << "R = " << radius << endl;
		os << "sin = " << sine << endl;
		os << "cos = " << cosine << endl;
		os << "asin = " << asin << endl;
		os << "acos = " << acos;
		return os;
	}
	ostream& LR::operator << (ostream& os, const LR::Point& p)
	{
		os << p.xVal <<" " << p.yVal;
		return os;
	}
	ostream& LR::Point::show_XY(ostream& os) const
	{
		os << "X = " << xVal << "; ";
		os << "Y = " << yVal;
		return os;
	}

	Point& LR::Point::operator = (const Point& rhPoint)
	{
		xVal = rhPoint.xVal;
		yVal = rhPoint.yVal;
		cosine = rhPoint.cosine;
		sine = rhPoint.sine;
		radius = rhPoint.radius;
		acos = rhPoint.acos;
		asin = rhPoint.asin;
		return *this;
	}
	
	bool operator < (const LR::Point& lhPoint, const LR::Point& rhPoint)
	{
		double CP = LR::Point::cross_product(lhPoint, rhPoint);
		if (CP < 0)
		{
			return true;
		}
		else if(CP == 0)
		{
			if (lhPoint.radius < rhPoint.radius) return true;
			else return false;
		}
		else
		{
			return false;
		}
	}

	

	bool operator > (const LR::Point& lhPoint, const LR::Point& rhPoint)
	{
		double CP = LR::Point::cross_product(lhPoint, rhPoint);
		if (CP > 0)
		{
			return true;
		}
		else if (CP == 0)
		{
			if (lhPoint.radius > rhPoint.radius) return true;
			else return false;
		}
		else
		{
			return false;
		}
	}
	
	bool operator == (const LR::Point& lhPoint, const LR::Point& rhPoint)
	{
		if (lhPoint.xVal == rhPoint.xVal && lhPoint.yVal == rhPoint.yVal) return true;
		else return false;

	}
	
	const Point& Point::operator - (const LR::Point& rhPoint) 
	{
		double x = xVal - rhPoint.get_X();
		double y = yVal - rhPoint.get_Y();
		return Point(x, y);

	}
	
	Point::~Point()
	{

	}


	double Point::cross_product(const LR::Point& lhPoint, const LR::Point& rhPoint)
	{
		return lhPoint.xVal*rhPoint.yVal - lhPoint.yVal*rhPoint.xVal;
	}


}