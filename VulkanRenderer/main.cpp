#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "first_app.h"

int main()
{
	lve::FirstApp app{};
	try
	{
		app.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	return 0;
}