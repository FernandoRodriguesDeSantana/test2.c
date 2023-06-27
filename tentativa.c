#include <stdio.h>
#include <stdlib.h>

struct athlete{
    char name[30];
    char sport[20];
    int age;
    float height;
};
struct athlete2{
    char name[30];
    char sport[20];
    int age;
    float height;
};
int main(){
    FILE *archive;
    int i, p = 2;
    struct athlete info[p];

    //testing the file opening
    archive = fopen("atlhete_info.txt", "w");
    if(archive == NULL){
        printf("\nERROR! The file cannot be opened.");
    }
    else{
        printf("\nSUCESS! The file has been opened.");
    }

    //storing the information in the structure
    printf("\n\n    --+=+--WELCOME TO ATLHETE INFO INTERFACE--+=+--    ");
    for(i = 0; i < p; i++){
        printf("\n\nFor the atlhete number %d:", i+1);

        printf("\n\n >Enter the atlhete name: ");
        fgets(info[i].name, 30, stdin);
        fflush(stdin);

        printf("\n >Enter the atlhete sport: ");
        fgets(info[i].sport, 20, stdin);
        fflush(stdin);

        printf("\n >Enter the atlhete age: ");
        scanf("%d", &info[i].age);
        fflush(stdin);

        printf("\n >Enter the atlhete height: ");
        scanf("%f", &info[i].height);
        fflush(stdin);

        printf("\n--+=+--+=+--+=+--+=+--+=+--+=+--+=+--+=+--");
    }


    //writing the information stored in the structure to a text file
    for(i = 0; i < p; i++){
        fprintf(archive, "%s", info[i].name);
        fprintf(archive, "%s", info[i].sport);
        fprintf(archive, "%d\n", info[i].age);
        fprintf(archive, "%.2f\n", info[i].height);
    }

    fclose(archive);

    //pointer for read the archive "atlhete_info.txt"
    FILE *archive2;
    archive2 = fopen("atlhete_info.txt", "r");
    struct athlete2 info2[p];

    //Testing the file opening
    if(archive2 == NULL){
        printf("\nERROR! The file cannot be opened.");
    }
    else{
        printf("\nSUCESS! The file has been opened.");
    }

    //reading the age and the height of the atlhetes
    for(i = 0; i < p; i++){
        fgets(info2[i].name, 30, archive2);
        fgets(info2[i].sport, 20, archive2);
        fscanf(archive2, "%d", &info2[i].age);
        fscanf(archive2, "%f", &info2[i].height);
    }

    for(i = 0; i < p; i++){
        printf("\nName: %s", info2[i].name);
        printf("\nSport: %s", info2[i].sport);
        printf("\nAge: %d", info2[i].age);
        printf("\nHeight: %.2f", info2[i].height);
    }

    fclose(archive2);
    return 0;
}
