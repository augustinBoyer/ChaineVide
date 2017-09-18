// *********************************************************************
// Description : 
//   Ce fichier contient la déclaration de la classe Chaine.
//
//  Auteur :
//    Nicolas Richard
// *********************************************************************


//   ######   N E   P A S   M O D I F I E R   C E   F I C H I E R   ######  

#pragma once

#include <sstream>
#include <iostream>


const int NON_TROUVÉ = -99;


// *********************************************************************
// Description : 
//   Retourne le nombre de caractères dans p_String.
//
// Paramètres :
//   p_String       String dont il faut compter le nombre de caractères.
//
// Postcondition :
//   - La valeur retournée est supérieur ou égale à zéro.
//
// Retourne :
//   Le nombre de caractère dans p_String.
// *********************************************************************
int LongueurString(const char* p_String);


// *********************************************************************
// Description : 
//   Cette classe représente une chaîne de caractères.
//
// Invariants :
//   - La longueur est plus grande ou égale à zéro.
//   - La longueur est zéro si et seulement si le pointeur est NULL.
// *********************************************************************
class Chaine
{
public:
// *********************************************************************
// Description : 
//   Constructeur par défaut.
//
// Paramètres :
//   Aucun.
//
// Postcondition :
//   - La chaine est vide.
//   - Les invariants de la classe sont respectés.
// *********************************************************************
explicit            Chaine();

// *********************************************************************
// Description : 
//   Constructeur d'initialisation.
//
// Paramètres :
//   p_String       String à copier.
//
// Postcondition :
//   - La chaine courante et p_String ont la même longueur.
//   - Les invariants de la classe sont respectés.
// *********************************************************************
explicit            Chaine(const char* p_String);
                    
// *********************************************************************
// Description : 
//   Constructeur de copie.
//
// Paramètres :
//   p_Chaine       Chaine à copier.
//
// Postcondition :
//   - La chaine courante et p_Chaine sont égales.
//   - Les invariants de la classe sont respectés.
// *********************************************************************
                    Chaine(const Chaine& p_Chaine);

// *********************************************************************
// Description : 
//   Destructeur.
//
// Paramètres :
//   Aucun.
//
// Postcondition :
//   - La chaine est vide.
//   - Les invariants de la classe sont respectés.
// *********************************************************************
                    ~Chaine();

// *********************************************************************
// Description : 
//   Retourne la longueur.
//
// Paramètres :
//   Aucun.
//
// Retourne :
//   La longueur.
// *********************************************************************
    int             Longueur() const;

// *********************************************************************
// Description : 
//   Vide la chaine.
//
// Paramètres :
//   Aucun.
//
// Postcondition :
//   - Les invariants de la classe sont respectés.
//   - La chaine est vide.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            Vider();

// *********************************************************************
// Description : 
//   Détermine si la chaine est vide.
//
// Paramètres :
//   Aucun.
//
// Retourne :
//  true si la longueur est zéro.
// *********************************************************************
    bool            EstVide() const;

// *********************************************************************
// Description : 
//   Retourne l'indice où est située la chaine p_SousChaine dans la 
//   chaine courante, ou bien NON_TROUVÉ si elle absente.
//
// Paramètres :
//   p_SousChaine       Chaine à chercher.
//
// Précondition :
//   - p_SousChaine n'est pas vide.
//
// Postcondition :
//   - La valeur retournée est NON_TROUVÉ, ou bien est plus grande ou 
//     égale à zéro et inférieure à la longueur de la chaine courante.
//
// Retourne :
//  L'indice où apparait p_SousChaine, ou NON_TROUVÉ sinon.
// *********************************************************************
    int             Trouver(const Chaine& p_SousChaine) const;

// *********************************************************************
// Description : 
//   Retourne une chaine de caractère.
//
// Paramètres :
//   p_Indice       Indice de départ de la sous-chaine.
//   p_Longueur     Longueur de la sous-chaine.
//
// Préconditions :
//   - p_Indice est plus grand ou égal à 0 et plus petit que la 
//     longueur.
//   - p_Longueur est plus grand ou égal à 0 et plus petit ou égal à la 
//     longueur moins p_Indice.
//
// Postcondition :
//   - Les invariants de la chaine retournée sont respectés.
//
// Retourne :
//  La sous-chaine de caractère commençant à p_Indice, de longueur 
//  p_Longueur.
// *********************************************************************
    Chaine          SousChaine(int p_Indice, int p_Longueur) const;

// *********************************************************************
// Description : 
//   Insère une chaine de caractère à un indice donné.
//
// Paramètres :
//   p_Chaine       Chaine à insérer.
//   p_Indice       Indice pour l'insertion.
//
// Préconditions :
//   - p_Indice est plus grand ou égal à 0 et plus petit ou égal à la 
//     longueur.
//   - p_Chaine n'est pas l'objet courant.
//
// Postcondition :
//   - Les invariants de la classe sont respectés.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            Insérer(const Chaine& p_Chaine, int p_Indice);

// *********************************************************************
// Description : 
//   Supprime des caractères.
//
// Paramètres :
//   p_Indice       Indice où commencer la suppression.
//   p_Longueur     Nombre de caractères à effacer.
//
// Préconditions :
//   - p_Indice est plus grand ou égal à 0 et plus petit que la 
//     longueur.
//   - p_Longueur est plus grand ou égal à 0 et plus petit ou égal à la 
//     longueur moins p_Indice.
//
// Postcondition :
//   - Les invariants de la classe sont respectés.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            Suppprimer(int p_Indice, int p_Longueur);

// *********************************************************************
// Description : 
//   Opérateur d'affectation.
//
// Paramètres :
//   p_Chaine        Chaine à copier dans l'objet courant.
//
// Postcondition :
//   - Les invariants sont respectés.
//   - La chaine courante et p_Chaine sont égaux.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            operator=(const Chaine& p_Chaine);

// *********************************************************************
// Description : 
//   Opérateur d'affectation.
//
// Paramètres :
//   p_String        String à copier dans l'objet courant.
//
// Postcondition :
//   - La chaine courante et p_String ont la même longueur.
//   - Les invariants de la classe sont respectés.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            operator=(const char* p_String);
    
// *********************************************************************
// Description : 
//   Opérateur d'égalité.
//
// Paramètres :
//   p_Chaine        Chaine à comparer.
//
// Retourne :
//  true si les deux chaines ont les mêmes caractères.
// *********************************************************************
    bool            operator==(const Chaine& p_Chaine) const;

// *********************************************************************
// Description : 
//   Opérateur d'inégalité.
//
// Paramètres :
//   p_Chaine        Chaine à comparer.
//
// Retourne :
//  true si les deux chaines sont différentes.
// *********************************************************************
    bool            operator!=(const Chaine& p_Chaine) const;


// Pour permettre à l'opérateur << d'accéder à la partie privée de p_Chaine
friend std::ostream& operator<<(std::ostream& p_FluxDeSortie, const Chaine& p_Chaine);


private:
// *********************************************************************
// Description : 
//   Cette méthode vérifie les invariants.
//
// Paramètres :
//   Aucun.
//
// Retourne:
//  true si les invariants de la classe sont respectés sur l'objet 
//  courant.
// *********************************************************************
    bool    CheckInvariants() const;

    char*   m_Ptr;
    int     m_Longueur;
};


// ***************************************************************************
// Description : 
//   Opérateur de sortie dans un flux (std::cout ou un fichier).
//
// Paramètres :
//   p_Flux         Flux où écrire. 
//   p_Chaine      Chaine à afficher.
//
// Exemples :
//   "{}"
//   "{14, 34, 33, -13, 2000}"
//
// Retourne :
//  Une référence vers le flux.
// ***************************************************************************
std::ostream& operator<<(std::ostream& p_FluxDeSortie, const Chaine& p_Chaine);






// *********************************************************************
// Description : 
//   Fonction pour afficher un objet Chaine dans les messages d'erreur
//   de WinUnit.
//
// Paramètres :
//   p_Chaine       Objet à écrire dans p_Buffer. 
//   p_Buffer       Chaîne de caractère où écrire.
//   p_BufferSize   Taille maximal pour l'affichage.
//
// Retourne :
//  Un pointeur vers le chaîne affichée.
// *********************************************************************
template <>
inline const TCHAR* WinUnit::ToString(const Chaine&  p_Chaine, 
                                      TCHAR          p_Buffer[], 
                                      size_t         p_BufferSize)
{
    std::ostringstream oss;
    oss << p_Chaine;

    ::_sntprintf_s(p_Buffer, p_BufferSize, _TRUNCATE, "%s", oss.str().c_str());

    return p_Buffer;
}