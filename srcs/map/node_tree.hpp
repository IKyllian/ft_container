#ifndef NODE_TREE_HPP
#define NODE_TREE_HPP

#include <iostream>
#include <functional>
#include "utils.hpp"
#include "../iterators.hpp"
#include "../vector/vector_reverse_iterator.hpp"

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

			treeIterator(const Compare& comp = Compare()) : _comp(comp), current(nullptr) { };
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
		node(node *left, node *right, node *parent, int color, const Pair &pair = Pair()) : _left(left), _right(right), _parent(parent), _color(color), _pair(pair) {};

		node& operator=(const node& src) {
			_left = src._left;
			_right = src._right;
			_parent = src._parent;
			_color = src._color;
			_pair = src._pair;
		}
	};

	//Sert juste pour la fonctions qui print l'arbre
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
			typedef typename ft::vectorReverseIterator<iterator> reverse_iterator;
			typedef typename ft::vectorReverseIterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

			tree(value_compare comp, const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree_size(0), _root(nullptr) {};

			tree(const tree& src) : _alloc(src._alloc),  _comp(src._comp), _root(nullptr), _tree_size(0) { 
				*this = src;
			};

			~tree() {
				std::cout << "Tree Destructor" << std::endl;
				this->clear();
			};

			tree& operator=(const tree& src) {
				clear();
				_comp = src._comp;
				_tree_size = src._tree_size;
				tree_copy(src._root, this->_root, nullptr);
				// std::cout << "New Tree -----> Key = " << _root->_pair.first << " - Value = " << _root->_pair.second << std::endl;
				// !!!! Probleme avec la copie !!!!
				return (*this);
			};

			pointer get_parent(pointer n) { return (n->_parent); };
			pointer get_grandparent(pointer n) { 
				pointer p = get_parent(n);
				if (p == nullptr) // Noeud sans parent n'a pas de grand parent
					return (nullptr);
				return (get_parent(p));
			};
			pointer get_left(pointer n) { return (n->_left); };
			pointer get_right(pointer n) { return (n->_right); };
			pointer get_brother(pointer n) {
				pointer p = get_parent(n);
				if (p == nullptr)
					return (nullptr);
				if (n == p->_left)
					return (p->_right);
				return (p->_left);
			};
			pointer get_oncle(pointer n) {
				pointer p = get_parent(n);
				pointer g = get_grandparent(n);
				if (g == nullptr) // Noeud sans grand parent n'a pas d'oncle
					return (nullptr);
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
				if (y->_left != nullptr)
					y->_left->_parent = x;
				// -------------------

				// -------- 2 --------
				y->_parent = x->_parent;
				if (x->_parent == nullptr)
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
				if (y->_right != nullptr)
					y->_right->_parent = x;
				// -------------------

				// -------- 2 --------
				y->_parent = x->_parent;
				if (x->_parent == nullptr)
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
						3.1 : Si la couleur de l'oncle est rouge, alors, le pere et l'oncle du nouveau noeud sont coloriés en noir
							et le grand parent (qui est logiquement noir de base) est colorié en rouge.
							Toutefois, ces modifications ont pu crées de nouvelles violations des regles, il faut donc 
							reappeler la fonction (insert_repare()) pour refaire les checks necessaires.
						3.2 : Si la couleur de l'oncle est noir il faut effectuer des rotations (droite ou gauche en fontion de la configuration du noeud inseré)
							afin de rétablir l'équilibre dans l'arbre.
					
					Source + Schéma : https://fr.wikipedia.org/wiki/Arbre_bicolore#:~:text=Un%20arbre%20bicolore%20est%20un%20arbre%20binaire%20de%20recherche%20dans,est%20soit%20rouge%20soit%20noire.&text=Le%20chemin%20de%20la%20racine,n%C5%93uds%20noirs%20la%20hauteur%20noire 
				*/
				if (n->_parent == nullptr)
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

			pointer _insert(pointer &root, pointer n) {
			// 	/*
			// 		Regles a respecté pour un arbre binaire rouge et noir.

			// 		Un nœud est soit rouge soit noir ;
			// 		La racine est noire ;
			// 		Les enfants d'un nœud rouge sont noirs;
			// 		Tous les nœuds ont 2 enfants. Ce sont d'autres nœuds ou des feuilles (NULL), qui ne possèdent pas de valeur et qui sont les seuls nœuds sans enfants. Leur couleur est toujours noire et rentre donc en compte lors du calcul de la hauteur noire.
			// 		Le chemin de la racine à n'importe quelle feuille (NULL) contient le même nombre de nœuds noirs. On peut appeler ce nombre de nœuds noirs la hauteur noire

			// 	*/

				insert_node(root, n);
				insert_repare(n);
				printTree(_root,nullptr, false);
				_tree_size++;
				return (_root);
			};

			void replace_node(pointer n, pointer node_to_swap) {
					// Change le parent de n (n qui est la valeur a delete)
				
					if (n->_parent) {
						if (n->_parent->_right == n)
							n->_parent->_right = node_to_swap;
						else
							n->_parent->_left = node_to_swap;
					}
					
					// si le parent du noeud a swap n'est pas le noeud a delete alors on met son enfant gauche a null car il va etre deplacé
					// A Revoir
					if (node_to_swap->_parent != n)
						node_to_swap->_parent->_left = nullptr;
					
					// remplace les freres du noeud a swap par les freres du noeud a delete avant de le swap
					// if (n->_left != node_to_swap)
					node_to_swap->_left = n->_left;
					// else
					// 	node_to_swap->_left = nullptr;

					if (n->_right != node_to_swap)
						node_to_swap->_right = n->_right;
					else if (n->_right == node_to_swap && node_to_swap->_right == nullptr)
						node_to_swap->_right = nullptr;

					// remplace le parent du noeud a swap par le parent du noeud a delete avant de le swap
					node_to_swap->_parent = n->_parent;
					
					
					// remplace le parent du frere gauche du noeud a delete si il est non null 
					if (n->_left && n->_left != node_to_swap)
						n->_left->_parent = node_to_swap;

					if (n->_right && n->_right != node_to_swap)
						n->_right->_parent = node_to_swap;
		
					// delete_node(n);

					n = node_to_swap;

					// std::cout << " n = " << n->_pair.first << std::endl;
					// std::cout << " n Parent = " << n->_parent->_pair.first << std::endl;
					// if (n->_left)
					// 	std::cout << "n Left Non NULL " << n->_left->_pair.first << std::endl;
					// else
					// 	std::cout << "n Left NULL" << std::endl;

					// if (n->_right)
					// 	std::cout << "n Right Non NULL " << n->_right->_pair.first << std::endl;
					// else
					// 	std::cout << "n Right NULL" << std::endl;

					if (n->_parent == nullptr)
						_root = n;
			}

			void swap_node(pointer n, pointer node_to_swap) {
				pointer tmp = n;
				int qw = n->_right == node_to_swap ? 1 : 0;

				if (n->_parent) {
					if (n->_parent->_left == n)
						n->_parent->_left = node_to_swap;
					else
						n->_parent->_right = node_to_swap;
				}
				if (node_to_swap->_right)
					node_to_swap->_right->_parent = n;
				

				pointer p_n = n->_parent;
				pointer l_n = n->_left;
				pointer r_n = n->_right;
				int color_n = n->_color;

				pointer p_s = node_to_swap->_parent;
				pointer l_s = node_to_swap->_left;
				pointer r_s = node_to_swap->_right;
				int color_s = node_to_swap->_color;

				if (!qw)
					tmp->_parent = node_to_swap->_parent;

				n = node_to_swap;

				n->_color = color_n;

				n->_parent = p_n;
				n->_left = l_n;

				//
				if (qw)
					n->_right = tmp;
				else
					n->_right = r_n;

				node_to_swap = tmp;

				node_to_swap->_color = color_s;

				//
				if (qw)
					node_to_swap->_parent = n;
				else {
					node_to_swap->_parent = p_s;
				}


				node_to_swap->_left = l_s;
				node_to_swap->_right = r_s;

					

				std::cout << "N = " << n->_pair.first << std::endl;
				if (n->_parent)
					std::cout << "N Parent = " << n->_parent->_pair.first << std::endl;
				else
					std::cout << "N Racine" << std::endl;
				if (n->_left)
					std::cout << "N Left = " << n->_left->_pair.first << std::endl;
				else
					std::cout << "N Left NULL " << std::endl;
				if (n->_right)
					std::cout << "N Right = " << n->_right->_pair.first << std::endl;
				else
					std::cout << "N Right NULL " << std::endl;

				std::cout << std::endl;

				std::cout << "Node to swap = " << node_to_swap->_pair.first << std::endl;
				if (node_to_swap->_parent)
					std::cout << "Node to swap Parent = " << node_to_swap->_parent->_pair.first << std::endl;
				else
					std::cout << "Node to swap Racine" << std::endl;
				if (node_to_swap->_left)
					std::cout << "Node to swap Left = " << node_to_swap->_left->_pair.first << std::endl;
				else
					std::cout << "Node to swap Left NULL " << std::endl;
				if (node_to_swap->_right)
					std::cout << "Node to swap Right = " << node_to_swap->_right->_pair.first << std::endl;
				else
					std::cout << "Node to swap Right NULL " << std::endl;


				if (n->_parent == nullptr)
					_root = n;
			}

			pointer search_replace(pointer n) {
				if (n->_left == nullptr && n->_right == nullptr)
					return (nullptr);
				else if (n->_left != nullptr && n->_right != nullptr)
					return (min_element(n->_right));
				if (n->_left)
					return (n->_left);
				else
					return (n->_right);
			}

			void double_black_repare(pointer n) {
				if (n == _root)
					return ;
				pointer brother = get_brother(n);
				std::cout << "Brother = " << brother->_pair.first << std::endl;
				pointer parent = get_parent(n);
				if (brother == nullptr)
					double_black_repare(parent);
				else if (brother->_color == ROUGE) {
					parent->_color = ROUGE;
					brother->_color = NOIR;
					if (brother->_parent->_right == brother)
						left_rotation(parent);
					else 
						right_rotation(parent);
					double_black_repare(n);
				} else if (brother->_color == NOIR) {
					if ((brother->_left && brother->_left->_color == ROUGE)
						|| (brother->_right && brother->_right->_color == ROUGE)) {
								std::cout << brother->_pair.first << brother->_parent->_pair.first  << std::endl;
								std::cout << "TEST3" << std::endl;
						if (brother->_parent->_left == brother) {
							
								std::cout << "TEST3" << std::endl;
							if (brother->_left && brother->_left->_color == ROUGE) {
								// Left Left
								brother->_left->_color = brother->_color;
								brother->_color = parent->_color;
								right_rotation(parent);
							}
							else {
								// Left Right
								brother->_right->_color = parent->_color;
								left_rotation(brother);
								right_rotation(parent);
							}
						} else {

								std::cout << "TEST3" << std::endl;
							if (brother->_right && brother->_right->_color == ROUGE) {

								//Right Right
								brother->_right->_color = brother->_color;
								brother->_color = parent->_color;
								left_rotation(parent);
							} else {
								// Right Left
								brother->_left->_color = parent->_color;
								right_rotation(brother);
								left_rotation(parent);
							}
						}
					} else {
						brother->_color = ROUGE;
						if (parent->_color == NOIR)
							double_black_repare(parent);
						else
							parent->_color = NOIR;
					}
				}
			}


			void _erase(pointer n) {
				// std::cout << "Val n = "<< n->_pair.first << "N Parent = " << n->_parent->_pair.first << "N Color = " << n->_parent->_color << std::endl;
				std::cout << "Val n = "<< n->_pair.first << std::endl;
				pointer u = search_replace(n);
				bool doubleBlack = ((u == nullptr || u->_color == NOIR) && n->_color == NOIR);
				pointer parent = n->_parent;

				if (u == nullptr) {
					std::cout << "TEST" << _root->_pair.first << n->_pair.first << std::endl;
					if (n == _root) {
						_root = nullptr;
					} else {
						if (doubleBlack) {
							
							double_black_repare(n);
						}
						else {
							if (get_brother(n) != nullptr)
								get_brother(n)->_color = ROUGE;
						}
						if (n == n->_parent->_left)
							n->_parent->_left = nullptr;
						else
							n->_parent->_right = nullptr;
					}
					delete_node(n);
					// printTree(_root,nullptr, false);
					return ;
				}
				if (n->_left == NULL || n->_right == NULL) {
					if (n == _root)
						replace_node(n, u);
					else {
						if (n->_parent->_left == n)
							n->_parent->_left = u;
						else
							n->_parent->_right = u;
					}
					delete_node(n);
					u->_parent = parent;
					if (doubleBlack)
						double_black_repare(n);
					else
						u->_color = NOIR;
						return ;
				}
				swap_node(n, u);
				_erase(n);
				printTree(_root,nullptr, false);
			}

			// void _erase(pointer n) {
			// 	pointer u = search_replace(n);
			// 	bool doubleBlack = ((u == nullptr || u->_color == NOIR) && n->_color == NOIR);

			// 	if (u == nullptr) {
			// 		if (n == _root)
			// 			_root = nullptr;
			// 		else {
			// 			if (doubleBlack)
			// 				double_black_repare(n);
			// 			else {
			// 				if (get_brother(n) != nullptr)
			// 					get_brother(n)->_color = ROUGE;
			// 			}
			// 			if (n == n->_parent->_left)
			// 				n->_parent->_left = nullptr;
			// 			else
			// 				n->_parent->_right = nullptr;
			// 		}
			// 		delete_node(n);
			// 		printTree(_root,nullptr, false);
			// 		return ;
			// 	} else {
			// 		replace_node(n, u);
			// 		if (doubleBlack)
			// 			double_black_repare(n);
			// 		else
			// 			u->_color = NOIR;
			// 	}
			// 	printTree(_root,nullptr, false);
			// }

			// Functions for map container

			iterator begin() { return (iterator(min_element(_root), _comp)); };
			const_iterator begin() const { return (const_iterator(min_element(_root), _comp)); };

			iterator end() { return (++(iterator(max_element(_root), _comp))); };
			const_iterator end() const { return (const_iterator(max_element(_root, _comp))); };

			reverse_iterator rbegin() { return (reverse_iterator(--(end()))); };
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(--(end()))); };

			reverse_iterator rend() { return (reverse_iterator(--(begin()))); };
			const_reverse_iterator rend() const { return (const_reverse_iterator(--(begin()))); };
			

			bool empty() const { return (!_root ? true : false); };
			size_type size() const { return (_tree_size); };

			pair<iterator,bool> insert(const value_type& val) {
				pointer search = search_node(_root, val);
				if (search != nullptr)
					return (ft::make_pair(iterator(search, _comp), false));

				pointer node = _alloc.allocate(1);
				_alloc.construct(node, val);
				_root = _insert(_root, node);			

				return (ft::make_pair(iterator(node, _comp), true));

			};

			iterator insert (iterator position, const value_type& val) {
				// if (position.base() && _comp(position.base()->_pair, val))
				// {
				// 	pointer search = search_node(_root, val);
				// 	if (search != nullptr)
				// 		return (iterator(search, _comp));

				// 	pointer node = _alloc.allocate(1);
				// 	pointer from = position.base();
				// 	_alloc.construct(node, val);
				// 	_root = _insert(from, node);		

				// 	return (iterator(node, _comp));
				// }
				// else
					return (insert(val).first);
			};

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; first++)
					insert(first->_pair);
			};

			size_type erase(const value_type& k) {
				pointer node = search_node(_root, k);
				if (node == nullptr)
					return (0);
				else{
					_erase(node);
					return (1);
				}
			};

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

			pair<iterator,iterator>	equal_range(value_type k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

			void clear() {
				_clear_tree(_root);
				_root = nullptr;
				_tree_size = 0;
			};

			void swap (tree & x) {
				pointer root = x._root;
				size_type size = x._tree_size;

				x._tree_size = this->_tree_size;
				x._root = this->_root;

				this->_tree_size = size;
				this->_root = root;
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
				// if (node)
				// 	std::cout << "Clear Tree node = " << node->_pair.first << std::endl;
				// else
		 		// 	std::cout << "Clear Tree node = " << std::endl;
				if (node == nullptr)
					return ;
				_clear_tree(node->_left);
				_clear_tree(node->_right);
				delete_node(node);
			}

			void tree_copy(pointer cpy_from, pointer &cpy_to, pointer parent) {
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

			void showTrunks(Trunk *p)
			{
				if (p == nullptr)
					return;
				showTrunks(p->prev);
				std::cout << p->str;
			}
			
			void printTree(pointer root, Trunk *prev, bool isLeft)
			{
				if (root == nullptr)
					return;
				std::string prev_str = "    ";
				Trunk *trunk = new Trunk(prev, prev_str);
			
				printTree(root->_right, trunk, true);
			
				if (!prev)
					trunk->str = "———";
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
	};
}
#endif