#ifndef NODE_TREE_HPP
#define NODE_TREE_HPP

#include <iostream>
#include <functional>
#include "../utils.hpp"
#include "../iterators.hpp"
#include "../vector/vector_reverse_iterator.hpp"

#define NOIR 0
#define ROUGE 1

namespace ft
{
	template <class Node, class Tree>
	class treeIterator {
		public :
			typedef typename ft::iterator_traits<Node>::value_type value_type;
			typedef typename ft::iterator_traits<Node>::pointer pointer;
			typedef typename ft::iterator_traits<Node>::reference reference;
			typedef typename ft::iterator_traits<Node>::difference_type difference_type;
			typedef ft::bidirectional_iterator_tag iterator_category;

			treeIterator() : current(nullptr) { };
			treeIterator(pointer ptr, Tree *tree) : current(ptr), tree(tree) {};
			template <class N, class T>
			treeIterator(const treeIterator<N, T> &src) : current(src.base()), tree(src.tree_base()) {};
			~treeIterator() {};

			treeIterator &operator=(const treeIterator& src) {
				current = src.base();
				tree = src.tree_base();
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
					while (current->_parent != NULL && current->_parent->_right == current)
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
				if (current == nullptr)
					current = tree->most_right(tree->get_root());
				else if (current->_left != nullptr) {
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
			pointer base() const { return (current); };
			Tree* tree_base() const { return (tree); };

		private :
			pointer current;
			Tree *tree;
	};

	template <class Node, class Tree>
	bool operator==(const ft::treeIterator<Node, Tree>& lhs, const ft::treeIterator<Node, Tree>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Node, class Tree>
	bool operator!=(const ft::treeIterator<Node, Tree>& lhs, const ft::treeIterator<Node, Tree>& rhs) { return (lhs.base() != rhs.base()); };

	template <class T>
	struct node {
		node	*_left;
		node	*_right;
		node	*_parent;
		int		_color;
		T		_value;

		node(const T &value = T()) : _left(nullptr), _right(nullptr), _parent(nullptr), _color(ROUGE), _value(value) {};
		node(node *left, node *right, node *parent, int color, const T &value = T()) : _left(left), _right(right), _parent(parent), _color(color), _value(value) {};

		node& operator=(const node& src) {
			_left = src._left;
			_right = src._right;
			_parent = src._parent;
			_color = src._color;
			_value = src._value;
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

	template <class T, class Compare, class Alloc = std::allocator<ft::node<T> > >
	class tree
	{
		public :

			typedef T value_type;
			typedef Compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::treeIterator<pointer, ft::tree<value_type, value_compare> > iterator;
			typedef typename ft::treeIterator<const_pointer, ft::tree<value_type, value_compare> > const_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

			tree(value_compare comp, const allocator_type& alloc = allocator_type()) : _root(nullptr), _comp(comp), _alloc(alloc), _tree_size(0) {};

			tree(const tree& src) : _root(nullptr), _comp(src._comp), _alloc(src._alloc), _tree_size(src._tree_size) { 
				tree_copy(src._root, this->_root, nullptr);
			};

			~tree() {
				this->clear();
			};

			tree& operator=(const tree& src) {
				clear();
				_comp = src._comp;
				_tree_size = src._tree_size;
				tree_copy(src._root, this->_root, nullptr);
				return (*this);
			};

			pointer get_parent(pointer n) { return (n->_parent); };
			pointer get_grandparent(pointer n) { 
				pointer p = get_parent(n);
				if (p == nullptr)
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
				if (g == nullptr)
					return (nullptr);
				return (get_brother(p));
			};

			pointer get_root() { return (_root); };

			pointer search_node(pointer root, value_type to_search) const {
				if (!root)
					return (nullptr);
				if (_comp(to_search, root->_value))
					return (search_node(root->_left, to_search));
				else if (_comp(root->_value, to_search))
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
				if (racine != nullptr && _comp(n->_value, racine->_value)) {
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
				// printTree(_root,nullptr, false);
				// std::cout << " ------------------ "  << std::endl;
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
					
					if (node_to_swap->_parent != n)
						node_to_swap->_parent->_left = nullptr;
					
					// remplace les freres du noeud a swap par les freres du noeud a delete avant de le swap
					node_to_swap->_left = n->_left;

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
		
					n = node_to_swap;

					if (n->_parent == nullptr)
						_root = n;
			}

			void swap_node(pointer n, pointer node_to_swap) {
				pointer tmp = n;
				int is_one_side = n->_right == node_to_swap ? 1 : 0;

				if (n->_parent) {
					if (n->_parent->_left == n)
						n->_parent->_left = node_to_swap;
					else
						n->_parent->_right = node_to_swap;
				}

				if (n->_right != node_to_swap)
     				n->_right->_parent = node_to_swap;
				if (n->_left)
					n->_left->_parent = node_to_swap;

				if (node_to_swap->_right)
					node_to_swap->_right->_parent = n;
				if (node_to_swap->_parent->_left == node_to_swap)
					node_to_swap->_parent->_left = n;
				else
					node_to_swap->_parent->_right = n;
				
				pointer p_n = n->_parent;
				pointer l_n = n->_left;
				pointer r_n = n->_right;
				int color_n = n->_color;

				pointer p_s = node_to_swap->_parent;
				pointer l_s = node_to_swap->_left;
				pointer r_s = node_to_swap->_right;
				int color_s = node_to_swap->_color;

				if (!is_one_side)
					tmp->_parent = node_to_swap->_parent;

				n = node_to_swap;

				n->_color = color_n;

				n->_parent = p_n;
				n->_left = l_n;

				if (is_one_side)
					n->_right = tmp;
				else
					n->_right = r_n;

				node_to_swap = tmp;

				node_to_swap->_color = color_s;

				if (is_one_side)
					node_to_swap->_parent = n;
				else
					node_to_swap->_parent = p_s;

				node_to_swap->_left = l_s;
				node_to_swap->_right = r_s;

				if (n->_parent == nullptr)
					_root = n;
			}

			pointer search_replace(pointer n) {
				if (n->_left == nullptr && n->_right == nullptr)
					return (nullptr);
				else if (n->_left != nullptr && n->_right != nullptr)
					return (most_left(n->_right));
				if (n->_left)
					return (n->_left);
				else
					return (n->_right);
			}

			void double_black_repare(pointer n) {
				if (n == _root)
					return ;
				pointer brother = get_brother(n);
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
						if (brother->_parent->_left == brother) {
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
						parent->_color = NOIR;
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
				pointer u = search_replace(n);
				bool doubleBlack = ((u == nullptr || u->_color == NOIR) && n->_color == NOIR);
				pointer parent = n->_parent;

				if (u == nullptr) {
					if (n == _root) {
						_root = nullptr;
					} else {
						if (doubleBlack)
							double_black_repare(n);
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
					// printTree(_root,nullptr, false);
					// std::cout << " ------------------ "  << std::endl;
					return ;
				}
				swap_node(n, u);
				_erase(n);
				// printTree(_root,nullptr, false);
				// std::cout << " ------------------ "  << std::endl;
			}

			// Functions for map container

			iterator begin() { return (iterator(most_left(_root), this)); };
			const_iterator begin() const { return (const_iterator(most_left(_root), this)); };

			iterator end() { return ((iterator(nullptr, this))); };
			const_iterator end() const { return (const_iterator(nullptr, this)); };			

			bool empty() const { return (!_root ? true : false); };
			size_type size() const { return (_tree_size); };

			pair<iterator,bool> insert(const value_type& val) {
				pointer search = search_node(_root, val);
				if (search != nullptr)
					return (ft::make_pair(iterator(search, this), false));
				pointer node = _alloc.allocate(1);
				_alloc.construct(node, val);
				_root = _insert(_root, node);			
				return (ft::make_pair(iterator(node, this), true));
			};

			iterator insert (iterator position, const value_type& val) {
				if (position.base() && _comp(position.base()->_value, val))
				{
					pointer search = search_node(_root, val);
					pointer from = _root;
					if (search != nullptr)
						return (iterator(search, this));
					pointer node = _alloc.allocate(1);
					_alloc.construct(node, val);
					_root = _insert(from, node);
					return (iterator(node, this));
				}
				else
					return (insert(val).first);
			};

			void insert (iterator first, iterator last) {
				for (; first != last; first++)
					insert(first->_value);
			};

			size_type erase(const value_type& k) {
				pointer node = search_node(_root, k);
				if (node == nullptr)
					return (0);
				else {
					_erase(node);
					_tree_size--;
					return (1);
				}
			};

			void erase(iterator position) {
				pointer to_search = (position++).base();
				if (to_search == nullptr)
					return ;
				pointer node = search_node(_root, to_search->_value);
				if (node == nullptr)
					return ;
				else {
					_erase(node);
					_tree_size--;
				}
			};

			void erase(iterator first, iterator last) {
				for (; first != last;) {
					iterator tmp = first;
					first++;
					erase(tmp);
				}
			};

			iterator find (value_type k) {
				pointer result = search_node(_root, k);
				if (result == nullptr)
					return (end());
				return (iterator(result, this));
			};

			size_type count(value_type k) const {
				if (search_node(_root, k) != nullptr)
					return (1);
				return (0);
			};

			iterator lower_bound(value_type k) {
				iterator it = begin();
				for (; it != end() && _comp((*it)._value, k); it++) ;
				return (it);
			};

			iterator upper_bound(value_type k) {
				iterator it = begin();
				for (; it != end() && !(_comp(k, (*it)._value)); it++) ;
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
				std::swap(_root, x._root);
				std::swap(_tree_size, x._tree_size);
			};

			pointer most_left(pointer node) {
				if (node == nullptr || node->_left == nullptr)
					return (node);
				return (most_left(node->_left));
			}

			pointer most_right(pointer node) {
				if (node == nullptr || node->_right == nullptr)
					return (node);
				return (most_right(node->_right));
			}

		private :
			pointer			 _root;
			value_compare	_comp;
			allocator_type	_alloc;
			size_type		_tree_size;

			void delete_node(pointer node) {
				_alloc.destroy(node);
				_alloc.deallocate(node, sizeof(value_type));
				node = nullptr;
			};

			void _clear_tree(pointer node) {
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
					std::cout << " " << root->_value << "(R)" << std::endl;
				else
					std::cout << " " << root->_value << "(N)" << std::endl;
				if (prev) {
					prev->str = prev_str;
				}
				trunk->str = "   |";
			
				printTree(root->_left, trunk, false);
			}

			void print_node(pointer n, std::string str) {
				std::cout << str << " = " << n->_value << " - Color =" << n->_color << std::endl;
				if (n->_parent)
					std::cout << str << " Parent = " << n->_parent->_value << " - Color =" << n->_color << std::endl;
				else
					std::cout << str << " Racine" << std::endl;
				if (n->_left)
					std::cout << str << " Left = " << n->_left->_value << " - Color =" << n->_color << std::endl;
				else
					std::cout << str << " Left NULL " << std::endl;
				if (n->_right)
					std::cout << str << " Right = " << n->_right->_value << " - Color =" << n->_color << std::endl;
				else
					std::cout << str << " Right NULL " << std::endl;

				std::cout << std::endl;
			}
	};
}
#endif