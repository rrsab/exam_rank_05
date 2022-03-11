#pragma once

#include "Aspell.hpp"

class Fwoosh: public Aspell
{
public:
    Fwoosh();
    ~Fwoosh();

    virtual Aspell *clone() const;
};
