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
	template <class Node, class Compare>
	class treeIterator {
		public :
			typedef typename ft::iterator_traits<Node>::value_type value_type;
			typedef typename ft::iterator_traits<Node>::pointer pointer;
			typedef typename ft::iterator_traits<Node>::reference reference;
			typedef typename ft::iterator_traits<Node>::difference_type difference_type;
			typedef ft::bidirectional_iterator_tag iterator_category;

			treeIterator(){ };
			treeIterator(pointer ptr, const Compare& comp = Compare()) : current(ptr), _comp(comp) {};
			treeIterator(const treeIterator &src) : current(src.current), _comp(src._comp) {};
			~treeIterator() {};

			treeIterator &operator=(const treeIterator& src) {
				current = src.current;
				return (*this);
			};

			// ---------Increment/Decrement---------
			treeIterator &operator++(void) {
				if (current == NULL)
					return (*this);
				if (current->_right != NULL) {
					current = current->_right;
					while (current->_left)
						current = current->_left;
				}
				else {
					while (current->_parent != NULL && current == current->_parent->_right)
						current = current->_parent;
					current = current->_parent;
				}
				return (*this);
			}
			treeIterator operator++(int) {
				treeIterator tmp = *this;
				operator++();
				return (tmp);
			}
			treeIterator &operator--(void) {
				if (current == NULL)
					return (*this);
				if (current->_left != NULL) {
					current = current->_left;
					while (current->_right)
						current = current->_right;
				}
				else {
					while (current->_parent != NULL && current == current->_parent->_left)
						current = current->_parent;
					current = current->_parent;
				}
				return (*this);
			}
			treeIterator operator--(int) {
				treeIterator tmp = *this;
				operator--();
				return (tmp);
			}
			
			// -----------Dereferencing/Address----------
			pointer operator ->() const { return (current); };		
			reference operator *() const { return (*current); };
			Node base() const { return (current); };

		private :
			Node current;
			Compare _comp;
	};

	template <class Node, class Compare>
	bool operator==(const ft::treeIterator<Node, Compare>& lhs, const ft::treeIterator<Node, Compare>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Node, class Compare>
	bool operator!=(const ft::treeIterator<Node, Compare>& lhs, const ft::treeIterator<Node, Compare>& rhs) { return (lhs.base() != rhs.base()); };

	template <class Pair>
	struct node {
		node	*_left;
		node	*_right;
		node	*_parent;
		int		_color;
		Pair	_pair;

		node(const Pair &pair = Pair()) : _left(nullptr), _right(nullptr), _parent(nullptr), _color(ROUGE), _pair(pair) {};

		node& operator=(const node& src) {
			_left = src._left;
			_right = src._right;
			_parent = src._parent;
			_color = src._color;
			_pair = src._pair;
		}
	};

	struct Trunk
	{
		Trunk *prev;
		std::string str;
	
		Trunk(Trunk *prev, std::string str)
		{
			this->prev = prev;
			this->str = str;
		}
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
			typedef typename ft::treeIterator<pointer, value_compare> iterator;
			typedef typename ft::treeIterator<const pointer, value_compare> const_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

			tree(value_compare comp, const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree_size(0), _root(nullptr) {};

			tree(const tree& src) : _alloc(src._alloc),  _comp(src._comp), _root(nullptr), _tree_size(0) { 
				*this = src;
			};

			void showTrunks(Trunk *p)
			{
				if (p == nullptr) {
					return;
				}
			
				showTrunks(p->prev);
				std::cout << p->str;
			}
			
			void printTree(pointer root, Trunk *prev, bool isLeft)
			{
				if (root == nullptr) {
					return;
				}
			
				std::string prev_str = "    ";
				Trunk *trunk = new Trunk(prev, prev_str);
			
				printTree(root->_right, trunk, true);
			
				if (!prev) {
					trunk->str = "———";
				}
				else if (isLeft)
				{
					trunk->str = ".———";
					prev_str = "   |";
				}
				else {
					trunk->str = "`———";
					prev->str = prev_str;
				}
			
				showTrunks(trunk);
				if (root->_color == ROUGE)
					std::cout << " " << root->_pair.first << "(R)" << std::endl;
				else
					std::cout << " " << root->_pair.first << "(N)" << std::endl;
				if (prev) {
					prev->str = prev_str;
				}
				trunk->str = "   |";
			
				printTree(root->_left, trunk, false);
			}

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
				pointer p = get_parent(n);
				if (p == NULL) // Noeud sans parent n'a pas de grand parent
					return (NULL);
				return (get_parent(p));
			};
			pointer get_left(pointer n) { return (n->_left); };
			pointer get_right(pointer n) { return (n->_right); };
			pointer get_brother(pointer n) {
				pointer p = get_parent(n);
				if (p == NULL)
					return (NULL);
				if (n == p->_left)
					return (p->_right);
				return (p->_left);
			};
			pointer get_oncle(pointer n) {
				pointer p = get_parent(n);
				pointer g = get_grandparent(n);
				if (g == NULL) // Noeud sans grand parent n'a pas d'oncle
					return (NULL);
				return (get_brother(p));
			};

			pointer get_root() { return (_root); };

			pointer search_node(pointer root, value_type to_search) const {
				if (!root)
					return (nullptr);
				if (_comp(to_search, root->_pair))
					return (search_node(root->_left, to_search));
				else if (_comp(root->_pair, to_search))
					return (search_node(root->_right, to_search));
				else
					return (root);
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
					_root = y;
				else if (x->_parent && x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				// -------------------

				// -------- 3 --------
				y->_left = x;
				x->_parent = y;
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
					_root = y;
				else if (x->_parent && x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
				// -------------------

				// -------- 3 --------
				y->_right = x;
				x->_parent = y;
				// -------------------
			}

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
				if (n->_parent == NULL)
					n->_color = NOIR;
				else if (get_parent(n)->_color == NOIR)
					return ;
				else if (get_oncle(n) && get_oncle(n)->_color == ROUGE) {
					get_parent(n)->_color = NOIR;
					get_oncle(n)->_color = NOIR;
					pointer g = get_grandparent(n);
					g->_color = ROUGE;
					insert_repare(g);
				}
				else {
					pointer p = get_parent(n);
					pointer g = get_grandparent(n);

					if (g->_left && n == g->_left->_right) {
						left_rotation(p);
						n = n->_left;
					}
					else if (g->_right && n == g->_right->_left) {
						right_rotation(p);
						n = n->_right;
					}
					pointer p2 = get_parent(n);
					pointer g2 = get_grandparent(n);
					
					if (n == p2->_left)
						right_rotation(g2);
					else
						left_rotation(g2);
					
					p2->_color = NOIR;
					g2->_color = ROUGE;	
				}
			}

			void insert_node(pointer &racine, pointer n) {
				if (!racine) {
					_root = n;
					return ;
				}
				if (racine != nullptr && _comp(n->_pair, racine->_pair)) {
					if (racine->_left != nullptr) {
						insert_node(racine->_left, n);
						return;
					}
					else {
						racine->_left = n;
						racine->_left->_parent = racine;
					}
				} 
				else if (racine != nullptr) {
					if (racine->_right != nullptr) {
						insert_node(racine->_right, n);
						return;
					}
					else {
						racine->_right = n;
						racine->_right->_parent = racine;
					}
				}
			}

			pointer _insert(pointer n) {
			// 	/*
			// 		Regles a respecté pour un arbre binaire rouge et noir.

			// 		Un nœud est soit rouge soit noir ;
			// 		La racine est noire ;
			// 		Les enfants d'un nœud rouge sont noirs;
			// 		Tous les nœuds ont 2 enfants. Ce sont d'autres nœuds ou des feuilles (NULL), qui ne possèdent pas de valeur et qui sont les seuls nœuds sans enfants. Leur couleur est toujours noire et rentre donc en compte lors du calcul de la hauteur noire.
			// 		Le chemin de la racine à n'importe quelle feuille (NULL) contient le même nombre de nœuds noirs. On peut appeler ce nombre de nœuds noirs la hauteur noire

			// 	*/

				insert_node(_root, n);
				insert_repare(n);
				printTree(_root,nullptr, false);
				return (_root);
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

			iterator begin() { return (iterator(min_element(_root), _comp)); };
			const_iterator begin() const { return (const_iterator(min_element(_root), _comp)); };

			iterator end() { return (iterator(max_element(_root), _comp)); };
			const_iterator end() const { return (const_iterator(max_element(_root, _comp))); };

			bool empty() const { return (!_root ? true : false); };
			size_type size() const { return (_tree_size); };


			iterator find (value_type k) {
				pointer result = search_node(_root, k);
				if (result == nullptr)
					return (end());
				return (iterator(result, _comp));
			};

			size_type count(value_type k) const {
				if (search_node(_root, k) != nullptr)
					return (1);
				return (0);
			};

			iterator lower_bound(value_type k) {
				iterator it = begin();
				for (; it != end() && _comp((*it)._pair, k); it++) ;
				return (it);
			};

			iterator upper_bound(value_type k) {
				iterator it = begin();
				for (; it != end() && !(_comp(k, (*it)._pair)); it++) ;
				return (it);
			};

			void clear() {
				_clear_tree(_root);
				_root = nullptr;
				_tree_size = 0;
			};

			void insert (const value_type& val) {
				pointer node = _alloc.allocate(1);

				_alloc.construct(node, val);
				_root = _insert(node);

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
				if (!cpy_from)
					return ;
				cpy_to = _alloc.allocate(1);
				_alloc.construct(cpy_to, *cpy_from);
				cpy_to->_parent = parent;
				tree_copy(cpy_from->_left, cpy_to->_left, cpy_to);
				tree_copy(cpy_from->_right, cpy_to->_right, cpy_to);
			};

			pointer min_element(pointer node) {
				if (node == nullptr || node->_left == nullptr)
					return (node);
				return (min_element(node->_left));
			}

			pointer max_element(pointer node) {
				if (node == nullptr || node->_right == nullptr)
					return (node);
				return (max_element(node->_right));
			}

			pointer search_root(pointer n) { 
				while (n->_parent != NULL)
					n = n->_parent;
				return (n);
			};
	};
}
#endif