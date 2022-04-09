#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;
public:
    ASpell() {};
    ASpell(ASpell const &other)
    {
        *this = other;
    }
    ASpell &operator=(ASpell const &other)
    {
        this->name = other.name;
        this->effects = other.effects;
        return (*this);
    }
    virtual ~ASpell() {}
    std::string const &getName() const
    {
        return this->name;
    }
    std::string const &getEffects() const
    {
        return this->effects;
    }
    ASpell(std::string name, std::string effects)
    {
        this->name = name;
        this->effects = effects;
    }
    virtual ASpell *clone() const = 0;

    void launch(ATarget const &other) const;
};
