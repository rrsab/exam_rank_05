#pragma once

#include <iostream>

class ASpell;

class ATarget
{
protected:
    std::string type;

public:
    ATarget() {};
    ATarget(ATarget const &other)
    {
        *this = other;
    }
    ATarget &operator=(ATarget const &other)
    {
        this->type = other.type;
        return (*this);
    }
    virtual ~ATarget() {}
    std::string const &getType() const
    {
        return this->type;
    }
    ATarget(std::string type)
    {
        this->type = type;
    }
    virtual ATarget *clone() const = 0;

    void getHitBySpell(ASpell const &other) const;
};
