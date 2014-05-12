
#include <stdexcept>
#include <iostream>
#include "line.h"

int main()
{
	try
	{
		Frame frm;
		Line l(1, 1, 1, 10);
		l.Draw(&frm);
		frm.Print();

		system("pause");

		return 0;
	}
	catch (std::exception& ex)
	{
		std::cerr << std::endl << "Exception: " << ex.what() << std::endl;
		system("pause");
		return -1;
	}
	catch ( ... )
	{
		std::cerr << std::endl << "Unknown exception" << std::endl;
		system("pause");
		return -2;
	}
}