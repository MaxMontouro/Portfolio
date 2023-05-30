/**
 * @file taquin.h
 * @author Maxime MONTOURO
 * @brief Fichier d'entête du module taquin
 * @date 2022-19-12
 */
#ifndef TAQUIN_H
#define TAQUIN_H

#include <iostream>
using namespace std;

/*-------------------------------------------------------------------------------------------------------------
                                        VARIABLES GLOBALES
-------------------------------------------------------------------------------------------------------------*/

const unsigned short int NB_LIGNE = 5;// Nombre de ligne d'un tableau 
const unsigned short int NB_COLONNE = 5;//Nombre de colonne 

/*-------------------------------------------------------------------------------------------------------------
                                     TYPE ENUMERES ET ENRTEGISTREMENTS
-------------------------------------------------------------------------------------------------------------*/

enum mouvementJoueurPossible {h = 1, g = 2, b = 3, d = 4};// Mouvement que peuvent effectuer les différentes cases du tableau

struct CaseVide
{
    unsigned short int coordonneeX;// Coordonne de la case vide sur l'axe des abscisses du tableau
    unsigned short int coordonneeY;// Coordonne de la case vide sur l'axe des ordonnées du tableau
};

/*-------------------------------------------------------------------------------------------------------------
                                        AFFICHAGE SUR LA GRILLE
-------------------------------------------------------------------------------------------------------------*/

void afficherGrilleTaquin(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
//But: Afficher la grille de Taquin de dimensions NB_LIGNE et NB_COLONNE

void afficherCaseVide(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
//But: Afficher une case vide lorsque la valeur de la case du tableau grilleTaquin de dimensions NB_LIGNE et NB_COLONNE est 0.

/*-------------------------------------------------------------------------------------------------------------
                                        GENERATION SUR LA GRILLE
-------------------------------------------------------------------------------------------------------------*/

void genererTaquin(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
//But: Génère une grille de taquin ordonnée de dimensions NB_LIGNE et NB_COLONNE

void genererTaquinNonTrier(int grilleTaquin[][NB_COLONNE], string& reponseJeu);
//But: Mélange une grille de taquin  ordonnée  et permet d'avoir accès à la réponse la plus simple reponseJeu si le mode debug est activé

void initialiserPositionCaseVide(CaseVide& pCaseVide, unsigned short int pAbscisse, unsigned short int pOrdonnee);
//But: Initialise la position de la Case Vide pCaseVide aux coordonnées pAbscisse et pOrdonne de la grille 

/*-------------------------------------------------------------------------------------------------------------
                                            MODIFICATEURS
-------------------------------------------------------------------------------------------------------------*/

void echangerCasesGrille(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide,unsigned short int indiceXcase2,unsigned short int indiceYCase2);
//Echanger les deux cases pCaseVide et case2 dont les coordonnees sont indiceXCase2 et indiceYCase2 d'une grille de taquin suivant le modèle algorithmique echange case d'un tableau

bool estOrdonne(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
//But: Renvoie vrai si le tableau grilleTaquin de longueur NB_LIGNE et NB_COLONNE est trier dans l'ordre croissant (ne prend pas en compte la case vide), renvoie faux sinon

bool coordonneeFinCaseVide(CaseVide& pCaseVide, const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
//But: Renvoie vrai si la position de la case vide pCaseVide se situe dans l'un des quatre coins de la grille de Taquin de  dimension NB_LIGNE et NB_COLONNE, faux sinon

void faireMouvementGauche(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, 
                          unsigned short int coordonneXCaseAEchanger, unsigned short int coordonneeYCaseAEchanger);
//But: Si le mouvement à gauche est disponible, la procédure échange les cases dudu tableau et change les coordonnées de la caseVide et de coordonneeXCaseAEchanger et coordonneeYCaseAEchanger

bool mouvementAGaucheDispo(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement,  unsigned short int coordonneeXCase, unsigned short int coordonneeYCase);
//But: Renvoie vrai, si la case a echanger de dimension indiceXCase et indiceYCase est situe à gauche de la case vide pCaseVide dans le tableau grilleTaquin de dimensions NB_LIGNE et NB_COLONNE

void convertirSaisieJoueurStringToInt(string& saisieJoueur, string& deplacementChoisi, int& caseChoisiPourDeplacement);
//But: convertie la saisie du joueur saisieJoueur en deux le mouvement choisi delacementChoisi et la case choisi caseChoisiPourDeplacement

void chercherValeurCaseAEchanger(int grilleTaquin[][NB_COLONNE], int caseChoisiPourDeplacement,
                                 unsigned short int& coordonneeXCase, unsigned short int& coordonneeYCase);
//But: Cherche dans la grille de taquin grilleTaquin les coordonnes de la 
void faireMouvementDroite(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide,int caseChoisiPourDeplacement,  unsigned short int coordonneXCaseAEchanger, unsigned short int coordonneeYCaseAEchanger);

bool mouvementADroiteDispo(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide,int caseChoisiPourDeplacement,  unsigned short int coordonneeXCase, unsigned short int coordonneeYCase);
//But: Renvoie vrai, si la case a echanger de dimension indiceXCase et indiceYCase est situe à gauche de la case vide pCaseVide dans le tableau grilleTaquin de dimensions NB_LIGNE et NB_COLONNE

void faireMouvementBas(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement, unsigned short int coordonneeXCaseAEchanger,const unsigned short int coordonneeYCaseAEchanger);

bool mouvementEnBasDispo(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement, unsigned short int coordonneeXCase, unsigned short int coordonneeYCase);

#endif