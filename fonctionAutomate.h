//@ requires chemin valide vers un automate
//@ assigns rien
//@ ensures le nombre 
int nombre_etat(char* automate);

//@ requires un etat s entre 0 et 255 et un caractere c entre 0 et 255 et un chemin valide vers un automate
//@ assigns rien
//@ ensures action(s,c)= 0=rejet, 1=accepte, 2=decale, 3=reduit
unsigned char action(char s,char c, char* automate);

//@ requires un etat s entre 0 et 255 et chemin valide vers un automate
//@ assigns rien 
//@ ensures reduit1(s)=n , avec n le nombre de fois qu'on va depiler
unsigned char reduit1(char s, char* automate);

//@ requires un etat s entre 0 et 255 et chemin valide vers un automate
//@ assigns rien
//@ ensures reduit2(s)=a , avec a le caractere non terminal de branchement
unsigned char reduit2(char s, char* automate);

//@ requires un etat s entre 0 et 255 et chemin valide vers un automate
//@ assigns rine
//@ ensures decale(s,c)=s'
unsigned char decale(char s,char c, char* automate);

//@ requires un etat s entre 0 et 255 et chemin valide vers un automate
//@ assigns rien
//@ ensures branchement(s,c)=s'
unsigned char branchement(char s,char c, char* automate);