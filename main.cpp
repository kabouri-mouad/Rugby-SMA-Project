#include <iostream>
#include "mt19937ar.c"
#include "SimulationRugby.hpp"

int main(int, char **) {

    //Initialisation du générateur MT
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    SimulationRugby simulation;
    simulation.demarrer();

    return 0;
}
