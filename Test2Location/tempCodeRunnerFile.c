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