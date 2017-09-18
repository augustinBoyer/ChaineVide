// *********************************************************************
// Description : 
//   Ce fichier contient les tests de la classe Chaine.
//
//  Auteur :
//    Nicolas Richard
// *********************************************************************


#include "EntêtePrécompilée.h"
#include "Chaine.h"

using namespace std;

bool EstValide(const char* p_StringAttendue, const Chaine& p_Chaine);

BEGIN_TEST(TestConstructeurParDéfaut)
{
	Chaine chaine;

	bool Egal = EstValide("", chaine);

	WIN_ASSERT_EQUAL(0, chaine.Longueur());
	WIN_ASSERT_TRUE(chaine.EstVide());
	WIN_ASSERT_TRUE(Egal);
}
END_TEST

BEGIN_TEST(TestConstructeurParInitialisation)
{
	Chaine chaine("Chaine");
	Chaine chaine2("Youpi");
	Chaine chaine3("");

	bool Egal = EstValide("Chaine", chaine);

	WIN_ASSERT_EQUAL(6, chaine.Longueur());
	WIN_ASSERT_FALSE(chaine.EstVide());
	WIN_ASSERT_TRUE(Egal);

	bool Egal2 = EstValide("Youpi", chaine2);

	WIN_ASSERT_EQUAL(5, chaine2.Longueur());
	WIN_ASSERT_FALSE(chaine2.EstVide());
	WIN_ASSERT_TRUE(Egal2);

	bool Egal3 = EstValide("", chaine3);

	WIN_ASSERT_EQUAL(0, chaine3.Longueur());
	WIN_ASSERT_TRUE(chaine3.EstVide());
	WIN_ASSERT_TRUE(Egal3);
}
END_TEST

BEGIN_TEST(TestConstructeurParCopie)
{
	Chaine chaine("Chaine");

	Chaine chaineParCopie(chaine);

	bool Egal = EstValide("Chaine", chaineParCopie);

	WIN_ASSERT_EQUAL(6, chaineParCopie.Longueur());
	WIN_ASSERT_FALSE(chaineParCopie.EstVide());
	WIN_ASSERT_TRUE(Egal);

	Chaine chaine2("EncoreYoupi");

	Chaine chaineParCopie2(chaine2);

	bool Egal2 = EstValide("EncoreYoupi", chaineParCopie2);

	WIN_ASSERT_EQUAL(11, chaineParCopie2.Longueur());
	WIN_ASSERT_FALSE(chaineParCopie2.EstVide());
	WIN_ASSERT_TRUE(Egal2);

	Chaine chaine3("");
	Chaine chaineParCopie3(chaine3);

	bool Egal3 = EstValide("", chaineParCopie3);

	WIN_ASSERT_EQUAL(0, chaineParCopie3.Longueur());
	WIN_ASSERT_TRUE(chaineParCopie3.EstVide());
	WIN_ASSERT_TRUE(Egal3);

	Chaine chaine4;
	Chaine chaineParCopie4(chaine4);

	bool Egal4 = EstValide("", chaineParCopie4);

	WIN_ASSERT_EQUAL(0, chaineParCopie4.Longueur());
	WIN_ASSERT_TRUE(chaineParCopie4.EstVide());
	WIN_ASSERT_TRUE(Egal4);
}
END_TEST

BEGIN_TEST(TestLongueur)
{
	Chaine chaine("Chaine");
	Chaine chaine1;
	Chaine chaine2("Anticonstitutionnellement");
	Chaine chaineT("T");
	Chaine chaineO("O");
	Chaine chaine3;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 2 == 0)
		{
			chaine3.Insérer(chaineT,i);
		}
		else
		{
			chaine3.Insérer(chaineO, i);
		}

	}

	WIN_ASSERT_EQUAL(6, chaine.Longueur());
	WIN_ASSERT_EQUAL(0, chaine1.Longueur());
	WIN_ASSERT_EQUAL(25, chaine2.Longueur());
	WIN_ASSERT_EQUAL(1000, chaine3.Longueur());
}
END_TEST

BEGIN_TEST(TestVider)
{
	Chaine chainePleine("Plein");
	Chaine chaineVide("");
	Chaine chaineUn("a");

	chainePleine.Vider();

	WIN_ASSERT_EQUAL(0, chainePleine.Longueur());
	WIN_ASSERT_TRUE(chainePleine.EstVide());

	chaineVide.Vider();

	WIN_ASSERT_EQUAL(0, chaineVide.Longueur());
	WIN_ASSERT_TRUE(chaineVide.EstVide());

	chaineUn.Vider();

	WIN_ASSERT_EQUAL(0, chaineUn.Longueur());
	WIN_ASSERT_TRUE(chaineUn.EstVide());
}
END_TEST

BEGIN_TEST(TestEstVide)
{
	Chaine chaine("");
	Chaine chainePleine("Plein");
	Chaine chaineNulle;

	WIN_ASSERT_TRUE(chaine.EstVide());
	WIN_ASSERT_FALSE(chainePleine.EstVide());
	WIN_ASSERT_TRUE(chaineNulle.EstVide());

	WIN_ASSERT_EQUAL(0, chaine.Longueur());
	WIN_ASSERT_EQUAL(5, chainePleine.Longueur());
	WIN_ASSERT_EQUAL(0, chaineNulle.Longueur());
}
END_TEST

BEGIN_TEST(TestOperateurTrouver)
{
	Chaine chaine("chaine");
	Chaine sousChaine("hain");
	Chaine fausseSousChaine("naih");
	Chaine sousChainePremier("c");
	Chaine sousChaineDernier("e");
	Chaine sousChaineEntier("chaine");
	Chaine sousChaineFail("z");
	Chaine sousChaineTrop("chainechaine");

	int Trouve = chaine.Trouver(sousChaine);

	int Trouve1 = chaine.Trouver(fausseSousChaine);

	int Trouve2 = chaine.Trouver(sousChainePremier);

	int Trouve3 = chaine.Trouver(sousChaineEntier);

	int Trouve4 = chaine.Trouver(sousChaineDernier);

	int Trouve5 = chaine.Trouver(sousChaineEntier);

	int Trouve6 = chaine.Trouver(sousChaineFail);

	int Trouve7 = chaine.Trouver(sousChaineTrop);

	WIN_ASSERT_EQUAL(1, Trouve);
	WIN_ASSERT_EQUAL(-99, Trouve1);
	WIN_ASSERT_EQUAL(0, Trouve2);
	WIN_ASSERT_EQUAL(0, Trouve3);
	WIN_ASSERT_EQUAL(5, Trouve4);
	WIN_ASSERT_EQUAL(0, Trouve5);
	WIN_ASSERT_EQUAL(-99, Trouve6);
	WIN_ASSERT_EQUAL(-99, Trouve7);

	Chaine chaine1("");
	Chaine sousVide("e");

	int TrouveVide = chaine1.Trouver(sousVide);

	WIN_ASSERT_EQUAL(-99, TrouveVide);

	Chaine chaine2("e");
	Chaine sousChaineUn("e");

	int TrouveUn = chaine2.Trouver(sousChaineUn);

	WIN_ASSERT_EQUAL(0, TrouveUn);
}
END_TEST

BEGIN_TEST(TestSousChaine)
{
	Chaine chaine("Chaine");

	Chaine sousChaine = chaine.SousChaine(1, 4);

	bool sousChaine1 = EstValide("hain", sousChaine);

	WIN_ASSERT_EQUAL(4, sousChaine.Longueur());
	WIN_ASSERT_TRUE(sousChaine1);

	Chaine sousChainePleine = chaine.SousChaine(0, 6);

	bool sousChainePleine1 = EstValide("Chaine", sousChainePleine);

	WIN_ASSERT_EQUAL(6, sousChainePleine.Longueur());
	WIN_ASSERT_TRUE(sousChainePleine1);

	Chaine chaineUn("U");

	Chaine sousChaineUn = chaineUn.SousChaine(0, 0);

	bool sousChaineUn1 = EstValide("", sousChaineUn);

	WIN_ASSERT_EQUAL(0, sousChaineUn.Longueur());
	WIN_ASSERT_TRUE(sousChaineUn1);


	Chaine sousChaineDeux = chaineUn.SousChaine(0, 1);

	bool sousChaineDeux1 = EstValide("U", sousChaineDeux);

	WIN_ASSERT_EQUAL(1, sousChaineDeux.Longueur());
	WIN_ASSERT_TRUE(sousChaineDeux1);

}
END_TEST

BEGIN_TEST(TestInsérer)
{
	Chaine chaine("Ce");
	Chaine chaineAInserer("hain");

	chaine.Insérer(chaineAInserer, 1);

	bool Egal = EstValide("Chaine", chaine);

	WIN_ASSERT_EQUAL(6, chaine.Longueur());
	WIN_ASSERT_TRUE(Egal);

	Chaine chaine1("aine");
	Chaine chaineAInserer1("ch");

	chaine1.Insérer(chaineAInserer1, 0);

	bool Egal1 = EstValide("chaine", chaine1);

	WIN_ASSERT_EQUAL(6, chaine1.Longueur());
	WIN_ASSERT_TRUE(Egal1);

	Chaine chaine2("encore une");
	Chaine chaineAInserer2(" chaine");

	chaine2.Insérer(chaineAInserer2, 10);

	bool Egal2 = EstValide("encore une chaine", chaine2);

	WIN_ASSERT_EQUAL(17, chaine2.Longueur());
	WIN_ASSERT_TRUE(Egal2);

	Chaine chaine3("encore une");
	Chaine chaineAInserer3("");

	chaine2.Insérer(chaineAInserer3, 0);

	bool Egal3 = EstValide("encore une", chaine3);

	WIN_ASSERT_EQUAL(10, chaine3.Longueur());
	WIN_ASSERT_TRUE(Egal3);

	Chaine chaine4("");
	Chaine chaineAInserer4("encore une chaine");

	chaine4.Insérer(chaineAInserer4, 0);

	bool Egal4 = EstValide("encore une chaine", chaine4);

	WIN_ASSERT_EQUAL(17, chaine4.Longueur());
	WIN_ASSERT_TRUE(Egal4);

	Chaine chaine5("encore une chaine");
	Chaine chaineAInserer5("");

	chaine4.Insérer(chaineAInserer5, 9);

	bool Egal5 = EstValide("encore une chaine", chaine5);

	WIN_ASSERT_EQUAL(17, chaine5.Longueur());
	WIN_ASSERT_TRUE(Egal5);

	Chaine chaine6("encore une chaine");
	Chaine chaineAInserer6("");

	chaine4.Insérer(chaineAInserer6, 9);

	bool Egal6 = EstValide("encore une chaine", chaine6);

	WIN_ASSERT_EQUAL(17, chaine6.Longueur());
	WIN_ASSERT_TRUE(Egal6);

	Chaine chaine7("encore une chaine");
	Chaine chaineAInserer7("");

	chaine4.Insérer(chaineAInserer7, 17);

	bool Egal7 = EstValide("encore une chaine", chaine7);

	WIN_ASSERT_EQUAL(17, chaine7.Longueur());
	WIN_ASSERT_TRUE(Egal7);
}
END_TEST


BEGIN_TEST(TestSupprimer)
{
	Chaine chaine1("Tototo");
	chaine1.Suppprimer(2, 2);
	bool Egal1 = EstValide("Toto", chaine1);

	WIN_ASSERT_EQUAL(4, chaine1.Longueur());
	WIN_ASSERT_TRUE(Egal1);

	Chaine chaine2("T");
	chaine2.Suppprimer(0, 0);
	bool Egal2 = EstValide("T", chaine2);

	WIN_ASSERT_EQUAL(1, chaine2.Longueur());
	WIN_ASSERT_TRUE(Egal2);

	Chaine chaine3("T");
	chaine3.Suppprimer(0, 1);
	bool Egal3 = EstValide("", chaine3);

	WIN_ASSERT_EQUAL(0, chaine3.Longueur());
	WIN_ASSERT_TRUE(Egal3);

	Chaine chaineT("T");
	Chaine chaineO("O");
	Chaine chaine4;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 2 == 0)
		{
			chaine4.Insérer(chaineT, i);
		}
		else
		{
			chaine4.Insérer(chaineO, i);
		}

	}
	chaine4.Suppprimer(0, 1000);
	bool Egal4 = EstValide("", chaine4);

	WIN_ASSERT_EQUAL(0, chaine4.Longueur());
	WIN_ASSERT_TRUE(Egal4);



}
END_TEST


BEGIN_TEST(TestOperateurAfectationChaine)
{
	Chaine chaine1("Toto");
	Chaine chaine2;
	chaine2 = chaine1;
	Chaine chaine3("Test");
	Chaine chaine4;
	chaine3 = chaine4;
	Chaine chaine5("Toto");
	Chaine chaine6("Alexandre est le meilleur!");
	chaine5 = chaine6;

	bool Egal1 = EstValide("Toto", chaine1);
	bool Egal2 = EstValide("Toto", chaine2);
	bool Egal3 = EstValide("", chaine3);
	bool Egal4 = EstValide("", chaine4);
	bool Egal5 = EstValide("Alexandre est le meilleur!", chaine5);

	WIN_ASSERT_TRUE(Egal1);
	WIN_ASSERT_TRUE(Egal2);
	WIN_ASSERT_TRUE(Egal3);
	WIN_ASSERT_TRUE(Egal4);
	WIN_ASSERT_TRUE(Egal5);

	WIN_ASSERT_EQUAL(4, chaine1.Longueur());
	WIN_ASSERT_EQUAL(4, chaine2.Longueur());
	WIN_ASSERT_EQUAL(0, chaine3.Longueur());
	WIN_ASSERT_EQUAL(0, chaine4.Longueur());
	WIN_ASSERT_EQUAL(26, chaine5.Longueur());

}
END_TEST

BEGIN_TEST(TestOperateurAfectationString)
{
	const char* chaine1 = "Toto";
	Chaine chaine2;
	chaine2 = chaine1;
	Chaine chaine3("Test");
	const char* chaine4 = "";
	chaine3 = chaine4;
	Chaine chaine5("Toto");
	const char* chaine6 = "Alexandre est le meilleur!";
	chaine5 = chaine6;
	const char* chaine7 = "Toto";
	Chaine chaine8("Alexandre est le meilleur!");
	chaine8 = chaine7;
	Chaine chaine9("Toto");
	chaine9 = chaine8;

	bool Egal1 = EstValide("Toto", chaine2);
	bool Egal2 = EstValide("", chaine3);
	bool Egal3 = EstValide("Alexandre est le meilleur!", chaine5);
	bool Egal4 = EstValide("Toto", chaine8);
	bool Egal5 = EstValide("Toto", chaine9);

	WIN_ASSERT_TRUE(Egal1);
	WIN_ASSERT_TRUE(Egal2);
	WIN_ASSERT_TRUE(Egal3);
	WIN_ASSERT_TRUE(Egal4);
	WIN_ASSERT_TRUE(Egal5);

	WIN_ASSERT_EQUAL(4, LongueurString(chaine1));
	WIN_ASSERT_EQUAL(4, chaine2.Longueur());
	WIN_ASSERT_EQUAL(0, chaine3.Longueur());
	WIN_ASSERT_EQUAL(0, LongueurString(chaine4));
	WIN_ASSERT_EQUAL(26, LongueurString(chaine6));
	WIN_ASSERT_EQUAL(26, chaine5.Longueur());
	WIN_ASSERT_EQUAL(4, chaine8.Longueur());
	WIN_ASSERT_EQUAL(4, chaine9.Longueur());
}
END_TEST


BEGIN_TEST(TestEgalite)
{
	Chaine chaine("Augustin est encore meilleur");

	Chaine chaine1("Augustin est encore meilleur");

	bool EstEgal = (chaine == chaine1);

	WIN_ASSERT_TRUE(EstEgal);

	bool EstEgalBis = (chaine1 == chaine);

	WIN_ASSERT_TRUE(EstEgalBis);

	Chaine chaine2("");

	Chaine chaine3("");

	bool EstEgal1 = (chaine2 == chaine3);

	WIN_ASSERT_TRUE(EstEgal1);

	bool EstEgal1Bis = (chaine3 == chaine2);

	WIN_ASSERT_TRUE(EstEgal1Bis);

	bool EstEgal2 = (chaine2 == chaine);

	WIN_ASSERT_FALSE(EstEgal2);

	bool EstEgal2Ter = (chaine == chaine2);

	WIN_ASSERT_FALSE(EstEgal2Ter);

	Chaine chaine4("1");

	Chaine chaine5("1");

	bool EstEgal3 = (chaine4 == chaine5);

	WIN_ASSERT_TRUE(EstEgal3);
}
END_TEST

BEGIN_TEST(TestInegalite)
{
	Chaine chaine("Augustin est encore meilleur");

	Chaine chaine1("Augustin est encore meilleur");

	WIN_ASSERT_FALSE(chaine != chaine1);

	WIN_ASSERT_FALSE(chaine1 != chaine);

	Chaine chaine2("");

	Chaine chaine3("");

	WIN_ASSERT_FALSE(chaine2 != chaine3);

	WIN_ASSERT_FALSE(chaine3 != chaine2);

	WIN_ASSERT_TRUE(chaine2 != chaine);

	WIN_ASSERT_TRUE(chaine != chaine2);

	Chaine chaine4("1");

	Chaine chaine5("1");

	WIN_ASSERT_FALSE(chaine4 != chaine5);

	WIN_ASSERT_FALSE(chaine5 != chaine4);
}
END_TEST

// *********************************************************************
// Description : 
//   Valide qu'une chaine correspond bien à une string donnée.
//
// Paramètres :
//   p_Attendue        String attendue.
//   p_ÀValider         Chaine à valider
//
// Retourne :
//  true si p_ÀValider correspond bien à p_Attendue.
// *********************************************************************
bool EstValide(const char* p_Attendue, const Chaine& p_ÀValider)
{
	bool valide = (LongueurString(p_Attendue) == p_ÀValider.Longueur());

	if (valide)
	{
		if (p_Attendue == NULL)
		{
			valide = p_ÀValider.EstVide();
		}
		else
		{
			std::ostringstream flux;

			flux << p_ÀValider;

			valide = (string(p_Attendue) == flux.str());
		}
	}
	return valide;
}

