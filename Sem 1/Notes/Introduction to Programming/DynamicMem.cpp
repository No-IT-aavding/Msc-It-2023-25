#include <vcruntime_string.h>
#include <corecrt_malloc.h>
#include <stdlib.h>
#include <iostream>

struct Circle
{
	Circle()
	{
		rad = area = 0;
	}
	float rad;
	double area;
};

Circle** CreateCircles(const int& n)
{
	Circle** p = new Circle * [n];

	for (int i{ 0 }; i < n; i++)
		*(p + i) = new Circle();

	return p;
}
void ReadRadiiAndUpdateCircles(Circle**& const p, const int& n)
{
	for (int i{ 0 }; i < n; i++)
	{
		(*(p + i))->rad = rand() % 100;
	}
}

void CalculateAreas(Circle**& const p, const int& n)
{
	for (int i{ 0 }; i < n; i++)
	{
		(*(p + i))->area = (*(p + i))->rad * (*(p + i))->rad * 3.14159;
	}
}

void Display(Circle**& p, const int& n)
{
	for (int i{ 0 }; i < n; i++)
	{
		auto rad = (*(p + i))->rad;
		auto area = (*(p + i))->area;
		std::cout << "Circle " << i + 1 << ": Radius = " << rad << ", Area = " << area << std::endl;
	}
}

void DeleteCircles(Circle**& p, const int& n)
{
	for (int i{ 0 }; i < n; i++)
		delete* (p + i);

	delete[] p;

	p = nullptr;

}

void main()
{
	int num{ 10 };
	auto p = CreateCircles(num);

	ReadRadiiAndUpdateCircles(p, num);

	CalculateAreas(p, num);

	Display(p,num);

	DeleteCircles(p, num);

}

void arraysOnFreeStore()
{
	// allocate one dim array on free store

	int intArray[100];

	int j{ 10 };

	int* p = new int[j] {0};
	// use
	// end - free the allocated
	delete []p;

	// allocate multidim
	int twoD[3][5];

	int rows{ 10 };

	//int* twoDd[5]{ new int[rows][5] };

	// array of pointers

	// int* p = new int[j] {0};
	int** x = new int* [j];
	int k{ 30 };
	// allocating rows (or, array columns) to each row pointer
	for (int i{ 0 }; i < j; i++)
	{
		*(x + i) = new int[k];
	}

	*(*(x + 5) + 3) = 8; // use


	// end
	for (int i{ 0 }; i < j; i++) {
		delete[] * (x + i);
		//delete[] x[i];
	}

	delete[] x;

}