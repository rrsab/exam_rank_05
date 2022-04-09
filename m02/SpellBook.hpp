#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
    SpellBook(SpellBook const &other);
    SpellBook &operator=(SpellBook const &other);
    std::map<std::string, ASpell *> arr_spell;

public:
    SpellBook() {};
    ~SpellBook()
    {
        std::map<std::string, ASpell *>::iterator it_begin = this->arr_spell.begin();
        std::map<std::string, ASpell *>::iterator it_end = this->arr_spell.end();
        while (it_begin != it_end)
        {
            delete it_begin->second;
            ++it_begin;
        }
        this->arr_spell.clear();
    }
    void learnSpell(ASpell const *other)
    {
        if (other)
            arr_spell.insert(std::pair<std::string, ASpell *>(other->getName(), other->clone()));
    }
    void forgetSpell(std::string const spell_name)
    {
        arr_spell.erase(spell_name);
    }
    ASpell* createSpell(std::string const &spell_name)
    {
        std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
        if (it != arr_spell.end())
        {
            return arr_spell[spell_name];
        }
        return NULL;
    }
};
