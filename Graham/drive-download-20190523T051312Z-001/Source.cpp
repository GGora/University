#include <iostream>
#include <fstream>
#include "Point.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "Stack.h"
#include "priority_queue.h"
#include "Binary_heap.h"
#include "Binary_heap_point.h"
#include "Priority_queue.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "<<<<Graham scan>>>>\n\n";
	string path;
	ifstream coord_file;
	try {
		if (argc == 2)
		{
			path = argv[1];
			coord_file.open(argv[1], ios_base::in);
		}
		else
		{
			cout << "Input the path: ";
			cin >> path;
			coord_file.open(path, ios_base::in);
		}
		if (!coord_file.is_open())
		{
			throw path;
		}
	}
	catch (string ex)
	{
		std::cerr <<"file: " <<ex<< " couldn't be opened" << "\n";
	}

	//Reading the points
	vector<LR::Point> SetOfPoints;
	string point_s;
	while (getline(coord_file, point_s))
	{
		istringstream iss(point_s);
		double x, y;
		iss >> x >> y;
		SetOfPoints.push_back(LR::Point(x, y));
	}

	LR::Binary_heap_point heap_of_points(SetOfPoints);//Heap of points
	LR::Stack<LR::Point> stack_of_points;//Stack of the convex hull
	LR::Point origin = heap_of_points.get_origin();//origin point
	stack_of_points.push(origin);// the origin point put to stack as first point of the convex hull
	LR::Priority_queue<LR::Point> queue_of_points(heap_of_points);//queue of points
		
	stack_of_points.push(queue_of_points.top());// top point of queue pushed to stack
	queue_of_points.pop();
	
	
	auto stack_top = stack_of_points.top();
	auto queue_top = queue_of_points.top();
	auto next_to_top = origin;//first next_to_top point equals origin
	while (queue_of_points.size() != 0)
	{
		queue_top = queue_of_points.top();// top element of queue
		LR::Point basic_vector = stack_top - next_to_top;
		LR::Point new_vector = queue_top - next_to_top;
		double CP = LR::Point::cross_product(basic_vector, new_vector);
		if (CP > 0)
		{
			next_to_top = stack_top;
			stack_top = queue_top;
			stack_of_points.push(queue_top);
			queue_of_points.pop();
		}
		else if (CP == 0)
		{
			stack_of_points.pop();
			stack_top = queue_top;
			stack_of_points.push(stack_top);
			stack_top = queue_of_points.top();
			queue_of_points.pop();

		}
		else
		{
			stack_of_points.pop();
			stack_top = stack_of_points.top();
			stack_of_points.pop();
			next_to_top = stack_of_points.top();
			stack_of_points.push(stack_top);
		}

	}
	ostringstream oss;
	cout << "The points of convex hull:" << endl;
	while (stack_of_points.top_index() >= 0)
	{
		oss << stack_of_points.top()<< endl;
		stack_of_points.top().show_XY(cout) << endl;
		stack_of_points.pop();
	}
	
	string convex_hull_path;
	cout << "Input the path or file name: ";
	cin >> convex_hull_path;
	try {
		ofstream convex_hull_file(convex_hull_path, ios_base::out | ios_base::trunc);
		if (!convex_hull_file.is_open()) throw "incorrect path or filename";
		convex_hull_file << oss.str();
		convex_hull_file.close();
	}
	catch (string ex)
	{
		std::cerr << ex << endl;
	}
	cout << "file has been writen successfully" << endl;
	cout << "Press \"Enter\" to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	return 0;

}