#include <stdlib.h>
#include <stdio.h>
#include "Pile.h"
#include "fonctionAutomate.h"



//@ requires chemin valide vers un automate et une chaine de caracteres
//@ assigns rien
//@ ensures accepted ou rejected apres avoir applique l'automate sur la chaine de caractere
void automate(char* texte, char* automate);

//fonctions main

void automate(char* texte, char* automate){
    unsigned char c_a; //c_a=caractere actuel
    int i=0; //Cette variable va servir pour acceder au caractere actuel
    unsigned char c_n_t_a; //c_n_t_a=caractere non terminal actuel
    unsigned char e_a=0; //e_a=etat actuel
    unsigned char test; //Cette variable va servir pour stocker la valeur de action(e_a,c_a)
                        //0=rejet, 1=accepte, 2=decale, 3=reduit
    unsigned char n; //Cette variable servira pour stocker la 1ere composante de reduit cad reduit1
    int j; //Cette variable servira pour la boucle for a la ligne 219.
    Pile *pileEtat = initialiser();
    empiler(pileEtat, 0);
    c_a=texte[i];
    test=action(e_a,c_a,automate);
    while((test!=0) && (test!=1) ){
        while( (test)==2  ){
            e_a=decale(e_a,c_a,automate);
            empiler(pileEtat,e_a);
            i++;
            c_a=texte[i];
            test=action(e_a,c_a,automate);
        }
        
        if( (test)==3 ){
            n=reduit1(e_a,automate);
            c_n_t_a=reduit2(e_a,automate);
            for(j=0;j<n;j++){
                depiler(pileEtat);
            }
            e_a=(pileEtat->premier)->nombre; //l'etat actuel est la tete de pile
            e_a=branchement(e_a,c_n_t_a,automate);
            empiler(pileEtat,e_a);
        }
        test=action(e_a,c_a,automate);
    }
    if( (test)==0 ){
        printf("Rejected \n");
    }
    if( (test)==1 ){
        printf("Accepted \n");
    }

}

/*...............................*/

int main(int argc, char *argv[]){
    char texte[1000];
    int fermer=0;
    do
        {
            printf("\nVeuillez tapper votre entree (de taille inferieur a 1000 caractere): ");
            fgets(texte,1000,stdin);
            automate(texte,argv[1]);
        }while(fermer!=1);
    return 0;
}