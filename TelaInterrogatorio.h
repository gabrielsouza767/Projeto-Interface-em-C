#ifndef TELAINTERROGATORIO_H
#define TELAINTERROGATORIO_H
struct Delegado
{
    char nome[20],img[30];
    short int idade;
};
int tela8(int alt, int larg);
void botaoFalaSuspeitos( int alt, int larg, int *h);
void botaoFalaTestemunhas( int alt, int larg,int *j);
void respostasSuspeitos(int *flag,char *textButton,int alt, int larg,int *h);
void respostasTestemunhas(int *flag, char *textBot,int alt, int larg, int *j);
void FichaSuspeitosTela8(int alt,int larg,int *h);
void FichaTestemunhasTela8(int alt,int larg,int *j);
#endif // TELAINTERROGATORIO_H
