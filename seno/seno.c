#include <stdio.h>

int fatorial(int num){
    int fat=1;
    for (int i = 1; i <= num; i++)
    {
        fat=fat*i;
    }
    return fat;
}

int radiano(int angulo){
    double rad;
    double pi = 3.141592;
    rad = (angulo*pi)/180;
    return rad;
}

int seno(double A, int numTermos){
    double senoA;
    double termo;
    int exp=1;
    for (int i=0; i<numTermos; i++){
        termo=(A/fatorial(exp));
        exp=exp+2;
        //Calculo do seno
        senoA = senoA+
    }
    return senoA;
}

int main(){
    int numtermos;
    double senoA;

}
