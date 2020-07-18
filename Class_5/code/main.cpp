#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

struct BTNode
{
    int value;
    struct BTNode* left, *right;
};

BTNode *newNode(int value)
{
    BTNode *temp = new BTNode;
    temp->value = value;
    temp->left = temp->right = NULL;
    return (temp);
}

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(ListNode** head_ref, int new_data)
{
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->value  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(ListNode* node)
{
    while (node != NULL)
    {
        printf(" %d ", node->value);
        node = node->next;
    }
}

void ArrayPrint(vector<char>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        printf(" %c ", arr.at(i));
    }
}

// Delete an elemnt at pos in the linked list
// if we delete the head node, count = 1, otherwise count = 0;
int deleteNode(ListNode** head, int pos){
    int count = 0;
    if(*head == NULL)
        return count;
    ListNode* temp = *head;
    if(pos == 0){
        *head = temp->next;
        free(temp);
        return count+1;
    }
    for(int i = 0; temp!= NULL && i < pos - 1; i ++)
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)
        return count;
    ListNode* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return count;
}

// Delete nodes at indices using function deleteNode
void deleteNodes(ListNode** head, vector<int> indices){
    int count = 0;
    for(int i = 0; i < indices.size(); i++){
        count += deleteNode(head, indices[i] - count);
    }
}

// Reverse pairs of elements in linked list
void reverseInPairs(ListNode* head){
    ListNode* temp = head;
    if(temp == NULL || temp->next == NULL)
        return;
    while(temp != NULL && temp->next != NULL){
        swap(temp->value, temp->next->value);
        temp = temp->next->next;
    }
}

// insert a node to the sorted linked list
void sortedInsert(ListNode** head, ListNode* newNode){
    if(*head == NULL || (*head)->value >= newNode->value){ // head node need to be changed
        newNode->next = *head;
        *head = newNode;
    }
    else {
        ListNode *pCurr = *head;
        while (pCurr->next != NULL && pCurr->next->value < newNode->value)
            pCurr = pCurr->next;
        newNode->next = pCurr->next;
        pCurr->next = newNode;
    }
}

// Sort a Linked List using Insertion Sort
void insertionSortLL(ListNode** head){
    ListNode* sorted = NULL;
    ListNode* pCurr = *head;
    while(pCurr != NULL){
        ListNode* pNext = pCurr->next;
        sortedInsert(&sorted, pCurr);
        pCurr = pNext;
    }
    *head = sorted;
}

// Count the number of elements in linked list
int listLength(ListNode* node){
    int count = 0;
    while(node != NULL) {
        count += 1;
        node = node->next;
    }
    return count;
}

// rotate the list to the right by k places
void rotateLL(ListNode** head, int k){
    int length = listLength(*head);
    if(k % length == 0)
        return;
    int trainsitionIdx = length - k % length - 1;
    ListNode* curr = *head;
    int count = 0;
    while(count < trainsitionIdx && curr != NULL){
        curr = curr->next;
        count++;
    }
    // store the node before new head node
    ListNode* transition = curr;
    // traverse to the end of list
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = *head;
    *head = transition->next;
    transition->next = NULL;
}

// Split the linked list into two
void splitLL(ListNode* head, ListNode** front, ListNode** back){
    if(head == NULL)
        return;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Merge two sorted linked list
ListNode* sortedMerge(ListNode* a, ListNode* b){
    ListNode* result = NULL;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    if(a->value < b->value){
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Sort the linked list using Merge Sort
void mergeSortLL(ListNode** head){
    ListNode* a;
    ListNode* b;
    if(*head == NULL || (*head)->next == NULL)
        return;
    splitLL(*head, &a, &b);
    mergeSortLL(&a);
    mergeSortLL(&b);
    *head = sortedMerge(a, b);
}

// iterative, in-order traversal of binary tree.
vector<char> inOrder(vector<char> binaryTree){
    vector<int> resultIdx;
    vector<char> result;
    stack<char> s;
    int n = binaryTree.size();
    char curr = 0;
    while(binaryTree[curr] != '#' || !s.empty()){
        while(binaryTree[curr] != '#' && curr <= n - 1){
            s.push(curr);
            curr = 2 * curr + 1;
        }
        curr = s.top();
        s.pop();
        resultIdx.push_back(curr);
        curr = 2 * curr + 2;
    }
    for(int i = 0; i < resultIdx.size(); i++)
        result.push_back(binaryTree[resultIdx[i]]);
    return result;
}

// return minimum depth of binary tree
int minDepth(BTNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    if(root->left == NULL)
        return 1 + minDepth(root->right);
    if(root->right == NULL)
        return 1 + minDepth(root->left);
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main() {
    /* Start with the empty list */
    ListNode *head = NULL;
    vector<int> indices = {0, 2};
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    puts("Created Linked List: ");
    printList(head);

//    deleteNodes(&head, indices);
//    reverseInPairs(head);
//    insertionSortLL(&head);
//    rotateLL(&head, 12);
    mergeSortLL(&head);
    puts("\nafter operations: ");
    printList(head);
//    cout << "\n" << listLength(head) << endl;
    cout << endl;


    vector<char> binaryTree = {'1', '2', '3', '#', '#', '4', '#'};
    vector<char> result = inOrder(binaryTree);
    ArrayPrint(result);
    cout << endl;


    BTNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << minDepth(root) << endl;
    return 0;
}