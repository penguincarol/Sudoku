//
// Created by johnny on 12.05.25.
//
#pragma once
extern "C" {
#include "kissat.h"
}

namespace input{
    int readInput(kissat* solver);
}