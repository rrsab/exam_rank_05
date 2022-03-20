#include "ATarget.hpp"

void ATarget::getHitBySpell(ASpell const &other) const
{
    std::cout << this->type << " has been " << other.getEffects() << "!\n";
}
