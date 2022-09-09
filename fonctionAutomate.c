#include <stdlib.h>
#include <stdio.h>
#include "fonctionAutomate.h"

int nombre_etat(char* automate){
    FILE* fichier = fopen(automate, "r");
    int nq;
    fscanf(fichier,"a %d",&nq);

    fclose(fichier);
    return nq;
}
unsigned char action(char s,char c, char* automate){
    FILE* fichier = fopen(automate, "rb");
    unsigned char octet; //l'octet selectionne
    fseek(fichier, (4+128*s+c), SEEK_CUR);
    octet=(char)fgetc(fichier);

    fclose(fichier);
    return octet;
}

unsigned char reduit1(char s, char* automate){
    FILE* fichier = fopen(automate, "rb");
    unsigned char octet; //l'octet selectionne
    int nq=nombre_etat(automate);
    fseek(fichier, (4+(nq*128+1)+s), SEEK_CUR); //Pour se placer au debut de la 3eme ligne
    octet=(char)fgetc(fichier);

    fclose(fichier);
    return octet;
}

unsigned char reduit2(char s, char* automate){
    FILE* fichier = fopen(automate, "rb");
    unsigned char octet; //l'octet selectionne
    int nq=nombre_etat(automate);
    fseek(fichier, (4+(nq*128+1)+(nq+1)+s), SEEK_CUR); //Pour se placer au debut de la 4eme ligne
    octet=(char)fgetc(fichier);

    fclose(fichier);
    return octet;
}

unsigned char decale(char s,char c, char* automate){
    FILE* fichier = fopen(automate, "rb");
    unsigned char octet; //l'octet selectionne
    unsigned char caractere; //le caractere selectionne
    unsigned char resultat; //le resultat qui va etre renvoye
    int nq=nombre_etat(automate);
    fseek(fichier, (4+(nq*128+1)+2*(nq+1)), SEEK_CUR); //Pour se placer au debut de la 5eme ligne
    do{
        octet=(char)fgetc(fichier);
        caractere=(char)fgetc(fichier);
        resultat=(char)fgetc(fichier);
    }while(octet!=s || caractere!=c);

    fclose(fichier);
    return resultat;
}

unsigned char branchement(char s,char c, char* automate){
    int n_ad=0; //compteur des 'ad' (='/255' en hexa)
    FILE* fichier = fopen(automate, "rb");
    unsigned char octet; //l'octet selectionne
    unsigned char caractere; //l'octet selectionne
    unsigned char resultat; //le resultat qui va etre renvoye
    int nq=nombre_etat(automate);
    fseek(fichier, (4+(nq*128+1)+2*(nq+1)), SEEK_CUR); //Pour se placer au debut de la 5eme ligne
    while(n_ad!=3){
        octet=fgetc(fichier);
        if (octet==173){ //173 en decimal = '/255' en octal
            n_ad ++;
        }
    }
    do{
        octet=(char)fgetc(fichier);
        caractere=(char)fgetc(fichier);
        resultat=(char)fgetc(fichier);
    }while(octet!=s || caractere!=c);
    
    fclose(fichier);
    return resultat;
}