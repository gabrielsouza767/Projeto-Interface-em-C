int telaFinal9(int alt, int larg);
int telaPoliciais(int alt, int larg);
int telaResDel(int alt, int larg);
int telaResPolis(int alt, int larg);
int ultimatelaPolis(int alt, int larg);
void conversaDel(int alt, int larg, char conversa[2][85]);
int telaLab(int alt, int larg);
int telaEscolha(int alt, int larg);
void DesenhaBotaoEscolhas(int alt, int larg,float porcentLarg, float porcentAlt);
void ClickBotaoEscolhas(int alt, int larg, int *IndSusp, int SuspSelecionados[3]);
int telaFinal9(int alt, int larg)
{
    char perguntasdel[2][85]=
    {
        {
            "Olá senhores policiais, gostaria de saber se voces encontraram alguma boa pista."
        },
        {
            "Algo que ajude e colabore na investigação, o mais rápido possível."
        }
    };
    readimagefile("img/delegado.jpg",0,0,larg,alt);
    conversaDel(alt,larg,perguntasdel);
    return BotaoeTeclas();
}
int telaPoliciais(int alt, int larg)
{
    char respostasPolis[2][85]=
    {
        {
            "Olá Sr Delegado, encontramos somente muitas notas queimadas da explosão,tentamos"
        },
        {
            "coletar mais informações, mas só temos as armas apreendidas e os suspeitos."
        }
    };
    readimagefile("img/imgPoliciais.jpg",0,0,larg,alt);
    conversaDel(alt,larg,respostasPolis);
    return BotaoeTeclas();
}
int telaResDel(int alt, int larg)
{
    char respostasDel[2][85]=
    {
        {
            "Ok! Conseguem para agora as digitais em cada arma para mim? Urgente!"
        },
        {
            "Preciso encontrar os criminosos ainda hoje, se não perco o emprego!"
        }
    };
    readimagefile("img/delegado.jpg",0,0,larg,alt);
    conversaDel(alt,larg,respostasDel);
    return BotaoeTeclas();
}
int telaResPolis(int alt, int larg)
{
    char respostasPolis[2][85]=
    {
        {
            "Sim Sr! Conseguimos sim, iremos falar com o departamento de provas."
        },
        {
            "Ainda hoje teremos as digitais em cada arma,assim irá te ajudar Sr."
        }
    };
    readimagefile("img/imgPoliciais.jpg",0,0,larg,alt);
    conversaDel(alt,larg,respostasPolis);
    return BotaoeTeclas();
}
int ultimatelaPolis(int alt, int larg)
{
    char respostasPolis[2][85]=
    {
        {
            "Sr Delegado! Sr Delegado! Saiu o resultado das digitais! Venha ver!"
        },
        {
            "Tem a digital de 3 suspeitos,que juntando com o interrogatório,você terá provas!"
        }
    };
    readimagefile("img/imgPoliciais.jpg",0,0,larg,alt);
    conversaDel(alt,larg,respostasPolis);
    return 1;
}
void conversaDel(int alt, int larg, char conversa[2][85])
{
    int i,j;
    float porcentlarg,porcent=0.85;
    char letra[2];
    bar(larg*0.018,alt*0.84, larg*0.85,alt*0.93);
    settextstyle(0,HORIZ_DIR,TamFonte2(alt));
    for(i=0; i<2; i++)
    {
        porcentlarg=0.02;
        for(j=0; j<85; j++)
        {
            delay(40);
            letra[0]=conversa[i][j];
            letra[1]='\0';
            outtextxy(larg*porcentlarg,alt*porcent,letra);
            porcentlarg+=0.01;
        }
        porcent+=0.03;
    }
    /*
    A função outtextxy espera receber uma string, e se eu passar o somente o perguntasdel[i][j] estarei passando um char so como argumento,
    gerando um erro de compilação,por isso os indices da var letra[2] estao dentro do loop,a cada loop ela  recebe o caracter seguinte e o terminador,
    o terminador esta ali para sinalizar o fim da string, e sendo passada como argumento, a func outtextxy entende como string.
    */
}
int telaLab(int alt, int larg)
{
    struct Digitais
    {
        char nome[40],img[30];
        short int idade,dig;
    };
    short int i;
    char idadeStr[3],digStr[3];
    int j;
    float porcentlarg=0,porcent=0.85;
    char letra[2];
    struct Digitais Ds[3]=
    {
        {"Pedro Henrique Silva","img/suspeito5.jpg",48,1},
        {"Arthur Carvalho","img/suspeito4.jpg",45,2},
        {"Jose de Oliveira","img/suspeito2.jpg",50,3}
    };
    char respDel[40]=
    {
        "Ok! Agora consigo prender os suspeitos!"
    };

    readimagefile("img/labPolis.jpg",0,0,larg,alt);
    readimagefile("img/delegado.jpg",0,0,larg*0.45,alt);
    bar(0,alt*0.84, larg*0.43,alt*0.885);
    settextstyle(0,HORIZ_DIR,TamFonte2(alt));
    for(j=0; j<40; j++)
    {
        delay(40);
        letra[0]=respDel[j];
        letra[1]='\0';
        outtextxy(larg*porcentlarg,alt*porcent,letra);
        porcentlarg+=0.01;
    }
    setfillstyle(SOLID_FILL, WHITE);
    bar(larg*0.55,alt*0.3,larg*0.95,alt*0.8);
    setcolor(0);
    settextstyle(0, HORIZ_DIR, TamFonte2(alt));
    outtextxy(larg*0.565,alt*0.32,"NOME: ");
    outtextxy(larg*0.63,alt*0.32,Ds[0].nome);
    outtextxy(larg*0.565,alt*0.35,"IDADE: ");
    sprintf(idadeStr,"%d",Ds[0].idade);
    outtextxy(larg*0.63,alt*0.35,idadeStr);
    outtextxy(larg*0.565,alt*0.38,"DIGITAL: ");
    sprintf(digStr,"%d",Ds[0].dig);
    outtextxy(larg*0.65,alt*0.38,digStr);
    readimagefile(Ds[0].img,larg*0.87,alt *0.3,larg*0.95,alt*0.45);
// Indice 1
    outtextxy(larg*0.565, alt*0.44, "NOME: ");
    outtextxy(larg*0.63, alt*0.44, Ds[1].nome);
    outtextxy(larg*0.565, alt*0.47, "IDADE: ");
    sprintf(idadeStr, "%d", Ds[1].idade);
    outtextxy(larg*0.63, alt*0.47, idadeStr);
    outtextxy(larg*0.565, alt*0.50, "DIGITAL: ");
    sprintf(digStr, "%d", Ds[1].dig);
    outtextxy(larg*0.65, alt*0.50, digStr);
    readimagefile(Ds[1].img, larg*0.87, alt*0.465, larg*0.95, alt*0.59);

// Indice 2
    outtextxy(larg*0.565, alt*0.56, "NOME: ");
    outtextxy(larg*0.63, alt*0.56, Ds[2].nome);
    outtextxy(larg*0.565, alt*0.59, "IDADE: ");
    sprintf(idadeStr, "%d", Ds[2].idade);
    outtextxy(larg*0.63, alt*0.59, idadeStr);
    outtextxy(larg*0.565, alt*0.62, "DIGITAL: ");
    sprintf(digStr, "%d", Ds[2].dig);
    outtextxy(larg*0.65, alt*0.62, digStr);
    readimagefile(Ds[2].img, larg*0.87, alt*0.605, larg*0.95, alt*0.73);
    bar(larg*0.55, alt*0.1,larg*0.95,alt*0.25);
    readimagefile("img/Digital.jpg",larg*0.565,alt*0.1,larg*0.665,alt*0.25);
    readimagefile("img/Digital.jpg",larg*0.69,alt*0.1,larg*0.79,alt*0.25);
    readimagefile("img/Digital.jpg",larg*0.82,alt*0.1,larg*0.92,alt*0.25);
    return BotaoeTeclas();
}
int telaEscolha(int alt, int larg)
{
    int IndiceSuspeito=0, SuspSel[3],i;
    for(i=0;i<3;i++)
    {
        SuspSel[i]=0;
    }
    readimagefile("img/DelegaciaFinal.jpg",0,0,larg,alt);
    setfillstyle(SOLID_FILL,WHITE);
    bar(larg*0.02,alt*0.17,larg*0.98,alt*0.88);
    rectangle(larg*0.047, alt*0.26, larg*0.219,alt*0.713);
    readimagefile("img/Suspeito1.jpg", larg*0.052, alt*0.278, larg*0.208, alt*0.648);
    outtextxy(larg*0.051, alt*0.666,"Alexandre");
    DesenhaBotaoEscolhas(alt,larg,0.055,0.75);

    rectangle(larg*0.24, alt*0.26, larg*0.407,alt*0.713);
    readimagefile("img/suspeito2.jpg", larg*0.25, alt*0.278, larg*0.395, alt*0.648);
    outtextxy(larg*0.25, alt*0.666,"Jose");
    DesenhaBotaoEscolhas(alt,larg,0.24,0.75);

    rectangle(larg*0.42, alt*0.26,larg*0.572, alt*0.713);
    readimagefile("img/suspeito3.jpg", larg*0.430, alt*0.278, larg*0.560, alt*0.648);
    outtextxy(larg*0.44, alt*0.666,"Renan");
    DesenhaBotaoEscolhas(alt,larg,0.42,0.75);

    rectangle(larg*0.598, alt*0.26, larg*0.765,alt*0.713);
    readimagefile("img/suspeito4.jpg", larg*0.605, alt*0.278, larg*0.754, alt*0.648);
    outtextxy(larg*0.61, alt*0.666,"Arthur");
    DesenhaBotaoEscolhas(alt,larg,0.61,0.75);

    rectangle(larg*0.787, alt*0.26, larg*0.968, alt*0.713);
    readimagefile("img/suspeito5.jpg", larg*0.797, alt*0.278, larg*0.95, alt*0.648);
    outtextxy(larg*0.797, alt*0.666,"Pedro");
    DesenhaBotaoEscolhas(alt,larg,0.797,0.75);

    outtextxy(larg*0.275,alt*0.85,"Escolha os três suspeitos que irá prender.");
    while(IndiceSuspeito<3)
    {
        ClickBotaoEscolhas(alt, larg, &IndiceSuspeito, SuspSel); // botão 0
    }
    return BotaoeTeclas();
}
void DesenhaBotaoEscolhas(int alt, int larg, float porcentLarg, float porcentAlt)
{

    rectangle(larg*porcentLarg,alt*porcentAlt,larg*(porcentLarg+0.06),alt*(porcentAlt+0.04));
    bar(larg*(porcentLarg+0.005),alt*(porcentAlt+0.005),larg*(porcentLarg+0.04),alt*(porcentAlt+0.03));
    outtextxy(larg*(porcentLarg+0.002),alt*(porcentAlt+0.002),"Este");
}
void ClickBotaoEscolhas(int alt, int larg, int *IndSusp, int SuspSelecionados[3])
{
    int fluxoLoop=0, mx, my;
    while(!fluxoLoop)
    {
        mx=mousex() , my=mousey();
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mx>=larg*0.055 && mx<=larg*0.15&& my>=alt*0.75 && my<=alt*0.78)
            {
                setcolor(BLUE);
                rectangle(larg*0.047, alt*0.26, larg*0.219,alt*0.713);
                SuspSelecionados[*IndSusp]=0;
            }
            else if(mx>=larg*0.24 && mx<=larg*0.29&& my>=alt*0.75 && my<=alt*0.78)
            {
                setcolor(BLUE);
                rectangle(larg*0.24, alt*0.26, larg*0.407,alt*0.713);
                SuspSelecionados[*IndSusp]=1;
            }
            else if(mx>=larg*0.42 && mx<=larg*0.47&& my>=alt*0.75 && my<=alt*0.78)
            {
                setcolor(BLUE);
                rectangle(larg*0.42, alt*0.26,larg*0.572, alt*0.713);
                SuspSelecionados[*IndSusp]=0;
            }
            else if(mx>=larg*0.61 && mx<=larg*0.66&& my>=alt*0.75 && my<=alt*0.78)
            {
                setcolor(BLUE);
                rectangle(larg*0.598, alt*0.26, larg*0.765,alt*0.713);
                SuspSelecionados[*IndSusp]=1;
            }
            else if(mx>=larg*0.797 && mx<=larg*0.84 && my>=alt*0.75 && my<=alt*0.78)
            {
                setcolor(BLUE);
                rectangle(larg*0.787, alt*0.26, larg*0.968, alt*0.713);
                SuspSelecionados[*IndSusp]=1;
            }
            (*IndSusp)++;
            fluxoLoop=1;
            clearmouseclick(WM_LBUTTONDOWN);
        }
    /*
        Se o jogador clicou no botao com o suspeito errado, o indice do vetor recebe 0, para sinalizar q nn é o correto
        Se o jogador clicou no botao certo, o indice recebe 1, para indicar q é o suspeito correto.
        O IndSusp, é o indice do suspeito escolhido, onde teremos 3, por ponteiro para parar a chamada da função
    */
    }

}
