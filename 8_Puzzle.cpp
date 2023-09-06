#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#define TAM 3

using namespace std;
void incrementa(int matriz[TAM][TAM],int matriz1[TAM][TAM], int matriz2[TAM][TAM], int matriz3[TAM][TAM],int matriz4[TAM][TAM]){
    int linha,coluna,cont=0; 
    for(linha=0; linha<TAM; linha++){
        for(coluna=0;coluna<TAM;coluna++){
            matriz[linha][coluna]=0;
        }
    }
    matriz[0][0]=0;     // incrementa os valores
    matriz[0][1]=1;
    matriz[0][2]=2;
    matriz[1][0]=5;
    matriz[1][1]=6;
    matriz[1][2]=3;
    matriz[2][0]=4;
    matriz[2][1]=7;
    matriz[2][2]=8;
    for(linha=0; linha<TAM; linha++){
        for(coluna=0;coluna<TAM;coluna++){
            matriz1[linha][coluna]=matriz[linha][coluna]; //iguala as 4 matrizes com a matriz principal
            matriz2[linha][coluna]=matriz[linha][coluna];
            matriz3[linha][coluna]=matriz[linha][coluna];
            matriz4[linha][coluna]=matriz[linha][coluna];
        }
    }

}

void calcula(int matriz[TAM][TAM], int matriz1[TAM][TAM], int matriz2[TAM][TAM], int matriz3[TAM][TAM], int matriz4[TAM][TAM]){
    int linha=0, coluna=0, cont=1, H1=0,H2=0,H3=0,H4=0,x=0,aux=0,H5=0,H6=0, movimento=0;
    while(matriz[0][0]!=1 || matriz[0][1]!=2 || matriz[0][2]!=3 || matriz[1][0]!=4 || matriz[1][1]!=5 || matriz[1][2]!=6 || matriz[2][0]!=7 || matriz[2][1]!=8 || matriz[2][2]!=0){
        if(matriz[0][0]==0){
            matriz1[0][0]=matriz[0][1];   //matriz1 recebe a posição da linha 0 e 1
            matriz1[0][1]=0;           
            matriz2[0][0]=matriz[1][0];   //matriz2 recebe a posição da linha 1 e 0
            matriz2[1][0]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;                   //calcula a Heurística da matriz1
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;                   //calcula a Heurística da matriz2
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2){
                matriz[0][0]=matriz1[0][0];     // se a heurística da matriz1
                matriz[0][1]=matriz1[0][1];     // for maior que da matriz2,
            }else if(H2>H1){                    // a matriz principal recebe a matriz1.
                matriz[0][0]=matriz2[0][0]; // se a heurística da matriz1 
                matriz[1][0]=matriz2[1][0]; // for maior que da matriz2,
                                            // a matriz principal recebe a matriz1.
            }
                else{          
                x = rand()%2;  // se H1 não for maior que H2 nem viceversa, 
                                //então será trocado os valores aleatoriamente.            
                if(x==0){
                    matriz[0][0]=matriz1[0][0];
                    matriz[0][1]=matriz1[0][1];
                }
                if(x==1){
                    matriz[0][0]=matriz2[0][0];
                    matriz[1][0]=matriz2[1][0];
                }
            }
             
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna]; //iguala todas as matrizes para
                    matriz2[linha][coluna]=matriz[linha][coluna]; //realizar uma nova comparação futura.
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 =0;  //recebe zero para ser contada novamente quando for necessário.
             H2 =0;
                for(linha=0; linha<TAM; linha++){      // apenas printa a matriz
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                 movimento+=1; //conta quantas vez foram trocadas as posições.

        }
        if(matriz[0][1]==0){  //realiza a mesma a função que a linha 39.
            matriz1[0][1]=matriz[0][0];
            matriz1[0][0]=0;
            matriz2[0][1]=matriz[0][2];
            matriz2[0][2]=0;
            matriz3[0][1]=matriz[1][1];
            matriz3[1][1]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    if(matriz3[linha][coluna]==cont){
                        H3++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2 && H1>H3){
                matriz[0][1]=matriz1[0][1];
                matriz[0][0]=matriz1[0][0];
            }else if(H2>H1 && H2>H3){
                matriz[0][1]=matriz2[0][1];
                matriz[0][2]=matriz2[0][2];
            }else if(H3>H1 && H3>H2){
                matriz[0][1]=matriz3[0][1];
                matriz[1][1]=matriz3[1][1];
            }
            else{
                x = rand()%3;
                if(x==0){
                    matriz[0][1]=matriz1[0][1];
                    matriz[0][0]=matriz1[0][0];
                }
                if(x==2){
                   matriz[0][1]=matriz2[0][1];
                    matriz[0][2]=matriz2[0][2];
                }
                if(x==1){
                    matriz[0][1]=matriz3[0][1];
                    matriz[1][1]=matriz3[1][1];
                }
            }  
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 = 0; 
             H2 = 0;
             H3 = 0;
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                movimento+=1;
        }
        if(matriz[0][2]==0){
            matriz1[0][2]=matriz[0][1];
            matriz1[0][1]=0;
            matriz2[0][2]=matriz[1][2];
            matriz2[1][2]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2){
                matriz[0][2]=matriz1[0][2];
                matriz[0][1]=matriz1[0][1];
            }else if(H2>H1){
                matriz[0][2]=matriz2[0][2];
                matriz[1][2]=matriz2[1][2];
            } else{
                x = rand()%3;
                if(x==0){
                    matriz[0][2]=matriz1[0][2];
                    matriz[0][1]=matriz1[0][1];
                }
                if(x==1 || x==2){
                    matriz[0][2]=matriz2[0][2];
                    matriz[1][2]=matriz2[1][2];
                }
            }
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 =0; 
             H2 =0;
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                movimento+=1;

        }
        if(matriz[1][0]==0){
            matriz1[1][0]=matriz[0][0];
            matriz1[0][0]=0;
            matriz2[1][0]=matriz[1][1];
            matriz2[1][1]=0;
            matriz3[1][0]=matriz[2][0];
            matriz3[2][0]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    if(matriz3[linha][coluna]==cont){
                        H3++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2 && H1>H3){
                matriz[1][0]=matriz1[1][0];
                matriz[0][0]=matriz1[0][0];
            }else if(H2>H1 && H2>H3){
                matriz[1][0]=matriz2[1][0];
                matriz[1][1]=matriz2[1][1];
            }else if(H3>H1 && H3>H2){
                matriz[1][0]=matriz3[1][0];
                matriz[2][0]=matriz3[2][0];
            }else{
                x = rand()%3;
                if(x==0){
                    matriz[1][0]=matriz1[1][0];
                    matriz[0][0]=matriz1[0][0];
                }
                if(x==1){
                    matriz[1][0]=matriz2[1][0];
                    matriz[1][1]=matriz2[1][1];
                }
                if(x==2){
                    matriz[1][0]=matriz3[1][0];
                    matriz[2][0]=matriz3[2][0];
                }
            }  
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 = 0; 
             H2 = 0;
             H3 = 0;
             
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                movimento+=1;
        }
        if(matriz[1][1]==0){
            matriz1[1][1]=matriz[0][1];
            matriz1[0][1]=0;
            matriz2[1][1]=matriz[1][0];
            matriz2[1][0]=0;
            matriz3[1][1]=matriz[1][2];
            matriz3[1][2]=0;
            matriz4[1][1]=matriz[2][1];
            matriz4[2][1]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    if(matriz3[linha][coluna]==cont){
                        H3++;
                    }
                    if(matriz4[linha][coluna]==cont){
                        H4++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2 && H1>H3 && H1>H4){
                matriz[1][1]=matriz1[1][1];
                matriz[0][1]=matriz1[0][1];
            }else if(H2>H1 && H2>H3 && H2>H4){
                matriz[1][1]=matriz2[1][1];
                matriz[1][0]=matriz2[1][0];
            }else if(H3>H1 && H3>H2 && H3>H4){
                matriz[1][1]=matriz3[1][1];
                matriz[1][2]=matriz3[1][2];
            }
            else if(H4>H1 && H4>H2 && H4>H3){
                matriz[1][1]=matriz4[1][1];
                matriz[2][1]=matriz4[2][1];
            }else{
                x = rand()%3;
                if(x==0){
                    matriz[1][1]=matriz1[1][1];
                    matriz[0][1]=matriz1[0][1];
                }
                if(x==1){
                    matriz[1][1]=matriz2[1][1];
                    matriz[1][0]=matriz2[1][0];
                }
                if(x==2){
                    matriz[1][1]=matriz3[1][1];
                    matriz[1][2]=matriz3[1][2];
                }
            } 
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
            }
             H1 = 0; 
             H2 = 0;
             H3 = 0;
             H4 = 0;
             
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                      cout<<matriz[linha][coluna]<<"\t";
                }
                cout<<"\n";
            }
            cout<<"\n";
            // system("pause");
            movimento+=1;
        }
        if(matriz[1][2]==0){
            matriz1[1][2]=matriz[0][2];
            matriz1[0][2]=0;
            matriz2[1][2]=matriz[1][1];
            matriz2[1][1]=0;
            matriz3[1][2]=matriz[2][2];
            matriz3[2][2]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    if(matriz3[linha][coluna]==cont){
                        H3++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2 && H1>H3){
                matriz[1][2]=matriz1[1][2];
                matriz[0][2]=matriz1[0][2];
            }else if(H2>H1 && H2>H3){
                matriz[1][2]=matriz2[1][2];
                matriz[1][1]=matriz2[1][1];
            }else if(H3>H1 && H3>H2){
                matriz[1][2]=matriz3[1][2];
                matriz[2][2]=matriz3[2][2];
            }else{
                x = rand()%3;
                if(x==0){
                    matriz[1][2]=matriz1[1][2];
                    matriz[0][2]=matriz1[0][2];
                }
                if(x==1){
                    matriz[1][2]=matriz2[1][2];
                    matriz[1][1]=matriz2[1][1];
                }
                if(x==2){
                    matriz[1][2]=matriz3[1][2];
                    matriz[2][2]=matriz3[2][2];
                }
            }  
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 = 0; 
             H2 = 0;
             H3 = 0;
             
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                movimento+=1;
        }
        if(matriz[2][0]==0){
            matriz1[2][0]=matriz[1][0];
            matriz1[1][0]=0;
            matriz2[2][0]=matriz[2][1];
            matriz2[2][1]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2){
                matriz[2][0]=matriz1[2][0];
                matriz[1][0]=matriz1[1][0];
            }else if(H2>H1){
                matriz[2][0]=matriz2[2][0];
                matriz[2][1]=matriz2[2][1];
            }else{
                x = rand()%2;
                if(x==0){
                    matriz[2][0]=matriz[1][0];
                    // aux=matriz[1][0];
                    matriz[1][0]=matriz1[0][0];
                    matriz[0][0]=0;

                    // cout<<"RANDO1"<<endl;
                }
                if(x==1){
                    matriz[2][0]=matriz2[2][0];
                    matriz[2][1]=matriz2[2][1];
                    // cout<<"RANDO2"<<endl;
                }
            }  
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 =0; 
             H2 =0;
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                movimento+=1;
        }
         if(matriz[2][1]==0){
            matriz1[2][1]=matriz[2][0];
            matriz1[2][0]=0;
            matriz2[2][1]=matriz[1][1];
            matriz2[1][1]=0;
            matriz3[2][1]=matriz[2][2];
            matriz3[2][2]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    if(matriz3[linha][coluna]==cont){
                        H3++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2 && H1>H3){
                matriz[2][1]=matriz1[2][1];
                matriz[2][0]=matriz1[2][0];
            }else if(H2>H1 && H2>H3){
                matriz[2][1]=matriz2[2][1];
                matriz[1][1]=matriz2[1][1];
            }else if(H3>H1 && H3>H2){
                matriz[2][1]=matriz3[2][1];
                matriz[2][2]=matriz3[2][2];
            }
            else{
                x = rand()%3;
                if(x==0){
                    matriz[2][1]=matriz1[2][1];
                    matriz[2][0]=matriz1[2][0];
                }
                if(x==1){
                   matriz[2][1]=matriz2[2][1];
                    matriz[1][1]=matriz2[1][1];
                }
                if(x==2){
                    matriz[2][1]=matriz3[2][1];
                    matriz[2][2]=matriz3[2][2];
                }
            }  
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 = 0; 
             H2 = 0;
             H3 = 0;
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
                movimento+=1;
        }
        
        if(matriz[2][2]==0){
            for(linha=0; linha<TAM; linha++){          //essa parte é um pouco diferente porque,
                for(coluna=0;coluna<TAM;coluna++){     //será contado os pontos das heurística primeiro,
                    if(matriz1[linha][coluna]==cont){  //se H5 e H6 for menor que 9, então ele executa esta
                        H5++;                          //condição, se não houver esta condição, mesmo com a heuristica
                    }                                  //com 8 pontos será executado esta parte, tirando o 0 do seu devido
                    if(matriz2[linha][coluna]==cont){  //lugar.
                        H6++;
                    }
                    cont++;
                }
            }
            if(H5<=8 && H6<=8){
            matriz1[2][2]=matriz[1][2];
            matriz1[1][2]=0;
            matriz2[2][2]=matriz[2][1];
            matriz2[2][1]=0;
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    if(matriz1[linha][coluna]==cont){
                        H1++;
                    }
                    if(matriz2[linha][coluna]==cont){
                        H2++;
                    }
                    cont++;
                }
            }
            cont=1;
            if(H1>H2){
                matriz[2][2]=matriz1[2][2];
                matriz[1][2]=matriz1[1][2];
            }else if(H2>H1){
                matriz[2][2]=matriz2[2][2];
                matriz[2][1]=matriz2[2][1];
            }
                else{
                x = rand()%2;
                if(x==0){
                    matriz[2][2]=matriz1[2][2];
                    matriz[1][2]=matriz1[1][2];
                }
                if(x==1){
                    matriz[2][2]=matriz2[2][2];
                    matriz[2][1]=matriz2[2][1];
                }
            } 
             
            for(linha=0; linha<TAM; linha++){
                for(coluna=0;coluna<TAM;coluna++){
                    matriz1[linha][coluna]=matriz[linha][coluna];
                    matriz2[linha][coluna]=matriz[linha][coluna];
                    matriz3[linha][coluna]=matriz[linha][coluna];
                    matriz4[linha][coluna]=matriz[linha][coluna];
                }
             }
             H1 =0; 
             H2 =0;
                for(linha=0; linha<TAM; linha++){
                    for(coluna=0;coluna<TAM;coluna++){
                        cout<<matriz[linha][coluna]<<"\t";
                    }
                    cout<<"\n";
                 }
                cout<<"\n";
                // system("pause");
             movimento+=1;

        }
        }
    }
    cout<<"\t"<<"Movimento(s) realizado(s) = "<<movimento<<endl;
}
void mostra(int matriz[TAM][TAM]){ //printa a matriz inicial
    int linha,coluna,cont=0;
    for(linha=0; linha<TAM; linha++){
        for(coluna=0;coluna<TAM;coluna++){
            cout<<matriz[linha][coluna]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){  //executa todas as funções.
srand(time(NULL));
int matriz[TAM][TAM], matriz1[TAM][TAM], matriz2[TAM][TAM], matriz3[TAM][TAM], matriz4[TAM][TAM];
incrementa(matriz,matriz1,matriz2,matriz3,matriz4);
mostra(matriz);
calcula(matriz,matriz1,matriz2,matriz3,matriz4);
}