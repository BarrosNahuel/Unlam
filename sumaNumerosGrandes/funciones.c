#include "funciones.h"

void crearArchivosPrueba(){
    int i;
    FILE *pf1 = fopen("numero1.txt", "wt"), *pf2 = fopen("numero2.txt", "wt");
    if(!pf1 || !pf2){
        fclose(pf1);
        fclose(pf2);
        return;
    }
    srand(time(NULL));
    for(i=0;i<32;i++){
        fprintf(pf1, "%d", rand()%10);
        fprintf(pf2, "%d", rand()%10);
    }
    fclose(pf1);
    fclose(pf2);
}
int sumarNumeros(const char *archNum1, const char *archNum2, const char *archRes){
    int num1, num2, suma, resto = 0;
    tPila pilaNum1, pilaNum2, pilaRes;

    crearPila(&pilaNum1);
    crearPila(&pilaNum2);
    crearPila(&pilaRes);

    if(!cargarNumerosEnPila(&pilaNum1, archNum1)){
        vaciarPila(&pilaNum1);
        return 0;
    }
    if(!cargarNumerosEnPila(&pilaNum2, archNum2)){
        vaciarPila(&pilaNum1);
        vaciarPila(&pilaNum2);
        return 0;
    }

    while(!pilaVacia(&pilaNum1) && !pilaVacia(&pilaNum2)){

        desapilar(&pilaNum1, &num1, sizeof(int));
        desapilar(&pilaNum2, &num2, sizeof(int));

        suma = num1 + num2 + resto;
        if(suma>=10){
            suma = suma % 10;
            resto = 1;
        }
        else{
            resto = 0;
        }

        apilar(&pilaRes, &suma, sizeof(int));
    }
    while(!pilaVacia(&pilaNum1)){
        desapilar(&pilaNum1, &num1, sizeof(int));
        if(resto){
            num1 += resto;
            resto = 0;
        }
        apilar(&pilaRes, &num1, sizeof(int));
    }
    while(!pilaVacia(&pilaNum2)){
        desapilar(&pilaNum2, &num2, sizeof(int));
        if(resto){
            num2 += resto;
            resto = 0;
        }
        apilar(&pilaRes, &num2, sizeof(int));
    }
    if(resto){
        apilar(&pilaRes, &resto, sizeof(int));
    }

    cargarPilaEnArchTxt(&pilaRes, archRes);

    return 1;
}
int cargarNumerosEnPila(tPila *p, const char *nombArch){
    int num;
    FILE *pf = fopen(nombArch, "rt");
    if(!pf)
        return 0;

    while((num = getc(pf)) != -1){
        CHTOINT(num);
        if(!apilar(p, &num, sizeof(int)))
            return 0;
    }

    fclose(pf);
    return 1;
}
int cargarPilaEnArchTxt(tPila *p, const char *nombArch){
    int num;
    FILE *pf = fopen(nombArch, "wt");
    if(!pf)
        return 0;
    while(desapilar(p, &num, sizeof(int))){
        fprintf(pf, "%d", num);
    }
    return 1;
}


