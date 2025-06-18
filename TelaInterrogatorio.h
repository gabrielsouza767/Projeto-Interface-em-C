int tela8(int alt, int larg);
void botaoFalaSuspeitos( int alt, int larg, int *h);
void botaoFalaTestemunhas( int alt, int larg,int *j);
void respostasSuspeitos(int *flag,char *textButton,int alt, int larg,int *h);
void respostasTestemunhas(int *flag, char *textBot,int alt, int larg, int *j);
void FichaSuspeitosTela8(int alt,int larg,int *h);
void FichaTestemunhasTela8(int alt,int larg,int *j);
struct Delegado
{
    char nome[20],img[30];
    short int idade;
};
int tela8(int alt, int larg)
{
    int h=0, j=0;        //Para eu saber qual ficha estou alterando
    printf("%d %d ",alt,larg);
    setbkcolor(15);
    cleardevice();
    setcolor(BLACK);
    line(0,alt/2,larg/2.1,alt/2);
    line(larg/2.1,0,larg/2.1,alt);
    FichaTestemunhasTela8(alt,larg,&j);
    FichaSuspeitosTela8(alt,larg,&h);   //Por ponteiro pq preciso do valor dela sem reiniciar
    return BotaoeTeclas();
}
void botaoFalaSuspeitos( int alt, int larg, int *h )
{
    int x,y,saidaloop=0,flag=0;
    char textBot[40]="Voce tem alguma passagem?";
    while (flag<3)      //Perguntara todas as perguntas ao primeiro suspeito
    {
        bar(larg * 0.050, alt * 0.861, larg * 0.42, alt * 0.926); // limpa área
        rectangle(larg * 0.050, alt * 0.861, larg * 0.43, alt * 0.926);
        settextstyle(0, HORIZ_DIR, TamFonte2(alt));
        outtextxy(larg * 0.055, alt * 0.880, textBot);
        while(!saidaloop)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x=mousex();
                y=mousey();
                if(x >= larg * 0.050 && x <= larg * 0.43 && y >= alt * 0.861 && y <= alt * 0.926)
                {
                    respostasSuspeitos(&flag,textBot,alt,larg,h);  //Chama a resposta da primeira pergunta, e altera a flag
                    saidaloop=1;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
        saidaloop=0;
    }
}
void respostasSuspeitos(int *flag, char *textBot, int alt, int larg, int *h)
{
    int tamFonte=4,i=0;
    char falasSuspeitos[22][75]=
    {
        "Sim senhor, tenho 1 passagem, nada mais.",
        "Não senhor, tivemos ajuda, mas não vou falar",
        "Não tenho nada a dizer, quero meu advogado",     //0 a 2 sao as respostas do 1 suspeito
        "Sim senhor,fui detido por roubo.",
        "Não sei dizer, não participei do crime.",
        "Estou aqui injustiçadamente, ja paguei",
        "pelos meus crimes, não sei por que estou",
        "aqui, quero meu advogado!",   //3 a 7 sao do 2 suspeito
        "Sim senhor, tenho passagem, mas nao vou",
        "dizer nada, desista!",
        "Sim, planejamos o roubo sozinhos,idai?!",
        "Eu roubei mesmo, tenho dinheiro da fiança e",
        "muito mais pra quando eu sair da prisão!",    //8 a 12 do 3 suspeito
        "Sim, tenho passagem!",
        "Sim planejamos o roubo, e não direi mais!",
        "Quero meu advogado! Não vou dizer nada sem",
        "a presença do meu avogado!",    //13 a 16 do 4 suspeito
        "Sim senhor, uma passagem simples de furto",
        "Não sei dizer, não roubei nada, apenas ",
        "alguns mercados por ai...",
        "Não tenho nada a dizer,neste dia inclusive",
        "estava quieto em casa deitado." //17 ao 22 do 5 suspeito

    };
    settextstyle(0,HORIZ_DIR,TamFonte(alt,&tamFonte));
    switch (*flag)
    {
    case 0:
    bar(larg * 0.52, alt * 0.63, larg * 0.92, alt * 0.803);
        switch(*h)
        {
        case 0:     //Fala suspeito 1
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[*flag]);        //Mostra a primeira resposta
            break;
        case 1:          //Fala suspeito 2
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[3]);
            break;
        case 2:         //Fala suspeito 3
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[8]);
            outtextxy(larg * 0.52, alt * 0.66, falasSuspeitos[9]);
            break;
        case 3:         //Fala suspeito 4
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[13]);
            break;
        case 4:         //Fala suspeito 5
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[17]);
            break;
        }
        strcpy(textBot, "Voces planejaram o roubo sozinhos?"); // Copia o conteúdo da string          //Altera o conteudo do botao,segundo botao
        (*flag)++;              //Pra eu nn fazer um offset sem querer na memoria, primeiro acesso o conteudo do ponteiro e dps incremento o conteudo
        break;
    case 1:
        bar(larg * 0.52, alt * 0.63, larg * 0.92, alt * 0.803);
        switch (*h)
        {
        case 0:     //Fala suspeito 1
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[*flag]);     //Resposta do segundo botao
            break;
        case 1:     //Fala suspeito 2
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[4]);     //Resposta do segundo botao
            break;
        case 2:     //Fala suspeito 3
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[10]);//Resposta do segundo botao
            break;
        case 3: //Fala suspeito 4
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[14]);     //Resposta do segundo botao
            break;
        case 4: //Fala suspeito 5
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[18]);
            outtextxy(larg * 0.52, alt * 0.66, falasSuspeitos[19]);     //Resposta do segundo botao
            break;
        }
        strcpy(textBot,"Tem algo a dizer a seu favor?");                                         //Altera para o 3 botao
        (*flag)++;      //Mas esta flag controla as perguntas, sao 3, ent por isso 3 incrementos nela aqui, reinicia na chamada da func
        break;
    case 2:
        bar(larg * 0.52, alt * 0.63, larg * 0.92, alt * 0.803);
        switch(*h)
        {
        case 0:     //Fala suspeito 1
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[*flag]);     //Resposta pro terceiro botao
            bar(larg * 0.040, alt * 0.851, larg * 0.47, alt * 0.946); // limpa área
            settextstyle(0, HORIZ_DIR, TamFonte2(alt));
            outtextxy(larg * 0.055, alt * 0.880, "Vai ser difícil em...");
            delay(2000);
            break;
        case 1:     //Fala suspeito 2
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[5]);
            outtextxy(larg * 0.52, alt * 0.66, falasSuspeitos[6]);
            outtextxy(larg * 0.52, alt * 0.69, falasSuspeitos[7]);    //Resposta pro terceiro botao
            break;
        case 2:     //Fala suspeito 3
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[11]);
            outtextxy(larg * 0.52, alt * 0.66, falasSuspeitos[12]);
            break;
        case 3:  //Fala suspeito 4
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[15]);
            outtextxy(larg * 0.52, alt * 0.66, falasSuspeitos[16]);
            break;
        case 4:  //Fala suspeito 5
            outtextxy(larg * 0.52, alt * 0.63, falasSuspeitos[20]);
            outtextxy(larg * 0.52, alt * 0.66, falasSuspeitos[21]);
            bar(larg * 0.040, alt * 0.851, larg * 0.47, alt * 0.946); // limpa área
            settextstyle(0, HORIZ_DIR, TamFonte2(alt));
            outtextxy(larg * 0.055, alt * 0.880, "Vou conversar com uns policiais...");
            break;
        }
        //Volta o conteudo dos botoes para o 2 segundo suspeito
        (*flag)++;    //Flag de cada pergunta, por ponteiro pois preciso redesenhar na função botao
        (*h)++;      //Para alterar a resposta a cada ficha, por ponteiro para nn reiniciar a cada chamada da função
        break;
    }
}

void botaoFalaTestemunhas(int alt, int larg, int *j )
{
    int x,y,saidaloop=0,flag=0;
    char textBotTeste[30]="Qual deles estava com a arma?";
    char idadeint[5];
    struct Delegado D={"Gabriel Oliveira","img/ImgDelegado.jpg",20};

    setlinestyle(0,0,4);
    readimagefile("img/delegaciaPocos.jpg",larg*0.48,0,larg,alt);
    outtextxy(larg*0.019,alt*0.55,"Delegado: ");
    outtextxy(larg*0.095,alt*0.55,D.nome);
    sprintf(idadeint,"%d",D.idade);
    outtextxy(larg*0.25,alt*0.55,"Idade: ");
    outtextxy(larg*0.30,alt*0.55,idadeint);
    readimagefile(D.img,larg*0.37,alt*0.505,larg*0.474,alt*0.65);
    while(flag<2)
    {
        rectangle(larg * 0.04, alt * 0.659, larg * 0.36, alt * 0.728);
        bar(larg * 0.045, alt * 0.661, larg * 0.358, alt * 0.726);
        settextstyle(0, HORIZ_DIR, TamFonte2(alt));
        outtextxy(larg * 0.045, alt * 0.668,textBotTeste);
        outtextxy(larg*0.055, alt*0.775,"Perguntas Suspeitos: ");
        outtextxy(larg*0.055, alt*0.861,"Aguarde, testemunhas depondo");
        while(!saidaloop)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x=mousex();
                y=mousey();
                if(x >= larg * 0.05 && x <= larg * 0.4 && y >= alt * 0.661 && y <= alt * 0.726)
                {
                    respostasTestemunhas(&flag,textBotTeste,alt,larg,j);
                    saidaloop=1;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
        saidaloop=0;
    }

}
void respostasTestemunhas(int *flag, char *textBot,int alt, int larg,int *j)
{
    int tamFonte=4,i;
    float porcent=0.29;
    struct falastest
    {
         char falastestemunhas[7][75];
    };
    struct falastest Ft[2]=
    {
        {
        "Eu vi 3 homens invadindo o banco, um deles",
        "com arma grande, um alemaozin.",
        "Consegui reconhecer-lo,ele parecia meio alemao,",
        "cabelo liso, altura mediana,mas quando eu vi eles",
        "se aproximando eu só consegui correr mesmo,não",
        "reconheço outro, perdão... "
        },
        {
            "Eu vi 3 homens invadindo o banco,um alemãozin",
            "estava com arma grande.",
            "Eles estavam de roupa preta, moletom e com muita",
            "pressa, consegui reconhecer apenas 2,um branco",
            "bronzeado, parecia ser o mais tranquilo,mediano",
            "tambem,o outro usava óculos,bem moreno,rapaz alto."
        }
    };

    settextstyle(0,HORIZ_DIR,TamFonte(alt,&tamFonte));
    switch(*flag)
    {
    case 0:
        switch(*j)
        {
        case 0:
            bar(larg*0.02,alt*0.29,larg*0.45,alt*0.39);
            outtextxy(larg*0.02, alt *0.29,Ft[*j].falastestemunhas[0]);
            outtextxy(larg*0.02, alt *0.32,Ft[*j].falastestemunhas[1]);
            strcpy(textBot, "O q vc viu?"); // Copia o conteúdo da string
            *flag=1;
            break;
        case 1:
            bar(larg*0.02,alt*0.29,larg*0.45,alt*0.39);
             outtextxy(larg*0.02, alt *0.29,Ft[*j].falastestemunhas[0]);
            outtextxy(larg*0.02, alt *0.32,Ft[*j].falastestemunhas[1]);         //Testemunha 2
            strcpy(textBot, "O q vc viu?"); // Copia o conteúdo da string
            *flag=1;
        }
        break;
    case 1:
        switch(*j)
        {
        case 0:
            bar(larg*0.02,alt*0.29,larg*0.45,alt*0.39);
            for(i=2;i<7;i++)
            {
                outtextxy(larg*0.02,alt* porcent,Ft[*j].falastestemunhas[i]);
                porcent+=0.03;
            }
            *flag=2;
            break;
        case 1:
            bar(larg*0.02,alt*0.29,larg*0.45,alt*0.39);
            for(i=2;i<7;i++)
            {
                outtextxy(larg*0.02,alt* porcent,Ft[*j].falastestemunhas[i]);
                porcent+=0.03;
            }
            *flag=2;
        }
        (*j)++;
    }

}
void FichaSuspeitosTela8(int alt, int larg, int *h)
{
    int i=0,saidaloop=0,mx,my,tamFonte=4;
    char idadeint[10],numFichaint[5],numIdint[5];
    struct TamanhoTela T;
    T.tamLarg=getmaxwidth(),T.tamAlt=getmaxheight();
    Suspeitos p[5]=
    {
        {"Alexandre de Souza","Pocos de Caldas-MG","431.900.706-32","(19)99468-9443","img/Suspeito1.jpg",40,1,910},
        {"Jose de Oliveira","Andradas-MG","234.789.321-56","(35)99123-5567","img/suspeito2.jpg",50,2,911},
        {"Renan da Silva","Piracicaba-SP","345.789.340-70","(35)99658-8739","img/suspeito3.jpg",35,3,912},
        {"Arthur Carvalho","Caldas-MG","976.324.675-88","(35)98545-4378","img/suspeito4.jpg",45,4,913},
        {"Pedro Herique Silva","Monte-Verde-MG","247.414.875-59","(35)98779-2098","img/suspeito5.jpg",48,5,914}
    };
    setfillstyle(SOLID_FILL, WHITE);
    bar(T.tamLarg*0.48,0,T.tamLarg,T.tamAlt);
    do
    {
        setcolor(0);
        // Limpar a área dos textos da ficha (agora no lado direito da tela)
        setfillstyle(SOLID_FILL, WHITE);
        bar(T.tamLarg * 0.5, T.tamAlt * 0.093, T.tamLarg * 0.906, T.tamAlt * 0.926);

        setcolor(0);
        settextstyle(0, HORIZ_DIR, TamFonte2(alt));

// NOME
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.120, "NOME :");
        outtextxy(T.tamLarg * 0.572, T.tamAlt * 0.120, p[i].nomeSuspeito);

// IDADE
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.185, "IDADE :");
        sprintf(idadeint, "%d", p[i].idade);
        outtextxy(T.tamLarg * 0.582, T.tamAlt * 0.185, idadeint);

// ESTADO
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.25, "CIDADE :");
        outtextxy(T.tamLarg * 0.593, T.tamAlt * 0.25, p[i].cidadeEstado);

// CPF
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.315, "CPF :");
        outtextxy(T.tamLarg * 0.582, T.tamAlt * 0.315, p[i].cpf);

// TELEFONE
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.38, "TEL :");
        outtextxy(T.tamLarg * 0.582, T.tamAlt * 0.38, p[i].numeroTel);

// Número da ficha e ID
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.435, "Numero da ficha :");
        sprintf(numFichaint, "%d", p[i].numFicha);
        outtextxy(T.tamLarg * 0.682, T.tamAlt * 0.435, numFichaint);
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.5, "ID :");
        sprintf(numIdint,"%d",p[i].id);
        outtextxy(T.tamLarg * 0.572, T.tamAlt * 0.5, numIdint);

// Texto da imagem da delegacia
        outtextxy(T.tamLarg * 0.51, T.tamAlt * 0.574, "Delegacia civil-MG");
        rectangle(T.tamLarg * 0.51, T.tamAlt * 0.62, T.tamLarg * 0.96, T.tamAlt * 0.805);

// Imagens
        settextstyle(0, HORIZ_DIR, TamFonte2(alt));
        setcolor(0);
        readimagefile(p[i].img, T.tamLarg * 0.78, T.tamAlt * 0.093, T.tamLarg * 0.906, T.tamAlt * 0.287);
        readimagefile("img/wanted.jpg", T.tamLarg * 0.78, T.tamAlt * 0.38, T.tamLarg * 0.89, T.tamAlt * 0.555);

        setcolor(0);
        botaoFalaSuspeitos(alt, larg, h);

// Botão "Próxima ficha"
        rectangle(T.tamLarg * 0.604, T.tamAlt * 0.833, T.tamLarg * 0.771, T.tamAlt * 0.88);
        outtextxy(T.tamLarg * 0.615, T.tamAlt * 0.843, "Proxima Ficha");

// Lógica para sair do loop
        if(i == 4)
            break;

        while(!saidaloop)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx = mousex();
                my = mousey();
                if(mx >= T.tamLarg * 0.604 && mx <= T.tamLarg * 0.771 && my >= T.tamAlt * 0.833 && my <= T.tamAlt * 0.88)
                {
                    i++;    //Para mostrar todos os campos do vetor da struct suspeitos,1 por click
                    saidaloop=1;    //Flag para controlar o fluxo do while
                }

                clearmouseclick(WM_LBUTTONDOWN);
            }

        }
        saidaloop=0; //entrar ao loop do click novamente
    }
    while(i<5);

}
void FichaTestemunhasTela8(int alt,int larg,int *j)
{
    int i=0,x,y,loop=0,b,tamFonte=5;
    char idadeint[10],numFichaint[5],numIdint[5];
    struct TamanhoTela T;
    T.tamLarg=getmaxwidth(),T.tamAlt=getmaxheight();
    Testemunhas test[2]=
    {
        {"Alvares Gonzaga","Poços de Caldas-MG","356.780.450-78","(35)93462-9343","img/testemunha.jpg",40,01,0001},
        {"Luan Silva","Poços de Caldas-MG","267.908.678-21","(35)93322-9372","img/testemunha2.jpg",30,02,0002}
    };
    do
    {
        setcolor(0);

// Limpar a área da ficha (1/4 da tela: metade largura x metade altura)
        setfillstyle(SOLID_FILL, WHITE);
        bar(T.tamLarg * 0.0, T.tamAlt * 0.0, T.tamLarg * 0.46, T.tamAlt * 0.49);

        setcolor(0);
        settextstyle(0, HORIZ_DIR, TamFonte2(alt));

// NOME
        outtextxy(T.tamLarg * 0.02, T.tamAlt * 0.03, "NOME:");
        outtextxy(T.tamLarg * 0.13, T.tamAlt * 0.03, test[i].nomeTestemunha);

// IDADE
        outtextxy(T.tamLarg * 0.02, T.tamAlt * 0.10, "IDADE:");
        sprintf(idadeint, "%d", test[i].idade);
        outtextxy(T.tamLarg * 0.13, T.tamAlt * 0.10, idadeint);

// CPF
        outtextxy(T.tamLarg * 0.02, T.tamAlt * 0.17, "CPF:");
        outtextxy(T.tamLarg * 0.13, T.tamAlt * 0.17, test[i].cpf);

// Texto da delegacia
        outtextxy(T.tamLarg * 0.02, T.tamAlt * 0.24, "Delegacia civil-MG");
        rectangle(T.tamLarg * 0.015, T.tamAlt * 0.28, T.tamLarg * 0.465, T.tamAlt * 0.41);

// Falas (2 linhas dentro da caixa)
        settextstyle(0, HORIZ_DIR, TamFonte(alt, &tamFonte));

// Imagem pequena e discreta no canto da ficha
        readimagefile(test[i].img, T.tamLarg * 0.30, T.tamAlt * 0.01, T.tamLarg * 0.45, T.tamAlt * 0.20);
        botaoFalaTestemunhas(alt,larg,j);
// Botão "Próxima Ficha" (dentro do limite do 1/4)
        settextstyle(0, HORIZ_DIR, TamFonte2(alt));
        rectangle(T.tamLarg * 0.15, T.tamAlt * 0.43, T.tamLarg * 0.35, T.tamAlt * 0.48);
        outtextxy(T.tamLarg * 0.18, T.tamAlt * 0.445, "Proxima Ficha");

        if (i == 1)
            break;

        while (!loop)
        {
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                if (x >= T.tamLarg * 0.15 && x <= T.tamLarg * 0.35 &&
            y >= T.tamAlt * 0.43 && y <= T.tamAlt * 0.48)
                {
                    i++;                        //Trecho de codigo reutilizado
                    loop=1;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
        loop=0;
    }
    while(i<2);
}
