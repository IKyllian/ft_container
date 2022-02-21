#ifndef NODE_TREE_HPP
#define NODE_TREE_HPP

#include <iostream>
#include <functional>
#include "utils.hpp"
#include "../iterators.hpp"

#define NOIR 0
#define ROUGE 1

namespace ft
{
	template <class Tree, class Node>
	class mapIterator {
		public :

			typedef typename ft::iterator_traits<Node>::value_type value_type;
			typedef typename ft::iterator_traits<Node>::pointer pointer;
			typedef typename ft::iterator_traits<Node>::reference reference;
			typedef typename ft::iterator_traits<Node>::difference_type difference_type;
			typedef ft::bidirectional_iterator_tag iterator_category;

			mapIterator(){ };
			mapIterator(pointer ptr) : current(ptr) {};
			mapIterator(const mapIterator &src){ *this = src; };
			~mapIterator() {};

			mapIterator &operator=(const mapIterator& src) {
				current = src.current;
				return (*this);
			};
			
			// ---------Bool--------
			bool operator==(const mapIterator& src) const { return (current == src.current); };
			bool operator!=(const mapIterator& src) const { return (current != src.current); };
			bool operator<(const mapIterator& src) const { return (current < src.current); };
			bool operator<=(const mapIterator& src) const { return (current <= src.current); };
			bool operator>(const mapIterator& src) const { return (current > src.current); };
			bool operator>=(const mapIterator& src) const { return (current >= src.current); };

			// ---------Increment/Decrement---------
			mapIterator &operator++(void) {
				current++;
				return (*this);
			}
			mapIterator operator++(int) {
				mapIterator tmp = *this;
				current++;
				return (tmp);
			}
			mapIterator &operator--(void) {
				current--;
				return (*this);
			}
			mapIterator operator--(int) {
				mapIterator tmp = *this;
				current--;
				return (tmp);
			}
			
			// -----------Dereferencing/Address----------
			pointer operator ->() const { return (current); };		
			reference operator *() const { return (*current); };

		private :
			Node current;
	};

	template <class Pair>
	struct node {
		node	*_left;
		node	*_right;
		node	*_parent;
		int		_color;
		Pair	_pair;

		node(const Pair &pair = Pair()) : _left(NULL), _right(NULL), _parent(NULL), _color(ROUGE), _pair(pair) {};
	};

	template <class Pair, class Compare, class Alloc = std::allocator<ft::node<Pair> > >
	class tree
	{
		public :

			typedef Pair value_type;
			typedef Compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

			tree(value_compare comp, const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree_size(0), _root(nullptr) {};

			tree(const tree& src) : _alloc(src._alloc),  _comp(src._comp), _root(nullptr), _tree_size(0) { 
				*this = src;
			};

			tree& operator=(const tree& src) {
				std::cout << "operator=() tree" << std::endl;
				clear();
				_comp = src._comp;
				_tree_size = src._tree_size;
				tree_copy(src._root, _root, nullptr);
				// std::cout << "New Tree -----> Key = " << _root->_pair.first << " - Value = " << _root->_pair.second << std::endl;
				// !!!! Probleme avec la copie !!!!
				return (*this);
			};

			~tree() {
				this->clear();
			};

			pointer get_parent(pointer n) { return (n->_parent); };
			pointer get_grandparent(pointer n) { 
				pointer p = n->get_parent();
				if (p == NULL) // Noeud sans parent n'a pas de grand parent
					return (NULL);
				return (p->get_parent());
			};
			pointer get_left(pointer n) { return (n->_left); };
			pointer get_right(pointer n) { return (n->_right); };
			// pointer get_brother(pointer n) {
			// 	pointer p = n->get_parent();
			// 	if (p == NULL) // Noeud sans parent n'a pas de frere
			// 		return (NULL);
			// 	if (n == p->_left)
			// 		return (p->_right);
			// 	return (p->left);
			// };
			pointer get_oncle(pointer n) {
				pointer p = n->get_parent();
				pointer g = n->get_grandparent();
				if (g == NULL) // Noeud sans grand parent n'a pas d'oncle
					return (NULL);
				return (p->get_brother());
			};

			void left_rotation(pointer x) {
				pointer y = x->_right;

				// -------- 1 --------
				x->_right = y->_left;
				if (y->_left != NULL)
					y->_left->_parent = x;
				// -------------------

				// -------- 2 --------
				y->_parent = x->_parent;
				if (x->_parent == NULL)
					x = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				// -------------------

				// -------- 3 --------
				y->_left = x;
				x->parent = y;
				// -------------------
			}

			void right_rotation(pointer x) {
				pointer y = x->_left;

				// -------- 1 --------
				x->_left = y->_right;
				if (y->_right != NULL)
					y->_right->_parent = x;
				// -------------------

				// -------- 2 --------
				y->_parent = x->_parent;
				if (x->_parent == NULL)
					x = y;
				else if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
				// -------------------

				// -------- 3 --------
				y->_right = x;
				x->parent = y;
				// -------------------
			}

			// pointer search_node(Key key) {
			// 	pointer tmp = this;

			// 	while (tmp != NULL)
			// 	{
			// 		if (tmp->_pair == key)
			// 			return (tmp);
			// 		if (key > tmp->_pair)
			// 			tmp = tmp->_right;
			// 		else
			// 			tmp = tmp->_left;
			// 	}
			// 	return (NULL);
			// };

			pointer get_root() { return (this); };

			void insert_repare(pointer n)
			{
				/*
					Une fois qu'on ajoute un noeud il faut check si toutes les regles sont encore respectés
					Differents cas possible lors d'une insertion.

					Cas 1 : Si le parent du nouveau noeud est NULL c'est que celui ci est la racine
						-> Juste mettre la couleur du noeud en noir
					Cas 2 : Si la couleur du parent est noir les proprietés sont toujours respectés donc rien a faire

					Cas 3 : Si la couleur du parent est rouge il y a deux cas possible
						3.1 : Si la couleur de l'oncle est rouge, alors, le pere et l'oncle du nouveau sont colorié en noir
							et le grand parent (qui est logiquement noir de base) et colorié en rouge.
							Toutefois, ces modification ont pu crées de nouvelles violations des regles, il faut donc 
							reappeler la fonction (insert_repare()) pour refaire les check necessaire.
						3.2 : Si la couleur de l'oncle est noir il faut effectuer des rotations (droite ou gauche en fontion de la configuration du noeud inseré)
							afin de rétablir l'équilibre dans l'arbre.
					
					Source + Schéma : https://fr.wikipedia.org/wiki/Arbre_bicolore#:~:text=Un%20arbre%20bicolore%20est%20un%20arbre%20binaire%20de%20recherche%20dans,est%20soit%20rouge%20soit%20noire.&text=Le%20chemin%20de%20la%20racine,n%C5%93uds%20noirs%20la%20hauteur%20noire 
				*/
				if (n->parent() == NULL)
					n->_color = NOIR;
				else if (parent(n)->couleur == NOIR)
					return ;
				else if (n->get_oncle()->_color == ROUGE) {
					n->get_parent()->_color = NOIR;
					n->get_oncle()->_color = NOIR;

					pointer g = n->get_grandparent();
					g->_color = ROUGE;
					g.insert_repare();
				}
				else {
					pointer p = n->get_parent();
					pointer g = n->get_grandparent();

					if (n == g->_left->_right) {
						n->left_rotation();
						n = n->_left;
					}
					else if (n == g->_right->_left) {
						n->right_rotation();
						n = n->_right;
					}

					pointer p2 = n->get_parent();
					pointer g2 = n->get_grandparent();
					
					if (n == p2->_left)
						n->right_rotation();
					else
						n->left_rotation();
					
					p2->_color = NOIR;
					g2->_color = ROUGE;
					
				}
			}

			void insert_node(pointer new_node) {
			// 	/*
			// 		Regles a respecté pour un arbre binaire rouge et noir.

			// 		Un nœud est soit rouge soit noir ;
			// 		La racine est noire ;
			// 		Les enfants d'un nœud rouge sont noirs;
			// 		Tous les nœuds ont 2 enfants. Ce sont d'autres nœuds ou des feuilles (NULL), qui ne possèdent pas de valeur et qui sont les seuls nœuds sans enfants. Leur couleur est toujours noire et rentre donc en compte lors du calcul de la hauteur noire.
			// 		Le chemin de la racine à n'importe quelle feuille (NULL) contient le même nombre de nœuds noirs. On peut appeler ce nombre de nœuds noirs la hauteur noire

			// 	*/

				if (!_root)
				{
					_root = new_node;
					_root->_parent = NULL;
					_root->_right = NULL;
					_root->_left = NULL;
					_root->_color = ROUGE;
				}
			// 	while (this != NULL)
			// 	{
			// 		if (new_node->_pair > this->_pair) {
			// 			if (this->_right != NULL)
			// 				this = this->_right;
			// 			else {
			// 				this->_right = new_node;
			// 				break ;
			// 			}
			// 		}
			// 		else {
			// 			if (this->_left != NULL)
			// 				this = this->_left;
			// 			else {
			// 				this->_left = new_node;
			// 				break ;
			// 			}
			// 		}
			// 	}
				// new_node->parent = this;
				// new_node->_right = NULL;
				// new_node->_left = NULL;
				// new_node->_color = ROUGE;

			// 	// Equilibrer arbre si il le faut
			// 	new_node->insert_repare();
				
			// 	while (this->parent() != NULL)
			// 		this = this->parent();
			// 	// Return la racine
			};

			// pointer search_node_to_swap() {
			// 	pointer tmp = this;
			// 	Key key_to_swap = this->_pair;

			// 	// Faire un check sur la longueur du sous arbre gauche et droit pour savoir dans quel sous arbre delete le noeud

			// 	this = this->_right;
			// 	while (this->_left->_left != NULL)
			// 		this = this->_left;
			// 	tmp->_pair = this->_pair;
			// 	this->_pair = key_to_swap;
			// 	return (this);
			// }

			// void delete_node(pointer to_delete) {
			// 	/*
			// 		Pour commencé on recherche le noeud a supprimé dans l'arbre.
			// 		Pour pouvoir supprimé le noeud correctement il faut que celui-ci ait au plus un enfant qui ne soit pas une feuille (noeud NULL).
			// 		Si le noeud contient deux enfants qui ne sont pas des feuilles il faut recherché soit le successeur le plus proche (le noeud le plus a gauche du sous arbre droit)
			// 		ou le predecesseur le plus proche (le noeud le plus a droite du sous arbre gauche)

			// 	*/

			// 	pointer racine = this;
			// 	while (this->_pair != to_delete->_pair) {
			// 		if (to_delete->_pair > this->_pair) {
			// 			if (this->_right == NULL)
			// 				return (NULL);
			// 			this = this->_right;
			// 		}
			// 		else {
			// 			if (this->_left == NULL)
			// 				return (NULL);
			// 			this = this->_left;
			// 		}
			// 	}
			// 	if (this->_left != NULL && this->_right != NULL)
			// 		this = search_node_to_swap();

			// 	if (this->_left == NULL) {
			// 		if (this == this->_parent->_right) {
			// 			this->_parent->_right = this->_right;
			// 			this->_right->_parent = this->_parent;
			// 		} else {
			// 			this->_parent->_left = this->_right;
			// 			this->_right->_parent = this->_parent;
			// 		}
			// 		_alloc.destroy(this);
			// 	}
			// 	else {
			// 		if (this == this->_parent->_right) {
			// 			this->_parent->_right = this->_left;
			// 			this->_right->_parent = this->_parent;
			// 		} else {
			// 			this->_parent->_left = this->_left;
			// 			this->_left->_parent = this->_parent;
			// 		}
			// 		_alloc.destroy(this);
			// 	}
			// }

			// Functions for map container


			bool empty() const { return (!_root ? true : false);};
			size_type size() const { return (_tree_size); };

			void clear() {
				_clear_tree(_root);
				_root = nullptr;
				_tree_size = 0;
			};

			void insert (const value_type& val) {
				pointer node = _alloc.allocate(1);

				_alloc.construct(node, val);
				insert_node(node);

				std::cout << "Key = " << _root->_pair.first << " - Value = " << _root->_pair.second << std::endl;
			};


		private :
			pointer			 _root;
			value_compare	_comp;
			allocator_type	_alloc;
			size_type		_tree_size;

			void delete_node(pointer node) {
				_alloc.destroy(node);
				_alloc.deallocate(node, sizeof(value_type));
			};

			void _clear_tree(pointer node) {
				if (node == NULL)
					return ;
				_clear_tree(node->_left);
				_clear_tree(node->_right);
				delete_node(node);
			}

			void tree_copy(pointer cpy_from, pointer cpy_to, pointer parent) {
				// std::cout << "TEST" << std::endl;
				if (!cpy_from)
					return ;
				cpy_to = _alloc.allocate(1);
				_alloc.construct(cpy_to, *cpy_from);
				cpy_to->_parent = parent;
				tree_copy(cpy_from->_left, cpy_to->_left, cpy_to);
				tree_copy(cpy_from->_right, cpy_to->_right, cpy_to);
			};
	};
}
#endif