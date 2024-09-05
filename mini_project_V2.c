
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stock_max 100 // constant global for maximum storage in our warehouse

struct book_info { // struct for all book information
    int book_qty;
    float book_price;
    char book_name[50];
    char book_author[30];
};

struct book_info books_array[stock_max]; // struct array to create many book profiles

int main() {
    int user_needs, book_id, search_check_var, total_stock;
    char search_var[50];
    book_id = -1; // initialize with -1 for no boos in stock

    do {
        printf("1 - Ajouter un livre au stock.\n"
               "2 - Afficher tous les livres disponibles.\n"
               "3 - Rechercher un livre par son titre.\n"
               "4 - Mettre à jour la quantité d'un livre.\n"
               "5 - Supprimer un livre du stock.\n"
               "6 - Afficher le nombre total de livres en stock.\n"
               "7 - Quitter.\n"
               " | \n"
               " | --> : ");
        scanf("%d", &user_needs);
        getchar(); // to consume newline character left by scanf

        switch (user_needs) {
            case 1: // Add a book to stock
                if (book_id >= stock_max - 1) {
                    printf("No stock available pour le moment pour ajouter ce livre.\n");
                } else {
                    book_id++;
                    printf("Donner le titre du livre : ");
                    scanf(" %[^\n]", books_array[book_id].book_name);
                    printf("Donner le nom de l'auteur : ");
                    scanf(" %[^\n]", books_array[book_id].book_author);
                    printf("Donner la QTY du livre : ");
                    scanf("%d", &books_array[book_id].book_qty);
                    printf("Donner le prix du livre : ");
                    scanf("%f", &books_array[book_id].book_price);
                }
                break;

            case 2: // Display all books available
                if (book_id == -1) {
                    printf("Aucun livre en stock.\n");
                } else {
                    for (int i = 0; i <= book_id; i++) {
                        printf("\nTitre du livre : %s\n", books_array[i].book_name);
                        printf("Auteur : %s\n", books_array[i].book_author);
                        printf("Prix : %.2f\n", books_array[i].book_price);
                        printf("Quantité disponible : %d\n", books_array[i].book_qty);
                    }
                }
                break;

            case 3: // Search a book by title
                if (book_id == -1) {
                    printf("Aucun livre en stock.\n");
                } else {
                    printf("Donner le titre du livre : ");
                    scanf(" %[^\n]", search_var);
                    search_check_var = -1;
                    for (int i = 0; i <= book_id; i++) {
                        if (strcmp(books_array[i].book_name, search_var) == 0) {
                            search_check_var = i;
                            break;
                        }
                    }
                    if (search_check_var != -1) {
                        printf("Livre trouvé ! Quantité actuelle : %d\n", books_array[search_check_var].book_qty);
                    } else {
                        printf("Livre non trouvé.\n");
                    }
                }
                break;

            case 4: // Update quantity of a book
                if (book_id == -1) {
                    printf("Aucun livre en stock.\n");
                } else {
                    printf("Donner le titre du livre : ");
                    scanf(" %[^\n]", search_var);
                    search_check_var = -1;
                    for (int i = 0; i <= book_id; i++) {
                        if (strcmp(books_array[i].book_name, search_var) == 0) {
                            search_check_var = i;
                            break;
                        }
                    }
                    if (search_check_var != -1) {
                        printf("Quantité actuelle : %d, entrer la nouvelle quantité : ", books_array[search_check_var].book_qty);
                        scanf("%d", &books_array[search_check_var].book_qty);
                    } else {
                        printf("Livre non trouvé.\n");
                    }
                }
                break;

            case 5: // Delete a book from stock
                if (book_id == -1) {
                    printf("Aucun livre en stock.\n");
                } else {
                    printf("Donner le titre du livre à supprimer : ");
                    scanf(" %[^\n]", search_var);
                    search_check_var = -1;
                    for (int i = 0; i <= book_id; i++) {
                        if (strcmp(books_array[i].book_name, search_var) == 0) {
                            search_check_var = i;
                            break;
                        }
                    }
                    if (search_check_var != -1) {
                        for (int j = search_check_var; j < book_id; j++) {
                            books_array[j] = books_array[j + 1];
                        }
                        book_id--;
                        printf("Livre supprimé.\n");
                    } else {
                        printf("Livre non trouvé.\n");
                    }
                }
                break;

            case 6: // Show total number of books in stock
                total_stock = 0;
                for (int i = 0; i <= book_id; i++) {
                    total_stock += books_array[i].book_qty;
                }
                printf("Nombre total de livres en stock : %d\n", total_stock);
                break;

            case 7: // Exit
                printf("Quitter.\n");
                break;

            default:
                printf("Choix incorrect, essayez encore.\n");
                break;
        }
    } while (user_needs != 7);

    return 0;
}
