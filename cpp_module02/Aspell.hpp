#pragma once

#include <iostream>

class ATarget;

class Aspell
{
private:
    std::string name;
    std::string effects;
public:
    Aspell();
    Aspell(std::string const &name, std::string const &effects);
    Aspell(Aspell const &other);
    Aspell &operator=(Aspell const &other);
    virtual ~Aspell();
    std::string const &getName() const;
    std::string const &getEffects() const;

    void launch(ATarget const &atarget_ref) const;

    virtual Aspell *clone() const = 0;
};

#include "ATarget.hpp"
