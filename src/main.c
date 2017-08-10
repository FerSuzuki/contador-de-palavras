#include <stdio.h>

//O programa se baseia na leitura de uma palavra e incremento em uma variável após a leitura sobre essa palavra ou número terminar

int encontra_letra(int aux, char *Entrada);
int encontra_numero(int aux, char *Entrada);

int i;

int main(){

int Qnt = 0, t =700;
char Entrada[t];

for (i = 0; i < t; ++i)
{
    Entrada[i] = 0;
}

scanf("%[^\n]s", Entrada);

for(i = 0; Entrada[i] != '\0'; i ++){


//Lógica para verificar se a frase termina com algum tipo de ponto, adiciona na contagem de palavras
   if(((Entrada[i] == '.' || Entrada[i] == ',' || Entrada[i] == ':'  || Entrada[i] == '?') && Entrada[i+1] == '\0')){
         if (!(encontra_letra(-1,Entrada)))
            Qnt ++;
    }

//Lógica para quando se encontra uma letra, incrementa na variável somente quando alcança a última letra da palavra
    if(encontra_letra(0, Entrada)) {
        if(Entrada[i+1] == ' ' || Entrada[i+1] == '\0' || Entrada[i+1] == '-' || Entrada[i+1] == '.' || Entrada[i+1] == ',' || Entrada[i+1] == ':' || Entrada[i+1] == '!' ){
            Qnt ++;
        }
    }

//Lógica para quando se encontra um número, incrementa na variável somente quando alcança o último número do conjunto
    if(encontra_numero(0, Entrada)){
        if(Entrada[i+1] == ' ' || Entrada[i+1] == '\0' || Entrada[i+1] == '-'){
            Qnt ++;
        }

        //Se a partir do último número a posição duas a frente for letra ou espaço, deve-se incrementar na variável
        else if(((encontra_letra(2,Entrada)) || Entrada[i+2] == ' ') && !encontra_numero(1,Entrada) ){
            Qnt ++;
        }
    }
}

printf("%d \n", Qnt);

return 0;
}

int encontra_letra(int aux, char *Entrada){
     //Verifica se o char está dentro do range de letra da tabela ASCII
     if((Entrada[i+aux] >= 65 && Entrada[i+aux] <= 90) || (Entrada[i+aux] >= 97 && Entrada[i+aux] <= 122)){
         return 1;
     }

return 0;
}

int encontra_numero(int aux, char *Entrada){
    //Verifica se o char está dentro do range de número da tabela ASCII
    if(Entrada[i+aux] >= 48 && Entrada[i+aux] <= 57){
        return 1;
    }
return 0;
}
