#pragma once

#include <iostream>

class Aspell;

class ATarget
{
private:
    std::string type;
public:
    ATarget();
    ATarget(std::string const &type);
    ATarget(ATarget const &other);
    ATarget &operator=(ATarget const &other);
    virtual ~ATarget();

    std::string const &getType() const;

    void getHitBySpell(Aspell const &aspell_ref) const;

    virtual ATarget *clone() const = 0;
};

#include "Aspell.hpp"