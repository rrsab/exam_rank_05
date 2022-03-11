#pragma once

#include "Aspell.hpp"
#include <map>

class SpellBook
{
private:
    SpellBook(SpellBook const &other);
    SpellBook &operator=(SpellBook const &other);

    std::map<std::string, Aspell *> arr_spell;
public:
    SpellBook();
    ~SpellBook();

    void learnSpell(Aspell *aspell_ptr);
    void forgetSpell(std::string const &name);
    Aspell* createSpell(std::string const &name);
};
