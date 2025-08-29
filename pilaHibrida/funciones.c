#include "funciones.h"

void crearLote(){
    tEstudiante est[] = {{"Nahuel", 100, "Ingenieria"},
                       {"Benjamin", 200, "Ingenieria"},
                       {"Maria", 300, "Medicina"},
                       {"Ramiro", 400, "Sociales"},
                       {"Lucas", 500, "Economicas"},
                       {"Jazmin", 600, "Sociales"},
                       {"Morena", 700, "Ingenieria"},
                       {"Nicolas", 800, "Medicina"},
                       {"Jorge", 900, "Economicas"},
                       {"Agustin", 1000, "Sociales"},
                    };
    FILE *pf = fopen("prueba.dat", "wb");
    if(!pf)
        return;
    fwrite(est, sizeof(est), 1, pf);
    fclose(pf);
}
int cargarPilaDesdeArchBin(tPila *p, const char *nombArch, unsigned tam){
    void *aux = malloc(tam);
    FILE *pf = fopen(nombArch, "rb");

    if(!pf){
        free(aux);
        return 0;
    }
    if(!aux){
        fclose(pf);
        return 0;
    }

    while(fread(aux, tam, 1, pf) && !pilaLlena(p, tam)){
        apilar(p, aux, tam);
    }
    free(aux);
    if(feof(pf)){
        fclose(pf);
        return 1;
    }
    else{
        fclose(pf);
        return 0;
    }
}










