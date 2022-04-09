#include "ATarget.hpp"
#include "ASpell.hpp"

    void ATarget::getHitBySpell(ASpell const &other) const
    {
        std::cout << type << " has been " << other.getEffects() << "!\n";
    }