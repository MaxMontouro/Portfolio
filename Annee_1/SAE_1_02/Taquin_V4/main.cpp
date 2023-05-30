/* Programme: Jeu course poursuite
But: Faire un jeu pour 2 joueurs basé sur des dé
Date de dernière modif: 23/10/2022
Auteur: Maxime MONTOURO */

#include <iostream>
#include "taquin.h"
#include "game-tools.h"
#include "organisation_jeu.h"
#include <string>

using namespace std; 


int main(void)
{
    //VARIABLES
    int grilleDeTaquin[NB_LIGNE][NB_COLONNE];// Grille de taquin sous forme d'un tableau à deux dimensions de taille NB_LIGNE et NB_COLONNE.
    unsigned short int indiceXEchange = 0;
    unsigned short int indiceYEchange = 1;
    string caseADeplaceChoixJoueur = "";
    int valeurCaseChoisiPourDeplacement = 0;
    string enTete = " - JEU DU TAQUIN - ";
    string mouvementInvalide = " Mouvement INVALIDE !!! ";
    string aAbandonner = "Perdu par abandon :'-( ";
    string saisieIncorrecte = "Saisie I N C O R R E C T E. Recommencez... (Appuyer sur Entree) ";
    string aGagner = "Felicitations Vous avez gagne la partie ! ";
    string solutionJeu = " La solution est : "; // Solution pour la résolution du Taquin
    char reponseModeDebug;//Reponse pour l'affichage du mode Debug, o si oui et n sinon
    bool modeDebug = false;//Si reponseModeDebug est vrai alors modeDebug est vrai sinon faux, est initialisé a faux
    bool abandonner = false;// Si le joueur décide d'abandonner le jeu au cours de la partie alors abandonner = vrai, est initialisé à faux
    bool gagner = false;
    string mouvementJoueur;//Le mouvement qu ele joueur souhaite effectuer
    //mouvementJoueurPossible mouvementJoueurChoisi;
    CaseVide positionCaseVide;

    //                                                       INITIALISATION 
    //afficherTeteCouleur(enTete) >> écran
    afficherTexteEnCouleur(enTete, cyan, true);
    
    //Initialisation du mode Debug
    while(true)
    {

       cout << "\n";
        cout << "Voulez-vous activer le mode Debug (o/n) ? ";
        cin >> reponseModeDebug;
        cout << "\n";
        
        if(reponseModeDebug == 'o')
        {
            modeDebug = true; 
            break;
        }
        else if (reponseModeDebug =='n')
        {
            modeDebug = false;
            break;
        }

        afficherTexteEnCouleur(saisieIncorrecte, rouge, false);
        pause();
        effacer();
        afficherTexteEnCouleur(enTete, cyan, true); 
    }
    
    effacer();
    //Generation de la grille de Taquin
    genererTaquinNonTrier(grilleDeTaquin, solutionJeu);
     
    //                                               JOUER 
    //Commencement de la Partie 
    while(true)
    {
        afficherTexteEnCouleur(enTete, cyan, true);
        if(modeDebug == true)
        {
            cout << "\n";
            afficherTexteEnCouleur(solutionJeu, vert,true);
            afficherGrilleTaquin(grilleDeTaquin, NB_LIGNE, NB_COLONNE);
            cout << "\n";
        }
        else
        {
            afficherGrilleTaquin(grilleDeTaquin, NB_LIGNE, NB_COLONNE);
            cout << "\n";
        }
        
        while(true)
        {
            cout << "\n";
            cout<<"Quel mouvement souhaitez-vous faire (a pour abandonner) ? ";
            cin >> mouvementJoueur;
            convertirSaisieJoueurStringToInt(mouvementJoueur, caseADeplaceChoixJoueur, valeurCaseChoisiPourDeplacement);
            chercherValeurCaseAEchanger(grilleDeTaquin, valeurCaseChoisiPourDeplacement, indiceXEchange, indiceYEchange);
            cout << mouvementJoueur;
            if(mouvementJoueur == "h")
            {
               
                break;
            }
            else if(mouvementJoueur == "g")
            {
                if(mouvementAGaucheDispo(grilleDeTaquin, positionCaseVide,valeurCaseChoisiPourDeplacement,  indiceXEchange, indiceYEchange ) == true)
                {
                    faireMouvementGauche(grilleDeTaquin, positionCaseVide, indiceXEchange, indiceYEchange);
                }
                else
                {
                    afficherTexteEnCouleur(saisieIncorrecte, rouge, true);
                }
            }
            else if(mouvementJoueur == "b")
            {
                break;
            }
            else if(mouvementJoueur == "d")
            {
                if(mouvementADroiteDispo(grilleDeTaquin, positionCaseVide,valeurCaseChoisiPourDeplacement, indiceXEchange, indiceYEchange))
                {
                    faireMouvementDroite(grilleDeTaquin, positionCaseVide, valeurCaseChoisiPourDeplacement, indiceXEchange, indiceYEchange);
                }
                else
                {
                    afficherTexteEnCouleur(saisieIncorrecte,rouge, true);
                }
            }
            else if(mouvementJoueur == "a")
            {
                abandonner = true;
            }
            else
            {
                cout << "\n";
                afficherTexteEnCouleur(saisieIncorrecte, rouge, false);
                pause();
                effacer();
                afficherTexteEnCouleur(enTete, cyan, true);
                if(modeDebug == true)
                {
                    cout<<"\n";
                    afficherTexteEnCouleur(solutionJeu, vert,true);
                    afficherGrilleTaquin(grilleDeTaquin, NB_LIGNE, NB_COLONNE);
                    cout << "\n";
                }
                else
                {
                    afficherGrilleTaquin(grilleDeTaquin, NB_LIGNE, NB_COLONNE);
                    cout << "\n";
                }
            }
        }
     
        if(abandonner == true)
        {
            break;
        }


        if((estOrdonne(grilleDeTaquin, NB_LIGNE, NB_COLONNE) == true) && (coordonneeFinCaseVide(positionCaseVide, NB_LIGNE, NB_COLONNE)))
        {
            gagner = true;
            break;
        }
    }

    //                              FIN DE PARTIE
    
    effacer();
    afficherTexteEnCouleur(enTete, cyan, true);
    afficherGrilleTaquin(grilleDeTaquin, NB_LIGNE, NB_COLONNE);
    if(abandonner == true)
    {
        cout << "\n"<< endl;
        afficherTexteEnCouleur(aAbandonner, rouge, false);
        cout << "\n"<< endl;
        echangerCasesGrille(grilleDeTaquin, positionCaseVide, indiceXEchange, indiceYEchange);
        cout << "\n"<< endl;
        cout << positionCaseVide.coordonneeX << "  " << positionCaseVide.coordonneeY;
    }
    else if(gagner == true)
    {
        cout << "\n" << endl;
        afficherTexteEnCouleur(aGagner, vert, false);
    }
    return 0;
}