#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

//prototype untuk deklarasi function sebelum definisi 
//format: tipedata nama(inputnya); ex: int nambah(int a, int b)
//JANGAN LUPA BUAT SEBELUM SETIAP FUNCTION BIAR NGGAK IMPLICIT DECLARATION
void Exit();
void MenuUtama();
void MenuAwal();


struct User{
    char username[20];
    char password[20]; 
};

void MenuAwal(){ 
    printf("===============================\n");
    printf("S H I P P E X  L O G I S T I C \n");
    printf("===============================\n\n");
    printf("[1] Login\n");
    printf("[2] Register\n");
    printf("[3] Exit\n\n"); 
    int input = 0;
    printf("Your input:");
    while (input == 0){
        scanf ("%d",&input);
        switch (input){
            case 1:
                system("cls");
                //login
                break;
            case 2:
                system("cls");
                //reg
                break;
            case 3:
                system("cls");
                Exit();
                break;
            default:
                printf("Input invalid!\n");
                printf("Coba lagi!\n");
                input = 0;
                continue;
        }
    }

}

void MenuUtama(){
    printf("===============================\n");
    printf("S H I P P E X  L O G I S T I C \n");
    printf("===============================\n\n");
    printf("New Shipment Item\n"); 
    printf("View All Items\n"); 
    printf("Sort Item List\n"); 
    printf("Search Item Name\n"); 
    printf("Exit\n"); 
}

void Exit(){
    printf("==========================\n"); 
    printf("    Thank You For Using! \n");
    printf("==========================\n\n"); 
    printf("Press any key to exit...\n");
    getchar();
}



int main() {
    MenuAwal();
    return 0;
}
