#include "ASpell.hpp"
#include "ATarget.hpp"

    void ASpell::launch(ATarget const &other) const
    {
        other.getHitBySpell(*this);
    }