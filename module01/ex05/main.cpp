#include "Harl.hpp"

#include <iostream>

int main(void)
{
    Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("NOTHING");

    std::cout << "\n-----\n" << std::endl;

	harl.complain("NOTHING");
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");

    return 0;
}
