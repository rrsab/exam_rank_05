#include "Warlock.hpp"

Warlock::Warlock()
{}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}

Warlock::Warlock(std::string name, std::string title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

std::string const &Warlock::getName() const
{
    return name;
}

std::string const &Warlock::getTitle() const
{
    return title;
}

void Warlock::setTitle(std::string const &title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

Warlock &Warlock::operator=(Warlock const &other)
{
    this->name = other.name;
    this->title = other.title;
    return (*this);
}

Warlock::Warlock(Warlock const &other)
{
    *this = other;
}