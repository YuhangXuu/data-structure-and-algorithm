#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int Diameter(vector<char> tree, int root, int& global_max){
    if(root > tree.size() - 1 || tree[root] == '#')
        return 0;
    int left_height = Diameter(tree, 2 * root + 1, global_max);
    int right_height = Diameter(tree, 2 * root + 2, global_max);
    global_max = max(global_max, left_height + right_height + 1 );
    return max(left_height, right_height) + 1;
}

bool isUniValue(Node* root, int& count){
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL){
        count++;
        return true;
    }
    bool left_isUniVal = isUniValue(root->left, count);
    bool right_isUniVal = isUniValue(root->right, count);
    if(left_isUniVal && right_isUniVal && root->left->data == root->right->data) {
        count++;
        return true;
    }
    else
        return false;
}

struct Node* findLCA1(Node* root, int a, int b){
    if(root == NULL || root->data == a || root->data == b)
        return root;
    Node* leftLCA = findLCA1(root->left, a, b);
    Node* rightLCA = findLCA1(root->right, a, b);
    if(leftLCA && rightLCA)
        return root;
    else
        return (leftLCA == NULL) ? rightLCA : leftLCA;
}

bool isTreeNode(Node* root, int a){
    if(root == NULL)
        return false;
    if(root->data == a)
        return true;
    bool InLeft = isTreeNode(root->left, a);
    bool InRight = isTreeNode(root->right, a);
    return InLeft || InRight;
}

struct Node* findLCA2(Node* root, int a, int b){
    if(isTreeNode(root, a) && isTreeNode(root, b))
        return findLCA1(root, a, b);
    else
        return NULL;
}

int distanceToLCA(Node* root, int a, int dist){
    if(root == NULL) return -1;
    if(root->data == a) return dist;
    int left = distanceToLCA(root->left, a, dist+1);
    if(left == -1)
        return distanceToLCA(root->right, a, dist+1);
    return left;
}

int distance(Node*root, int a, int b){
    struct Node* rootLCA = findLCA1(root, a, b);
    cout << rootLCA->data << "," << distanceToLCA(rootLCA, a, 0) << "," << distanceToLCA(rootLCA, b, 0) << endl;
    return distanceToLCA(rootLCA, a, 0) + distanceToLCA(rootLCA, b, 0);
}

void binaryTreePath(Node* root, vector<string>& paths, string path){
    path += to_string(root->data);
    if(!root->left && !root->right) {
        paths.push_back(path);
        return;
    }
    if(root->left)
        binaryTreePath(root->left, paths, path + "->");
    if(root->right)
        binaryTreePath(root->right, paths, path + "->");
}

vector<string> binaryTreePath(Node* root, vector<string>& paths){
    binaryTreePath(root, paths, "");
    return paths;
}

void arrayPrint(vector<string> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    cout << endl;
}

int main() {
    // problem 1
//    vector<char> tree = {'0', '1', '2', '#', '#', '4'};
//    int global_max = -1;
//    Diameter(tree, 0, global_max);
//    cout << global_max << endl;

    // problem 2
//    int count = 0;
//    struct Node* root = newNode(5);
//    root->left = newNode(1);
//    root->right = newNode(5);
//    root->left->left = newNode(5);
//    root->left->right = newNode(5);
//    root->right->right = newNode(5);
//    isUniValue(root, count);
//    cout << count << endl;

    // problem 3
//    struct Node* root = newNode(5);
//    root->left = newNode(9);
//    root->right = newNode(12);
//    root->left->left = newNode(2);
//    root->left->right = newNode(3);
//    root->right->right = newNode(14);
//    cout << findLCA1(root, 2, 9)->data << endl;

    // problem 4
//    struct Node* root = newNode(5);
//    root->left = newNode(9);
//    root->right = newNode(12);
//    root->left->left = newNode(2);
//    root->left->right = newNode(3);
//    root->right->right = newNode(14);
//    cout << findLCA2(root, 2, 7)->data << endl;

    // problem 5
//    Node * root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->right->left->right = newNode(8);
//    cout << "Dist(4, 5) = " << distance(root, 4, 5);
//    cout << "\nDist(4, 6) = " << distance(root, 4, 6);
//    cout << "\nDist(3, 4) = " << distance(root, 3, 4);

    // problem 6
    vector<string> result;
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    binaryTreePath(root, result);
    arrayPrint(result);
    return 0;
}