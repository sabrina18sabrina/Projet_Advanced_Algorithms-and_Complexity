#include <stdio.h>

#define MAX 100

int A[MAX], topA = -1;
int B[MAX], topB = -1;
int C[MAX], topC = -1;

 // push 
void push(int peg[], int *top, int disk) {
    peg[++(*top)] = disk;
}

// pop
int pop(int peg[], int *top) {
    return peg[(*top)--];
}

// afficher les pegs
void afficherPegs() {
    int i;
    printf("A: ");
    for(i=0; i<=topA; i++) printf("%d ", A[i]);
    printf("\tB: ");
    for(i=0; i<=topB; i++) printf("%d ", B[i]);
    printf("\tC: ");
    for(i=0; i<=topC; i++) printf("%d ", C[i]);
    printf("\n");
}

// recursive de Hanoi
void Hanoi(int n, char source, char destination, char auxiliaire) {
    if(n == 1) {
    
        int disk;
        if(source == 'A') disk = pop(A, &topA);
        if(source == 'B') disk = pop(B, &topB);
        if(source == 'C') disk = pop(C, &topC);

        if(destination == 'A') push(A, &topA, disk);
        if(destination == 'B') push(B, &topB, disk);
        if(destination == 'C') push(C, &topC, disk);
        // affiche sur le terminal
       printf("Deplacer disque %d de %c a %c\n", disk, source, destination);
        afficherPegs();
    } else {
        Hanoi(n-1, source, auxiliaire, destination);  
        Hanoi(1, source, destination, auxiliaire);    
        Hanoi(n-1, auxiliaire, destination, source);  
    }
}
// le main pour laffichage sur le terminal
int main() {
    int n, i;

    printf("Entrer le nombre de disques: ");
    scanf("%d", &n);
    for(i=n; i>=1; i--) push(A, &topA, i);
    printf("Etat initial des pegs:\n");
    afficherPegs();
    Hanoi(n, 'A', 'C', 'B');

    return 0;
}

