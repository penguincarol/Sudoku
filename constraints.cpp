extern "C" {
#include "kissat.h"
}
#include "utils.h"

namespace constr {

    void addCellsGiven(kissat* solver){
        kissat_add(solver, utils::cell_to_literal(2,1,6));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(3,1,1));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(4,1,8));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(9,1,7));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(2,2,8));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(3,2,9));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(4,2,2));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(6,2,5));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(8,2,4));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(5,3,4));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(7,3,9));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(9,3,3));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(1,4,2));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(4,4,1));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(4,4,1));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(5,4,6));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(7,4,3));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(1,5,6));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(2,5,7));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(8,5,5));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(9,5,1));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(3,6,4));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(5,6,2));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(6,6,3));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(9,6,8));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(1,7,7));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(3,7,5));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(5,7,9));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(2,8,9));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(4,8,4));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(6,8,2));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(7,8,7));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(8,8,3));
        kissat_add(solver, 0);

        kissat_add(solver, utils::cell_to_literal(1,9,1));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(6,9,8));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(7,9,4));
        kissat_add(solver, 0);
        kissat_add(solver, utils::cell_to_literal(8,9,6));
        kissat_add(solver, 0);
    }

    void everyCellAtLeastOneVal(kissat *solver) {
        for(int r = 1; r <= 9; r++){
            for(int c=1; c<=9; c++){
                for(int num = 1; num <= 9; num++){
                    kissat_add(solver, utils::cell_to_literal(r, c, num));
                }
                kissat_add(solver, 0);
            }
        }
    }

    void everyCellAtMostOneVal(kissat* solver){
        for(int r = 1; r <= 9; r++){
            for(int c=1; c<=9; c++){
                for(int num = 1; num <= 8; num++) {//num only goes to 8 here, careful
                    kissat_add(solver, -utils::cell_to_literal(r, c, num));
                    kissat_add(solver, -utils::cell_to_literal(r, c, num + 1));
                    kissat_add(solver, 0);
                }
            }
        }
    }

    void everyNumOnlyOnceInEachRow(kissat* solver){
        for(int r = 1; r <= 9; r++){
            for(int num = 1; num <= 9; num++){
                for(int c1=1; c1<=8; c1++){//col only to 8
                    for(int c2 = c1 + 1; c2 <= 9; c2++){
                        kissat_add(solver, -utils::cell_to_literal(r, c1, num));
                        kissat_add(solver, -utils::cell_to_literal(r, c2, num));
                        kissat_add(solver, 0);
                    }
                }
            }
        }
    }

    void everyNumInEachRow(kissat* solver){
        for(int num=1; num <= 9; num++){
            for(int r=1; r <=1; r++){
                for(int col = 1; col <= 9; col++){
                    kissat_add(solver, utils::cell_to_literal(r, col, num));
                }
                kissat_add(solver, 0);
            }
        }
    }

    void everyNumOnlyOnceInEachCol(kissat* solver){
        for(int c=1; c<=9; c++){
            for(int num = 1; num <= 9; num++){
                for(int r1 = 1; r1 <= 8; r1++){//row only goes to 8 here
                    for(int r2 = r1 + 1; r2 <= 9; r2++){
                        kissat_add(solver, -utils::cell_to_literal(r1, c, num));
                        kissat_add(solver, -utils::cell_to_literal(r2, c, num));
                        kissat_add(solver, 0);
                    }
                }
            }
        }
    }

    void everyNumInEachCol(kissat* solver){
        for(int num=1; num <= 9; num++){
            for(int col=1; col <=9; col++){
                for(int row = 1; row <= 9; row++){
                    kissat_add(solver, utils::cell_to_literal(row, col, num));

                }
                kissat_add(solver, 0);
            }
        }
    }

    void everyNumInEachChunk(kissat* solver){
        for(int num = 1; num <=9; num++){
            for(int chunk_row=0; chunk_row < 3; chunk_row++){
                for(int chunk_col=0; chunk_col < 3; chunk_col++){

                    for(int r = 1; r<=3; r++){
                        for(int c=1; c<=3; c++){
                            kissat_add(solver,
                                       utils::cell_to_literal((3 * chunk_row + r), (3 * chunk_col + c), num));
                        }
                    }
                    kissat_add(solver, 0);

                }
                }
            }
        }
    void everyNumOnlyOnceInEachChunk(kissat* solver){
        for(int num=1; num <=9; num++){
            for(int chunk_row = 0; chunk_row < 3; chunk_row++){
                for(int chunk_col = 0; chunk_col < 3; chunk_col++){

                    for(int r1 = 1; r1 <=2; r1++){
                        for(int c1 = 1; c1 <= 2; c1++){
                            for(int r2 = r1; r2 <=3; r2++){
                                for(int c2=c1; c2 <= 3; c2++) {
                                    if(r1==r2 && c1==c2) continue;
                                    kissat_add(solver,
                                               -utils::cell_to_literal((3 * chunk_row + r1), (3 * chunk_col + c1), num));
                                    kissat_add(solver,
                                               -utils::cell_to_literal((3 * chunk_row + r2), (3 * chunk_col + c2), num));
                                    kissat_add(solver, 0);
                                }
                            }
                        }
                    }
                }
            }
        }

/*
        //i think the paper is just wrong here
        for(int num=1; num <=9; num++){
            for(int chunk_row = 0; chunk_row < 3; chunk_row++){
                for(int chunk_col = 0; chunk_col < 3; chunk_col++){
                    for(int r = 1; r <=3; r++){
                        for(int c1 = 1; c1 <= 2; c1++){
                            for(int c2=c1+1; c2 <= 3; c2++){
                                kissat_add(solver, -utils::cell_to_literal((3*chunk_row+r), (3*chunk_col+c1), num));
                                kissat_add(solver, -utils::cell_to_literal((3*chunk_row+r), (3*chunk_col+c2), num));
                                kissat_add(solver, 0);
                            }
                        }
                    }
                }
            }
        }

        for(int num=1; num <=9; num++){
            for(int chunk_row = 0; chunk_row < 3; chunk_row++){
                for(int chunk_col = 0; chunk_col < 3; chunk_col++){
                    for(int r1 = 1; r1 <=2; r1++){
                        for(int c = 1; c <= 3; c++){
                            for(int r2=r1+1; r2 <= 3; r2++){
                                kissat_add(solver, -utils::cell_to_literal((3*chunk_row+r1), (3*chunk_col+c), num));
                                kissat_add(solver, -utils::cell_to_literal((3*chunk_row+r2), (3*chunk_col+c), num));
                                kissat_add(solver, 0);
                            }
                        }
                    }
                }
            }
        }*/

    }

    void addAllConstraints(kissat* solver){
        everyCellAtLeastOneVal(solver);
        everyCellAtMostOneVal(solver);
        everyNumInEachRow(solver);
        everyNumOnlyOnceInEachRow(solver);
        everyNumInEachCol(solver);
        everyNumOnlyOnceInEachCol(solver);
        everyNumInEachChunk(solver);
        everyNumOnlyOnceInEachChunk(solver);
    }
}



