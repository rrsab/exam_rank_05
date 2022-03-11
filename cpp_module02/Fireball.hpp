#pragma once

#include "Aspell.hpp"

class Fireball: public Aspell
{
public:
    Fireball();
    ~Fireball();

    virtual Aspell *clone() const;
};