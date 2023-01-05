#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

 
int grade[9][9];
 
void numeros_grade(){
    grade[0][5]=2;//ok's dentro da regra
    grade[3][3]=7;//ok
    grade[4][2]=9;//ok
    grade[7][2]=2;//ok
    grade[6][3]=9;//ok
    grade[6][2]=4;//ok
    grade[2][4]=3;//ok
    grade[2][3]=6;//ok
    grade[1][4]=1;//ok
    grade[1][3]=5;//ok
    grade[1][8]=6;//ok
    grade[1][5]=8;//ok
    grade[1][6]=9;//ok
    grade[1][5]=8;//ok
    grade[8][5]=7;//ok
    grade[5][3]=8;//ok
    grade[2][5]=4;//ok
    grade[5][1]=4;//ok
    grade[5][5]=6;//ok
    grade[0][2]=1;//ok
    grade[0][1]=8;//ok
    grade[1][1]=2;//ok
   
}
 
int desenha_grade() {
   
    int i,j;
    numeros_grade();
  printf("\n| 0  1  2 | 3  4  5 | 6  7  8 | \n");
  printf("+---------+---------+---------+\n");
  for (i = 0; i < 9; i++) {
    printf("|");
    for (j = 0; j < 9; j++) {
      if (grade[i][j] != 0)
    printf(" %d ", grade[i][j]);
      else
    printf("   ");
      if (j % 3 == 2)
    printf("|");
    }
    if (i % 3 == 2)
      printf("\n+---------+---------+---------+");
      printf("\n");
  }
}
 
void regras_jogo(){
    system("color 3f");
   
    printf("                    Bem-vindo ao jogo!");
    printf("\n Antes de começar, é necessário relembrar algumas regras!");
    printf("\n Os números em cada bloco de 3x3 não podem se repetir!");
    printf("\n Ah! E a cada linha ou coluna do campo inteiro também não podem!");
    printf("\n Vamos começar!\n\n");
}
 
 
int inserir_numero(int num){
    
     int i,j,linha,coluna,aux1,opcao1;
     char comando1;
 
 
    for (i = 0; i < 36; i++){
    for (j = 0; j < 36; j++){
    menu(opcao1);
 
    printf("\nInsira a linha (0-8) na qual deseja inserir seu numero: ");
    scanf("%d",&i);
    printf("\nInsira a coluna (0-8) na qual deseja inserir seu numero: ");
    scanf("%d",&j);
    printf("\nInsira um número para ser inserido dentro do jogo: ");
    scanf("%d",&num);
 
        if(grade[i][j]==0){
            linha = i;
            coluna = j;
            checarLinha(i,num);
            checarColuna(j,num);
            checarBloco(i,j,num);
            if((checarLinha(i,num))==0){
                printf("\nNumero já existente nesta linha!\n");
            }
            else if((checarColuna(j,num))==0){
                printf("\nNumero já existente nesta coluna!\n");
            }
            else if((checarBloco(i,j,num))==0){
                printf("\nNumero já existente neste bloco!\n");
            }
 else if(((checarBloco(i,j,num))!=0)&&((checarColuna(j,num))!=0)&&((checarBloco(i,j,num))!=0)){
                grade[i][j] = num;
            }
 
        }
        else{
            printf("\nNumero fixo já existente na posição!\n");
        }
   
    desenha_grade();
        }
        }  
        }
 
int checarLinha(int i,int num){
    
    int coluna;
    for(coluna = 0;coluna<9;coluna++){
        if(grade[i][coluna]==num){
            return 0;
        }
    }
    return 1;
}
 
int checarColuna(int j,int num){
   
    int linha;
    for(linha=0;linha<9;linha++){
        if(grade[linha][j]==num){
            return 0;
        }
 
    }
    return 1;
}
 
int checarBloco(int i,int j,int num){
    system("color 3f");
    i= (i/3)*3;
    i = (j/3)*3;
 
    int r,c;
    for(r = 0; r<3; r++){
        for(c = 0;c<3;c++){
            if (grade[i+r][j+c]==num){
               return 0;
            }
 
        }
    }
    return 1;
}
 
 
int menu(){
    
    int opcao,num1,verificando1;
    printf("\n   Selecione apartir do menu abaixo, o que você gostaria de realizar: \n");
    printf("\nPara começar o jogo,insira o numero 1");
    printf("\nPara continuar o jogo,insira o numero 2");
    printf("\nPara finalizar o jogo, insira o número 3");
    printf("\nPara sair do jogo, é só digitar o zero!");
    scanf("%d",&opcao);
        if(opcao==0){
            printf("\n          Jogo Finalizado :)! Até breve!  \n");
            exit(1);
        }
        else if (opcao==3){
            if(encerramento()==0){
                printf("\n Ainda existem lacunas vazias! Verifique novamente!\n");
            }
            else if(encerramento(verificando1)==81){
                printf("\n Jogo Finalizado! Parabéns!! <o// :))");
            }
        }
   
}
int encerramento(){
    int i,j,verificando;
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(grade[i][j]==0){
                return 0;
            }
            else if(grade[i][j]!=0){
                verificando = verificando + 1;
            }
        }
    }
}
 
 
int main(){
    int num1,opcao1;
    int val;
    regras_jogo();
    printf("\n          Agora sim, vamos lá! \n");
    
    desenha_grade();
    while(opcao1==1||opcao1==2){
        printf("\n\nSe lembre que os números devem ser inseridos em ordem!");
        desenha_grade();
        numeros_grade();
        inserir_numero(num1);
        menu(opcao1);
    }
   
    numeros_grade();
    inserir_numero(num1);
    desenha_grade();
    numeros_grade();
    }
