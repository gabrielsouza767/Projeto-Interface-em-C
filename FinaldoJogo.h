#ifndef FINALDOJOGO_H
#define FINALDOJOGO_H
int telaFinal9(int alt, int larg);
int telaPoliciais(int alt, int larg);
int telaResDel(int alt, int larg);
int telaResPolis(int alt, int larg);
int ultimatelaPolis(int alt, int larg);
void conversaDel(int alt, int larg, char conversa[2][85]);
int telaLab(int alt, int larg);
int telaEscolha(int alt, int larg);
int TelaFinal(int alt, int larg);
void DesenhaBotaoEscolhas(int alt, int larg,float porcentLarg, float porcentAlt);
void ClickBotaoEscolhas(int alt, int larg, int *IndSusp);
extern int SuspSel[3];
#endif // FINALDOJOGO_H
