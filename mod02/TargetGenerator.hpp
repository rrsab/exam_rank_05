#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class TargetGenerator
{
private:
    TargetGenerator(TargetGenerator const &other){*this = other;}
    //TargetGenerator &operator=(TargetGenerator const &other){this = other.name; this->effects = other.effects; return (*this);}

    std::map<std::string, ATarget *> arr_spell;
public:
    TargetGenerator(){}
    ~TargetGenerator()
    {
        std::map<std::string, ATarget *>::iterator it_begin = arr_spell.begin();
        std::map<std::string, ATarget *>::iterator it_end = arr_spell.end();
        while (it_begin != it_end)
        {
            delete it_begin->second;
            ++it_begin;
        }
        this->arr_spell.clear();
    };
    
    void learnTargetType(ATarget* atarget_ptr)
    {
        if (atarget_ptr)
        {
            arr_spell.insert(std::pair<std::string, ATarget *>(atarget_ptr->getType(), atarget_ptr->clone()));
        }
    }
    void forgetTargetType(std::string const &spell_name)
    {
        arr_spell.erase(spell_name);
    }

    ATarget* createTarget(std::string const &spell_name)
    {
        std::map<std::string, ATarget *>::iterator it = arr_spell.find(spell_name);
        if (it != arr_spell.end())
        {
            return (arr_spell[spell_name]);
        }
        return NULL;        
    }

};