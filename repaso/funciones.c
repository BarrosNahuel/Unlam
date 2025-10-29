#include "funciones.h"

void* myMemcpy(void* dest, const void* src, unsigned tam){
    int i;
    for(i=0;i<tam;i++){
        *((char*)dest + i) = *((char*)src + i);
    }
    return dest;
}
void* myMemmove(void* dest, const void* src, unsigned tam){
    int i;
    char *aux = (char*)malloc(tam);
    if(!aux) return NULL;
    for(i=0;i<tam;i++){
        *(aux + i) = *((char*)src + i);
    }
    for(i=0;i<tam;i++){
        *((char*)dest + i) = *(aux + i);
    }
    free(aux);
    return dest;
}
int isFibonacci(int nro){
    int fibo = 1, fiboAnt1 = 1, fiboAnt2 = 0;
    while(fibo < nro){
        fibo = fiboAnt1 + fiboAnt2;
        fiboAnt2 = fiboAnt1;
        fiboAnt1 = fibo;
    }
    return (fibo == nro);
}
void desofuscarLinea(char *linea){
    char letras[] = "abcdghijkoqtuv", *nuevaLetra;
    int pos = 0, aux;
    while(*linea){
        if(isalpha(*linea)) pos++;
        ///Si hay un espacio hay una nueva palabra
        if(isspace(*linea)){
            pos = 0;
        }
        if((nuevaLetra = strchr(letras, *linea))){
            ///Si al ir hacia adelante me paso
            if((nuevaLetra + pos) > (letras + strlen(letras) - 1)){
                ///Aux es la cantidad de letras que puedo ir hacia adelante
                aux = (nuevaLetra + pos) - (letras + strlen(letras));
                nuevaLetra = letras + aux;
                *linea = *nuevaLetra;
            }
            else{
                *linea = *(nuevaLetra + pos);
            }
        }
        linea++;
    }
}
//char* myStrchr(const char *linea, int val){
//    while(*linea != '\0' && *linea != val)
//        linea++;
//    return (*linea == val ? linea : NULL);
//}
//int myStrcmp(const char *s1, const char *s2){
//    while(*s1 && *s2 && *s1 == *s2){
//        s1++;
//        s2++;
//    }
//
//}
void ejercicio52(const char *linea, char *primerPalabra, int* cantRep, int *cantPal, int *palLarga){
    const char *aux;
    *cantPal = 0;
    *cantRep = 0;
    *palLarga = 0;

    while(linea){
        aux = strchr(linea, '.');
        ///si hay un punto es porque hay mas de una palabra restante
        if(aux){
            ///Si hubo repeticiones de la primer palabra es porque no estamos
            ///en la primer palabra y debemos ver si en la que estamos es igual a la primera
            if(*cantRep != 0){
                if(memcmp(primerPalabra, linea, aux - linea) == 0){
                    (*cantRep)++;
                }
            }
            ///Si no hay repeticiones es porque es la primer palabra, la debemos copiar en la variable
            else{
                memcpy(primerPalabra, linea, aux - linea);
                *(primerPalabra + (aux - linea)) = '\0';
                (*cantRep)++;
            }
            ///Actualizo cantidad de palabras y veo si esta palabra es mas larga que la mas larga encontrada
            (*cantPal)++;
            if(*palLarga < (aux - linea))
                *palLarga = aux - linea;
        }
        ///Estamos en la ultima palabra (puede ser ultima y primera) o no hay palabra
        else{
            if(strlen(linea) == 0) return;
            if(*cantRep != 0){
                if(strcmp(primerPalabra, linea) == 0){ ///-1?
                    (*cantRep)++;
                }
            }
            else{
                strcpy(primerPalabra, linea);
                (*cantRep)++;
            }
            (*cantPal)++;
            if(*palLarga < strlen(linea))
                *palLarga = strlen(linea);
        }
        linea = aux ? aux + 1 : aux;
    }
}
int ejercicio513(const char* nombArch){
    char linea[35], orden[5][35], *aux;
    int i;
    tAlumno alumno;
    FILE *pTxt = fopen(nombArch, "rt"), *pBin = fopen("res.dat", "wb");
    if(!pTxt || !pBin){
        fclose(pTxt);
        fclose(pBin);
        return 0;
    }
    ///Guardo el orden en un vector de string
    fgets(linea, sizeof(linea), pTxt);
    aux = strchr(linea, '\n');
    *aux = '\0';
    for(i=4;i>0;i--){
        aux = strrchr(linea, '|');
        strcpy(orden[i], aux + 1);
        *aux = '\0';
    }
    strcpy(orden[0], linea);
    ///Bucle principal, mientras haya alumnos
    while(fgets(linea, sizeof(linea), pTxt)){
        for(i=4;i>0;i--){
            aux = strrchr(linea, '|');
            if(strcmpi(orden[i], "dni") == 0) sscanf(aux + 1, "%d", &alumno.dni);
            else if(strcmpi(orden[i], "promedio") == 0) sscanf(aux + 1, "%f", &alumno.promedio);
            else if(strcmpi(orden[i], "edad") == 0) sscanf(aux + 1, "%d", &alumno.edad);
            else if(strcmpi(orden[i], "legajo") == 0) sscanf(aux + 1, "%d", &alumno.legajo);
            else if(strcmpi(orden[i], "genero") == 0) sscanf(aux + 1, "%c", &alumno.genero);
            *aux = '\0';
        }
        if(strcmpi(orden[0], "dni") == 0) sscanf(linea, "%d", &alumno.dni);
        else if(strcmpi(orden[0], "promedio") == 0) sscanf(linea, "%f", &alumno.promedio);
        else if(strcmpi(orden[0], "edad") == 0) sscanf(linea, "%d", &alumno.edad);
        else if(strcmpi(orden[0], "legajo") == 0) sscanf(linea, "%d", &alumno.legajo);
        else if(strcmpi(orden[0], "genero") == 0) sscanf(linea, "%c", &alumno.genero);

        fwrite(&alumno, sizeof(tAlumno), 1, pBin);
    }
    fclose(pTxt);
    fclose(pBin);
    return 1;
}

int** crearMatrizD(int f, int c){
    int **mat, i, j;
    mat = (int**)malloc(f * sizeof(int*));
    if(!mat) return NULL;
    for(i=0;i<f;i++){
        *(mat + i) = (int*)malloc(sizeof(int) * c);
        if(!*(mat + i)){
            for(j=0;j<i;j++){
                free(*(mat + j));
            }
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void destruirMatrizD(int** mat, int f){
    int i;
    for(i=0;i<f;i++){
        free(*(mat + i));
    }
    free(mat);
}

int sumarDiagonalSuperior(int** mat, int cf, int cc){
    int i, j, res = 0;
    for(i=0;i<cf;i++){
        for(j=i+1;j<cc;j++){
            res += mat[i][j];
        }
    }
    return res;
}
int esMatrizIdentidad(int **mat, int cf, int cc){
    int i, j;
    for(i=0;i<cf;i++){
        for(j=0;j<cc;j++){
            if(i==j){
                if(mat[i][j] != 1) return 0;
            }
            else
                if(mat[i][j] != 0) return 0;
        }
    }
    return 1;
}
int insertarOrdenado(void *vec, void *dato, unsigned tam, unsigned *ce, unsigned ceMax, int cmp(const void *d1, const void *d2)){
    int comp;
    void *pFin = vec + (*ce) * tam;

    if(*ce == ceMax) return 0;
    while(vec < pFin && (comp = cmp(vec, dato)) < 0){
        vec += tam;
    }
    if(vec < pFin)
        memmove(vec + tam, vec, pFin - vec);

    memcpy(vec, dato, tam);
    (*ce)++;
    return 1;
}
int compararFloat(const void *d1, const void *d2){
    float res = (*(float*)d1 - *(float*)d2);
    if(res < 0) return -1;
    if(res > 0) return 1;
    return 0;
}












