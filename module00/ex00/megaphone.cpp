#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string const defaultMessage = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

    if (argc == 1)
        std::cout << defaultMessage;
    for (int count_args = 1; count_args < argc; count_args++)
    {
        std::string arg(argv[count_args]);
        for (std::string::iterator it = arg.begin(); it != arg.end(); it++)
            *it = std::toupper(*it);
        std::cout << arg;
    }
    std::cout << std::endl;
    return (0);
}
