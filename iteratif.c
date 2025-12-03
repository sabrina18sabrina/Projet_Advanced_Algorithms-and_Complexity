#include <stdio.h>
#include <stdlib.h>


//enregistrement(pile)
typedef struct {
    int *t;
    int sommet;
} Pile;
// creer une pile
Pile* nouvellepile(int n) {
    Pile *p = malloc(sizeof(Pile));
    p->t = malloc(n * sizeof(int));
    p->sommet = -1;
    return p;
}
//empiler(ajouter) un element
void push(Pile *p, int x) {
    p->t[++p->sommet] = x;
}
//depiler(supprimer) un element
int pop(Pile *p) {
    if (p->sommet == -1) return -1;
    return p->t[p->sommet--];
}
// afficher le sommet du stack
int top(Pile *p) {
    if (p->sommet == -1) return -1;
    return p->t[p->sommet];
}
// fonction qui permet de montrer les deplacements
void move(int disque, char from, char to) {
    printf("Déplacer disque %d de %c vers %c\n", disque, from, to);
}
// fonction qui permet de faire le deplacement
void deplacement(Pile *a, Pile *b, char A, char B) {
    int x = top(a);
    int y = top(b);
    // si a est vide , on prend de b
    if (x == -1) {
        pop(b);
        push(a, y);
        move(y, B, A);
    } // si b est vide , on prend de a
    else if (y == -1) {
        pop(a);
        push(b, x);
        move(x, A, B);
    }// sinon on prend le plus petit
    else if (x > y) {
        pop(b);
        push(a, y);
        move(y, B, A);
    }
    else {
        pop(a);
        push(b, x);
        move(x, A, B);
    }
}

void hanoiiteratif(int n, char A, char B, char C) {
    int i, total;
    // on cree les 3 piles
    Pile *src = nouvellepile(n);
    Pile *aux = nouvellepile(n);
    Pile *dest = nouvellepile(n);
    // on met tous les disques sur la pile(tour) source dans un ordre decroissant
    for (i = n; i >= 1; i--) {
        push(src, i);
    }
     // si n est pair, alors on inverse B et C
    if (n % 2 == 0) {
        char tmp = C;
        C = B;
        B = tmp;
    }
   // calcul du nombre total de deplacements necessaires
    total = (1 << n) - 1;

    for (i = 1; i <= total; i++) {
        if (i % 3 == 1)
            deplacement(src, dest, A, C);
        else if (i % 3 == 2)
            deplacement(src, aux, A, B);
        else
            deplacement(aux, dest, B, C);
    }
}

int main() {
    int n;
    printf("Donner le nombre de disques : ");
    scanf("%d", &n);

    hanoiiteratif(n, 'A', 'B', 'C');

    return 0;
}
