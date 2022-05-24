#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

typedef struct {
    // col do arquivo
    char *DataDiagnostico;
    char *Classificacao;
    char *Municipio;
    char *Bairro;
    char *Sexo;
    char *RacaCor;
}tregCovidES;

bool stringsIguais(const char s1[],const char s2[]){
    int i = 0;
    while(s1[i]==s2[i] && s1[i]!= '\0' && s2[i]!='\0' && s1[i]!=EOF)
    {
        ++i;
    }
    
    if (s1[i]=='\0' && s2[i]=='\0'){
        return true;
    }else{
        return false;
    }
}
int main(){
    FILE *file;
    file = fopen("microdadostarefa03.csv","r");
    char texto[250];
    char *result;
    int aux=0;
    int pardoc=0;
    int pardos=0;
    int pardod=0;
    int brancac=0;
    int brancas=0;
    int brancad=0;
    int amarelac=0;
    int amarelad=0;
    int amarelas=0;
    int indigenac=0;
    int indigenad=0;
    int indigenas=0;
    int ignoradoc=0;
    int ignoradod=0;
    int ignorados=0;

    if (file){
        printf("[MSG]:dados lidos do arquivo\n");
        tregCovidES col[30000];

        for (aux=1;aux<=30000;aux=aux+1){
            fgets(texto,250,file);
            //printf("%i: %s",aux,texto);
            if (texto == NULL) {
                break;
            }
            result= strtok(texto,";"); col[aux].DataDiagnostico=result;//data
            result= strtok(NULL,";"); col[aux].Classificacao=result;//classificacao
            result= strtok(NULL,";"); col[aux].Municipio=result;//municipio
            result= strtok(NULL,";"); col[aux].Bairro=result;//bairro
            result= strtok(NULL,";"); col[aux].Sexo=result;//sexo
            result= strtok(NULL,";"); col[aux].RacaCor=result;//RacaCor
            //printf("%i:  %s,%s,%s,%s,%s,%s",aux,col[aux].DataDiagnostico,col[aux].Classificacao,col[aux].Municipio,col[aux].Bairro,col[aux].Sexo,col[aux].RacaCor);
            printf("%i: %s",aux,col[aux].RacaCor);
            if (col[aux].RacaCor=="(null)"){
                col[aux].RacaCor="";
                col[aux].Classificacao="";
            }
            if (stringsIguais(col[aux].RacaCor,"Parda")==true){
                if(stringsIguais(col->Classificacao,"Confirmados")==true){
                    pardoc=pardoc+1;
                    //printf("pardos confirmados:%i  ",pardoc);
                }else if(stringsIguais(col->Classificacao,"Suspeito")==true){
                    pardos=pardos+1;
                   // printf("pardo suspeito:%i  ",pardos);
                }else if (stringsIguais(col->Classificacao,"Descartados")==true){
                    pardod=pardod+1;
                   // printf("pardo descart:%i  ",pardod);

                }
            }
            else if(col[aux].RacaCor="Branca"){
                if(col[aux].Classificacao="Confirmados"){
                    brancac=brancac+1;
                }else if(col[aux].Classificacao="Suspeito"){
                    brancas=brancas+1;
                }else if (col[aux].Classificacao="Descartados"){
                    brancad=brancad+1;
                }
            }
            else if(col[aux].RacaCor="Amarela"){
                if(col[aux].Classificacao="Confirmados"){
                    amarelac=amarelac+1;
                }else if(col[aux].Classificacao="Suspeito"){
                    amarelas=amarelas+1;
                }else if (col[aux].Classificacao="Descartados"){
                    amarelas=amarelas+1;
                }
            }
            else if(col[aux].RacaCor="Indigena"){
                if(col[aux].Classificacao="Confirmados"){
                    indigenac=indigenac+1;
                }else if(col[aux].Classificacao="Suspeito"){
                    indigenas=indigenas+1;
                }else if (col[aux].Classificacao="Descartados"){
                    indigenad=indigenad+1;
                }
            }
            else if(col[aux].RacaCor="Ignorado"){
                if(col[aux].Classificacao="Confirmados"){
                    ignoradoc=ignoradoc+1;
                }else if(col[aux].Classificacao="Suspeito"){
                    ignorados=ignorados+1;
                }else if (col[aux].Classificacao="Descartados"){
                    ignoradod=ignoradod+1;
                }
            }

        printf("pardo descart:%i  ",pardod);
        printf("pardos supeitos:%i  ",pardos);
        printf("pardos confirmados:%i  ",pardoc);
        }
        fclose(file);

        }
    else{
        printf("Erro ao abrir arquivo");
    }
        getch();
        return 0;
    
}

