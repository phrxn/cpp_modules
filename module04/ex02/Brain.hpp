#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    // --- variable(s)
    public:
        static const int IDEAS_NUMBER = 100;
    private:
        std::string ideas[IDEAS_NUMBER];

    // --- constructor(s) and destructor ---
    public:
        Brain(void);
        Brain(const Brain &brain);
        ~Brain();

    // --- functions ---
    public:
        //operator(s) overload
        Brain &operator=(const Brain &brain);

        //functions
        std::string getIdea(unsigned int index);
        void        setIdea(unsigned int index, const std::string &newIdeia);
};

#endif
