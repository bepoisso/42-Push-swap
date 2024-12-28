/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:00:04 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/28 19:30:24 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// __________________________INFORMATION__________________________
		// On push dans la stack b tout le contenue de a
		// en ordre decroisant
			// On a donc dans b un max et un min
			// faut les trier ? 
				// toutes les node d a doivent avoir un target en b
//		25	|	// Une target est le nombre le plus proche et plus petit que la node a.
// -38	0	|// (A voir plus tard)
//	10	99	|// pour 0 99 dans b et a = 25 la target de 25 seras 0 par ce que
//	7		|// c'est la seul vbaleur plus petite que 25
//	42		|// si un nombre est plus petit que la valeur min dans b alor ca target seras max
					// exemple : pour -38 la target seras 99 (max)
			// /!\ On recalcule la target a chaque fois en la target est le nombre min le plus prets
			

			
			// Trouver le node la moins chere a push
			// /!\ On ne compte pas le pb() dans les mouve
			// la formule :		x mouve pour envoyer en top a
			// 				+	x mouve pour envoyer la node au dessus de la target
			//				=	Push cost
			// si on trouve un push cost de 0 on s'arrete par ce que rien ne peut etre en dessous
			// exemple pour push	25 = 0 (pb) (A PAS TROP PRENDRE EN COMPTE)
			// 						-38 = 1 (pb + rrb) (on mets 99 en haut et on push)
			// 						10 = 1 (ss + pb) (10 doit etre au desus de 0 donc on ss puis pb)
			// 						7 = 3 (sb + rra + rra  + pb)
			// 						42 = 1 (rra + pb)
			
		//Les trois restant de la stack a sont trier
	

	// ensuite on push tout les node de b 1 par 1 jusqua ce que b soit vide
	// pour ca on regarde avant de push si on le push au dessus de la bonne node
	// chaque node b a besoin d'une target en a qui est la valeur la plus proche et la plus grosse
	// si on trouve pas de plus grand que la node b alors sa target est le plus petit nombre
//		-38	|
//		99	|
//	7	25	|
//	10	0	|
//	42		|
	// la target de -38 est 7 (car le plus gros nombre le plus proche de -38)
	// la target de 99 est -38 (On viens de la push car il n'y a pas de nombre au dessus de 99)
	// ta target de 25 est 42
	// la target de 0 est 7
	// si la target n'est pas au dessus alors on fait soit un ra soit un rra pour l'avoir en haut donc
	// il faut imaginer une mediane au milieu de la stack a
	// et si la targette est en dessous on rra() et si au dessus on ra()
	// Car ca coute moins de mouvement

	// On push la node de b au dessus de ca target
	// a la fin on verifie que le min soit au top si c'est pas le cas on ra ou rra jusqua l'avoir en haut



// __________________________Pseudo code__________________________

// declarer les pointeur des deux stack (a et b)
	// On les set a NULL

// On gere les erreur d'argument (Invalide etc...)
	// Si erreur return error

// on gere les 2 cas des arg si c'est une string ou une commande line(7 4 6 9 3 2 1 0 && "7 4 6 9 3 2 1 0")
	// si c'est une string on split() vers des sous chaine

// On initalise la stack a avec tout les nombre
	// on gere les overflow de int, double nombre, erreur de syntax (seulement des nombre et '+' '-')
		// si il y a une erreur on free et on return error
	// On verifie que tout les nombre fit dans un int
		// on mets tout les valeur dans des long int (dans nos node) (On utilise des long pour voir si on a des overflow de int)
	// On ajoute toutes les node a la stack a

// Check si a est trier
	// si il est pas trier
		// si il y a 2 node
			// on swape les node
		// si il y a 3 node
			// on utilise notre algo sort_three()
		// si il y a plus que 3 node
			// utilise alog truk

// Free les stack

// ____________________________________________________

// __________________________DETAIL ALGO TURK__________________________

// push 2 node a vers b
	// si a est pas trier et qu'il reste au moins 3 node dans la stack a
// jusequa ce que stack a = 3
	// On donne une target a chaque node a
		// la target est le nombre le plus petit le plus perts
			// si pas de nombre plus petit la target est le nombre max
	// On push la node a vers la stack b (au dessus de sa target)
		// on calcule le chepest push_coast de toute nos node a
			// si on trouve 0 on le fait imediatement
			// si non on continue

// On utilise l'algo three_sort()
	// (Pour trier a)

// push toutes les node b dans la stack a
	// On calcule la target de chaque node b
		// la target est le nombre le plus grand et le plus prets
	// On push la node au dessus de ca target
		// si la target est au dessus de la mediane
			// on rotate (ra) jusqua avoir la target en haut
		// si la target est en dessuous de la mediane
			// on revers rotate (rra) jusqua avoir la target en haut
// on mets le plus grand nombre au top de a
	// on regarde si le plus petit nombre est au top et le plus grand au bottom
		// si c'est pas le cas
			// on regarde ou se trouve le plus petit nombre par apport a la mediane
				// si il est au dessus on rotate (ra) jusqua ce qu'il soit en haut
				// Si il est en dessous on revers rotate (rra) "		"
			
// ____________________________________________________
