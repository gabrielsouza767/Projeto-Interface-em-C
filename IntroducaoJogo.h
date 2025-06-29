#ifndef INTRODUCAOJOGO_H
#define INTRODUCAOJOGO_H
typedef struct
{
    char nomeSuspeito[40],cidadeEstado[20],cpf[15],numeroTel[16],img[40];
    short int idade,id,numFicha;
} Suspeitos;                                                                //Struct usada na rotação das fichas
typedef struct
{
    char nomeTestemunha[40],cidadeEstado[20],cpf[15],numeroTel[16],img[40];
    short int idade,id,numFicha;
} Testemunhas;                                                              //Struct usada na rotação das fichas
struct TamanhoTela
{
   short int tamLarg,tamAlt;
};
struct CoordenadasMouse
{
     short int x,y;
};
int Jogo(int alt,int larg);
int Manual(int alt, int larg);
int Noticia(int alt, int larg);
int Introducao(int alt, int larg);
int Delegacia(int alt, int larg);
int InvestigandoFichas(int alt, int larg,struct CoordenadasMouse *c);
void FichaSuspeitos(int alt);
void ClickFichas(int alt, int larg, int *i);
void FichaTestemunhas(int alt);
int UltimaTelaIntroducao(int alt, int larg);
int BotaoeTeclas();
int TamFonte(int alt, int *fonte);
int TamFonte2(int alt);

#endif // INTRODUCAOJOGO_H







