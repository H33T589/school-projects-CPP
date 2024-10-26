#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

class BinarySearchTree {
private:
    class TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;
        int data;
        TreeNode(TreeNode* l, TreeNode* r, int d) : left(l), right(r), data(d) {}
    };
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    bool isEmpty() const { return root == nullptr; }

    void printInorder();
    void inorder(TreeNode* node);

    void printPreorder();
    void preorder(TreeNode* node);

    void printPostorder();
    void postorder(TreeNode* node);

    void insert(int data);
    void remove(int data);
    bool find(int data);

private:
    TreeNode* removeNode(TreeNode* node, int data);
    TreeNode* findMin(TreeNode* node);
};

void BinarySearchTree::insert(int data) {
    TreeNode* new_node = new TreeNode(nullptr, nullptr, data);
    TreeNode* parent = nullptr;

    if (isEmpty()) {
        root = new_node;
    } else {
        TreeNode* current = root;
        while (current) {
            parent = current;
            if (data > current->data) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        if (data < parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
}

void BinarySearchTree::remove(int data) {
    root = removeNode(root, data);
}

BinarySearchTree::TreeNode* BinarySearchTree::removeNode(TreeNode* node, int data) {
    if (node == nullptr) {
        return node;
    } else if (data < node->data) {
        node->left = removeNode(node->left, data);
    } else if (data > node->data) {
        node->right = removeNode(node->right, data);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            TreeNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }
    return node;
}

BinarySearchTree::TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

bool BinarySearchTree::find(int data) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void BinarySearchTree::printInorder() {
    inorder(root);
    cout << endl;
}

void BinarySearchTree::inorder(TreeNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BinarySearchTree::printPreorder() {
    preorder(root);
    cout << endl;
}

void BinarySearchTree::preorder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BinarySearchTree::printPostorder() {
    postorder(root);
    cout << endl;
}

void BinarySearchTree::postorder(TreeNode* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    // Create a BinarySearchTree object
    BinarySearchTree bst;

    // Insert 10 tree nodes with random two-digit integer data values
    for (int i = 0; i < 10; ++i) {
        int random_data = rand() % 90 + 10; // Generate random two-digit integer data
        bst.insert(random_data);
    }

    // Display the BST in three orders
    cout << "BST in Inorder traversal: ";
    bst.printInorder();

    cout << "BST in Preorder traversal: ";
    bst.printPreorder();

    cout << "BST in Postorder traversal: ";
    bst.printPostorder();

    // Remove 2 nodes
    int data_to_remove1, data_to_remove2;
    cout << "Enter data value for the first node to be removed: ";
    cin >> data_to_remove1;
    cout << "Enter data value for the second node to be removed: ";
    cin >> data_to_remove2;

    bst.remove(data_to_remove1);
    bst.remove(data_to_remove2);

    // Display the BST again in three orders
    cout << "BST after removing nodes: " << endl;
    cout << "Inorder traversal: ";
    bst.printInorder();

    cout << "Preorder traversal: ";
    bst.printPreorder();

    cout << "Postorder traversal: ";
    bst.printPostorder();

    // Check if a tree_node with a given data value is found in the tree
    int data_to_find;
    cout << "Enter data value to search for: ";
    cin >> data_to_find;

    if (bst.find(data_to_find)) {
        cout << "Tree node with data " << data_to_find << " is found in the tree." << endl;
    } else {
        cout << "Tree node with data " << data_to_find << " is not found in the tree." << endl;
    }

    return 0;
}
