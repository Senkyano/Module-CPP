# DOCUMENTATION

En general ca marche comme en C structure, operation, boucle et autres

convertion de std::string en char* = "_Nom_De_La_Variable.c_str()"

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

### Constructeur

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
	
	Quand nous appellons un constructeur il se créer mais des que on as plus besoin de lui il va directement se detruire.

### Les attribue et Methodes

	Les attribues sont en quelque sorte en appeller une fonction pour initialiser une une varaible qui se trouve dans le domaine du private. 
		exemple :
					Nom_de_la_class::Nom_Du_Constructeur(_Variable_ Nom_Variable) : _Nom_de_Attribue_(Nom_Variable)
					{
						(ou on peut faire sous cette forme)
							this->_Nom_de_Attribue_ = (Nom_Variable);
					}
		
	Une methode :
		une fonction qui appartient a la class comme le constructeur mais que on l'appelle.

	on peut ajoute un noexcept a la fin du nom de la fonction qui va dire que la fonction ne prend pas d'expection ou meme const qui voudras dire qu'il ne prendras que des constantes.
					-> Nom_de_la_class::Nom_Du_Constructeur(_Variable_ Nom_Variable) noexpect

### Encapsulation

	Accesseur et Modificateur, on as des attributs qui sont en private, mais nous ne pouvons pas acceder classiquement comme un C avec les structures, en fessant Nom_de_La_class/Structure._Nom_Attribue_;

	Pour creer un accesseur c'est une fonction qui vas se contruire comme si-dessous :
				-> _Type_de_l'attribue_		Nom_deLa_class::Nom_de_la_fonction() (un parametre comme const)
				{
					return (this->Nom_de_l'attribue);
				}
		Le this permet de dire vraiment que vont celui-la specifiquement de tel classe

	convention si on veut modifier un attribue il faut mettre en nom de fonction "Set"
				ca seras un type ->	void	Set"Nom_de_La_fonction"(_Type_attribue_  Nom_de_L'atttribue/variable);

## Tableau de pointeur de fonction

	On vas creer une fonction pour avoir plusieur niveau et que chaque niveau on vas faire une methode differente.
	Par exemple on vas prendre la methode Harl, Harl auras 4 script pour ces 4 differents niveaux : Debug, info, warning, error.
	On auras un aussi une fonction qui vas excuter avec un certain niveau.
	dans cette fonction on auras un tableau de fonction qui vas definir le niveau de ca plainte.
	Pour ensuite excuter le niveau en question.

Fonction :
	_Nom_Attriube_.lenght() = connaitre la longueur de la chaine de caracteres
	
	attribue New = "allocation" 
	delete = "suppression d'un pointeur"
	delete [] = "suppression d'un tableau de pointeur"

REFERENCE / POINTEUR :
	Les pointeurs reste pareil que en C.
	Il y a de reference en cpp qui sont designer par une variable comme suit :
			_TYPE_	&_Nom_de_la_variable_ = _Nom_d'une_autre_Variable_;
		Et il faut savoir que si on l'initialise ou il ne peut plus etre redefinie plus tard et nous ne pouvons pas le definir a NULL.

	Il y a 2 type de reference les lvalue = & et les rvalue = &&
		lvalue font reference a une variable deja nommer
		rvalue correspond a une reference universel qui peut un lvalue ou a une variable temporaire.
