

#ifndef MATALA5_BINARYTREE_H
#define MATALA5_BINARYTREE_H

#include <vector>
#include <iostream>

using namespace std;


namespace ariel {
    template<class T>
    class Node {
    public:
        T value;
        //Pointers = so we can put a zero value
        Node *left;
        Node *right;

        // constructors
        Node(T val) : value(val), left(nullptr), right(nullptr) {}

        Node(T val, Node *r, Node *l) : value(val), left(l), right(r) {}

        ~Node(){//Delete all pointer
            delete left;
            delete right;
        }
    };


    template<class T>
    class BinaryTree {
    private:
        Node<T> *root;
    public:

        class iterator {
        private:
            unsigned int current;
            vector<Node<T> *> list;

        public:
            void inorder(Node<T> *node) {
                if (node->left != nullptr) {
                    inorder(node->left);
                }
                list.push_back(node);
                if (node->right != nullptr) {
                    inorder(node->right);
                }
            }


            void preorder(Node<T> *node) {

                list.push_back(node);
                if (node->left != nullptr) {
                    preorder(node->left);
                }
                if (node->right != nullptr) {
                    preorder(node->right);
                }
            }


            void postorder(Node<T> *node) {

                if (node->left != nullptr) {
                    postorder(node->left);
                }
                if (node->right != nullptr) {
                    postorder(node->right);
                }
                list.push_back(node);
            }
// constactor
            iterator(Node<T> *root, int order = 0) {

//order is meant to tell us which method we want to go through on the tree
                if (order == 0) {
                    if (root != nullptr) {
                        inorder(root);
                    }
                } else if (order == 1) {
                    if (root != nullptr) {
                        preorder(root);
                    }
                } else {
                    if (root != nullptr) {
                        postorder(root);
                    }
                }
                current = 0;//Point to the root that is on the list instead of zero
            }


            T &operator*() const {
                return list[current]->value;
            }

            T *operator->() const {
                return &(list[current]->value);
            }

            iterator &operator++() {
                //We know the tree ends up with the rest of the list at size 0 so we delete the list when the rest of us have reached its maximum size
                if (++current == list.size()) {
                    list.clear();
                }
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                current++;
                return tmp;
            }

            //Access the node itself to a "circle"
            Node<T> *getNode() {
                return list[current];
            }

            bool operator==(const iterator &rhs) const {
                return !(this == rhs);
            }

            bool operator!=(const iterator &rhs) const {
                //List size affects,
                //If one of the lists is size 0 then there is no need to check at all,
                //If both are size 0 there is no need to check,
                //And if both are different from size 0 then we would like to check the content
                if (list.size() != 0 && rhs.list.size() != 0) {
                    return list[current] != rhs.list[rhs.current];
                } else {
                    return !(list.size() == 0 && rhs.list.size() == 0);
                }
            }
        };
//cunstractor
        BinaryTree() {
            root = nullptr;
        }
        ~BinaryTree(){
            delete root;
        }

        iterator begin() {
            return iterator(root);
        }

        iterator end() {
            return iterator(nullptr);
        }

        iterator begin_preorder() {
            return iterator(root, 1);
        }

        iterator end_preorder() {
            return iterator(nullptr);

        }

        iterator begin_inorder() {
            return iterator(root, 0);

        }

        iterator end_inorder() {
            return iterator(nullptr);

        }

        iterator begin_postorder() {
            return iterator(root, 2);
        }

        iterator end_postorder() {
            return iterator(nullptr);
        }

        BinaryTree<T> &add_root(T tRoot) {
            if (root != nullptr) {
                root->value = tRoot;
            } else {
                root = new Node<T>(tRoot);
            }
            return *this;
        }

        BinaryTree<T> &add_left(T nodeIn, T nodeAdd) {
            for (iterator it = begin(); it != end(); ++it) {
                if (*it == nodeIn) {
                    if (it.getNode()->left) {
                        it.getNode()->left->value = nodeAdd;
                    } else {
                        it.getNode()->left = new Node<T>(nodeAdd);
                    }
                    return *this;
                }
            }
            throw std::invalid_argument("the node is not exist");
        }


        BinaryTree<T> &add_right(T nodeIn, T nodeAdd) {
            for (iterator it = begin(); it != end(); ++it) {
                if (*it == nodeIn) {
                    if (it.getNode()->right) {
                        it.getNode()->right->value = nodeAdd;
                    } else {
                        it.getNode()->right = new Node<T>(nodeAdd);
                    }
                    return *this;
                }
            }
            throw std::invalid_argument("the node is not exist");
        }

        void printT(const std::string &prefix, const Node<T> *node, bool isLeft) {
            if (node != nullptr) {
                std::cout << prefix;

                std::cout << (isLeft ? "├──" : "└──");

                // print the value of the node
                std::cout << node->value << std::endl;

                // enter the next tree level - left and right branch
                printT(prefix + (isLeft ? "│   " : "    "), node->left, true);
                printT(prefix + (isLeft ? "│   " : "    "), node->right, false);
            }
        }

        friend ostream &operator<<(ostream &os, BinaryTree<T> &tree) {
            tree.printT("", tree.root, false);
            return os;
        }
    };
}

#endif //MATALA5_BINARYTREE_H
