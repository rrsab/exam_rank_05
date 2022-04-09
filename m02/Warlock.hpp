#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
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
    SpellBook book;

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
        book.learnSpell(other);
    }
    void forgetSpell(std::string const &spell_name)
    {
        book.forgetSpell(spell_name);
    }
    void    launchSpell(std::string spellname, const ATarget &atarget_ref)
    {
        ASpell* spell = book.createSpell(spellname);
        if (spell)
            spell->launch(atarget_ref);
    }
};
