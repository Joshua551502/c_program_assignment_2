
/* deletes a node from the binary search tree */
void deleteNode ( TreeNodePtr *treePtr, int value )
{
    int found ;
    TreeNodePtr parentPtr, tempNodePtr, replacementNodePtr ;
    
    /* if tree is empty */
    if ( *treePtr == NULL )
    {
        printf ( "\nTree is empty" ) ;
        return ;
    }

    parentPtr = NULL ;
    tempNodePtr = NULL;

    /* find the node to be deleted */
    searchNode ( treePtr, value, &parentPtr, &tempNodePtr, &found ) ;

    /* if the node is not found */
    if ( found == FALSE )
    {
        printf ( "\n Data not found" ) ;
        return ;
    }

    /* if the node to be deleted has two children */
    if ( tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr != NULL )
    {
        parentPtr = tempNodePtr ;
        replacementNodePtr = tempNodePtr -> rightPtr ;

        while ( replacementNodePtr -> leftPtr != NULL )
        {
            parentPtr = replacementNodePtr ;
            replacementNodePtr = replacementNodePtr -> leftPtr ;
        }

        tempNodePtr -> data = replacementNodePtr -> data ;
        tempNodePtr = replacementNodePtr ;
    }

    /* if the node to be deleted has no child */
    if ( tempNodePtr -> leftPtr == NULL && tempNodePtr -> rightPtr == NULL )
    {
        if ( parentPtr -> rightPtr == tempNodePtr )
            parentPtr -> rightPtr = NULL ;
        else
            parentPtr -> leftPtr = NULL ;

        free ( tempNodePtr ) ;
        return ;
    }

    /* if the node to be deleted has only rightPtr */
   if ( tempNodePtr -> leftPtr == NULL && tempNodePtr -> rightPtr != NULL )
    {
        if ( parentPtr -> leftPtr == tempNodePtr )
            parentPtr -> leftPtr = tempNodePtr -> rightPtr ;
        else
            parentPtr -> rightPtr = tempNodePtr -> rightPtr ;

        free ( tempNodePtr ) ;
        return ;
    }

    /* if the node to be deleted has only left child */
    if ( tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr == NULL )
    {
        if ( parentPtr -> leftPtr == tempNodePtr )
            parentPtr -> leftPtr = tempNodePtr -> leftPtr ;
        else
            parentPtr -> rightPtr = tempNodePtr -> leftPtr ;

        free ( tempNodePtr ) ;
        return ;
    }
}

void searchNode ( TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found )
{
    TreeNodePtr tempPtr ;
    tempPtr = *treePtr ;
    *found = FALSE ;
    *parentPtr = NULL ;

    while ( tempPtr != NULL )
    {
     if ( tempPtr -> data == value )
     {
       *found = TRUE ;
       *tempNodePtr = tempPtr ;
       return ;
     }

       *parentPtr = tempPtr ;
        if ( tempPtr -> data > value )
            tempPtr = tempPtr -> leftPtr ;
        else
            tempPtr = tempPtr -> rightPtr ;
    }
}


