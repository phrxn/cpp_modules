#ifndef SERIALIZER_HPP 
#define SERIALIZER_HPP 

#include <stdint.h>

#include "Data.hpp"


class Serializer
{
    // ---------- constructor(s) and destructor ----------
    private:
        Serializer(void);
        Serializer(const Serializer &serializer);
        ~Serializer(void);
    
    // ---------- functions ----------
    public:
        static uintptr_t    serialize(Data *data);
        static Data         *deserialize(uintptr_t raw);

    private:
        //operator(s) overload
        Serializer &operator=(const Serializer &serializer);
};

#endif
