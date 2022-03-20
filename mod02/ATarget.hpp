#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
    std::string type;
public:
    ATarget() {};
    ATarget(std::string type){this->type = type;}
    ATarget(ATarget const &other){*this = other;}
    ATarget &operator=(ATarget const &other){this->type = other.type; return (*this);}
    virtual ~ATarget() {};
    std::string const &getType() const {return type;}
    virtual ATarget *clone() const = 0;
    void getHitBySpell(ASpell const &other) const;
};