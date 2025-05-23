#include "TPAlgoritmos.h"

int main(){
    tCola turnos;
    crearCola(&turnos);
    registrarTurno(&turnos, "Nahuel", 0, 1, 0, MAS1);
    registrarTurno(&turnos, "Bot", 2, 1, 1, MAS2);
    registrarTurno(&turnos, "Nahuel", 0, 1, 2, MENOS2);
    registrarTurno(&turnos, "Bot", 0, 0, 3, ESPEJO);
    registrarTurno(&turnos, "Nahuel", 0, 1, 4, MAS1);
    registrarTurno(&turnos, "Bot", 1, 1, 5, MAS1);
    registrarTurno(&turnos, "Nahuel", 1, 3, 6, MAS2);
    registrarTurno(&turnos, "Bot", 2, 3, 7, MAS1);
    registrarTurno(&turnos, "Nahuel", 2, 12, 8, MAS1);
    generarInforme(&turnos);
    return 0;
}
