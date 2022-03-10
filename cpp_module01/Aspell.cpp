#include "Aspell.hpp"

Aspell::Aspell() {}

Aspell::Aspell(std::string const &name, std::string const &effects)
{
    this->name = name;
    this->effects = effects;
}

Aspell::Aspell(Aspell const &other)
{
    *this = other;
}

Aspell &Aspell::operator=(Aspell const &other)
{
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

Aspell::~Aspell() {}

std::string const &Aspell::getName() const
{
    return (this->name);
}

std::string const &Aspell::getEffects() const
{
    return (this->effects);
} 

void Aspell::launch(ATarget const &atarget_ref) const
{
    atarget_ref.getHitBySpell(*this);
}