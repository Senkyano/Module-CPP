# DOCUMENTATION

En general ca marche comme en C structure, operation, boucle et autres

## Les differentes sortie d'ecriture + "free"
	- std::count : sortie standard (dans un buffer)
	- std::cerr : sortie standard d'erreur (affichage immédiat)
	- std::clog : sortie standard d'erreur (dans un buffer)

	- std::endl : retour à la ligne + vidage du buffer (flush)
	- std::flush : vidage du buffer

## Déclaration de Variable en C++

	pour declarer une variable c'est la meme chose que en C apart une chose ce sont
	les string ou nous devons les declarer comme suit: 
														- std::string Nom_Variable{"VALEUR"};

	Nous avons aussi la varaible auto qui permet definir le type de la variable automatiquement :
														- auto Nom_de_la_variable.

## Recuperation de saisie

	Saisie de l'utilisateur:
														- std::cin >> Nom_Variable;
														- std::getline(entree, 	Nom_Variable, limiteur);
	verification des erreurs: (valeur booleene)
										- std::cin.fail() : true/false
										- std::cin.good() : true/false
										- std::cin.bad() :  true/false
					par defaut std::cin est en mode good() = true et le reste est en false.
		on peut aussi utiliser std::cin.clear() pour remettre le flux en mode good() = true
		quand on auras gerer l'erreur.

					on peut faire aussi recuperer un certain nombre de caractere avec
										- std::cin.ignore(Nbr_octe, 'Char_de_fin');
	
	Pour les gestion des erreurs et les voirs on peut utilser la fonction assert dans la bibliotheque
	#include <cassert>, on ne met pas le .h car en cpp il le hash
				assert(Conditions, "message");


	Namespace (Nom_de_porter)
		Les noms aux debut comme "std::" c'est pour pouvoir qualifier des variables ou meme des fonctions
		comme ca on sait quelle fonctions on utilise et pas de nimporte ou, ou bien meme de nimportes quelle
		extensions. C'est principalement lier pour eviter les conflits de nom de fonctions.

	ecrire une macron d'un Namespace :
										- namespace (Nom_macro) = (Nom_du_namespace);
										ou 
										- using (Nom_macro) = (Nom_du_namespace);
	
## Structure et Class

	on vas surtout etudier la class car les structures ressemble meme ils sont identique que en C

	Les structures sont par defaut une données (publique).

	Les class :
		class Nom_de_la_class
		{
			Les niveaux d'acces :
									- Publique
									- Priver
									- Proteger
			public:
					Nom_du_constructeur() = delete;
					Nom_du_constructeur(const Nom_de_la_class& ..);
					Nom_du_constructeur_deplacement(Nom_de_la_class&& ..);
					~Nom_du_destructeur();
			private:
			protected:
		}
	Nous devons imperativement creer le constructeur et un destructeur mais si on le fait c'est fait automatiquement mais on peut empecher que ca se construise automatiquement en rajoutant "= delete" comme si-dessus ensuite pour proceder aux constructeur ca seras fait comme ce ci :
													Nom_de_la_class::Nom_du_constructeur_lier_a_la_class.
													{
														specifier comment il se construit
													}
		construction d'une copie d'un constructeur :

											Nom_de_la_class::Nom_du_constructeur_lier_a_la_class(const Nom_de_la_class& ..).
											{
												specifier comment il se construit
											}
							
		constructeur de deplacement permet de transmettre ces donnees a un autre objet qui se feras pareillement que ci-dessus avec quelque petites differences

	Les destructeurs commence par une tilde "~" l'implementation ce fait comme le constructeur.