#include "pch.h"
#include "CppUnitTest.h"

#include "../Yahtzee/figure_inferieure.h"
#include "../Yahtzee/figure_superieure.h"
#include "../Yahtzee/ia.h"
#include "../Yahtzee/lancer.h"
#include "../Yahtzee/joueur.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YahtzeeTest
{
	TEST_CLASS(InitTests)
	{
	public:
		TEST_METHOD(InitFigureSuperieure)
		{
      const std::string nom = "As";
			constexpr coo::partie_enum partie = coo::partie_enum::partie_superieur;
			constexpr unsigned int points = 0;
			constexpr bool est_choisie = false;

      const coo::figure_superieure<1> as(nom);

			Assert::AreEqual(nom, as.nom());
			Assert::AreEqual(static_cast<int>(partie), static_cast<int>(as.partie()));
			Assert::AreEqual(points, as.points());
			Assert::AreEqual(est_choisie, as.est_choisie());
		}
		
		TEST_METHOD(InitSuite)
		{
			const std::string nom = "Petite suite";
			constexpr coo::partie_enum partie = coo::partie_enum::partie_inferieur;
			constexpr unsigned int points = 0;
			constexpr bool est_choisie = false;

			const coo::suite<4> petite_suite(nom, 40);

			Assert::AreEqual(nom, petite_suite.nom());
			Assert::AreEqual(static_cast<int>(partie), static_cast<int>(petite_suite.partie()));
			Assert::AreEqual(points, petite_suite.points());
			Assert::AreEqual(est_choisie, petite_suite.est_choisie());
		}
		
		TEST_METHOD(InitFigureDesEgaux)
		{
			const std::string nom = "Brelan";
			constexpr coo::partie_enum partie = coo::partie_enum::partie_inferieur;
			constexpr unsigned int points = 0;
			constexpr bool est_choisie = false;

			const coo::figure_des_egaux<3, 2> brelan(nom);

			Assert::AreEqual(nom, brelan.nom());
			Assert::AreEqual(static_cast<int>(partie), static_cast<int>(brelan.partie()));
			Assert::AreEqual(points, brelan.points());
			Assert::AreEqual(est_choisie, brelan.est_choisie());
		}
		
		TEST_METHOD(InitDe)
	  {
			const coo::de de;

			Assert::AreEqual(coo::de::val_min, de.valeur());
		}
		
		TEST_METHOD(InitLancer)
	  {
			const coo::lancer lancer;

      for (int i = 0; i < coo::lancer::nombre_des; ++i)
				Assert::AreEqual(0, lancer[i]);
		}

		TEST_METHOD(InitJoueur)
		{
			const coo::joueur joueur("Joueur", std::make_shared<coo::lancer>());

			Assert::AreEqual(static_cast<unsigned>(0), joueur.points());
		}

		TEST_METHOD(InitIA)
		{
			const coo::ia ia(std::make_shared<coo::lancer>());

			Assert::AreEqual(static_cast<unsigned>(0), ia.points());
		}
	};
	
	TEST_CLASS(LancerTests)
	{
	public:
		TEST_METHOD(ToutLancer)
		{
			coo::lancer lancer;

			lancer.tout_lancer();

			int somme = 0;
			for (int i = 0; i < coo::de::nombre_faces; ++i)
				somme += lancer[i];

			Assert::AreEqual(coo::lancer::nombre_des, somme);
		}

		TEST_METHOD(SommeDes)
		{
			coo::lancer lancer;

			Assert::AreEqual(static_cast<unsigned>(0), lancer.somme_des());

			lancer.tout_lancer();

			Assert::IsTrue(lancer.somme_des() > static_cast<unsigned>(0));
		}
		TEST_METHOD(LancerDes)
		{
			coo::lancer lancer;

			lancer.tout_lancer();

      const unsigned int somme = lancer.somme_des();

      while (somme == lancer.somme_des()) {
				const std::set<int> des = { 1, 2, 4 };

				lancer.lancer_des(des);
      }

			Assert::AreNotEqual(somme, lancer.somme_des());
		}
	};

	TEST_CLASS(FigureSuperieurTest)
	{
	public:
		TEST_METHOD(CalcPoints)
		{
			coo::figure_superieure<1> as("As");
			coo::figure_superieure<2> deux("Deux");
			coo::figure_superieure<3> trois("Trois");
			coo::figure_superieure<4> quatre("Quatre");
			coo::figure_superieure<5> cinq("Cinq");
			coo::figure_superieure<6> six("Six");

			coo::lancer lancer;

			lancer.tout_lancer();

			as.calc_points(lancer);
			deux.calc_points(lancer);
			trois.calc_points(lancer);
			quatre.calc_points(lancer);
			cinq.calc_points(lancer);
			six.calc_points(lancer);

			unsigned int somme = as.points();
			somme += deux.points();
			somme += trois.points();
			somme += quatre.points();
			somme += cinq.points();
			somme += six.points();

			Assert::IsTrue(somme >= static_cast<unsigned>(6));
		}

	};

	TEST_CLASS(FigureInferieurTest)
	{
	public:

		TEST_METHOD(CalcPoints)
		{
			coo::figure_des_egaux<0> chance("Chance");
			coo::figure_des_egaux<0> chance_50("Chance", 50);

			coo::lancer lancer;

			lancer.tout_lancer();

			chance.calc_points(lancer);
			chance_50.calc_points(lancer);

			Assert::IsTrue(chance.points() >= static_cast<unsigned>(6));
			Assert::AreEqual(chance_50.points(), static_cast<unsigned>(50));
		}

	};

	TEST_CLASS(IATest)
	{
	public:

		TEST_METHOD(JoueTour)
		{
			coo::ia ia(std::make_shared<coo::lancer>());

			unsigned int points_avant_jouer = ia.points();

			ia.joue_tour();

			Assert::IsTrue(ia.points() > points_avant_jouer);

			points_avant_jouer = ia.points();

			ia.joue_tour();

			Assert::IsTrue(ia.points() > points_avant_jouer);
		}

	};
	
}
