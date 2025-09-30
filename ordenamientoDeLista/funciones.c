#include "funciones.h"

int compararInt(const void *d1, const void *d2){
    return (*(int*)d1 - *(int*)d2);
}
void mostrarInt(const void *d){
    printf("[%d]", *(int*)d);
}
void crearLoteTxt(){
    int i;
    tPersona pers[] = { {"Barros Nahuel",'M',5526454},
                        {"Vazquez Benjamin",'M',12345678},
                        {"Barros Alejandro",'M',23456789},
                        {"Alegre Julieta",'F',34567890},
                        {"Romero Fernando",'M',45678901},
                        {"Moreno Agustina",'F',56789012},
                        {"Felicitas Guerrero",'F',67890123},
                        {"San Martin",'M',78901234},
                        {"Zabatella Mariano",'M',89012345},
    };
    FILE *pf = fopen("lote.txt", "wt");
    if(!pf)
        return;
    for(i=0;i<sizeof(pers)/sizeof(tPersona);i++){
        fprintf(pf,"%-25s%c%d\n", (*(pers + i)).nya, (*(pers + i)).sex, (*(pers + i)).dni);
    }
    fclose(pf);
}
void crearLoteInt(tLista *p){
    int dato, i;
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        dato = rand()%10;
        insertarEnLista(p, &dato, sizeof(int));
    }
}
int cargarListaTxt(tLista *p, const char *nombArch,unsigned tam, int trozar(char *buffer, void *dato)){
    void *dato = malloc(tam), *buffer = malloc(TAM_BUFF);
    FILE *pf = fopen(nombArch, "rt");
    if(!dato || !pf){
        free(dato);
        free(buffer);
        fclose(pf);
        return 0;
    }
    while(fgets(buffer, TAM_BUFF, pf)){
        trozar(buffer, dato);
        insertarEnLista(p, dato, tam);
    }

    free(dato);
    free(buffer);
    fclose(pf);
    return 1;
}
int trozar(char *buffer, void *dato){
    tPersona *per = (tPersona*)dato;

    if(!buffer || !dato) return 0;
    *(buffer + 36) = '\0';
    sscanf(buffer + 26, "%d", &(per->dni));
    *(buffer + 26) = '\0';
    sscanf(buffer + 25, "%c", &(per->sex));
    *(buffer + 25) = '\0';
    strcpy(per->nya, buffer);
    return 1;
}
int compararPersonas(const void *d1, const void *d2){
    tPersona *per1 = (tPersona*)d1, *per2 = (tPersona*)d2;
    return strcmpi(per1->nya, per2->nya);
}
void mostrarPersonas(const void *d){
    tPersona *per = (tPersona*)d;
    printf("%s %c %d\n", per->nya, per->sex, per->dni);
}
