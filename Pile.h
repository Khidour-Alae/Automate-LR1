
typedef struct Element Element;
struct Element
{
    unsigned char nombre;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};
 
//@ requires rien
//@ assigns rien
//@ ensures cree un pile vide 
Pile *initialiser();

//@ requires une pile et un nouveau element
//@ assigns pile
//@ ensures empile le nouveau element dans la pile
void empiler(Pile *pile, unsigned char nvNombre);

//@ requires une pile non vide
//@ assigns pile
//@ ensures depile la tete de pile et la renvoie
unsigned char depiler(Pile *pile);