#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
        
        SpellBook book;
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &title);
        void introduce() const;

        void learnSpell(ASpell *aspell_ptr)
        {
            if (aspell_ptr)
            {
                book.learnSpell(aspell_ptr);
            }
        }
        void forgetSpell(std::string spell_name)
        {
            book.forgetSpell(spell_name);
        }
        void launchSpell(std::string spell_name, ATarget const &other)
        {
            ASpell* spell = book.createSpell(spell_name);
            if (spell)
            {
                spell->launch(other);
            }
            //return NULL;            
        }
};