cmake_minimum_required(VERSION 3.21)
project(exam_rank_05_mod2-1)

set(CMAKE_CXX_STANDARD 14)

include_directories(mod02-1)

add_executable(exam_rank_05_mod2-1
        mod02-1/Warlock.cpp
        mod02-1/ASpell.cpp
        mod02-1/ATarget.cpp
        mod02-1/Fwoosh.cpp
        mod02-1/Fwoosh.hpp
        mod02-1/Dummy.cpp
        mod02-1/Dummy.hpp mod02-1/Fireball.cpp mod02-1/Fireball.hpp mod02-1/Polymorph.cpp mod02-1/Polymorph.hpp mod02-1/BrickWall.cpp mod02-1/BrickWall.hpp mod02-1/SpellBook.cpp mod02-1/SpellBook.hpp mod02-1/TargetGenerator.cpp mod02-1/TargetGenerator.hpp)
