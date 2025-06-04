#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialisation des variables
    char txt[50], txt2[50], txt3[50], car, symb;
    int lencr, ascmax, tmp, maj, min, ascm, asci, diff, ascz, i, lendec, j, ascmaj, tmp1, symb1, symb2;

    // Constante pour le décalage de César
    int decal;

    do {
        printf("donner un cle souhaite  positive svp \t");-
        scanf("%d", &decal);
        getchar(); // liberer la memoire afin d eviter probleme avec fgets
    } while (decal <= 0);
    decal=decal%26;

    // Demande du message à l'utilisateur
    printf(" \n TAPEZ LE MESSAGE QUE TU VEUX CRYPTER SVP : \t ");
    fgets(txt, sizeof(txt), stdin);

    // Calcul de la longueur du texte
    lencr = strlen(txt);

    // Définition des limites ASCII pour les majuscules et minuscules
    ascmax = (int)'z';
    ascmaj = (int)'Z';

    // Début du cryptage
    for (i = 0; i < lencr; i++) {
        ascm = (int)txt[i]; // Convertir en valeur ASCII

        // Cryptage des majuscules
        if (txt[i] >= 'A' && txt[i] <= 'Z') {
            if (decal+ ascm <= ascmaj) { // De 'A' à 'M' vers 'N' à 'Z'
                tmp = ascm + decal;
                car = (char)tmp;
                txt2[i] = car;
            } else { // De 'N' à 'Z' vers 'A' à 'M'
                maj = ascm + decal - 26;
                car = (char)maj;
                txt2[i] = car;
            }
        }
        // Cryptage des minuscules
        else if (txt[i] >= 'a' && txt[i] <= 'z') {
            if ( decal+ ascm <= ascmax) { // De 'a' à 'm' vers 'n' à 'z'
                tmp = ascm + decal;
                car = (char)tmp;
                txt2[i] = car;
            } else { // De 'n' à 'z' vers 'a' à 'm'
                min = ascm + decal - 26;
                car = (char)min;
                txt2[i] = car;
            }
        }
        // Garder les chiffres et symboles
        else {
            if (txt[i] == ' ')
                txt2[i] = txt[i];
            else
                txt2[i] = txt[i];
        }
    }

    // Addition de  null terminator to txt2
    txt2[lencr] = '\0';

    // Affichage du texte crypté

    printf("\n LE TEXTE CHIFFRES EST : \t %s ", txt2);

    // Début du décryptage
    lendec = strlen(txt2);
    for (j = 0; j < lendec; j++) {
        ascz = (int)txt2[j]; // Convertir le crypté en ASCII

        // Décryptage des majuscules
        if (txt2[j] >= 'A' && txt2[j] <= 'Z') {
            if (ascz - decal  >= (ascmaj-26) ) { // De 'A' à 'M' vers 'N' à 'Z'
                tmp1 = ascz - decal;
                symb1 = (char)tmp1;
                txt3[j] = symb1;
            } else { // De 'N' à 'Z' vers 'A' à 'M'
                symb2 = ascz - decal + 26;
                symb1 = (char)symb2;
                txt3[j] = symb1;
            }
        }
        // Décryptage des minuscules
        else if (txt2[j] >= 'a' && txt2[j] <= 'z') {
            if (  ascz - decal >=(ascmax-26) ) { // De 'a' à 'm' vers 'n' à 'z'
                min = ascz - decal;
                symb = (char)min;
                txt3[j] = symb;
            } else { // De 'n' à 'z' vers 'a' à 'm'
                diff = ascz - decal + 26;
                symb = (char)diff;
                txt3[j] = symb;
            }
        }
        // Garder les chiffres et symboles
        else {
            if (txt2[j] == ' ')
                txt3[j] = txt2[j];
            else
                txt3[j] = txt2[j];
        }
    }

    // Addition de  null terminator to txt3
    txt3[lendec] = '\0';

    // Affichage du texte décrypté
    printf("\n VOTRE MESSAGE DECHIFFRRES EST : \t %s", txt3);
    return 0;
}
