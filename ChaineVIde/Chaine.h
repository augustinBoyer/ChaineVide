// *********************************************************************
// Description : 
//   Ce fichier contient la d�claration de la classe Chaine.
//
//  Auteur :
//    Nicolas Richard
// *********************************************************************


//   ######   N E   P A S   M O D I F I E R   C E   F I C H I E R   ######  

#pragma once

#include <sstream>
#include <iostream>


const int NON_TROUV� = -99;


// *********************************************************************
// Description : 
//   Retourne le nombre de caract�res dans p_String.
//
// Param�tres :
//   p_String       String dont il faut compter le nombre de caract�res.
//
// Postcondition :
//   - La valeur retourn�e est sup�rieur ou �gale � z�ro.
//
// Retourne :
//   Le nombre de caract�re dans p_String.
// *********************************************************************
int LongueurString(const char* p_String);


// *********************************************************************
// Description : 
//   Cette classe repr�sente une cha�ne de caract�res.
//
// Invariants :
//   - La longueur est plus grande ou �gale � z�ro.
//   - La longueur est z�ro si et seulement si le pointeur est NULL.
// *********************************************************************
class Chaine
{
public:
// *********************************************************************
// Description : 
//   Constructeur par d�faut.
//
// Param�tres :
//   Aucun.
//
// Postcondition :
//   - La chaine est vide.
//   - Les invariants de la classe sont respect�s.
// *********************************************************************
explicit            Chaine();

// *********************************************************************
// Description : 
//   Constructeur d'initialisation.
//
// Param�tres :
//   p_String       String � copier.
//
// Postcondition :
//   - La chaine courante et p_String ont la m�me longueur.
//   - Les invariants de la classe sont respect�s.
// *********************************************************************
explicit            Chaine(const char* p_String);
                    
// *********************************************************************
// Description : 
//   Constructeur de copie.
//
// Param�tres :
//   p_Chaine       Chaine � copier.
//
// Postcondition :
//   - La chaine courante et p_Chaine sont �gales.
//   - Les invariants de la classe sont respect�s.
// *********************************************************************
                    Chaine(const Chaine& p_Chaine);

// *********************************************************************
// Description : 
//   Destructeur.
//
// Param�tres :
//   Aucun.
//
// Postcondition :
//   - La chaine est vide.
//   - Les invariants de la classe sont respect�s.
// *********************************************************************
                    ~Chaine();

// *********************************************************************
// Description : 
//   Retourne la longueur.
//
// Param�tres :
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
// Param�tres :
//   Aucun.
//
// Postcondition :
//   - Les invariants de la classe sont respect�s.
//   - La chaine est vide.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            Vider();

// *********************************************************************
// Description : 
//   D�termine si la chaine est vide.
//
// Param�tres :
//   Aucun.
//
// Retourne :
//  true si la longueur est z�ro.
// *********************************************************************
    bool            EstVide() const;

// *********************************************************************
// Description : 
//   Retourne l'indice o� est situ�e la chaine p_SousChaine dans la 
//   chaine courante, ou bien NON_TROUV� si elle absente.
//
// Param�tres :
//   p_SousChaine       Chaine � chercher.
//
// Pr�condition :
//   - p_SousChaine n'est pas vide.
//
// Postcondition :
//   - La valeur retourn�e est NON_TROUV�, ou bien est plus grande ou 
//     �gale � z�ro et inf�rieure � la longueur de la chaine courante.
//
// Retourne :
//  L'indice o� apparait p_SousChaine, ou NON_TROUV� sinon.
// *********************************************************************
    int             Trouver(const Chaine& p_SousChaine) const;

// *********************************************************************
// Description : 
//   Retourne une chaine de caract�re.
//
// Param�tres :
//   p_Indice       Indice de d�part de la sous-chaine.
//   p_Longueur     Longueur de la sous-chaine.
//
// Pr�conditions :
//   - p_Indice est plus grand ou �gal � 0 et plus petit que la 
//     longueur.
//   - p_Longueur est plus grand ou �gal � 0 et plus petit ou �gal � la 
//     longueur moins p_Indice.
//
// Postcondition :
//   - Les invariants de la chaine retourn�e sont respect�s.
//
// Retourne :
//  La sous-chaine de caract�re commen�ant � p_Indice, de longueur 
//  p_Longueur.
// *********************************************************************
    Chaine          SousChaine(int p_Indice, int p_Longueur) const;

// *********************************************************************
// Description : 
//   Ins�re une chaine de caract�re � un indice donn�.
//
// Param�tres :
//   p_Chaine       Chaine � ins�rer.
//   p_Indice       Indice pour l'insertion.
//
// Pr�conditions :
//   - p_Indice est plus grand ou �gal � 0 et plus petit ou �gal � la 
//     longueur.
//   - p_Chaine n'est pas l'objet courant.
//
// Postcondition :
//   - Les invariants de la classe sont respect�s.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            Ins�rer(const Chaine& p_Chaine, int p_Indice);

// *********************************************************************
// Description : 
//   Supprime des caract�res.
//
// Param�tres :
//   p_Indice       Indice o� commencer la suppression.
//   p_Longueur     Nombre de caract�res � effacer.
//
// Pr�conditions :
//   - p_Indice est plus grand ou �gal � 0 et plus petit que la 
//     longueur.
//   - p_Longueur est plus grand ou �gal � 0 et plus petit ou �gal � la 
//     longueur moins p_Indice.
//
// Postcondition :
//   - Les invariants de la classe sont respect�s.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            Suppprimer(int p_Indice, int p_Longueur);

// *********************************************************************
// Description : 
//   Op�rateur d'affectation.
//
// Param�tres :
//   p_Chaine        Chaine � copier dans l'objet courant.
//
// Postcondition :
//   - Les invariants sont respect�s.
//   - La chaine courante et p_Chaine sont �gaux.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            operator=(const Chaine& p_Chaine);

// *********************************************************************
// Description : 
//   Op�rateur d'affectation.
//
// Param�tres :
//   p_String        String � copier dans l'objet courant.
//
// Postcondition :
//   - La chaine courante et p_String ont la m�me longueur.
//   - Les invariants de la classe sont respect�s.
//
// Retourne :
//  Rien.
// *********************************************************************
    void            operator=(const char* p_String);
    
// *********************************************************************
// Description : 
//   Op�rateur d'�galit�.
//
// Param�tres :
//   p_Chaine        Chaine � comparer.
//
// Retourne :
//  true si les deux chaines ont les m�mes caract�res.
// *********************************************************************
    bool            operator==(const Chaine& p_Chaine) const;

// *********************************************************************
// Description : 
//   Op�rateur d'in�galit�.
//
// Param�tres :
//   p_Chaine        Chaine � comparer.
//
// Retourne :
//  true si les deux chaines sont diff�rentes.
// *********************************************************************
    bool            operator!=(const Chaine& p_Chaine) const;


// Pour permettre � l'op�rateur << d'acc�der � la partie priv�e de p_Chaine
friend std::ostream& operator<<(std::ostream& p_FluxDeSortie, const Chaine& p_Chaine);


private:
// *********************************************************************
// Description : 
//   Cette m�thode v�rifie les invariants.
//
// Param�tres :
//   Aucun.
//
// Retourne:
//  true si les invariants de la classe sont respect�s sur l'objet 
//  courant.
// *********************************************************************
    bool    CheckInvariants() const;

    char*   m_Ptr;
    int     m_Longueur;
};


// ***************************************************************************
// Description : 
//   Op�rateur de sortie dans un flux (std::cout ou un fichier).
//
// Param�tres :
//   p_Flux         Flux o� �crire. 
//   p_Chaine      Chaine � afficher.
//
// Exemples :
//   "{}"
//   "{14, 34, 33, -13, 2000}"
//
// Retourne :
//  Une r�f�rence vers le flux.
// ***************************************************************************
std::ostream& operator<<(std::ostream& p_FluxDeSortie, const Chaine& p_Chaine);






// *********************************************************************
// Description : 
//   Fonction pour afficher un objet Chaine dans les messages d'erreur
//   de WinUnit.
//
// Param�tres :
//   p_Chaine       Objet � �crire dans p_Buffer. 
//   p_Buffer       Cha�ne de caract�re o� �crire.
//   p_BufferSize   Taille maximal pour l'affichage.
//
// Retourne :
//  Un pointeur vers le cha�ne affich�e.
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