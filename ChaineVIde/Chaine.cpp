// *********************************************************************
// Description : 
//   Ce fichier contient l'impl�mentation de la classe Chaine.
//
//  Auteur :
//    Nicolas Richard
// *********************************************************************

#include "Ent�tePr�compil�e.h"

#include "Chaine.h"

#include "Assertion.h"


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
int LongueurString(const char* p_String)
{
	int taille = 0;
	while (p_String[taille] != '\0')
	{
		taille++;
	}
	POSTCONDITION(taille >= 0);

	return taille;
}



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
Chaine::Chaine()
{
	this->m_Ptr = new char[1];

	this->m_Ptr = NULL;

	this->m_Longueur = 0;

	POSTCONDITION((this->EstVide()) && (this->CheckInvariants()));
}

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
Chaine::Chaine(const char* p_String)
{
	int compteur = 0;

	this->m_Longueur = LongueurString(p_String);

	this->m_Ptr = new char[this->m_Longueur + 1];
	if (this->m_Longueur > 0)
	{
		for (compteur; compteur < this->m_Longueur; compteur++)
		{
			this->m_Ptr[compteur] = p_String[compteur];
		}

		this->m_Ptr[compteur] = '\0';
	}
	else
	{
		this->m_Ptr = NULL;
	}

	POSTCONDITION(this->m_Longueur == LongueurString(p_String) && (this->CheckInvariants()));
}

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
Chaine::Chaine(const Chaine& p_Chaine)
{
	int compteur = 0;

	this->m_Longueur = p_Chaine.m_Longueur;

	this->m_Ptr = new char[this->m_Longueur + 1];
	
	if (this->m_Longueur > 0)
	{
		for (compteur; compteur < this->m_Longueur; compteur++)
		{
			this->m_Ptr[compteur] = p_Chaine.m_Ptr[compteur];
		}

		m_Ptr[compteur] = '\0';
	}
	else
	{
		this->m_Ptr = NULL;
	}

	POSTCONDITION(*this == p_Chaine);
	POSTCONDITION(CheckInvariants());
}


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
Chaine::~Chaine()
{
	if (this->m_Ptr != NULL)
	{
		delete[] this->m_Ptr;
		this->m_Ptr = NULL;
		this->m_Longueur = 0;
	}

	POSTCONDITION(this->m_Ptr == NULL);
	POSTCONDITION(CheckInvariants());
 }


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
bool Chaine::CheckInvariants() const
{
	bool invariant = false;

	if ((this -> m_Ptr == NULL && this -> m_Longueur == 0) || (this -> m_Longueur > 0 && this -> m_Ptr != NULL))
	{
		invariant = true;
	}

    return invariant;
}




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
int Chaine::Longueur() const
{
	return this->m_Longueur;
}

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
void Chaine::Vider()
{
	delete[] this->m_Ptr;

	this->Chaine::Chaine();

	POSTCONDITION(CheckInvariants() && this -> EstVide());
}



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
bool Chaine::EstVide() const
{
	bool EstVide = true;

	if (this -> m_Longueur > 0)
	{
		EstVide = false;
	}

    return EstVide;
}

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
int Chaine::Trouver(const Chaine& p_SousChaine) const
{
	PR�CONDITION(p_SousChaine.Longueur() > 0);

	int compteur = 0;
	int recherche = 0;
	int retour = 0;

	bool EstTrouve = true;
	bool EstCorrect = false;

	for (int i = 0; i < this-> m_Longueur; i++)
	{
		if (p_SousChaine.m_Ptr[compteur] == this->m_Ptr[i])
		{
			retour = i;
			for (int j = 0; j <= p_SousChaine.m_Longueur && EstTrouve; j++)
			{

				if ((p_SousChaine.m_Longueur == j) && EstTrouve == true)
				{
					EstCorrect = true;
				}

				if (p_SousChaine.m_Ptr[j] != this->m_Ptr[i])
				{
					EstTrouve = false;
				}

				i++;
			}
		}
	}

	if (!EstCorrect)
	{
		retour = NON_TROUV�;
	}

	POSTCONDITION(retour == NON_TROUV� || (retour >= 0 && retour < this->m_Longueur));

	return retour;
}



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
Chaine Chaine::SousChaine(int p_Indice, int p_Longueur) const
{
	PR�CONDITION((p_Indice >= 0 && p_Indice<this->m_Longueur) && (p_Longueur >= 0 && p_Longueur <= (this->m_Longueur - p_Indice)));

	Chaine chaine1;
	int compteur = 0;

	chaine1.m_Ptr = new char[p_Longueur + 1];
	chaine1.m_Longueur = p_Longueur;

	for (int i = p_Indice; i <= p_Longueur; i++)
	{
		chaine1.m_Ptr[compteur] = this -> m_Ptr[i];
		compteur++;
	}

	chaine1.m_Ptr[chaine1.m_Longueur] = '\0';

    return chaine1;
}




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
void Chaine::Ins�rer(const Chaine& p_Chaine, int p_Indice)
{
	int compteur = 0;
	int compteurACopier = 0;

	int taille = p_Chaine.Longueur() + this->Longueur() + 1;

	char* tableau = new char[taille];

	for (compteur; compteur < p_Indice; compteur++)
	{
		tableau[compteur] = this->m_Ptr[compteurACopier];
		compteurACopier++;
	}

	for (int i = 0; i < p_Chaine.m_Longueur; i++)
	{
		tableau[compteur] = p_Chaine.m_Ptr[i];
		compteur++;
	}


	for (compteur; compteur < taille - 1; compteur++)
	{
		tableau[compteur] = this->m_Ptr[compteurACopier];
		compteurACopier++;
	}

	tableau[compteur] = '\0';

	delete[]this->m_Ptr;
	
	this->m_Ptr = tableau;
	this->m_Longueur = compteur;
}




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
void Chaine::Suppprimer(int p_Indice, int p_Longueur)
{
	PR�CONDITION((p_Indice >= 0 && p_Indice < this->m_Longueur) && (p_Longueur >= 0) && (p_Longueur <= m_Longueur - p_Indice));

	int compteur = 0;
	int compteurASup = 0;

	int taille = this->m_Longueur - p_Longueur + 1;

	char* tableau = new char[taille];

	for (compteur; compteur < p_Indice; compteur++)
	{
		tableau[compteur] = this->m_Ptr[compteurASup];
		compteurASup++;
	}

	compteurASup = p_Indice + p_Longueur;

	for (compteur; compteur < taille - 1; compteur++)
	{
		tableau[compteur] = this->m_Ptr[compteurASup];
		compteurASup++;
	}

	tableau[compteur] = '\0';

	delete[]this->m_Ptr;

	this->m_Ptr = tableau;
	this->m_Longueur = compteur;
	if (this->m_Longueur == 0)
	{
		this->m_Ptr = NULL;
	}

	POSTCONDITION(this->CheckInvariants());
}


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
void Chaine::operator=(const Chaine& p_Chaine)
{
	delete[]this->m_Ptr;

	this->Chaine::Chaine(p_Chaine);

	POSTCONDITION((this->CheckInvariants()) && (*this == p_Chaine));
}

// *********************************************************************
// Description : 
//   Op�rateur d'affectation.
//
// Param�tres :
//	 const char* p_String        String � copier dans l'objet courant.
//
// Postcondition :
//   - La chaine courante et const char* p_String ont la m�me longueur.
//   - Les invariants de la classe sont respect�s.
//
// Retourne :
//  Rien.
// *********************************************************************
void Chaine::operator=(const char* p_String)
{
	delete[] this->m_Ptr;

	this->Chaine::Chaine(p_String);

	POSTCONDITION(this->m_Longueur == LongueurString(p_String) && (this->CheckInvariants()));
}



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
bool Chaine::operator==(const Chaine& p_Chaine) const
{
	bool EstEgal = true;

	EstEgal = (this->m_Longueur == p_Chaine.Longueur());

	for (int i = 0; i < p_Chaine.Longueur() && EstEgal == true; i++)
	{
		if (this->m_Ptr[i] != p_Chaine.m_Ptr[i])
		{
			EstEgal = false;
		}
	}

	return EstEgal;
}

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
bool Chaine::operator!=(const Chaine& p_Chaine) const
{
    return (!operator==(p_Chaine));
}



// ***************************************************************************
// Description : 
//   Op�rateur de sortie dans un flux (std::cout ou un fichier).
//
// Param�tres :
//   p_Flux         Flux o� �crire. 
//   p_Chaine      Chaine � afficher.
//
//
// Retourne :
//  Une r�f�rence vers le flux.
// ***************************************************************************
std::ostream& operator<<(std::ostream& p_Flux,    const Chaine& p_Chaine)
{
	int compteur = 0;

	while (compteur < p_Chaine.Longueur())
	{
		p_Flux << p_Chaine.m_Ptr[compteur];
		compteur++;
	}

	return p_Flux;
}