#include "taquin.h"
#include "game-tools.h"
#include <iostream>
#include <string>

using namespace std; 


/*-------------------------------------------------------------------------------------------------------------
                                        AFFICHAGE SUR LA GRILLE
-------------------------------------------------------------------------------------------------------------*/

void afficherGrilleTaquin(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    //VARIABLES
    const int DIZAINE = 10;//si valeur du tableau inferieure a 10 alors affiche ' nbr '

    //CODE 
    for(unsigned short int indice = 0; indice < NB_LIGNE; indice++)
    {
        cout << "\n";  
        for(unsigned short int indice2 = 0; indice2 < NB_COLONNE; indice2++)
        {
            if(grilleTaquin[indice][indice2] < DIZAINE)
            {
                if(grilleTaquin[indice][indice2] == 0)
                {
                    afficherCaseVide(grilleTaquin,NB_LIGNE,NB_COLONNE);
                }
                else
                {
                    cout <<"0" <<grilleTaquin[indice][indice2] << "  ";
                }
            }
            else
            {
                cout << grilleTaquin[indice][indice2] << "  ";
            }
            
        }
    
    }
}

void afficherCaseVide(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    for(unsigned short int indiceParcours = 0; indiceParcours < NB_LIGNE; indiceParcours++)
    {
        for(unsigned short int indiceParcoursColonne = 0; indiceParcoursColonne < NB_COLONNE; indiceParcoursColonne++)
        {
            if(grilleTaquin[indiceParcours][indiceParcoursColonne] == 0)
            {
                cout<< "    ";
            }
        }
    }
}    

/*-------------------------------------------------------------------------------------------------------------
                                        GENERATION SUR LA GRILLE
-------------------------------------------------------------------------------------------------------------*/

void initialiserPositionCaseVide(CaseVide& pCaseVide, unsigned short int pAbscisse, unsigned short int pOrdonnee)
{
    pCaseVide.coordonneeX = pAbscisse;
    pCaseVide.coordonneeY = pOrdonnee;
}

void genererTaquin(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    //VARIABLE

    int compteur = 0;// Le compteur du tableau initialisé à 0
    CaseVide positionCaseVide;
    unsigned short int coordonneAbscisseCaseVide = 0;
    unsigned short int coordonneOrdonneeCaseVide = 0;

    //CORPS DU SOUS-PROGRAMME
    //Initialisation de la grille de Taquin
    for(unsigned short int indiceParcours = 0; indiceParcours < NB_LIGNE; indiceParcours++)
    {
        for(unsigned short int indice = 0; indice < NB_COLONNE; indice++)
        {
            grilleTaquin[indiceParcours][indice] = compteur;
            compteur++;
        }   
    }
    initialiserPositionCaseVide(positionCaseVide, coordonneAbscisseCaseVide, coordonneOrdonneeCaseVide);
}

void genererTaquinNonTrier(int grilleTaquin[][NB_COLONNE], string& reponseJeu)
{
    //VARIABLES
    int mouvementRandom;// nombre de mouvement à faire pour mélanger la grille
    int mouvementRandomTour1;// mouvement à faire au premier tour (controlé pour faire un mouvement valide)
    int nombreTourMelange;//nombre de tour du mélange itéré à chaque tour du parcours
    CaseVide positionCaseVide;
    unsigned short int coordonneeX;//coordonnee X de la case à changer
    unsigned short int coordonneeY;//coordonnee Y de la case à echanger
    string deplacementAFaire;//deplacement à faire (ici il s'agit du mouvement ex: 'g')
    int caseChoisiPourDeplacement = 0;
    int mouvementPrecedent;// Acces au mouvement precedent (1 pour bas, 2 pour droite, 3 pour haut, 4 pour gauche)
    
    //INTIALIATION
    mouvementRandom = random(5, 15);
    mouvementRandomTour1 = random(1,2);
    nombreTourMelange = 0;
    coordonneeX = 0;//coordonnee X de la case en dessous de la case vide lorsque celle ci n est pas encore triee
    coordonneeY = 1;//coordonnee Y de la case en dessous de la case vide lorsque celle ci n est pas encore triee
    
    genererTaquin(grilleTaquin, NB_LIGNE, NB_COLONNE);//initialisation de la grille de taquin triée

    for(unsigned short int indiceParcoursMelange = 0; indiceParcoursMelange < mouvementRandom; indiceParcoursMelange++)
    {
        if(nombreTourMelange == 0)
        {
            if(mouvementRandomTour1 == 1)
            {
                faireMouvementBas(grilleTaquin, positionCaseVide, caseChoisiPourDeplacement, coordonneeX, coordonneeY );
                nombreTourMelange++;
                mouvementPrecedent = 1;
                reponseJeu = to_string(grilleTaquin[positionCaseVide.coordonneeX][positionCaseVide.coordonneeY])+ deplacementAFaire + "  ";
            }
            else
            {
                faireMouvementDroite(grilleTaquin, positionCaseVide, caseChoisiPourDeplacement, coordonneeX, coordonneeY );
                nombreTourMelange++;
                mouvementPrecedent = 2;
                reponseJeu = to_string(grilleTaquin[coordonneeX][coordonneeY])+ deplacementAFaire + "  ";
            }
        }
    }
    
}

/*-------------------------------------------------------------------------------------------------------------
                                            MODIFICATEURS
-------------------------------------------------------------------------------------------------------------*/

void echangerCasesGrille(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide,unsigned short int indiceXCase2, unsigned short int indiceYCase2)
{
    //ECHANGE DES CASES DU TABLEAUX 
    int copieCase1 = grilleTaquin[pCaseVide.coordonneeX][pCaseVide.coordonneeY];
    grilleTaquin[pCaseVide.coordonneeX][pCaseVide.coordonneeY] = grilleTaquin[indiceXCase2][indiceYCase2];
    grilleTaquin[indiceXCase2][indiceYCase2] = copieCase1; 

    //MODIFICATIONS DES COORDONNEES DE LA CASE VIDE 

    pCaseVide.coordonneeX = indiceXCase2;//modification de la coordonnee X de la case vide
    pCaseVide.coordonneeY = indiceYCase2;//modification de la coordonnee Y de la case vide
}

bool estOrdonne(int grilleTaquin[][NB_COLONNE], const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    //VARIABLES
    int compteur = 1;
    bool estVerifier = true;
    
    //CORPS DU SOUS PROGRAMME

    for(unsigned short int indiceParcoursLigne = 0; indiceParcoursLigne < NB_LIGNE; indiceParcoursLigne++)
    {
        for(unsigned short int indiceParcoursColonne = 0; indiceParcoursColonne < NB_COLONNE; indiceParcoursColonne++)
        {
            if(grilleTaquin[indiceParcoursLigne][indiceParcoursColonne] != 0)
            {
                if(grilleTaquin[indiceParcoursLigne][indiceParcoursColonne] != compteur)
                {
                    estVerifier = false;
                    break;
                }
            }
            compteur++;
        } 
    }

    return estVerifier;
}

bool coordonneeFinCaseVide(CaseVide& pCaseVide, const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    //VARIABLE
    bool positionValideFinPartie = false;
    
    //CORPS DU SOUS PROGRAMME

    if(((pCaseVide.coordonneeX == 0)&&(pCaseVide.coordonneeY == 0)) || ((pCaseVide.coordonneeX == 0)&&(pCaseVide.coordonneeY==NB_COLONNE)) || ((pCaseVide.coordonneeX == NB_LIGNE)&&(pCaseVide.coordonneeY==0)) || ((pCaseVide.coordonneeX == NB_LIGNE)&&(pCaseVide.coordonneeY==NB_COLONNE)))
    {
        positionValideFinPartie = true;
    }
    return positionValideFinPartie;
}

void faireMouvementGauche(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, unsigned short int coordonneeXCaseAEchanger,const unsigned short int coordonneeYCaseAEchanger)
{
    echangerCasesGrille(grilleTaquin, pCaseVide, coordonneeXCaseAEchanger, coordonneeYCaseAEchanger);
}

bool mouvementAGaucheDispo(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement, unsigned short int coordonneeXCase, unsigned short int coordonneeYCase)
{

    //CORPS DU SOUS PROGRAMME

    chercherValeurCaseAEchanger(grilleTaquin, caseChoisiPourDeplacement, coordonneeXCase, coordonneeYCase);
    
    if((pCaseVide.coordonneeY == (coordonneeYCase-1)) && (grilleTaquin[coordonneeXCase][coordonneeYCase] == caseChoisiPourDeplacement))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void convertirSaisieJoueurStringToInt(string& saisieJoueur,string& deplacementChoisi, int& caseChoisiPourDeplacement)
{

    //CORPS DU SOUS PROGRAMME

    for(unsigned short int indice = 0; indice < saisieJoueur.size(); indice++)
    {
        if(indice != (saisieJoueur.size()-1))
        {
            deplacementChoisi += saisieJoueur[indice];
            caseChoisiPourDeplacement = stoi(deplacementChoisi);
        }
        else
        {
            deplacementChoisi = saisieJoueur[indice];
        }
    }
}

void chercherValeurCaseAEchanger(int grilleTaquin[][NB_COLONNE], int caseChoisiPourDeplacement, unsigned short int& coordonneeXCase, unsigned short int& coordonneeYCase)
{
    
    
    

    for(unsigned short int indiceParcours1; indiceParcours1 < NB_LIGNE; indiceParcours1++)
    {
        for(unsigned short int indiceParcours2; indiceParcours1 < NB_COLONNE; indiceParcours2++)
        {
            if(grilleTaquin[indiceParcours1][indiceParcours2] == caseChoisiPourDeplacement)
            {
                coordonneeXCase = indiceParcours1;
                coordonneeYCase = indiceParcours2;
            }
        }
    }
}

void faireMouvementDroite(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement, unsigned short int coordonneeXCaseAEchanger, unsigned short int coordonneeYCaseAEchanger)
{
    if(mouvementADroiteDispo(grilleTaquin, pCaseVide, caseChoisiPourDeplacement, coordonneeXCaseAEchanger, coordonneeYCaseAEchanger) == true)
    {
        echangerCasesGrille(grilleTaquin, pCaseVide, coordonneeXCaseAEchanger, coordonneeYCaseAEchanger);
    }
}

bool mouvementADroiteDispo(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement, unsigned short int coordonneeXCase, unsigned short int coordonneeYCase)
{
    //CORPS SOUS PROGRAMMES
    chercherValeurCaseAEchanger(grilleTaquin, caseChoisiPourDeplacement, coordonneeXCase, coordonneeYCase);

    if((coordonneeXCase-1 == pCaseVide.coordonneeX) && (coordonneeYCase == pCaseVide.coordonneeY) && (grilleTaquin[coordonneeXCase][coordonneeYCase] == caseChoisiPourDeplacement))
    {
        return true;
    }
    else
    {
        return false;
    }  
}

void faireMouvementBas(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement, unsigned short int coordonneeXCaseAEchanger,const unsigned short int coordonneeYCaseAEchanger)
{
    if(mouvementEnBasDispo(grilleTaquin, pCaseVide, caseChoisiPourDeplacement, coordonneeXCaseAEchanger, coordonneeYCaseAEchanger) == true)
    {
        echangerCasesGrille(grilleTaquin, pCaseVide, coordonneeXCaseAEchanger, coordonneeYCaseAEchanger);
    } 
}

bool mouvementEnBasDispo(int grilleTaquin[][NB_COLONNE], CaseVide& pCaseVide, int caseChoisiPourDeplacement,  unsigned short int coordonneeXCase, unsigned short int coordonneeYCase)
{
    chercherValeurCaseAEchanger(grilleTaquin,caseChoisiPourDeplacement, coordonneeXCase, coordonneeYCase);
    if((coordonneeXCase == pCaseVide.coordonneeX) && (coordonneeYCase == pCaseVide.coordonneeY-1) && (grilleTaquin[coordonneeXCase][coordonneeYCase] == caseChoisiPourDeplacement))
    {
        return true;
    }
    else
    {
        return false;
    }
}