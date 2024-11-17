#include "auto_parts_tree.h"

void treeMenu() {
    puts("\nAUTO PARTS TREE OPERATIONS");
    puts("1: Insert Auto Part into Inventory");
    puts("2: Remove Auto Part from Inventory");
    puts("3: Search for an Auto Part by ID");
    puts("4: Display Inventory (Pre-order Traversal)");
    puts("5: Display Inventory (Post-order Traversal)");
    puts("6: Display Inventory (In-order Traversal)");
    puts("7: Exit Inventory Operations");
    puts("");
}

int main() {
    TreeNodePtr root = NULL;
    int choice;
    struct item part;
    char itemID[10];

    while (1) {
        treeMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1:
                printf("Enter Part ID: ");
                scanf("%s", part.itemID);
                printf("Enter Part Name: ");
                scanf("%s", part.itemName);
                printf("Enter Part Price: ");
                scanf("%f", &part.itemPrice);
                printf("Enter Part Condition (N for New, U for Used, R for Refurbished): ");
                getchar();
                scanf("%c", &part.itemCondition);

                // Validate the condition input
                while (part.itemCondition != 'N' && part.itemCondition != 'U' && part.itemCondition != 'R') {
                    printf("Invalid input. Please enter 'N' for New, 'U' for Used, or 'R' for Refurbished: ");
                    getchar();
                    scanf("%c", &part.itemCondition);
                }

                insertItem(&root, part);
                printf("Auto Part '%s' (ID: %s) has been added to the inventory.\n", part.itemName, part.itemID);
                break;

            case 2:
                printf("Enter Part ID to remove: ");
                scanf("%s", itemID);
                root = removeItemFromTree(root, itemID);
                printf("Auto Part with ID '%s' has been removed from the inventory.\n", itemID);
                break;

            case 3:
                printf("Enter Part ID to search: ");
                scanf("%s", itemID);
                TreeNodePtr found = searchItem(root, itemID);
                if (found) {
                    printf("Found Auto Part: ID=%s, Name=%s, Price=%.2f, Condition=%c\n",
                           found->data.itemID, found->data.itemName, found->data.itemPrice, found->data.itemCondition);
                } else {
                    puts("Auto Part not found in the inventory.");
                }
                break;

            case 4:
                puts("Displaying Inventory (Pre-order Traversal):");
                preOrder(root);
                break;

            case 5:
                puts("Displaying Inventory (Post-order Traversal):");
                postOrder(root);
                break;

            case 6:
                puts("Displaying Inventory (In-order Traversal):");
                inOrder(root);
                break;

            case 7:
                puts("Exiting Inventory Operations.");
                return 0;

            default:
                puts("Invalid choice. Please try again.");
        }
    }
}
