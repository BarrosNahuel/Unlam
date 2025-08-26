#include "funciones.h"

int procesarArchivoBin(const char *archBin, const char* nombTxtAprob, const char* nombTxtObs, int porc){
    float cantFallados, cantProd;
    tCola aprobados, fallados;
    tProducto prod;
    char codAct[5];
    FILE *pf = fopen(archBin, "rb");
    if(!pf)
        return 0;
    crearCola(&aprobados);
    crearCola(&fallados);

    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        strcpy(codAct, prod.codLote);
        cantFallados = 0;
        cantProd = 0;

        while(strcmp(codAct, prod.codLote) == 0 && !feof(pf)){
            if(strcmp(prod.resultadoControl, "FALLA") == 0){
                ponerEnCola(&fallados, &prod, sizeof(tProducto));
                cantFallados++;
            }
            else{
                ponerEnCola(&aprobados, &prod, sizeof(tProducto));
            }
            cantProd++;
            fread(&prod, sizeof(tProducto), 1, pf);
        }

        if((cantFallados/cantProd)*100 >= porc){
            cargarEnArchivoTxt(nombTxtObs, &fallados);
            cargarEnArchivoTxt(nombTxtObs, &aprobados);
        }
        else{
            cargarEnArchivoTxt(nombTxtAprob, &aprobados);
            cargarEnArchivoTxt(nombTxtAprob, &fallados);
        }
    }
    if(strcmp(codAct, prod.codLote) != 0){
        if(strcmp(prod.resultadoControl, "FALLA") == 0){
            ponerEnCola(&fallados, &prod, sizeof(tProducto));
            cargarEnArchivoTxt(nombTxtObs, &fallados);
        }
        else{
            ponerEnCola(&aprobados, &prod, sizeof(tProducto));
            cargarEnArchivoTxt(nombTxtAprob, &aprobados);
        }
    }
    fclose(pf);
    return 1;
}
int cargarEnArchivoTxt(const char* nombTxt, tCola *datos){
    tProducto prod;
    FILE *pf = fopen(nombTxt, "at");
    if(!pf)
        return 0;
    while(sacarDeCola(datos, &prod, sizeof(tProducto))){
        fprintf(pf, "%s,%d,%s\n", prod.codLote, prod.idProducto, prod.resultadoControl);
    }
    fclose(pf);
    return 1;
}


char menu(){
    char opc;
    do{
        printf("Ingrese una opcion:\n");
        printf("a.Ingresar porcentaje de fallas\n");
        printf("b.Procesar archivo de entrada\n");
        printf("c.Mostrar archivo de entrada\n");
        printf("d.Mostrar el contenido de los archivos de salida\n");
        printf("e.Salir\n");
        fflush(stdin);
        scanf("%c", &opc);
    }while(!strchr("ABCDEabcde", opc));
    return opc;
}
int mostrarArchivoBin(const char *nombArch, unsigned tam, void accion(void *dato)){
    FILE *pf = fopen(nombArch, "rb");
    void *dato = malloc(tam);
    if(!dato || !pf)
        return 0;
    while(fread(dato, tam, 1, pf)){
        accion(dato);
    }
    fclose(pf);
    free(dato);
    return 1;
}
int mostrarArchivoTex(const char *nombArch){
    char linea[MAX_LINEA];
    FILE *pf = fopen(nombArch, "rt");
    if(!pf)
        return 0;
    while(fgets(linea, MAX_LINEA, pf)){
        printf("%s", linea);
    }
    fclose(pf);
    return 1;
}
void mostrarProducto(void *dato){
    tProducto *prod = (tProducto*)dato;
    printf("Codigo de Lote: %s, Id del Producto: %d, Resultado del Control: %s\n", prod->codLote, prod->idProducto, prod->resultadoControl);
}
void crearLotePruebas(){
    tProducto prods[] = {
        {"L001", 1, "OK"},
        {"L001", 2, "FALLA"},
        {"L002", 3, "FALLA"},
        {"L003", 4, "FALLA"},
        {"L003", 5, "OK"},
        {"L003", 6, "OK"},
        {"L003", 7, "FALLA"},
        {"L003", 8, "OK"},
        {"L005", 9, "OK"},
        {"L005", 10, "OK"},
        {"L006", 11, "FALLA"},
        {"L006", 12, "OK"},
        {"L006", 13, "FALLA"},
        {"L006", 14, "OK"},
        {"L007", 15, "OK"},
        {"L007", 16, "OK"},
        {"L007", 17, "OK"},
        {"L007", 18, "FALLA"},
        {"L009", 19, "FALLA"},
        {"L009", 20, "OK"},
        {"L009", 21, "OK"},
        {"L009", 22, "OK"},
    };
    FILE *pf = fopen("entrada.bin", "wb");
    if(!pf)
        return;
    fwrite(&prods, sizeof(prods), 1, pf);
    fclose(pf);
}
