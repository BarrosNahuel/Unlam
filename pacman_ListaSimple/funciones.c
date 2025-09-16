#include "funciones.h"

void crearLoteSimple(){
    int i;
    float datos[] = {2.34, 1.23, 2.34, 3.45, 1.23, 4.56, 9.01, 5.67, 6.78, 7.89, 8.90, 9.01};
    FILE *pf = fopen("lote.txt", "wt");
    if(!pf)
        return;

    for(i=0;i<(sizeof(datos)/sizeof(float));i++){
        fprintf(pf, "%.2f\n", *(datos + i));
    }
    fclose(pf);
}
void crearLoteEstructura(){
    tPersona personas[] = {{"Nahuel Barros", 'H', {15,7,2004}},//<--
                           {"Anahi Rodriguez", 'M', {12,2,2005}},
                           {"Roberto Gonzalez", 'H', {14,8,2003}},
                           {"Anahi Rodriguez", 'M', {12,2,2005}},
                           {"Marcos Mondello", 'H', {5,5,1999}},
                           {"Gabriela Ocaña", 'M', {3,10,1984}},//<----
                           {"Tomas Fernandez", 'H', {15,7,2004}},//<--
                           {"Julieta Venegas", 'M', {15,7,2004}},//<--
                           {"Marcos Mondello", 'H', {5,5,1999}},
                           {"Francisca Robledo", 'M', {3,10,1984}},//<----
                            };
    FILE *pf = fopen("lote.dat", "wb");
    if(!pf)
        return;

    fwrite(&personas, sizeof(personas), 1, pf);

    fclose(pf);
}
char menu(const char *msj, const char *opc){
    char res;
    do{
        printf("%s", msj);
        fflush(stdin);
        scanf("%c", &res);
    }while(strchr(opc, res) == NULL);

    return res;
}
int cargarListaArchTxtOrd(tLista *p, const char *nombArch, CMP cmp ,int dupl){
    char linea[10];
    float dato;
    FILE *pf = fopen(nombArch, "rt");
    if(!pf)
        return 0;
    while(fgets(linea, sizeof(linea), pf)){
        sscanf(linea, "%f", &dato);
        insertarOrdenado(p, &dato, sizeof(float), cmp, dupl);
    }
    fclose(pf);
    return 1;
}
int cargarListaArchBinOrd(tLista *p, const char *nombArch, CMP cmp, int dupl){
    tPersona pers;
    FILE *pf = fopen(nombArch, "rt");
    if(!pf)
        return 0;
    while(fread(&pers, sizeof(tPersona), 1, pf)){
        insertarOrdenado(p, &pers, sizeof(tPersona), cmp, dupl);
    }
    fclose(pf);
    return 1;
}
void mostrarFloat(void *d){
    printf("%.2f\n", *(float*)d);
}
void mostrarPersona(void *d){
    tPersona *p = (tPersona*)d;
    printf("%s, %c, %d/%d/%d\n", p->nom, p->sexo, p->fecNac.dia, p->fecNac.mes, p->fecNac.anio);
}
int compararFloat(const void *d1, const void *d2){
    return (*(float*)d1 - *(float*)d2);
}
int compararPersonas(const void *d1, const void *d2){
    tPersona *per1 = (tPersona*)d1, *per2 = (tPersona*)d2;

    if(per1->sexo != per2->sexo)
        return (per1->sexo - per2->sexo);
    if((per1->fecNac.anio - per2->fecNac.anio))
        return (per1->fecNac.anio - per2->fecNac.anio);
    if((per1->fecNac.mes - per2->fecNac.mes))
        return (per1->fecNac.mes - per2->fecNac.mes);

    return (per1->fecNac.dia - per2->fecNac.dia);
}







