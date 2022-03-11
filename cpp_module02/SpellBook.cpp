#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::map<std::string, Aspell *>::iterator it_begin = this->arr_spell.begin();
    std::map<std::string, Aspell *>::iterator it_end = this->arr_spell.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->arr_spell.clear();
}

void SpellBook::learnSpell(Aspell *spell_ptr)
{
    if (spell_ptr)
    {
        arr_spell.insert(std::pair<std::string, Aspell *>(spell_ptr->getName(), spell_ptr->clone()));
    }
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
    arr_spell.erase(spell_name);
}

Aspell* SpellBook::createSpell(std::string const &spell_name)
{
    std::map<std::string, Aspell *>::iterator it = arr_spell.find(spell_name);
    if (it != arr_spell.end())
    {
        return arr_spell[spell_name];
    }
    return NULL;
}