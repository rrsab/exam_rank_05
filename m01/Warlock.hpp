#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

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
    std::map<std::string, ASpell *> arr;

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
    void learnSpell(ASpell const *other)
    {
        if (other)
            arr.insert(std::pair<std::string, ASpell *>(other->getName(), other->clone()));
    }
    void forgetSpell(std::string spell_name)
    {
        arr.erase(spell_name);
    }
    void launchSpell(std::string spell_name, const ATarget &atarget_ptr)
    {
        ASpell *spell = arr[spell_name];
        if (spell)
            spell->launch(atarget_ptr);
    }
};
