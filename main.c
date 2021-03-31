#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Elev
{
    int Nr_matricol;
    char nume[250], telefon[20], parinte1[250], parinte2[250],adresa[250], data_nasterii[50];
    int purtare;

    struct Materie
    {
        char numeM[50];
        char medie[101];
        char nota[101];
        int absente;

    } materie[1001];

}elevi[1001];

char *p, l[505],k[105],al,materie1[101],materie2[101],materie3[101],b[150];

int i,j,y,x,z;
int lungime, nrelevi, nrmaterii,nrabs;

void AdaugaElev(int nrelevi, int nrmaterii)
{
    char date[150], materie111;
    int j;
    printf("Introduceti numele elevului: ");
    scanf("%s",&date);
    strcpy(elevi[nrelevi].nume,date);
    printf("Introduceti numarul de telefon: ");
    scanf("%s",&date);
    strcpy(elevi[nrelevi].telefon,date);
    printf("Introduceti numele tatalui: ");
    scanf("%s",&date);
    strcpy(elevi[nrelevi].parinte1,date);
    printf("Introduceti numele mamei: ");
    scanf("%s",&date);
    strcpy(elevi[nrelevi].parinte2,date);
    printf("Introduceti adresa elevului: ");
    scanf("%s",&date);
    strcpy(elevi[nrelevi].adresa,date);
    printf("Introduceti data nasterii: ");
    scanf("%s",&date);
    strcpy(elevi[nrelevi].data_nasterii,date);
    elevi[nrelevi].Nr_matricol=nrelevi;
    printf("\n");
    printf("%d %s %s %s %s %s %s ",elevi[nrelevi].Nr_matricol,elevi[nrelevi].nume,elevi[nrelevi].telefon,elevi[nrelevi].parinte1,elevi[nrelevi].parinte2,elevi[nrelevi].adresa,elevi[nrelevi].data_nasterii);

    for(j=1;j<=nrmaterii;j++)
    {
        strcpy(elevi[nrelevi].materie[j].numeM,elevi[1].materie[j].numeM);
        elevi[nrelevi].materie[j].absente=0;
        printf(" %s %s",elevi[nrelevi].materie[j].numeM,elevi[nrelevi].materie[j].absente);
    }

}
void AdaugaMaterie(int nrmaterii, int nrelevi)
{
    int i;
    char materie[40];
    printf("Cieteste noua materie: ");
    scanf("%s", &materie);
    for(i=1;i<=nrelevi;i++)
    {
        strcpy(elevi[i].materie[nrmaterii].numeM,materie);
        strcpy(elevi[nrelevi].materie[j].medie,"0");
        strcpy(elevi[nrelevi].materie[j].nota,"0");
        elevi[nrelevi].materie[j].absente=0;
        printf("%s",elevi[i].materie[nrmaterii].numeM);
    }
}
void AdaugareAbsente(int nrmaterii)
{
    int k,matricol,abs,nr;
    printf("\nIntroduceti numarul matricol al elevului: ");
    scanf("%d", &matricol);
    printf("Aegeti materia:\n");
    for(j=1;j<=nrmaterii;j++)
    printf("%d) %s\n",j,elevi[1].materie[j].numeM);
    printf("Raspuns: ");
    scanf("%d",&k); // k este numarul materiei
    printf("Numarul de absente actual: ");
    printf("%d",elevi[matricol].materie[k].absente);
    printf("\nNumarul de absente pe care doriti sa il adaugati: ");
    scanf("%d",&abs);//nr de adaugat
    printf("Numarul de absente in final: ");
    //nr =  atoi(elevi[matricol].materie[k].absente);
   elevi[matricol].materie[k].absente+=abs;
   printf("%d",elevi[matricol].materie[k].absente);

}
void AdaugaNota(int nrmaterii)
{
    int nr,i,a;
    char b[3];
    printf("Introduceti numarul matricol al elevului: ");
    scanf("%d",&nr);
    printf("Introduceti materia: \n");
    for(i=1;i<=nrmaterii;i++)
    {
        printf("%d) %s\n",i,elevi[1].materie[i].numeM);
    }
    printf("Raspunsul este: ");
    scanf("%d",&a);
    printf("Introduceti nota: ");
    scanf("%s",&b);

    strcat(elevi[nr].materie[a].nota,",");
    strcat(elevi[nr].materie[a].nota,b);
    printf("%s",elevi[nr].materie[a].nota);
    ////////////////////////////////////////////////////
    int t;
    float s=0,k=0;
    t=strlen(elevi[nr].materie[a].nota);
    char x[150],*p;
    strcpy(x,elevi[nr].materie[a].nota);
    p=strtok(x,",");
    //atoi(p)
    while(p)
    {
        s=s+atoi(p);
        k++;
        p=strtok(NULL,",");
    }
    float media;
    media=s/k;
    //////////////////////////////
    int ab;
    ab=(int)round(media);
    //printf("\n %d",ab);
    char n[3];
    //n=ab+'0';
    itoa(ab,n,10);
    //printf("\n %s",n);
    strcpy(elevi[nr].materie[a].medie,n);
    printf("\n%s",elevi[nr].materie[a].medie);

}
void StergeElev()
{
    int nr;
    printf("Introduceti numarul matricol al elevului: ");
    scanf("%d",&nr);
    elevi[nr].Nr_matricol=-1;
    printf("%d",elevi[nr].Nr_matricol);

}
void DateElev() //////////////////////////////////////////////// 5
{
    int matricol,nr,nr2;
    char date[150];
    printf("\nIntroduceti numarul matricol al elevului: ");
    scanf("%d", &matricol);
    printf("\nLegenda schimbari:\n\n");
    printf("1) Numele elevului\n");
    printf("2) Numarul de telefon\n");
    printf("3) Numele tatalui\n");
    printf("4) Numele mamei \n");
    printf("5) Adresa elevului\n");
    printf("6) Data nasterii\n");
    printf("\n");
    printf("Introduceti numarul elementului care trebuie schimbat: ");
    scanf("%d", &nr);
    while(nr)
    {
        switch (nr)
        {
        case 1:
            printf("Introduceti numele elevului: ");
            scanf("%s",&date);
            strcpy(elevi[matricol].nume,date);
            break;

        case 2:
            printf("Introduceti numarul de telefon: ");
            scanf("%s",&date);
            strcpy(elevi[matricol].telefon,date);
            break;

        case 3:
            printf("Introduceti numele tatalui: ");
            scanf("%s",&date);
            strcpy(elevi[matricol].parinte1,date);
            break;

        case 4:
            printf("Introduceti numele mamei: ");
            scanf("%s",&date);
            strcpy(elevi[matricol].parinte2,date);
            break;

        case 5:
            printf("Introduceti adresa elevului: ");
            scanf("%s",&date);
            strcpy(elevi[matricol].adresa,date);
            break;

        case 6:
            printf("Introduceti data nasterii: ");
            scanf("%s",&date);
            strcpy(elevi[matricol].data_nasterii,date);
            break;

        default:
            nr=0;
            break;
        }
        printf("Doriti sa mai continuati?\n 1)Da\n 2)Nu\n");
        printf("Raspuns: ");
        scanf("%d",&nr2);
        if(nr2==1)
        {
            printf("Introduceti numarul elementului care trebuie schimbat: ");
            scanf("%d", &nr);
        }
        else nr=0;
    }

   }
   void Afisare()
{
    int nr;
    printf("Alegeti modul de afisare: ");
    printf("\n 1)Alfabetic");
    printf("\n 2)Clasament");
    printf("\n 3)Elevii cu nota scazuta la purtare");
    printf("\nRaspunsul dumneavoastra este: ");
    scanf("%d",&nr);
    if(nr==1) Alfabetic();
    else if(nr==2) Clasament();
    else if(nr==3) Scazuta();

}
void Alfabetic()
{
    printf("Inca nu e gata");
}
void Clasament()
{
    printf("Inca nu e gata");
}
void Scazuta()
{
    printf("Inca nu e gata");
}
void StergeMateria()
{
    printf("Inca nu e gata");
}
int main()
{
    /////////////////////////////////aici luam informatiile pt elevi

    FILE *elev;
   elev=fopen("intrare.csv","r");
   char linie[150],ln[150];
   i=0;
   while(!feof(elev))
   {
       fgets(linie,150,elev); //citire linie
       strcpy(l,linie);
       p=strtok(l,";");
       while(p)
       {
        elevi[i].Nr_matricol=i;
        p=strtok(0,";");
        strcpy(elevi[i].nume,p);
        p=strtok(0,";");
        strcpy(elevi[i].telefon,p);
        p=strtok(0,";");
        strcpy(elevi[i].parinte1,p);
        p=strtok(0,";");
        strcpy(elevi[i].parinte2,p);
        p=strtok(0,";");
        strcpy(elevi[i].adresa,p);
        p=strtok(0,";");
        strcpy(elevi[i].data_nasterii,p);
        p=strtok(0,";");
        i++;

       }
   }

   i=i-2;
   nrelevi=i;
   fclose(elev);
   //printf("%d %s %s %s %s %s %s",elevi[2].Nr_matricol,elevi[2].nume,elevi[2].telefon,elevi[2].parinte1,elevi[2].parinte2,elevi[2].adresa,elevi[2].data_nasterii);
   for(j=1;j<=i;j++)
   {
       //printf("%d %s %s %s %s %s %s",elevi[j].Nr_matricol,elevi[j].nume,elevi[j].telefon,elevi[j].parinte1,elevi[j].parinte2,elevi[j].adresa,elevi[j].data_nasterii);
   }

   /////////////////////////////////aici luam informatiile de la materii

   FILE *mat;
   mat=fopen("Materii11.csv","r");
   i=1;
   fgets(linie,150,elev);
   while(!feof(mat))
   {
       /*fgets(linie,150,mat);
       puts(linie);*/


       j=1;
       fgets(linie,150,elev); //citire linie
       strcpy(l,linie);
       p=strtok(l,";");
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].numeM,p);
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].nota,p);
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].medie,p);
       p=strtok(NULL,";");
       elevi[i].materie[j].absente = atoi(p);

       j=2;
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].numeM,p);
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].nota,p);
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].medie,p);
       p=strtok(NULL,";");
       elevi[i].materie[j].absente = atoi(p);

       j=3;
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].numeM,p);
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].nota,p);
       p=strtok(NULL,";");
       strcpy(elevi[i].materie[j].medie,p);
       p=strtok(NULL,";");
       elevi[i].materie[j].absente = atoi(p);

       p=strtok(NULL,";");
       elevi[i].purtare=atoi(p);
        //printf("%d ",elevi[i].purtare);
       //printf("%s %s    Medie %s Absente %d\n",elevi[i].materie[j].numeM,elevi[i].materie[j].nota,elevi[i].materie[j].medie,elevi[i].materie[j].absente);
       i++;
    }

   i=i-2;
   nrmaterii=3;
   fclose(mat);
   ///////////////////////////////// aici incep cerintele in sine
   printf("\n");
   printf("         Legenda:\n");
   printf("1)    Adaugarea unui nou elev\n"); /////////////////////
   printf("2)    Adaugarea unei noi materii\n");////////////////////
   printf("3)     Stergerea unei materii\n");
   printf("4)    Adaugarea unei note\n");////////////////
   printf("5)     Adaugarea absentelor la o materie\n");////////////////////
   printf("6)    Modificarea datelor despre un elev\n");/////////////
   printf("7)    Stergerea unui elev si a tuturor notelor sale\n");
   printf("8)    Afisari pe baza datelor citite\n");
   printf("\n");
   printf("Alegeti numarul operatiei pe care doriti sa il efectuati: ");
   scanf("%d", &z);
    if(z==1) {nrelevi++; AdaugaElev(nrelevi,nrmaterii);}
    else if(z==2) {nrmaterii++;AdaugaMaterie(nrmaterii,nrelevi);}
    else if(z==3) StergeMateria();
    else if(z==4) AdaugaNota(nrmaterii);
    else if(z==5) AdaugareAbsente(nrmaterii);
    else if(z==6) DateElev();
    else if(z==7) StergeElev();
    else if(z==8) Afisare();
    else
    {for(j=1;j<=nrelevi;j++)
   {
       printf("%d %s %s %s %s %s %s\n",elevi[j].Nr_matricol,elevi[j].nume,elevi[j].telefon,elevi[j].parinte1,elevi[j].parinte2,elevi[j].adresa,elevi[j].data_nasterii);
       for(i=1;i<=nrmaterii;i++)
        printf("%s\n",elevi[j].materie[i].numeM);
   }
   printf("\n");}
    return 0;
}
