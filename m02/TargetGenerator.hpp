#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:
    TargetGenerator(TargetGenerator const &other);
    TargetGenerator &operator=(TargetGenerator const &other);
    std::map<std::string, ATarget *> arr_targ;

public:
    TargetGenerator() {};
    ~TargetGenerator()
    {
        std::map<std::string, ATarget *>::iterator it_begin = this->arr_targ.begin();
        std::map<std::string, ATarget *>::iterator it_end = this->arr_targ.end();
        while (it_begin != it_end)
        {
            delete it_begin->second;
            ++it_begin;
        }
        this->arr_targ.clear();
    }
    void learnTargetType(ATarget const *other)
    {
        if (other)
            arr_targ.insert(std::pair<std::string, ATarget *>(other->getType(), other->clone()));
    }
    void forgetTargetType(std::string const spell_name)
    {
        arr_targ.erase(spell_name);
    }
    ATarget* createTarget(std::string const &spell_name)
    {
        std::map<std::string, ATarget *>::iterator it = arr_targ.find(spell_name);
        if (it != arr_targ.end())
        {
            return arr_targ[spell_name];
        }
        return NULL;
    }
};
