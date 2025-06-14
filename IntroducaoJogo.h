int Jogo(int alt,int larg);
int Manual(int alt, int larg);
int Noticia(int alt, int larg);
int Introducao(int alt, int larg);
int Delegacia(int alt, int larg);
int InvestigandoFichas(int alt, int larg,struct CoordenadasMouse *c);
void FichaSuspeitos(int alt);
void ClickFichas(int alt, int larg, int *i);
void FichaTestemunhas(int alt);
int UltimaTelaIntroducao(struct TamanhoTela *t);
int BotaoeTeclas();
int TamFonte(int alt, int *fonte);
int TamFonte2(int alt);
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

//as porcentagens exatas da proporção da tela, usamos chat gpt pra sabermos, mas a logica de usar os parametros da struct e dividir pela porcentagem exata foi nossa
int Jogo(int alt,int larg)
{

    readimagefile("img/ImagemCapaJogo.jpg",0,0,larg,alt);       //Utilizo como parametro os campos da struct preenchidos com as dimenções da tela la no main
    return BotaoeTeclas();                                                  //Retorna 0 ou 1, atraves da flag para avançar ou retroceder uma tela,na função BotaoeTeclas
}
int Manual(int alt, int larg)
{

    setcolor(BLACK);
    settextstyle(0,HORIZ_DIR,TamFonte2(alt));
    outtextxy(100,100,"Manual do jogo...");
    outtextxy(100,140,"Agora se divirta novo delegado...");
    readimagefile(
        "img/Manual.jpg",
        larg * 0.2604, // 26.04%
        alt * 0.2778,  // 27.78%
        larg * 0.6771, // 67.71%
        alt * 0.9259   // 92.59%
    );
    return BotaoeTeclas();                                      //Ja explicado na função de cima
}

int Noticia(int alt, int larg)
{

    readimagefile("img/ImagemNoticia.jpeg",0,0,larg,alt*0.8);
    setcolor(BLACK);
    setlinestyle(0,0,4);
    rectangle(larg*0.14,alt*0.86,larg*0.84,alt*0.93);
    settextstyle(0,HORIZ_DIR,TamFonte2(alt));
    outtextxy(larg*0.15,alt*0.88,"E foi com esta noticia que Poços de Caldas acordou neste sabádo...");
    return BotaoeTeclas();                                                                       //Ja explicado na função Jogo
}
int Introducao(int alt, int larg)
{
    int tamFonte=4;
    rectangle(larg*0.05, alt*0.04, larg*0.929, alt*0.14);
    settextstyle(0,HORIZ_DIR,TamFonte(alt,&tamFonte));
    outtextxy(larg*0.053, alt*0.05,"Em meio a tanto caos e medo de acontecer novamente, o pessoal da cidade questiona o delegado");
    outtextxy(larg*0.053, alt*0.08, "local, que alega ter 5 suspeitos e 2 testemunhas sobre o caso, a quadrilha conhecida ja é na ");
    outtextxy(larg*0.053, alt*0.111,"região de Minas Gerais.");
    rectangle(larg*0.05, alt*0.164, larg*0.42, alt*0.210);
    outtextxy(larg*0.053, alt*0.183,"O delegado tem suspeita de quem sao: ");

    rectangle(larg*0.047, alt*0.26, larg*0.219,alt*0.713);
    readimagefile("img/Suspeito1.jpg", larg*0.052, alt*0.278, larg*0.208, alt*0.648);
    outtextxy(larg*0.052, alt*0.666,"Alexandre de Souza");

    rectangle(larg*0.24, alt*0.26, larg*0.407,alt*0.713);
    readimagefile("img/suspeito2.jpg", larg*0.25, alt*0.278, larg*0.395, alt*0.648);
    outtextxy(larg*0.26, alt*0.666,"Jose de Oliveira");

    rectangle(larg*0.42, alt*0.26,larg*0.572, alt*0.713);
    readimagefile("img/suspeito3.jpg", larg*0.430, alt*0.278, larg*0.560, alt*0.648);
    outtextxy(larg*0.442, alt*0.666,"Renan da Silva");

    rectangle(larg*0.598, alt*0.26, larg*0.765,alt*0.713);
    readimagefile("img/suspeito4.jpg", larg*0.605, alt*0.278, larg*0.754, alt*0.648);
    outtextxy(larg*0.615, alt*0.666,"Arthur Carvalho");

    rectangle(larg*0.787, alt*0.26, larg*0.968, alt*0.713);
    readimagefile("img/suspeito5.jpg", larg*0.797, alt*0.278, larg*0.95, alt*0.648);
    outtextxy(larg*0.797, alt*0.666,"Pedro Herique Silva");

    return BotaoeTeclas();                                  //Tirando as mil imagens e textos, nada de novo tambem
}
int Delegacia(int alt, int larg)
{

    readimagefile("img/Delegado.jpeg", larg*0.005, alt*0.009, larg*0.995, alt*0.852);
    setcolor(BLACK);
    settextstyle(0,HORIZ_DIR,TamFonte2(alt));
    outtextxy(larg*0.050, alt*0.87, "E com esses dados,voce sera nosso delegado e começara a investigar os suspeitos.");
    return BotaoeTeclas();
}
int InvestigandoFichas(int alt, int larg,struct CoordenadasMouse *c)
{
    int saidaTela4=0;
    readimagefile("img/MesaFichas.jpg",
                  larg * 0.005, alt * 0.01,
                  larg, alt);

    FichaSuspeitos(alt);
    settextstyle(0,HORIZ_DIR,TamFonte2(alt));
// Área do botão "Fichas testemunhas"
    float x1 = larg * 0.052;
    float x2 = larg * 0.25;
    float y1 = alt  * 0.833;
    float y2 = alt  * 0.88;

    rectangle(x1, y1, x2, y2);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1, y1, x2, y2);

    setcolor(BLACK);
    outtextxy(larg * 0.057, alt * 0.843, "Fichas testemunhas"); // Ajustado p/ ficar dentro da caixa

    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            c->x = mousex();            //Por eu estar acessando um ponteiro aqui, estou alterando os valores desses campos no main tbm, ent cuidado ao usar la
            c->y = mousey();
            if (c->x >= x1 && c->x <= x2 && c->y >= y1 && c->y <= y2)   //Aqui a dois parametros por referencia, a struct das coordenadas do mouse, e as do tamTela
            {
                FichaTestemunhas(alt);                    //Chama a função sem retorno das testemunhas
                saidaTela4=1;                          //Flag para sair do loop
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
    while(!saidaTela4);
    saidaTela4=0;   //Esquema de forçar o usuario ver as fichas das testemunhas, por isso a função dos botoes so vem depois
    return BotaoeTeclas();
}
void FichaSuspeitos(int alt)
{
    struct TxtSuspeitos
    {
        char falasSuspeitos[6][70];
    };
    int i=0,j=0,k=0,tamFonte=4;
    char idadeint[10],numFichaint[5],numIdint[5];
    struct TamanhoTela T;
    struct TxtSuspeitos Fs[5]=
    {
        {"Especialista em roubo a carro forte.",
        "Passagem no ART 157 §2° do CP,com agravantes.",
        "Modus operandi: Bem vestido, cabelo e barba",
        "bem feitos,não faz alardes e só  anuncia",
         "o roubo na mesa do gerente."
        },
        {
            "Especialista em armas, roubo a mao armada.",
            "Possuí passagem por furto/roubo,nos ART. 155",
            " e 157 com agravantes.",
            "Modus operandi: Veste-se bem,apresenta certo",
            "descontrole emocional,costuma andar armado",
            "com pistola 9mm preta."
        },
        {
            "Conhecido por ser bom piloto de fuga.",
            "Possuí passagem em roubo de veiculos -ART 157",
            "§ 1° do CP. Modus operandi: piloto de carro",
            "especialista em fuga,bem apessoado pra",
            "não chamar a atenção."
        },
        {
            "Possue passagem criminal em Roubo ART 157",
            "com agravantes.",
            "Modus operandi: Ex Soldado do exército,especi",
            "alista em bombas e armamentos bélicos de",
            "alta potência,  faz parte de uma quadrilha",
            "altamente organizada."
        },
        {
            "Possue passagem criminal de furto ART 155",
            "sem agravantes.",
            "Modus operandi: faz pequenos furtos em lojas",
            "e mercados."
        }
    };
    T.tamLarg=getmaxwidth(),T.tamAlt=getmaxheight();
    Suspeitos p[5]=
    {
        {"Alexandre de Souza","Pocos de Caldas-MG","431.900.706-32","(19)99468-9443","img/Suspeito1.jpg",40,1,910},
        {"Jose de Oliveira","Andradas-MG","234.789.321-56","(35)99123-5567","img/suspeito2.jpg",50,2,911},
        {"Renan da Silva","Piracicaba-SP","345.789.340-70","(35)99658-8739","img/suspeito3.jpg",35,3,912},
        {"Arthur Carvalho","Caldas-MG","976.324.675-88","(35)98545-4378","img/suspeito4.jpg",45,4,913},
        {"Pedro Herique Silva","Monte-Verde-MG","247.414.875-59","(35)98779-2098","img/suspeito5.jpg",48,5,914}
    };
    do
    {
        float porcentagem=0.63;     //Deixo ele aqui para resetar a cada loop
        setcolor(0);
        // Limpar a área dos textos da ficha
        setfillstyle(SOLID_FILL, WHITE); // Ou a cor de fundo
        bar(T.tamLarg * 0.312, T.tamAlt * 0.093, T.tamLarg * 0.74, T.tamAlt * 0.926);

        setcolor(0);
        settextstyle(0,HORIZ_DIR,TamFonte2(alt));
// NOME
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.120, "NOME :");
        outtextxy(T.tamLarg * 0.385, T.tamAlt * 0.120, p[i].nomeSuspeito);            //Um vetor da struct suspeitos, usada para rotacionar os dados


// IDADE
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.185, "IDADE :");
        sprintf(idadeint, "%d", p[i].idade);                                        // Converte int para string
        outtextxy(T.tamLarg * 0.395, T.tamAlt * 0.185, idadeint);

// ESTADO
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.25, "CIDADE :");
        outtextxy(T.tamLarg * 0.406, T.tamAlt * 0.25, p[i].cidadeEstado);         //Um vetor da struct suspeitos, usada para rotacionar os dados

// CPF
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.315, "CPF :");
        outtextxy(T.tamLarg * 0.395, T.tamAlt * 0.315, p[i].cpf);                  //Um vetor da struct suspeitos, usada para rotacionar os dados

// TELEFONE
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.38, "TEL :");
        outtextxy(T.tamLarg * 0.395, T.tamAlt * 0.38, p[i].numeroTel);           //Um vetor da struct suspeitos, usada para rotacionar os dados

// Número da ficha e ID
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.435, "Numero da ficha :");
        sprintf(numFichaint, "%d", p[i].numFicha);
        outtextxy(T.tamLarg * 0.495, T.tamAlt * 0.435, numFichaint);
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.5, "ID :");
        sprintf(numIdint,"%d",p[i].id);
        outtextxy(T.tamLarg * 0.385, T.tamAlt * 0.5, numIdint);
//texto da imagem da delegacia
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.574, "Delegacia civil-MG");
        rectangle(T.tamLarg * 0.323, T.tamAlt * 0.62, T.tamLarg * 0.73, T.tamAlt * 0.807);
        settextstyle(0,HORIZ_DIR,TamFonte(alt,&tamFonte));
        for(k=0; k<6; k++)
        {
            outtextxy(T.tamLarg * 0.328,T.tamAlt*porcentagem,Fs[i].falasSuspeitos[k]);    //exibe as linhas da matriz correspondentes a fala do suspeito
            porcentagem+=0.03;
        }

        //Matriz de caracteres, falas correspondentes a cada suspeito, por isso o indice da var "i", e somente ela "linhas" da matriz
        settextstyle(0,HORIZ_DIR,TamFonte2(alt));
        setcolor(0);
        readimagefile(p[i].img, T.tamLarg * 0.6, T.tamAlt * 0.093, T.tamLarg * 0.74, T.tamAlt * 0.28);
//Vetor da struct suspeito, para conseguir rotacionar a img sem disperdicio de código, fiz dela um campo char da struct, alterando a cada loop
        readimagefile("img/wanted.jpg", T.tamLarg * 0.593, T.tamAlt * 0.38, T.tamLarg * 0.703, T.tamAlt * 0.555);

        setcolor(0);
        rectangle(T.tamLarg * 0.416, T.tamAlt * 0.833, T.tamLarg * 0.583, T.tamAlt * 0.88);
        outtextxy(T.tamLarg * 0.427, T.tamAlt * 0.843, "Proxima Ficha");
        if(i==4)
            break;                              //Para não entrar no loop uma vez extra, pelo fato de ser um do while, ele executa antes de ver q o i seria 5
        ClickFichas(T.tamAlt, T.tamLarg,&i);
    }
    while(i<5);
}
void FichaTestemunhas(int alt)
{
    int i=0,x,y,loop=0,j,tamFonte=5;
    char idadeint[10],numFichaint[5],numIdint[5];
    struct TamanhoTela T;
    T.tamLarg=getmaxwidth(),T.tamAlt=getmaxheight();
    Testemunhas t[2]=
    {
        {"Alvares Gonzaga","Poços de Caldas-MG","356.780.450-78","(35)93462-9343","img/testemunha.jpg",40,01,0001},
        {"Luan Silva","Poços de Caldas-MG","267.908.678-21","(35)93322-9372","img/testemunha2.jpg",30,02,0002}
    };
    char falasTestemunhas[4][60]=
    {
        {"Alvarez estava na casa ao lado quando houve "},
        {"o crime,viu pouco dos suspeitos"},
        {"Luan estava no outro quarteirão,e tambem viu "},
        {"o crime e um pouco dos suspeitos"}
    };
    do
    {
        setcolor(0);
        // Limpar a área dos textos da ficha
        setfillstyle(SOLID_FILL, WHITE); // Ou a cor de fundo
        bar(T.tamLarg * 0.312, T.tamAlt * 0.093, T.tamLarg * 0.74, T.tamAlt * 0.926);

        setcolor(0);
        settextstyle(0,HORIZ_DIR,TamFonte2(alt));
// NOME
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.120, "NOME :");
        outtextxy(T.tamLarg * 0.385, T.tamAlt * 0.120, t[i].nomeTestemunha);        //Um vetor da struct testemunhas, usada para rotacionar os dados


// IDADE
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.185, "IDADE :");
        sprintf(idadeint, "%d", t[i].idade);                                        // Converte int para string
        outtextxy(T.tamLarg * 0.395, T.tamAlt * 0.185, idadeint);

// ESTADO
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.25, "CIDADE :");
        outtextxy(T.tamLarg * 0.406, T.tamAlt * 0.25, t[i].cidadeEstado);          //Um vetor da struct suspeitos, usada para rotacionar os dados


// CPF
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.315, "CPF :");
        outtextxy(T.tamLarg * 0.395, T.tamAlt * 0.315, t[i].cpf);                 //Um vetor da struct suspeitos, usada para rotacionar os dados


// TELEFONE
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.38, "TEL :");
        outtextxy(T.tamLarg * 0.395, T.tamAlt * 0.38, t[i].numeroTel);             //Um vetor da struct suspeitos, usada para rotacionar os dados


// Número da ficha e ID
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.435, "Numero da ficha :");
        sprintf(numFichaint, "%d", t[i].numFicha);
        outtextxy(T.tamLarg * 0.495, T.tamAlt * 0.435, numFichaint);
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.5, "ID :");
        sprintf(numIdint,"%d",t[i].id);
        outtextxy(T.tamLarg * 0.385, T.tamAlt * 0.5, numIdint);
        outtextxy(T.tamLarg * 0.323, T.tamAlt * 0.574, "Delegacia civil-MG");
        rectangle(T.tamLarg * 0.323, T.tamAlt * 0.62, T.tamLarg * 0.71, T.tamAlt * 0.805);
        settextstyle(0,HORIZ_DIR,TamFonte(alt,&tamFonte));
        for(j=0; j<2; j++)
        {
            if(i==0)        //Se estivermos na primeira ficha,execute:
            {
                outtextxy(T.tamLarg * 0.328, T.tamAlt * 0.63, falasTestemunhas[i]); //MOstre a primeira linha,o primeiro indice
                j++;                                                                //Incremente o j, j=0, agora é j=1
                outtextxy(T.tamLarg * 0.328, T.tamAlt * 0.65, falasTestemunhas[j]);  //Mostre a linha do indice j, ou seja, a linha 1
            }
            if(j==0)        //Aqui o i ja é 1, pois estaremos na outra ficha, e o j volta a valer 0
            {
                outtextxy(T.tamLarg * 0.328, T.tamAlt * 0.63, falasTestemunhas[j+2]); //Mostro diretamente o indice do j, no caso j=0,j+2,j=2, indice 2
                outtextxy(T.tamLarg * 0.328, T.tamAlt * 0.65, falasTestemunhas[3]); //Mostre o indice 3
            }
        }       //Deste jeito, mostraremos 2 linhas a cada loop do i, sem manipular a matriz dos char
        setcolor(0);
        readimagefile(t[i].img, T.tamLarg * 0.6, T.tamAlt * 0.093, T.tamLarg * 0.74, T.tamAlt * 0.284); //Trecho de codigo reutilizado
        setcolor(0);
        settextstyle(0,HORIZ_DIR,TamFonte2(alt));
        rectangle(T.tamLarg * 0.416, T.tamAlt * 0.833, T.tamLarg * 0.583, T.tamAlt * 0.88);
        outtextxy(T.tamLarg * 0.427, T.tamAlt * 0.843, "Proxima Ficha");
        if(i==1)                               //Trecho de codigo reutilizado
            break;
        ClickFichas(T.tamAlt,T.tamLarg,&i);
    }
    while(i<2);
}
void ClickFichas(int alt, int larg, int *i) //Passo o endereço de i para o ponteiro para mim alterar o conteudo dele na outra funcao, assim rotaciono as fichas
{
    int mx,my,saidaloop=0;
    while(!saidaloop)   //Ler sempre que ouver click, saidaloop tem q ser 0
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            mx=mousex();
            my=mousey();
            if( mx >= larg * 0.416 && mx <= larg * 0.583 && my >= alt * 0.833 && my <= alt * 0.88)
            {
                (*i)++;    //Para mostrar todos os campos do vetor da struct suspeitos,1 por click
                saidaloop=1;    //Flag para controlar o fluxo do while
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }

    }
    saidaloop=0; //entrar ao loop do click novamente
}
int UltimaTelaIntroducao(int alt, int larg)
{
    int i=16;
    char Iint[3];
    readimagefile("img/Interrogatorio.jpg", 0, 0, larg, alt);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    bar(larg*0.153, alt*0.76, larg*0.39, alt*0.838);
    outtextxy(larg*0.158, alt*0.76, "Neste momento o delegado se encaminha a sala dos interrogatórios...");
    outtextxy(larg*0.158, alt*0.8, "Aguarde ");
    do
    {
        i--;                    //O efeito de contagem regressiva
        sprintf(Iint, "%d",i);      //Converte o int pra string
        setfillstyle(SOLID_FILL,WHITE);
        bar(larg*0.23, alt*0.79, larg*0.263, alt*0.83);     //Pinto por cima a cada loop
        outtextxy(larg*0.237, alt*0.8, Iint);
        outtextxy(larg*0.265, alt*0.8, " segundos...");
        delay(1000);
    }
    while(i>0);
    return 1;       //Forço a proxima tela, independente do usuário
}

int BotaoeTeclas()
{

    int FlagFluxoFuncoes=2,tecla,x,y;
    struct TamanhoTela T;
    T.tamLarg=getmaxwidth(),T.tamAlt=getmaxheight();
    setcolor(BLACK);
    setlinestyle(0,0,4);
    setfillstyle(SOLID_FILL, WHITE);
    bar(T.tamLarg * 0.885, T.tamAlt * 0.861, T.tamLarg * 0.938, T.tamAlt * 0.926);
    rectangle(T.tamLarg * 0.885, T.tamAlt * 0.861, T.tamLarg * 0.938, T.tamAlt * 0.926);
    settextstyle(0, HORIZ_DIR, TamFonte2(T.tamAlt));
    outtextxy(T.tamLarg * 0.890, T.tamAlt * 0.880, "Next");
    do
    {
        if(kbhit())
        {
            tecla=getch();
            if(tecla==0)
            {
                tecla=getch();
                if(tecla==75)
                {
                    cleardevice();
                    FlagFluxoFuncoes=0;     //Se apertou a tecla voltar
                }

                if(tecla==77)
                {
                    cleardevice();
                    FlagFluxoFuncoes=1;     //Se apertou a tecla avançar
                }
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            x=mousex();
            y=mousey();
            if(x >= T.tamLarg * 0.885 && x <= T.tamLarg * 0.938 && y >= T.tamAlt * 0.861 && y <= T.tamAlt * 0.926)
            {
                cleardevice();
                FlagFluxoFuncoes=1;             //Se clickou em next,avançar
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
    while(FlagFluxoFuncoes==2); //Enquanto nada foi feito
    return FlagFluxoFuncoes;        //Retorno para sabermos qual tela avançar ou voltar la no main
}
int TamFonte(int alt,int *fonte)    //Para 2 telas em HD com quebras de linhas
{
    if(alt <=800 && *fonte!=4 && *fonte!=5)
        return 46;
    if(alt <=800 && *fonte==4)
        return 29;
    if(alt <=800 && *fonte==5)
        return 33;
    if(alt>800 && alt<900)
        return 13;
    if(alt>900)
        return 14;
}
int TamFonte2(int alt)  //Para telas sem quebras de linhas
{
    if(alt <=800)
        return 46;
    if(alt>900)
        return 37;
    if(alt>800 && alt<900)
        return 14;
}
//Fim da Introdução ao jogo!!!!!





