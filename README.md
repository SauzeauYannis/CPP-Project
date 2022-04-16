##### Table of Contents
* [Français](#fr)
  * [Présentation](#fr_pr)
  * [Utilisation](#fr_ut)
  * [Compétences acquises](#fr_cp)
  * [Résultat](#fr_rs)
* [English](#en)
  * [Presentation](#en_pr)
  * [Use](#en_u)
  * [Skills acquired](#en_sk)
  * [Result](#en_rs)

<a name="fr"/>

## Français

<a name="fr_pr"/>

### Présentation

Ce projet a été effectué en quatrième année du [CMI Informatique Parcours Conception logicielle](http://formations.univ-poitiers.fr/fr/index/autre-diplome-niveau-master-AM/autre-diplome-niveau-master-AM/cmi-informatique-JD2XQGVY.html) à l'[UFR SFA Université de Poitiers](https://sfa.univ-poitiers.fr/) dans le cadre de l'enseignement [Conception orientée-objet](https://formations.univ-poitiers.fr/fr/index/autre-diplome-niveau-master-AM/autre-diplome-niveau-master-AM/cmi-informatique-JD2XQGVY/cmi-parcours-conception-logicielle-K56KZ5KL/specialite-s7-JPEIFH2K/conception-orientee-objet-JC4UUO13.html).

Ce projet a été développé en binôme avec l'IDE [Visual studio 2022](https://visualstudio.microsoft.com/fr/vs/).

<a name="fr_ut"/>

### Utilisation

Pour lancer le jeu, il faut ouvrir la solution [Yahtzee/Yahtzee.sln](https://github.com/SauzeauYannis/CPP-Project/blob/main/Yahtzee/Yahtzee.sln) avec visual studio.

Au lancement de notre jeu, nous renseignons en premier le nombre de joueurs devant participer à la partie (nombre allant de 1 à 8 joueurs).

Si le nombre de joueurs est égal à 1, alors le joueur joue seul contre l’ordinateur qui ne lance qu’une fois les dés et qui choisit la figure qui lui rapporte le plus de points.

Si le nombre de joueurs est plus grand que 1, alors chaque joueur entre son nom et s’affronte tour à tour.

À l’issue de cette étape, nous simulons le lancer de dés en appuyant sur une touche ; en fonction de la configuration obtenue, les points correspondant aux figures s’affichent dans le tableau à titre informatif et trois choix s’offrent ainsi au joueur :

* Relancer les dés
* Sélectionner des dés spécifiques à lancer
* Construire une figure à partir des dés obtenus

Conformément aux règles du Yahtzee, chaque joueur a droit à 3 lancers maximum et peut donc former sa figure au moment qui lui convient parmi ces 3 lancers.

Après le choix de la figure voulue, le tableau de points est marqué d’un signe [ X ] pour signifier les figures choisies par le joueur depuis le début de la partie.

Aussi, à chaque lancer, le score actuel est toujours affiché ainsi que le statut d’obtention de la prime (en fonction, du fait qu’il l'ait obtenu ou non).

À l’issue de chaque manche, chaque joueur dispose du droit de mettre fin à la partie sinon la partie s’arrête quand toutes les figures ont été formées.

Quand la partie est terminée, le classement est ainsi affiché en fonction des scores et on a le choix de recommencer une nouvelle partie ou non.

<a name="fr_cp"/>

### Compétences acquises

* Syntaxe de langages objets, définition de classes, composition, agrégation
* Héritage simple
* Polymorphisme et abstraction
* Allocation statique/dynamique et compréhension mémoire, généricité, exceptions
* Pointeurs intelligents
* Patrons de conception
* Patrons de classe
* Cycle de vie du logiciel
* Analyse des besoins et validation
* Revue de code et test logiciel

<a name="fr_rs"/>

### Résultat

Nous avons obtenu la note de 12/20.

<a name="en"/>

## English

<a name="en_pr"/>

### Presentation

This project was carried out in the fourth year of the [CMI Informatique Parcours Conception logicielle](http://formations.univ-poitiers.fr/fr/index/autre-diplome-niveau-master-AM/autre-diplome-niveau-master-AM/cmi-informatique-JD2XQGVY.html) at the [UFR SFA Université de Poitiers](https://sfa.univ-poitiers.fr/) as part of the [Conception orientée-objet](https://formations.univ-poitiers.fr/fr/index/autre-diplome-niveau-master-AM/autre-diplome-niveau-master-AM/cmi-informatique-JD2XQGVY/cmi-parcours-conception-logicielle-K56KZ5KL/specialite-s7-JPEIFH2K/conception-orientee-objet-JC4UUO13.html) course.

This project was developed in binomial with the IDE [Visual studio 2022](https://visualstudio.microsoft.com/fr/vs/).

<a name="en_u"/>

### Use

To launch the game, we need to open the solution [Yahtzee/Yahtzee.sln](https://github.com/SauzeauYannis/CPP-Project/blob/main/Yahtzee/Yahtzee.sln) with visual studio.

When launching our game, we first enter the number of players who should participate in the game (number ranging from 1 to 8 players).

If the number of players is equal to 1, then the player plays alone against the computer, which throws the dice only once and chooses the trick that gives him the most points.

If the number of players is greater than 1, then each player enters his or her name and takes turns to compete.

At the end of this stage, we simulate the roll of the dice by pressing a key; depending on the configuration obtained, the points corresponding to the figures are displayed in the table for information purposes and the player has three choices:

* Raise the dice
* Select specific dice to roll
* Build a pattern from the dice rolled

In accordance with the Yahtzee rules, each player is allowed a maximum of 3 throws and can therefore form his pattern at any time within these 3 throws.

After the choice of the trick, the scoreboard is marked with an [ X ] sign to indicate the tricks chosen by the player since the beginning of the game.

Also, at each throw, the current score is always displayed, as well as the status of the bonus (depending on whether or not the bonus has been achieved).

At the end of each round, each player has the right to end the game, otherwise the game ends when all the figures have been formed.

When the game is over, the ranking is displayed according to the scores and you have the choice of starting a new game or not.

<a name="en_sk"/>

### Skills acquired

* Syntax of object languages, class definition, composition, aggregation
* Simple inheritance
* Polymorphism and abstraction
* Static/dynamic allocation and memory understanding, genericity, exceptions
* Intelligent pointers
* Design patterns
* Class patterns
* Software life cycle
* Requirements analysis and validation
* Code review and software testing
  
<a name="en_rs"/>

### Result

We obtained a score of 12/20.
