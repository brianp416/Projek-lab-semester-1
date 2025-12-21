#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <ctype.h>

void Out();
void MenuUtama();
void MenuAwal();
void koordinat(int x, int y); 
void Menu_Shipment();
int input(char *temp, int panjang); 
int input_khusus(char *temp, int panjang); 
void view_all(); 
void sorting_barang(); 
void search_menu();
void search_id();
void search_name();
void search_handling();

struct User{
    char username[20];
    char password[20]; 
};

struct Datacenter{
    int item_id; 
    char item_name[20];
    char item_type[30]; 
    int handling_code; 
}; 

void MenuAwal(){ 
    int posisi = 1; 
    int input;
    while(1){
        system("cls"); 
        printf("===============================\n");
        printf("S H I P P E X  L O G I S T I C \n");
        printf("===============================\n\n");

        printf("[1] Login    %s\n", (posisi == 1) ? "<<" : "");
        printf("[2] Register %s\n", (posisi == 2) ? "<<" : "");
        printf("[3] Exit     %s\n", (posisi == 3) ? "<<" : ""); 

        input = getch(); 

        if(input == 'w' || input == 'W'){
            posisi--; 
            if(posisi < 1){
                posisi = 3; 
            }
        }else if(input == 's' || input == 'S'){
            posisi++; 
            if(posisi > 3){
                posisi = 1; 
            }
        }else if(input == 13 ){
            switch (posisi){
                case 1:
                    system("cls");
                    
                    break;
                case 2:
                    system("cls");
                    
                    break;
                case 3:
                    system("cls");
                    Out(); 
                    exit(0);
                    break;
            }
        }
    }
}

void MenuUtama(){
    int posisi = 1; 
    char B; 

    while(1){
        system("cls"); 
        printf("===============================\n");
        printf("S H I P P E X  L O G I S T I C \n");
        printf("===============================\n\n");
        printf("[1] New Shipment Item %s\n" , (posisi == 1) ? "<<" : "");
        printf("[2] View All Items    %s\n" , (posisi == 2) ? "<<" : ""); 
        printf("[3] Sort Item List    %s\n" , (posisi == 3) ? "<<" : "");
        printf("[4] Search Item       %s\n" , (posisi == 4) ? "<<" : "");
        printf("[5] Exit              %s\n" , (posisi == 5) ? "<<" : "");

        B = getch(); 

        if(B == 'w' || B == 'W'){
            posisi--; 
            if(posisi < 0){
                posisi = 5; 
            }
        }else if(B == 's' || B == 'S'){
            posisi++; 
            if(posisi > 5){
                posisi = 1; 
            }
        }else if(B == 13 ){
            switch(posisi) {
            case 1: 
            system("cls");
            Menu_Shipment(); 
            break;
            case 2:
            system("cls"); 
            view_all(); 
            break;
            case 3:
            system("cls"); 
            sorting_barang(); 
            break;
            case 4: 
            system("cls"); 
            search_menu();
            break;
            case 5:
            return; 
            }
        }
    }





}
void koordinat(int x ,int y){
    COORD koordinat; 
    koordinat.X = x; 
    koordinat.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

int check_code(int pass){
    FILE *fp = fopen("datacenter.txt", "r"); 
    
    if(fp == NULL){
        return 0; 
    }
    struct Datacenter Temp; 

    while(fscanf(fp, "%d %s %s %d", &Temp.item_id, Temp.item_name, Temp.item_type, &Temp.handling_code) != EOF) {
        if(pass == Temp.handling_code){
            fclose(fp);
            return 1; 
        }
    
    }
    
   fclose(fp); 
     return 0; 
}

int check_id(int pass){
    FILE *fp = fopen("datacenter.txt", "r"); 
    
    if(fp == NULL){
        return 0; 
    }
    struct Datacenter Temp; 

    while(fscanf(fp, "%d %s %s %d", &Temp.item_id, Temp.item_name, Temp.item_type, &Temp.handling_code) != EOF) {
        if(pass == Temp.item_id){ 
            fclose(fp);
             return 1;
        }
    
    }
     
   fclose(fp); 
    return 0;
}
void Menu_Shipment(){

    char temp[50];
    int id; 
    char name[20]; 
    char type[30]; 
    int code; 
    int valid = 0; 
    
    printf("======================================================\n");
    printf("          SISTEM MANAJEMEN PENGIRIMAN (LOGISTIK)     \n");
    printf("======================================================\n\n");

    printf("|------- Tambah Barang Baru -------|     \n");
    printf("Masukan ITEM ID (0-9999)           :     \n");
    printf("Masukan Nama Barang                :     \n");
    printf("Masukan Type Barang(FRG/STB/SPD)   :     \n");
    printf("Masukan Handling Number(1000-9999) :     \n");

    do{
        koordinat(37,5); 
        if(input(temp, 10) == 1){
            return; 
        }else{
            id = atoi(temp); 
            if(check_id(id) == 1){
                valid = 0; 
                koordinat(37,5); printf("Id Telah Dipakai Sebelumnya, Silahkan Buat Id Baru\n");
                getchar();
                koordinat(37,5); printf("                                                     ");
            }else{
                valid = 1; 
            }
        }
    }while(!valid);

    koordinat(37,6); 
    if(input(name, 20) == 1){
        return; 
    }

    koordinat(37,7);
    if(input_khusus(type, 3) == 1){
        return; 
    }

    
    do{
        koordinat(37,8);
        if(input(temp, 10) == 1){
            return; 
        }else{
            code = atoi(temp); 
            if(check_code(code) == 1){
                valid = 0;
                koordinat(37,8); printf("Handling Code Telah Dipakai Sebelumnya, Silahkan Buat Handling Code Baru\n");
                getchar();
                koordinat(37,8); printf("                                                                          ");
            }else{
                valid = 1;
            }
        }
    }while(!valid);
    
    FILE *fp = fopen("datacenter.txt", "a"); 

    if(fp == NULL){ 
        printf("File Tidak Ditemukan"); 
        return; 
    }

    fprintf(fp, "%d %s %s %d", id, name, type, code);
    fprintf(fp,"\n");
    fclose(fp); 

    printf("\n");
    printf("Tekan enter to keluar...\n");
    getchar();
}


int input(char *temp, int panjang){
    int i = 0; 
    char B; 

    temp[0] = '\0'; 

    while(1){
        B = getch(); 

        if(B == 27 ){
            return 1; 
        }

        if(B == 13){
            temp[i] = '\0';
            return 0; 
        }

        if(B == 8 && i > 0 ){
            i--; 
            printf("\b \b"); 
        }

        if(i < panjang && isprint(B)){
            temp[i] = B; 
            i++;
            printf("%c", B); 
        }
    }

}

int input_khusus(char *temp, int panjang){
    int i = 0; 
    char B; 
    char kode[10];

    kode[0] = '\0'; 

    while(1){
        B = getch(); 

        if(B == 27 ){
            return 1; 
        }

        if(B == 13){
            kode[i] = '\0'; 
            if(strcmp(kode, "FRG") == 0){
                strcpy(temp,"Fragile"); 
                return 0; 
            } 
            if(strcmp(kode, "STB") == 0){
                strcpy(temp,"StandarHandling"); 
                return 0; 
            }
            if(strcmp(kode, "SPB") == 0){
                strcpy(temp, "SpecialHandling"); 
                return 0; 
            }
        }

        if(B == 8 && i > 0 ){
            i--; 
            printf("\b \b"); 
        }

        if(i < panjang && isprint(B)){
            char up = toupper(B); 
            kode[i] = up; 
            i++;
            printf("%c", up); 
        }
    }

}

void view_all(){

    printf("============================================================================\n");
    printf("                      SISTEM MANAJEMEN PENGIRIMAN LOGISTIK      \n");
    printf("============================================================================\n");

    printf("| %-20s | %-10s | %-20s | %-13s |\n", "Item Name", "Item ID", "Type Item", "Handling Code");
    printf("|--------------------------------------------------------------------------|\n");

    FILE *fp = fopen("datacenter.txt", "r"); 

    if (fp == NULL){
        printf("|                            D A T A  K O S O N G                          |\n");
        printf("|--------------------------------------------------------------------------|\n");
        printf("\nPress Enter to exit...\n");
        getchar();
        return; 
    }

    struct Datacenter Temp; 

    while(fscanf(fp, "%d %s %s %d", &Temp.item_id, Temp.item_name, Temp.item_type, &Temp.handling_code) != EOF) {
        printf("| %-20s | %-10d | %-20s | %-13d |\n", Temp.item_name, Temp.item_id, Temp.item_type, Temp.handling_code);
    }
    printf("|==========================================================================|"); 

    fclose(fp);

    printf("\n\nTekan Enter to keluar...\n");
    getchar(); 
}

void sorting_barang(){

    struct Datacenter Data[100]; 

    int count = 0; 

    FILE *fp = fopen("datacenter.txt", "r"); 

    if (fp == NULL) {
        printf("|                            D A T A  K O S O N G                          |\n");
        printf("|--------------------------------------------------------------------------|\n");
        printf("\nPress Enter to exit...\n");
        getchar();
    }

    while(fscanf(fp, "%d %s %s %d", &Data[count].item_id, Data[count].item_name, Data[count].item_type, &Data[count].handling_code) != EOF) {
        count++;
     }

    fclose(fp);

    int min; 

    for(int i= 0; i < count -1; i++){
        min = i; 
        for(int j = i +1; j < count; j++){
            if(Data[j].item_id < Data[min].item_id){
                min = j;
            }
        }
        if(min != i){
            struct Datacenter temp;
            temp = Data[min]; 
            Data[min] = Data[i];
            Data[i] = temp;
        }
    }

    printf("============================================================================\n");
    printf("                         SISTEM SORTING PENGIRIMAN LOGISTIK              \n");
    printf("============================================================================\n");

    printf("| %-10s | %-20s | %-20s | %-13s |\n", "Item ID", "Item Name", "Type Item", "Handling Code");
    printf("|--------------------------------------------------------------------------|\n");

    for(int i= 0; i < count; i++){
         printf("| %-10d | %-20s | %-20s | %-13d |\n", Data[i].item_id, Data[i].item_name, Data[i].item_type, Data[i].handling_code);
    }

    printf("\n\nTekan Enter to keluar...\n");
    getchar(); 

}

void search_menu(){
    int posisi = 1; 
    char B; 

    while(1){
        system("cls"); 
        printf("===========================================\n");
        printf("S H I P P E X  L O G I S T I C  S E A R C H\n");
        printf("===========================================\n\n");
        printf("[1] Search dengan ID              %s\n" , (posisi == 1) ? "<<" : "");
        printf("[2] Search dengan nama            %s\n" , (posisi == 2) ? "<<" : ""); 
        printf("[3] Search dengan handling code   %s\n" , (posisi == 3) ? "<<" : "");
        printf("[4] Exit                          %s\n" , (posisi == 4) ? "<<" : "");

        B = getch(); 

        if(B == 'w' || B == 'W'){
            posisi--; 
            if(posisi < 0){
                posisi = 4; 
            }
        }else if(B == 's' || B == 'S'){
            posisi++; 
            if(posisi > 4){
                posisi = 1; 
            }
        }else if(B == 13 ){
            switch(posisi) {
            case 1: 
            system("cls");
            search_id();
            break;
            case 2:
            system("cls"); 
            search_name(); 
            break;
            case 3: 
            system("cls"); 
            search_handling();
            break;
            case 4:
            return; 
            }
        }
    }
}

void search_id(){
    printf("Masukkan ID barang yang ingin dicari: ");
    int search;
    scanf("%d", &search);
    getchar();

    struct Datacenter Data[100]; 

    int count = 0; 

    FILE *fp = fopen("datacenter.txt", "r"); 

    if (fp == NULL) {
        printf("|                            D A T A  K O S O N G                          |\n");
        printf("|--------------------------------------------------------------------------|\n");
        printf("\nPress Enter to exit...\n");
        getchar();
    }

    while(fscanf(fp, "%d %s %s %d", &Data[count].item_id, Data[count].item_name, Data[count].item_type, &Data[count].handling_code) != EOF) {
        count++;
     }

    fclose(fp);

    printf("============================================================================\n");
    printf("                         SISTEM SEARCHING PENGIRIMAN LOGISTIK              \n");
    printf("============================================================================\n");
    printf("| %-10s | %-20s | %-20s | %-13s |\n", "Item ID", "Item Name", "Type Item", "Handling Code");
    printf("|--------------------------------------------------------------------------|\n");    

    for(int i= 0; i < count; i++){
        if(Data[i].item_id==search){
            printf("| %-10d | %-20s | %-20s | %-13d |\n", Data[i].item_id, Data[i].item_name, Data[i].item_type, Data[i].handling_code);  
            printf("\n\nTekan Enter to keluar...\n");
            getchar();
            return; 
        }
    }

    
    printf("|---------------------------Data tidak ditemukan---------------------------|");
    printf("\n\nTekan Enter to keluar...\n");
    getchar();
    return; 

}


void search_name(){
    printf("Masukkan nama barang yang ingin dicari (Case-Sensitive): ");
    char search[1000];
    scanf("%s", &search);
    getchar();

    struct Datacenter Data[100]; 

    int count = 0; 

    FILE *fp = fopen("datacenter.txt", "r"); 

    if (fp == NULL) {
        printf("|                            D A T A  K O S O N G                          |\n");
        printf("|--------------------------------------------------------------------------|\n");
        printf("\nPress Enter to exit...\n");
        getchar();
    }

    while(fscanf(fp, "%d %s %s %d", &Data[count].item_id, Data[count].item_name, Data[count].item_type, &Data[count].handling_code) != EOF) {
        count++;
     }

    fclose(fp);

    printf("============================================================================\n");
    printf("                         SISTEM SEARCHING PENGIRIMAN LOGISTIK              \n");
    printf("============================================================================\n");
    printf("| %-10s | %-20s | %-20s | %-13s |\n", "Item ID", "Item Name", "Type Item", "Handling Code");
    printf("|--------------------------------------------------------------------------|\n");    

    for(int i= 0; i < count; i++){
        if(strcmp(Data[i].item_name, search) == 0){
            printf("| %-10d | %-20s | %-20s | %-13d |\n", Data[i].item_id, Data[i].item_name, Data[i].item_type, Data[i].handling_code);  
            printf("\n\nTekan Enter to keluar...\n");
            getchar();
            return; 
        }
    }

    
    printf("|---------------------------Data tidak ditemukan---------------------------|");
    printf("\n\nTekan Enter to keluar...\n");
    getchar();
    return; 

}

void search_handling(){
    printf("Masukkan Handling Code barang yang ingin dicari: ");
    int search;
    scanf("%d", &search);

    getchar();

    struct Datacenter Data[100]; 

    int count = 0; 

    FILE *fp = fopen("datacenter.txt", "r"); 

    if (fp == NULL) {
        printf("|                            D A T A  K O S O N G                          |\n");
        printf("|--------------------------------------------------------------------------|\n");
        printf("\nPress Enter to exit...\n");
        getchar();
    }

    while(fscanf(fp, "%d %s %s %d", &Data[count].item_id, Data[count].item_name, Data[count].item_type, &Data[count].handling_code) != EOF) {
        count++;
     }

    fclose(fp);

    printf("============================================================================\n");
    printf("                         SISTEM SEARCHING PENGIRIMAN LOGISTIK              \n");
    printf("============================================================================\n");
    printf("| %-10s | %-20s | %-20s | %-13s |\n", "Item ID", "Item Name", "Type Item", "Handling Code");
    printf("|--------------------------------------------------------------------------|\n");    

    for(int i= 0; i < count; i++){
        if(Data[i].handling_code==search){
            printf("| %-10d | %-20s | %-20s | %-13d |\n", Data[i].item_id, Data[i].item_name, Data[i].item_type, Data[i].handling_code);  
            printf("\n\nTekan Enter to keluar...\n");
            getchar();
            return; 
        }
    }

    
    printf("|---------------------------Data tidak ditemukan---------------------------|");
    printf("\n\nTekan Enter to keluar...\n");
    getchar();
    return; 

}

void Out(){
    printf("==========================\n"); 
    printf("    Thank You For Using! \n");
    printf("==========================\n\n"); 
    printf("Tekan enter untuk keluar...\n");         
    getchar();
}

int main() {
    MenuAwal(); 
    return 0;
}
