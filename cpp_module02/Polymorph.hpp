#pragma once

#include "Aspell.hpp"

class Polymorph: public Aspell
{
public:
    Polymorph();
    ~Polymorph();

    virtual Aspell *clone() const;
};

