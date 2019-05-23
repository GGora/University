#pragma once
#include <cmath>
#include <iostream> 
using namespace std;


namespace LR 
{
	

	class Point
	{
	private:
		double xVal;
		double yVal;
		double cosine;
		double sine;
		double radius;
		double acos;
		double asin;
	public:
		static double cross_product(const LR::Point&, const LR::Point&);
		Point();
		Point(double, double);
		Point(const Point&);
		double get_Y() const;
		double get_X() const;
		double get_R() const;
		double get_cos() const;
		double get_sin() const;
		double get_acos() const;
		double get_asin() const;
		ostream& show_XY(ostream&) const;//output XY as: "X = *; Y = *"
		ostream& show_attrs(ostream&) const;//output: all atributes to stream
		friend ostream& operator << (ostream&, const LR::Point&);//output: X,Y magnitude to stream
		friend bool operator < (const LR::Point&, const LR::Point&);//comparing the points according to the cross product and magnitude
		friend bool operator > (const LR::Point&, const LR::Point&);//comparing the points according to the cross product and magnitude
		friend bool operator == (const LR::Point&, const LR::Point&);//comparing the points according to the cross product and magnitude
		const Point& operator - (const LR::Point&);
		Point& operator = (const Point&);
		~Point();
	};

	
}
