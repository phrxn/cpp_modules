#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{

    // ---------- variable(s) ----------
    private:
        int         value;
        std::string name;

    // ---------- constructor(s) and destructor ----------
    public:
        Data(void);
        Data(const Data &data);
        Data(int valud, std::string const &name);
        ~Data(void);
    
    // ---------- functions ----------
    public:
        int getValue(void);
        void setValue(int value);
        std::string const &getName(void);
        void setName(std::string const &name);

        // operator(s) overload
        Data &operator=(const Data &data);
};

#endif
