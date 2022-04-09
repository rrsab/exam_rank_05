#pragma once

#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;
    Warlock() {};
    Warlock(Warlock const &other)
    {
        *this = other;
    }
    Warlock &operator=(Warlock const &other)
    {
        this->name = other.name;
        this->title = other.title;
        return (*this);
    }

public:
    ~Warlock()
    {
        std::cout << name << ": My job here is done!\n";
    }
    std::string const &getName() const
    {
        return this->name;
    }
    std::string const &getTitle() const
    {
        return this->title;
    }
    void setTitle(std::string const title)
    {
        this->title = title;
    }
    Warlock(std::string name, std::string title)
    {
        this->name = name;
        this->title = title;
        std::cout << name << ": This looks like another boring day.\n";
    }
    void introduce() const
    {
        std::cout << name << ": I am " << name << ", " << title << "!\n";
    }

};
