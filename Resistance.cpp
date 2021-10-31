#include <iostream>
#include <graphics.h>

using namespace std;

void menu(void)
{
   initwindow(1400,900,"Calculateur de code couleur des résitances",100,100);

    setfillstyle(1,COLOR(211,211,211));
    bar(0,0,1400,900);

    setfillstyle(1,0);
    bar(0,0,1400,220);

    //bouton exit
    setfillstyle(1,COLOR(255,0,0));
    bar(1290,40,1360,80);

    setlinestyle(0,1,5);

    line(1315,50,1335,70);
    line(1335,50,1315,70);

    settextstyle(1,0,9);
    outtextxy(215,70,"RESISTANCE");

//    line(330,350,270,480);

    setcolor(WHITE);
    settextstyle(1,0,3);
    outtextxy(225,300,"Bonjour, ceci est un calculateur de couleur des résistances.");
    outtextxy(260,340,"Veuillez choisir entre une résistance à 4 ou 5 anneaux !");

    setfillstyle(1,0);
    bar(370,500,645,575);
    bar(740,500,1015,575);

    setcolor(WHITE);
    settextstyle(1,0,5);
    outtextxy(387,520,"4 bandes");
    outtextxy(757,520,"5 bandes");

    //bonhomme1
    setcolor(BLACK);
    circle(225,477,44);

    setlinestyle(0,1,5);
    //corps
    line(228,525,222,650);
    line(222,525,228,650);

    //bras
    line(225,550,300,588);
    line(225,550,150,588);

    //jambes
    line(225,647,300,710);
    line(225,647,150,710);

    setcolor(WHITE);
    settextstyle(1,0,2);
    outtextxy(120,750,"Eden BAUDIN");
}
void palette(void)
{
    //palette de couleur
    setfillstyle(1,-2);
    bar(100,600,200,700); //blanc

    setfillstyle(1,8);
    bar(200,600,300,700); //gris

    setfillstyle(1,0);
    bar(300,600,400,700); //noir

    setfillstyle(1,COLOR(153,76,0));
    bar(400,600,500,700); //marron

    setfillstyle(1,COLOR(255,0,0));
    bar(500,600,600,700); // rouge

    setfillstyle(1,COLOR(255,128,0));
    bar(600,600,700,700); //orange

    setfillstyle(1,COLOR(255,255,0));
    bar(700,600,800,700); //jaune

    setfillstyle(1,2);
    bar(800,600,900,700); //vert

    setfillstyle(1,1);
    bar(900,600,1000,700); //bleu

    setfillstyle(1,5);
    bar(1000,600,1100,700); //violet

    setfillstyle(1,COLOR(192,192,192));
    bar(1100,600,1200,700); //argent

    setfillstyle(1,COLOR(255,215,0));
    bar(1200,600,1300,700); //or

    //bouton exit
    setfillstyle(1,COLOR(255,0,0));
    bar(1290,40,1360,80); // rouge

    setlinestyle(0,1,5);
    line(1315,50,1335,70);
    line(1335,50,1315,70);

    //boutton reset
    setcolor(WHITE);
    settextstyle(1,0,4);
    outtextxy(1025,530,"réinitialiser");

    //ctrl z
    setcolor(WHITE);
    settextstyle(1,0,4);
    outtextxy(175,530,"Ctrl+Z");

}

//résistance
void un(void)
{
    palette();
    //dimensions de la ligne
    setlinestyle(0,1,5);
    //fil résitance
    line(250,200,450,200);
    line(950,200,1150,200);

    //longueur
    line(450,100,950,100);
    line(450,300,950,300);

    //largeur
    line(450,100,450,300);
    line(950,100,950,300);

    //intérieur resistance
    setfillstyle(1,COLOR(255,229,204));
    bar(452,102,948,298);

    //croix or et argent
    setlinestyle(0,1,5);

    line(1100,600,1200,700);
    line(1200,600,1100,700);

    line(1200,600,1300,700);
    line(1300,600,1200,700);

}
void undemie(void)
{
    setfillstyle(1,COLOR(211,211,211));
    bar(85,584,1339,713);
    palette();
     //croix or et argent
    setlinestyle(0,1,5);

    line(1100,600,1200,700);
    line(1200,600,1100,700);

    line(1200,600,1300,700);
    line(1300,600,1200,700);

}
void deux(void)
{
    setfillstyle(1,COLOR(211,211,211));
    bar(85,584,1339,713);

    palette();

}

void trois(void)
{
    //croix noir
    line(300,600,400,700);
    line(400,600,300,700);
}
void gris(void)
{
    setfillstyle(1,COLOR(211,211,211));
    bar(0,350,1400,450);
}

int main()
{

    menu();

    int x,y;

    while(1)//ceci permet d'avoir une boucle infinie
        {
            if(ismouseclick(WM_LBUTTONDOWN)) //si utilisateur clique avec sa souris sur la fenetre
            {
                getmouseclick(WM_LBUTTONDOWN,x,y); //on determine les coordonnées du clic et on les stock dans les variable x et y

                if(x>340 and x<642 and y>500 and y<575)//4 bandes
                {
                    //4 anneaux
    setfillstyle(1,COLOR(211,211,211));
    bar(0,0,1400,900);

    un();

    int x,y,i,eme,accent,valeur1,valeur2,digit,r,q;

    float valeur,tolerance,kilo,mega,giga,multiplier;

    cout<<"Cet outil est un calculateur de code couleur des resitances a 4 anneaux"<<endl<<"Pour la saisie des anneaux, cliquer sur la palette de couleurs."<<endl<<"Le resultat sera bien sur converti ;)"<<endl<<endl;

    accent=138; //variable pour accent
    eme=1; //variable pour énumérer l'ordre des résistances (1ère,2ème,3ème...)
    i=1; //sert à parcourir les différents bandes
    r=0;
    q=100000; //variable r et q servent à resoudre un probleme (lorsqu'on multplie avec des trop grands chiffres

    while(1)//ceci permet d'avoir une boucle infinie
        {
            if(i==5) //si i est égal à 5 alors c'est que l'utilisateur à choisit les 4 anneaux, on donne donc le résultat
            {
    digit=valeur1+valeur2; //simple addition entre dizaine et unité
    valeur= digit*multiplier; // simple multiplication entre la somme des deux premieres bandes et le facteur(multiplier)

    if(r==1)
    {
        valeur=valeur*q; //multiplie une derniere fois pour contourner le probleme des grands facteurs
    }

    if(valeur>0 and valeur<=999) // ici on range la valeur pour lui donner une unité correct pour l'utilisateur
    {
        if(eme==1)
        {

           bgiout<<"La valeur de cette 1ère resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1; //on initialise i égal à 1 pour permettre de refaire un calcul de resistance directement sans relancer le programme
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;//on énumére l'ordre des résistances (2ème,3ème...)
            i=1;
            eme++;
        }
    }
    if(valeur>=1000 and valeur<=999999)
    {
        kilo=valeur/1000; //divise par 1000 pour kilo ohms(1000ohms = 1k ohms)
        if(eme==1)
        {
           bgiout<<"La valeur de cette 1ère resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1;
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
            i=1;
            eme++;
        }
    }
    if(valeur>=1000000 and valeur<=999999999)
    {
        mega=valeur/1000000; //divise par 1000000 pour méga ohms(1000000ohms = 1M ohms)
        if(eme==1)
        {
           bgiout<<"La valeur de cette 1ère resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1;
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
            i=1;
            eme++;
        }
    }
    if(valeur>=1000000000)
    {
        giga=valeur/1000000000; //divise par 1000000000 pour giga ohms(1000000000ohms = 1G ohms)
        if(eme==1)
        {
           bgiout<<"La valeur de cette 1ère resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1;
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
            i=1;
            eme++;
        }
    }
            }
            if(ismouseclick(WM_LBUTTONDOWN)) //si utilisateur clique avec sa souris sur la fenetre
            {
                getmouseclick(WM_LBUTTONDOWN,x,y); //on determine les coordonnées du clic et on les stock dans les variable x et y
                //cout<<"dernier clic en "<<x<<" "<<y<<endl;

    if(x>300 and x<400 and y>600 and y<700)//si x et y sont compris dans cette intervalle on rentre dans le if
    {
        if(i==1) //ceci permet au premier tour de remplir la bande 1 et ainsi de suite tout ceci en fonction du i
        {
            valeur1=0;
            setfillstyle(1,0);
            bar(490,103,540,298);//on affiche l'anneau de resistance
            x=0; // on remet x et y égal à 0 pour eviter les erreurs
            y=0;
            i++; //on ajoute 1 à i pour passer à l'anneau suivant
            gris();

        }
        if(i==2 and x!=0 and y!=0) //on précise que x et y ne doivent pas être égal à 0
        {
            valeur2=0;
            setfillstyle(1,0);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();

        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=1;
            setfillstyle(1,0);
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            cout<<"Cette resistance ne peut pas etre utiliser pour la tolerance."<<endl;
            x=0;// on ajoute pas 1 à i car ce code couleur de resistance n'est pas fait pour la tolérance
            y=0;
        }

    }
    if(x>400 and x<500 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=10; //directement mettre des dizaines pour simplifier l'opération entre les deux premieres bandes
            setfillstyle(1,COLOR(153,76,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=1;
            setfillstyle(1,COLOR(153,76,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=10;
            setfillstyle(1,COLOR(153,76,0));
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();

        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=1;
            setfillstyle(1,COLOR(153,76,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();

        }

    }
    if(x>500 and x<600 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=20;
            setfillstyle(1,COLOR(255,0,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=2;
            setfillstyle(1,COLOR(255,0,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=100;
            setfillstyle(1,COLOR(255,0,0));
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=2;
            setfillstyle(1,COLOR(255,0,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>600 and x<700 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=30;
            setfillstyle(1,COLOR(255,128,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=3;
            setfillstyle(1,COLOR(255,128,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=1000;
            setfillstyle(1,COLOR(255,128,0));
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=3;
            setfillstyle(1,COLOR(255,128,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>700 and x<800 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=40;
            setfillstyle(1,COLOR(255,255,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=4;
            setfillstyle(1,COLOR(255,255,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=10000;
            setfillstyle(1,COLOR(255,255,0));
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=4;
            setfillstyle(1,COLOR(255,255,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>800 and x<900 and y>600 and y<700)
    {
        if(i==1 and x!=0 and y!=0)
        {
            valeur1=50;
            setfillstyle(1,2);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=5;
            setfillstyle(1,2);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=100000;
            setfillstyle(1,2);
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=0.5;
            setfillstyle(1,2);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>900 and x<1000 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=60;
            setfillstyle(1,1);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=6;
            setfillstyle(1,1);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=1000000;
            setfillstyle(1,1);
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=0.25;
            setfillstyle(1,1);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>1000 and x<1100 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=70;
            setfillstyle(1,5);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=7;
            setfillstyle(1,5);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=10000000;
            setfillstyle(1,5);
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=0.10;
            setfillstyle(1,5);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>200 and x<300 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=80;
            setfillstyle(1,8);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=8;
            setfillstyle(1,8);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=1000;//opération visant à résoudre le problème on multiplie 2 fois ici par 1000
            setfillstyle(1,8);
            bar(700,103,750,298);
            r+=1;// on ajoute 1 à r qui nous permet de multiplier une seconde fois plus tard
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=0.05;
            setfillstyle(1,8);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>100 and x<200 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=90;
            setfillstyle(1,-2);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=9;
            setfillstyle(1,-2);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=10000; //opération visant à résoudre le problème on multiplie 2 fois ici par 10000
            setfillstyle(1,-2);
            bar(700,103,750,298);
            r+=1; // on ajoute 1 à r qui nous permet de multiplier une seconde fois plus tard
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=20;
            setfillstyle(1,-2);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>1100 and x<1200 and y>600 and y<700)
    {
        if(i==1)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==2 and x!=0 and y!=0)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=0.1;
            setfillstyle(1,COLOR(192,192,192));
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=5;
            setfillstyle(1,COLOR(192,192,192));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>1200 and x<1300 and y>600 and y<700)
    {
        if(i==1)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==2 and x!=0 and y!=0)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==3 and x!=0 and y!=0)
        {
            multiplier=0.01;
            setfillstyle(1,COLOR(255,215,0));
            bar(700,103,750,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==4 and x!=0 and y!=0)
        {
            tolerance=10;
            setfillstyle(1,COLOR(255,215,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }
    }
    if(x>1024 and x<1266 and y>530 and y<559)//reset
    {
        //intérieur resistance
        setfillstyle(1,COLOR(255,229,204));
        bar(452,102,948,298);
        un();
        i=1;
        x=0;
        y=0;
        gris();
    }
    if(x>173 and x<320 and y>500 and y<559)//Ctrl+Z
    {
        if(i==2)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(490,103,540,298);
            i--;
        }
        if(i==3)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(565,103,615,298);
            i--;
            undemie();
        }
        if(i==4)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(700,103,750,298);
            i--;
            deux();
        }
    }

    if(x>1290 and x<1360 and y>40 and y<80) //bouton exit
    {
        return 0; //on retourne 0 c'est à dire fin du programme
    }
            }
        }
                }

                if(x>740 and x<1010 and y>500 and y<575)//5 bandes
                {
                    //5 anneaux
    setfillstyle(1,COLOR(211,211,211));
    bar(0,0,1400,900);

    un();

    int x,y,i,eme,accent,valeur1,valeur2,valeur3,digit,r,q;

    float valeur,tolerance,kilo,mega,giga,multiplier;

    cout<<"Cet outil est un calculateur de code couleur des resitances a 4 anneaux"<<endl<<"Pour la saisie des anneaux, cliquer sur la palette de couleurs."<<endl<<"Le resultat sera bien sur converti ;)"<<endl<<endl;

    accent=138; //variable pour accent
    eme=1; //variable pour énumérer l'ordre des résistances (1ère,2ème,3ème...)
    i=1; //sert à parcourir les différents bandes
    r=0;
    q=100000; //variable r et q servent à resoudre un probleme (lorsqu'on multplie avec des trop grands chiffres

    while(1)//ceci permet d'avoir une boucle infinie
        {
            if(i==6) //si i est égal à 5 alors c'est que l'utilisateur à choisit les 4 anneaux, on donne donc le résultat
            {
    digit=valeur1+valeur2+valeur3; //simple addition entre dizaine et unité
    valeur= digit*multiplier; // simple multiplication entre la somme des deux premieres bandes et le facteur(multiplier)

    if(r==1)
    {
        valeur=valeur*q; //multiplie une derniere fois pour contourner le probleme des grands facteurs
    }

    if(valeur>0 and valeur<=999) // ici on range la valeur pour lui donner une unité correct pour l'utilisateur
    {
        if(eme==1)
        {

           bgiout<<"La valeur de cette 1ère resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1; //on initialise i égal à 1 pour permettre de refaire un calcul de resistance directement sans relancer le programme
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<valeur<<" Ohms "<<tolerance<<"%"<<endl<<endl;//on énumére l'ordre des résistances (2ème,3ème...)
            i=1;
            eme++;
        }
    }
    if(valeur>=1000 and valeur<=999999)
    {
        kilo=valeur/1000; //divise par 1000 pour kilo ohms(1000ohms = 1k ohms)
        if(eme==1)
        {
           bgiout<<"La valeur de cette 1ère resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1;
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<kilo<<"k Ohms "<<tolerance<<"%"<<endl<<endl;
            i=1;
            eme++;
        }
    }
    if(valeur>=1000000 and valeur<=999999999)
    {
        mega=valeur/1000000; //divise par 1000000 pour méga ohms(1000000ohms = 1M ohms)
        if(eme==1)
        {
           bgiout<<"La valeur de cette 1ère resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1;
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<mega<<"M Ohms "<<tolerance<<"%"<<endl<<endl;
            i=1;
            eme++;
        }
    }
    if(valeur>=1000000000)
    {
        giga=valeur/1000000000; //divise par 1000000000 pour giga ohms(1000000000ohms = 1G ohms)
        if(eme==1)
        {
           bgiout<<"La valeur de cette 1ère resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
           outstreamxy(120,400);

           cout<<"La valeur de cette 1"<<(char)accent<<"re resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
           i=1;
           eme++;
        }
        else
        {
            bgiout<<"La valeur de cette "<<eme<<"ème resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
            outstreamxy(120,400);

            cout<<"La valeur de cette "<<eme<<(char)accent<<"me resistance est de "<<giga<<"G Ohms "<<tolerance<<"%"<<endl<<endl;
            i=1;
            eme++;
        }
    }
            }
            if(ismouseclick(WM_LBUTTONDOWN)) //si utilisateur clique avec sa souris sur la fenetre
            {
                getmouseclick(WM_LBUTTONDOWN,x,y); //on determine les coordonnées du clic et on les stock dans les variable x et y
                //cout<<"dernier clic en "<<x<<" "<<y<<endl;

    if(x>300 and x<400 and y>600 and y<700)//si x et y sont compris dans cette intervalle on rentre dans le if
    {
        if(i==1) //ceci permet au premier tour de remplir la bande 1 et ainsi de suite tout ceci en fonction du i
        {
            valeur1=0;
            setfillstyle(1,0);
            bar(490,103,540,298);//on affiche l'anneau de resistance
            x=0; // on remet x et y égal à 0 pour eviter les erreurs
            y=0;
            i++; //on ajoute 1 à i pour passer à l'anneau suivant
            gris();

        }
        if(i==2 and x!=0 and y!=0) //ceci permet au premier tour de remplir la bande 1 et ainsi de suite tout ceci en fonction du i
        {
            valeur2=0;
            setfillstyle(1,0);
            bar(565,103,615,298);//on affiche l'anneau de resistance
            x=0; // on remet x et y égal à 0 pour eviter les erreurs
            y=0;
            i++; //on ajoute 1 à i pour passer à l'anneau suivant

        }
        if(i==3 and x!=0 and y!=0) //on précise que x et y ne doivent pas être égal à 0
        {
            valeur3=0;
            setfillstyle(1,0);
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();

        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=1;
            setfillstyle(1,0);
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            cout<<"Cette resistance ne peut pas etre utiliser pour la tolerance."<<endl;
            x=0;// on ajoute pas 1 à i car ce code couleur de resistance n'est pas fait pour la tolérance
            y=0;
        }

    }
    if(x>400 and x<500 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=100; //directement mettre des dizaines pour simplifier l'opération entre les deux premieres bandes
            setfillstyle(1,COLOR(153,76,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=10;
            setfillstyle(1,COLOR(153,76,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=1;
            setfillstyle(1,COLOR(153,76,0));
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=10;
            setfillstyle(1,COLOR(153,76,0));
           bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();

        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=1;
            setfillstyle(1,COLOR(153,76,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();

        }

    }
    if(x>500 and x<600 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=200;
            setfillstyle(1,COLOR(255,0,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=20;
            setfillstyle(1,COLOR(255,0,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=2;
            setfillstyle(1,COLOR(255,0,0));
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=100;
            setfillstyle(1,COLOR(255,0,0));
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=2;
            setfillstyle(1,COLOR(255,0,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>600 and x<700 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=300;
            setfillstyle(1,COLOR(255,128,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=30;
            setfillstyle(1,COLOR(255,128,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=3;
            setfillstyle(1,COLOR(255,128,0));
           bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=1000;
            setfillstyle(1,COLOR(255,128,0));
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=3;
            setfillstyle(1,COLOR(255,128,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>700 and x<800 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=400;
            setfillstyle(1,COLOR(255,255,0));
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=40;
            setfillstyle(1,COLOR(255,255,0));
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=4;
            setfillstyle(1,COLOR(255,255,0));
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=10000;
            setfillstyle(1,COLOR(255,255,0));
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=4;
            setfillstyle(1,COLOR(255,255,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>800 and x<900 and y>600 and y<700)
    {
        if(i==1 and x!=0 and y!=0)
        {
            valeur1=500;
            setfillstyle(1,2);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=50;
            setfillstyle(1,2);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=5;
            setfillstyle(1,2);
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=100000;
            setfillstyle(1,2);
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=0.5;
            setfillstyle(1,2);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>900 and x<1000 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=600;
            setfillstyle(1,1);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=60;
            setfillstyle(1,1);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=6;
            setfillstyle(1,1);
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=1000000;
            setfillstyle(1,1);
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=0.25;
            setfillstyle(1,1);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>1000 and x<1100 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=700;
            setfillstyle(1,5);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=70;
            setfillstyle(1,5);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=7;
            setfillstyle(1,5);
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=10000000;
            setfillstyle(1,5);
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=0.10;
            setfillstyle(1,5);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>200 and x<300 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=800;
            setfillstyle(1,8);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=80;
            setfillstyle(1,8);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=8;
            setfillstyle(1,8);
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=1000;//opération visant à résoudre le problème on multiplie 2 fois ici par 1000
            setfillstyle(1,8);
            bar(750,103,800,298);
            r+=1;// on ajoute 1 à r qui nous permet de multiplier une seconde fois plus tard
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=0.05;
            setfillstyle(1,8);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>100 and x<200 and y>600 and y<700)
    {
        if(i==1)
        {
            valeur1=900;
            setfillstyle(1,-2);
            bar(490,103,540,298);
            x=0;
            y=0;
            i++;
            gris();
        }
        if(i==2 and x!=0 and y!=0)
        {
            valeur2=90;
            setfillstyle(1,-2);
            bar(565,103,615,298);
            x=0;
            y=0;
            i++;
        }
        if(i==3 and x!=0 and y!=0)
        {
            valeur3=9;
            setfillstyle(1,-2);
            bar(640,103,690,298);
            x=0;
            y=0;
            i++;
            deux();
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=10000; //opération visant à résoudre le problème on multiplie 2 fois ici par 10000
            setfillstyle(1,-2);
            bar(750,103,800,298);
            r+=1; // on ajoute 1 à r qui nous permet de multiplier une seconde fois plus tard
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=20;
            setfillstyle(1,-2);
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>1100 and x<1200 and y>600 and y<700)
    {
        if(i==1)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==2 and x!=0 and y!=0)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==3 and x!=0 and y!=0)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=0.1;
            setfillstyle(1,COLOR(192,192,192));
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=5;
            setfillstyle(1,COLOR(192,192,192));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }

    }
    if(x>1200 and x<1300 and y>600 and y<700)
    {
        if(i==1)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==2 and x!=0 and y!=0)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==3 and x!=0 and y!=0)
        {
            cout<<"Cette resistance peut seulement etre utiliser pour le multiplier et pour la tolerance."<<endl;

            x=0;
            y=0;
        }
        if(i==4 and x!=0 and y!=0)
        {
            multiplier=0.01;
            setfillstyle(1,COLOR(255,215,0));
            bar(750,103,800,298);
            x=0;
            y=0;
            i++;
            trois();
        }
        if(i==5 and x!=0 and y!=0)
        {
            tolerance=10;
            setfillstyle(1,COLOR(255,215,0));
            bar(860,103,910,298);
            x=0;
            y=0;
            i++;
            undemie();
        }
    }
    if(x>1024 and x<1266 and y>530 and y<559)//reset
    {
        //intérieur resistance
        setfillstyle(1,COLOR(255,229,204));
        bar(452,102,948,298);
        un();
        i=1;
        x=0;
        y=0;
        valeur1=0;
        valeur2=0;
        gris();
    }
    if(x>173 and x<320 and y>500 and y<559)//Ctrl+Z
    {
        if(i==2)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(490,103,540,298);
            i--;
        }
        if(i==3)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(565,103,615,298);
            i--;

        }
        if(i==4)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(640,103,690,298);
            i--;
            undemie();
        }
        if(i==5)
        {
            setfillstyle(1,COLOR(255,229,204));
            bar(750,103,800,298);
            i--;
            deux();
        }
    }

    if(x>1290 and x<1360 and y>40 and y<80) //bouton exit
    {
        return 0; //on retourne 0 c'est à dire fin du programme
    }
            }
        }
                }





                if(x>1290 and x<1360 and y>40 and y<80) //bouton exit
    {
        return 0; //on retourne 0 c'est à dire fin du programme
    }

            }

        }

    }
