#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// initialisation des variables
int main() {
    char ordre, txt2[200], tab[30];
    int i, j, k, len, lettre = 0, occurence, max, f = 0, tab1[30];
    double pro, proba[30];

    // saisie de texte
    printf("Donner le texte chiffré par sub :\t");
    fgets(txt2, sizeof(txt2), stdin);
    len = strlen(txt2);

    // quantité d alphabet
    for (i = 0; i < len; i++) {
        if (isalpha(txt2[i]))
            lettre++;
    }

    // nombre d occurences
    for (i = 0; i < len; i++) {
        occurence = 0;

        for (j = 0; j < len; j++) {
            if (i == j) // sauter
                continue;
            else if (isalpha(txt2[i]) && tolower(txt2[i]) == tolower(txt2[j]))
                occurence++;
        }

        // suppression de repitition
        int existe = 0;
        for (k = 0; k < f; k++) {
            if (tab[k] == tolower(txt2[i])) {
                existe = 1;
                break;
            }
        }

        if (isalpha(txt2[i]) && !existe) {
            tab1[f] = occurence + 1; // insertion de l occurence
            tab[f] = tolower(txt2[i]);
            f++;
        }
    }

    // Display letters, occurrences, and probabilities
    for (i = 0; i < f; i++) {
        proba[i] = (double)tab1[i] / lettre;
        printf("\nSymbole %d %c : NbOccurrence: %d Proba: %lf\n",i+1, tab[i], tab1[i], proba[i]);
    }

    // tri decroissant
    for (i = 0; i < f; i++) {
        for (j = i + 1; j < f; j++) {
            if (tab1[i] < tab1[j]) {
                // tri d occurences
                max = tab1[i];
                tab1[i] = tab1[j];
                tab1[j] = max;

                // tri de lettres
                ordre = tab[i];
                tab[i] = tab[j];
                tab[j] = ordre;

                // tri de proba
                pro = proba[i];
                proba[i] = proba[j];
                proba[j] = pro;
            }
        }
    }

    // afficher les 4 premier
    if (f > 3) {
        for (i = 0; i < 4; i++)
            printf("\nSymbole:%d  %c NbOccurrence: %d Probabilité: %lf\n",i+1, tab[i], tab1[i], proba[i]);
    } else {
        for (i = 0; i < f; i++)
            printf("\nSymbole: %d %c NbOccurrence: %d Probabilité: %lf\n",i+1, tab[i], tab1[i], proba[i]);
    }
//compairaison entre les plus répeté
char repete[4] = {'e', 's', 'a', 'n'};
double probb[4] = {0.1769, 0.0887, 0.0811, 0.0768};

if (f>3) {
    for (i=0; i<4;i++) {
        printf("\n Symbole:%d  %c  de Proba %lf  en Decalage avec %c:\n",i + 1, tab[i], proba[i], repete[i]);
    }
} else {
    for (i=0; i<f;i++) {
        printf("\nSymbole: %d %c de proba  %lf en Decalage avec %c \n",i + 1, tab[i], proba[i], repete[i]);
    }
}


return 0;
}
