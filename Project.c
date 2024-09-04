#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stock_max 100 // constant golbal for maximum de stockage on owr warehouse 

struct book_info { // struct pour tout les info du livres 
    int book_qty; 
    float book_price;
    char book_name[50];
    char book_author[30];

};

struct book_info books_array[stock_max]; // struct array to creat many liver profiles 

int main(){

    int user_needs, book_id, search_check_var, total_stock;// user_needs meqn le utilisateur choi, book_id un vqriqble to track how many book in stock, total_stock Qty of all books
    search_check_var = -1;                    // init to avoid problems
    total_stock = 0;                          // init to avoid problems
    char search_var[50];                      // the string put by user for seqrch
    book_id = -1; // initia with -1 pour no books in stock
    do
    {
        
    printf( "1-Ajouter un livre au stock. \n" // les chois pour user 
             "2-Afficher tous les livres disponibles. \n"
             "3-Rechercher un livre par son titre. \n"
             "4-Mettre à jour la quantité d'un livre. \n"
             "5-Supprimer un livre du stock. \n"
             "6-Afficher le nombre total de livres en stock. \n "
             "7- Quitte. \n "
             " | \n "
             " |-->\n ");
    scanf("%d", &user_needs);

    switch (user_needs) // swith options
    {
    case 1:                                                                                         // --- case 1 --- qdd books to stock qnd check if there is in space available for that

        if(book_id >= stock_max-1) // in case there is no space on stock
        {
            printf("No stock available pour lr mement pour ajouter ce liver \n"); // no stock message 
        }else
        {
        book_id++;
        printf("donner le titre de liver :");
        scanf("%[^\n]s", books_array[book_id].book_name); // qdd name to aaray
        printf("donner le nome de auteur :");
        scanf("%[^\n]s", books_array[book_id].book_author); // add author to array 
        printf("donner QTY de liver :");
        scanf("%d", &books_array[book_id].book_qty); // qdd qty to aaray
        printf("donner prix de liver :");
        scanf("%f", &books_array[book_id].book_price); // qdd price to aaray
        }
        break;
    case 2:                                                                                         // --- case 2 --- afficchage de tout le livres

        if(book_id == -1) // in cqse there is nothing on stock
        {
            printf(" no liver en stock : \n ");

        }else // in case there is a stock 
        {
            for (int i = 0; i <= book_id; i++) // loop qfficher tout les liver
            {
                printf("\n le nome de livre          :%s  \n ", books_array[i].book_name);
                printf(" le nome du auteur           :%s \n", books_array[i].book_author);
                printf(" le prix de liver            :%.2f \n", books_array[i].book_price);
                printf(" la QTY available de liver   :%d \n", books_array[i].book_qty);
            }
        }

        break;

    case 3:                                                                                         // --- case 3 --- Mettre à Jour la Quantité d'un Livre
        if (book_id == -1) // check stock if there is any
            {
                printf("se nom ne pas available dons le stock ou le nome incorrect \n");
                break;
            }
        printf(" Donner moi le titre de livre :\n");
        scanf("%s",search_var);
        for (int i=0; i<= book_id; i++) // loop to check if le titre availqble 
        {

            search_check_var = strcmp(books_array[i].book_name, search_var);
            if (search_check_var == 0)
            {
                printf("votre livre availabe avec la quantite de : %d, enter le nouvau QTY : ", books_array[i].book_qty);
                scanf("%d",&books_array[i].book_qty);
            }
        }
        if (search_check_var != 0)
            printf("se nom ne pas available dons le stock \n");
    
    break;

    case 4:                                                                                         // --- Case 4 --- Supprimer un Livre du Stock

    break;

    case 5:                                                                                         // --- Case 5 --- Afficher le Nombre Total de Livres en Stock
        printf("le nomber total de livres en Stock : %d \n", &book_id); // afficher le nomber total des livres
        for(int i = 0; i <= book_id; i++) // boucle pour calcule le total Qty accrosse tous les livre 
        {
                total_stock += books_array[i].book_qty;
        }
        printf("le total Qty accrosse tous les livre est : %d \n", &total_stock);

    break;

    default:                                                                                        // --- Case default --- Si l'utilisteur go wrong
            printf("\n le chois incorrect : try again \n");
        break;
    }

    } while (user_needs != 7);
    

    return 0;
}
