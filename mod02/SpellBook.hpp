#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class SpellBook
{
private:
    SpellBook(SpellBook const &other){*this = other;}
    //SpellBook &operator=(SpellBook const &other){this->name = other.name; this->effects = other.effects; return (*this);}

    std::map<std::string, ASpell *> arr_spell;
public:
    SpellBook(){}
    virtual ~SpellBook()
    {
        std::map<std::string, ASpell *>::iterator it_begin = arr_spell.begin();
        std::map<std::string, ASpell *>::iterator it_end = arr_spell.end();
        while (it_begin != it_end)
        {
            delete it_begin->second;
            ++it_begin;
        }
        this->arr_spell.clear();
    };
    
    void learnSpell(ASpell* aspell_ptr)
    {
        if (aspell_ptr)
        {
            arr_spell.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
        }
    }
    void forgetSpell(std::string const &spell_name)
    {
        arr_spell.erase(spell_name);
    }

    ASpell* createSpell(std::string const &spell_name)
    {
        std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
        if (it != arr_spell.end())
        {
            return (arr_spell[spell_name]);
        }
        return NULL;        
    }

};
