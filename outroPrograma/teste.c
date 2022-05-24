#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    // col do arquivo
    char DataDiagnostico;
    char Classificacao;
    char Municipio;
    char Bairro;
    char Sexo;
    char RacaCor;
}tregCovidES;
void Imprimedado(tregCovidES D) // declara o parâmetro como uma struct
{
  printf("Data:%s", D.DataDiagnostico);
}
int main(){
    FILE *file;
    file = fopen("microdadostarefa03.csv","r");
    char texto[250];
    char *result;
    int aux;
    if (file){
        printf("[MSG]:dados lidos do arquivo\n");
        tregCovidES col[30000];
        for (aux=0;aux<30000;++aux){
            fgets(texto,250,file);
            printf("%s",texto);
            result= strtok(texto,";"); col[aux].DataDiagnostico=result;//data
            printf("pos:%s\n",result);
            result= strtok(NULL,";"); col[aux].Classificacao=result;//classificacao
            result= strtok(NULL,";"); col[aux].Municipio=result;//municipio
            result= strtok(NULL,";"); col[aux].Bairro=result;//bairro
            result= strtok(NULL,";"); col[aux].Sexo=result;//sexo
            result= strtok(NULL,";"); col[aux].RacaCor=result;//RacaCor
            //printf("%s\n%s %s%s%s%s",col[aux].DataDiagnostico,col[aux].Classificacao,col[aux].Municipio,col[aux].Bairro,col[aux].Sexo,col[aux].RacaCor);
            aux=aux+1;

        }
        fclose(file);
        }
    else{
        printf("Erro ao abrir arquivo");
    }
        getch();
        return 0;
}