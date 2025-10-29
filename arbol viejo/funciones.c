#include "funciones.h"

int crearLote(FILE *p){
    tPersona personas[] = { {45526451, "nahuel", 'm'},
                            {123456789, "maria", 'f'},
                            {987654321, "fernando", 'm'},
                            {123543,"Alejandro",'m'},
                            {543236,"Miriam",'f'},
                            {856345,"Alejandra",'f'},
                            {234125,"Paredes",'m'},
                            {986456,"Lionel",'m'},
                            {543134,"Emiliano",'m'},
                            {76534,"Morena",'f'},
                            {5432,"Jorge",'m'},
                            {3423567,"Marchesin",'m'},
                            {1254324,"Mauricio",'m'},
                            {98753,"Cristina",'f'},
                            {452311,"Almiron",'m'},
                            {22244454,"Julia",'f'},
                            {3542356,"Juliana",'f'},
                            {744443223,"Malena",'f'},
                            {112244,"Joel",'m'},
                            {221114,"Mauro",'m'},
                            {66331,"Martina",'f'},
                            {124444,"Nestor",'m'},
                            {99775654,"Gaby",'f'},
                            {11155555,"cande",'f'},
                            {99,"mateo",'m'},
                            };
    fwrite(personas, sizeof(personas), 1, p);
    return sizeof(personas)/sizeof(tPersona);
}

int compararPersonas(const void *d1, const void *d2){
    tPersona *pers1 = (tPersona*)d1, *pers2 = (tPersona*)d2;
    return pers1->dni - pers2->dni;
}

void mostrarPersonas(const void *p){
    tPersona *pers = (tPersona*)p;
    printf("DNI: %d, Nombre: %s, Sexo: %c\n", pers->dni, pers->nya, pers->sex);
}

void mostrarInt(void* dato){
    printf("%d ", *(int*)dato);
}
int compararInt(const void* dato1, const void *dato2){
    return *(int*)dato1 - *(int*)dato2;
}
void escribirPersonaIndice(void *dst, const void* src, unsigned pos){
    tPersona *persona = (tPersona*)src;
    tIndice *indice = (tIndice*)dst;

    *(int*)indice->clave = persona->dni;
    indice->pos = pos;
}
unsigned leerArchivoBin(void **dst, void* src, unsigned pos, void *param){
    *dst = malloc(*(int*)param);
    if(!dst)
        return 0;
    fseek((FILE*)src, (*(int*)param) * pos, SEEK_SET);
    return fread(*dst, *(int*)param, 1, (FILE*)src);
}

