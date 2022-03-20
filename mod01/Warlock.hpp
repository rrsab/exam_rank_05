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

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
        std::map<std::string, ASpell *> arr;
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
                arr.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
            }
        }
        void forgetSpell(std::string spell_name)
        {
            arr.erase(spell_name);
        }
        void launchSpell(std::string spell_name, ATarget const &other)
        {
            ASpell* spell = arr[spell_name];
            if (spell)
            {
                return spell->launch(other);
            }
            //return NULL;            
        }
};