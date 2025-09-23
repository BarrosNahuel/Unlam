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
    tProducto productos[] = {{"Pañales", 200, "Pampers"},
                            {"Vendas", 50, "Everlast"},
                            {"Pañales", 20, "Huggies"},
                            {"Pilas", 10, "Andasiempre"},
                            {"Cepillo de dientes", 150, "Colgate"},
                            {"Vendas", 25, "Everlast"},
                            {"Cepillo de dientes elect", 10, "Colgate"},
                            {"Pasta de dientes", 70, "Colgate"},
                            {"Pañales", 100, "Pampers"},
                            {"Pilas", 30, "Duracell"},
                            {"Cepillo de dientes elect", 5, "Colgate"},
                            };
    FILE *pf = fopen("lote.dat", "wb");
    if(!pf)
        return;

    fwrite(&productos, sizeof(productos), 1, pf);

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
int cargarListaArchTxtOrd(tLista *p, const char *nombArch, CMP cmp ,int dupl, void acc(void*, const void*)){
    char linea[10];
    float dato;
    FILE *pf = fopen(nombArch, "rt");
    if(!pf)
        return 0;
    while(fgets(linea, sizeof(linea), pf)){
        sscanf(linea, "%f", &dato);
        insertarOrdenado(p, &dato, sizeof(float), cmp, dupl, acc);
    }
    fclose(pf);
    return 1;
}
int cargarListaArchBinOrd(tLista *p, const char *nombArch, CMP cmp, int dupl, void acc(void*, const void*)){
    tProducto prod;
    FILE *pf = fopen(nombArch, "rt");
    if(!pf)
        return 0;
    while(fread(&prod, sizeof(tProducto), 1, pf)){
        insertarOrdenado(p, &prod, sizeof(tProducto), cmp, dupl, acc);
    }
    fclose(pf);
    return 1;
}
void mostrarFloat(void *d){
    printf("%.2f\n", *(float*)d);
}
void mostrarProductos(void *d){
    tProducto *p = (tProducto*)d;
    printf("%-25s %-4d %-25s\n", p->nom, p->cant, p->marca);
}
int compararFloat(const void *d1, const void *d2){
    return (*(float*)d1 - *(float*)d2);
}
int compararProductos(const void *d1, const void *d2){
    tProducto *prod1 = (tProducto*)d1, *prod2 = (tProducto*)d2;
    int res;

    if((res = strcmpi(prod1->nom, prod2->nom)) == 0){
        res = strcmpi(prod1->marca, prod2->marca);
    }

    return res;
}
void accFloat(void* acum, const void* dato){
    float *numAcum = (float*)acum, *numDato = (float*)dato;
    *numAcum += *numDato;
}
void accProductos(void* acum, const void* dato){
    tProducto *prodAcum = (tProducto*)acum, *prodDato = (tProducto*)dato;
    prodAcum->cant += prodDato->cant;
}






