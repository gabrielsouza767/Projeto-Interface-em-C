#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "IntroducaoJogo.h"
#include "TelaInterrogatorio.h"
#include "FinaldoJogo.h"
/*
      ========================================================
      |  UNIVERSIDADE: PUC-MINAS - POÇOS DE CALDAS           |
      |  CURSO: CIÊNCIA DA COMPUTAÇÃO                        |
      |  MATÉRIA: LAB - ALGORITMOS E ESTRUTURAS DE DADOS I   |
      |  DESENVOLVIVO POR: GABRIEL OLIVEIRA DE SOUZA         |
      |  PERÍODO: I                                          |
      |                                                      |
      ========================================================

*/
int main()
{
    struct TamanhoTela T;  //Passado os campos da structs no arquivo .h
    int retornoBotao=0,indiceTelas=0,tamfonte=0;;
    struct CoordenadasMouse C;
    C.x=0;
    C.y=0;
    T.tamLarg=getmaxwidth(),T.tamAlt=getmaxheight();
    initwindow(T.tamLarg,T.tamAlt,"FurtBanks",0,0);
    setbkcolor(15);
    cleardevice();
    while (indiceTelas >= 0 && indiceTelas <= 14)    //Tratando as telas como indices,da primeira ate a ultima tela
    {
        switch (indiceTelas)
        {
        case 0:
            retornoBotao = Jogo(T.tamAlt,T.tamLarg);
            break;
        case 1:
            retornoBotao = Manual(T.tamAlt,T.tamLarg);
            break;
        case 2:
            retornoBotao = Noticia(T.tamAlt,T.tamLarg);
            break;
        case 3:
            retornoBotao = Introducao(T.tamAlt,T.tamLarg);
            break;
        case 4:
            retornoBotao = Delegacia(T.tamAlt,T.tamLarg);
            break;
        case 5:
            retornoBotao = InvestigandoFichas(T.tamAlt,T.tamLarg,&C);
            break;
        case 6:
            retornoBotao = UltimaTelaIntroducao(T.tamAlt,T.tamLarg);
            break;
        case 7:
            retornoBotao=tela8(T.tamAlt,T.tamLarg);
            break;
        case 8:
            retornoBotao=telaFinal9(T.tamAlt,T.tamLarg);
            break;
        case 9:
            retornoBotao=telaPoliciais(T.tamAlt,T.tamLarg);
            break;
        case 10:
            retornoBotao=telaResDel(T.tamAlt,T.tamLarg);
            break;
        case 11:
            retornoBotao=telaResPolis(T.tamAlt,T.tamLarg);
            break;
        case 12:
            retornoBotao=ultimatelaPolis(T.tamAlt,T.tamLarg);
            break;
        case 13:
            retornoBotao=telaLab(T.tamAlt,T.tamLarg);
            break;
        case 14:
            retornoBotao=telaEscolha(T.tamAlt, T.tamLarg);
        }
            if (retornoBotao)
                indiceTelas++;  //Se o usuario clickou em vançar,essa incrementação faz com que mostre a proxima tela com os cases
            else
            {
                if(indiceTelas==0)
                    retornoBotao=Jogo(T.tamAlt,T.tamLarg);  //Para que o usuario nao possa retroceder mais do q a primeira tela
                else
                    indiceTelas--;  //Se o usuario apertou a seta voltar, essa decrementação faz com q o usuario volte uma tela com os cases e o loop
            }

    }
    while(!kbhit());
    closegraph();
    return 0;
}
