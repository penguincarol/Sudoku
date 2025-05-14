#pragma once
extern "C" {
#include "kissat.h"
}

namespace constr{
    void addCellsGiven(kissat* solver);

    //does not include cells given
    void addAllConstraints(kissat* solver);

    //appends the constraint that we cannot have to write at least one value into every cell
    // every cell must have at least one value between 1 and 9 inside of them
    void everyCellAtLeastOneVal(kissat* solver);

    // appends the constraint that we cannot write multiple values into the same cell
    //every cell must have at most one value between 1 and 9 inside of them
    void everyCellAtMostOneVal(kissat* solver);

    void everyNumInEachRow(kissat* solver);

    void everyNumOnlyOnceInEachRow(kissat* solver);

    void everyNumInEachCol(kissat* solver);

    void everyNumOnlyOnceInEachCol(kissat* solver);

    void everyNumInEachChunk(kissat* solver);

    void everyNumOnlyOnceInEachChunk(kissat* solver);

}