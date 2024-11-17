#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing auto part data in a tree node
struct item {
    char itemID[10];
    char itemName[20];
    char itemCondition;
    float itemPrice;
};

struct treeNode {
    struct item data;
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePtr;

// Function Prototypes for Tree Operations
void insertItem(TreeNodePtr *treePtr, struct item data);
TreeNodePtr removeItemFromTree(TreeNodePtr treePtr, char itemID[]);
TreeNodePtr searchItem(TreeNodePtr treePtr, char itemID[]);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

/******* Function Definitions *******/

// Insert a new item into the tree
void insertItem(TreeNodePtr *treePtr, struct item data) {
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));
        if (*treePtr != NULL) {
            (*treePtr)->data = data;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            puts("Memory allocation failed for TreeNode.");
        }
    } else if (strcmp(data.itemID, (*treePtr)->data.itemID) < 0) {
        insertItem(&((*treePtr)->leftPtr), data);
    } else if (strcmp(data.itemID, (*treePtr)->data.itemID) > 0) {
        insertItem(&((*treePtr)->rightPtr), data);
    } else {
        printf("Duplicate ID %s. Not inserting.\n", data.itemID);
    }
}

// Remove an item from the tree by ID
TreeNodePtr removeItemFromTree(TreeNodePtr treePtr, char itemID[]) {
    if (treePtr == NULL) return NULL;

    if (strcmp(itemID, treePtr->data.itemID) < 0) {
        treePtr->leftPtr = removeItemFromTree(treePtr->leftPtr, itemID);
    } else if (strcmp(itemID, treePtr->data.itemID) > 0) {
        treePtr->rightPtr = removeItemFromTree(treePtr->rightPtr, itemID);
    } else {
        // Node with only one child or no child
        if (treePtr->leftPtr == NULL) {
            TreeNodePtr temp = treePtr->rightPtr;
            free(treePtr);
            return temp;
        } else if (treePtr->rightPtr == NULL) {
            TreeNodePtr temp = treePtr->leftPtr;
            free(treePtr);
            return temp;
        }

        // Node with two children
        TreeNodePtr temp = treePtr->rightPtr;
        while (temp && temp->leftPtr != NULL) temp = temp->leftPtr;
        
        treePtr->data = temp->data;
        treePtr->rightPtr = removeItemFromTree(treePtr->rightPtr, temp->data.itemID);
    }
    return treePtr;
}

// Search for an item by ID
TreeNodePtr searchItem(TreeNodePtr treePtr, char itemID[]) {
    if (treePtr == NULL || strcmp(itemID, treePtr->data.itemID) == 0) {
        return treePtr;
    } else if (strcmp(itemID, treePtr->data.itemID) < 0) {
        return searchItem(treePtr->leftPtr, itemID);
    } else {
        return searchItem(treePtr->rightPtr, itemID);
    }
}

// In-order traversal of the tree
void inOrder(TreeNodePtr treePtr) {
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("ID: %s, Part: %s, Price: %.2f, Condition: %c\n",
               treePtr->data.itemID, treePtr->data.itemName, treePtr->data.itemPrice, treePtr->data.itemCondition);
        inOrder(treePtr->rightPtr);
    }
}

// Pre-order traversal of the tree
void preOrder(TreeNodePtr treePtr) {
    if (treePtr != NULL) {
        printf("ID: %s, Part: %s, Price: %.2f, Condition: %c\n",
               treePtr->data.itemID, treePtr->data.itemName, treePtr->data.itemPrice, treePtr->data.itemCondition);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

// Post-order traversal of the tree
void postOrder(TreeNodePtr treePtr) {
    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("ID: %s, Part: %s, Price: %.2f, Condition: %c\n",
               treePtr->data.itemID, treePtr->data.itemName, treePtr->data.itemPrice, treePtr->data.itemCondition);
    }
}
