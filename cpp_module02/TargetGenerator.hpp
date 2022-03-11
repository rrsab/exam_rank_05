#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
    TargetGenerator(TargetGenerator const &other);
    TargetGenerator &operator=(TargetGenerator const &other);

    std::map<std::string, ATarget *> arr_target;
public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget*);
    void forgetTargetType(std::string const &);
    ATarget* createTarget(std::string const &);
};
