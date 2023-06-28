#include <stdio.h>
#include <stdlib.h>

struct athlete{
    char name[30];
    char sport[20];
    int age;
    float height;
};
struct athlete2{
    char name2[30];
    char sport2[20];
    int age2;
    float height2;
};
int main(){
    FILE *archive;
    int i, p = 3;
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

    int higher = 0, old = 0, count1 = 0, count2 = 0;

    //Testing the file opening
    if(archive2 == NULL){
        printf("\nERROR! The file cannot be opened.");
    }
    else{
        printf("\nSUCESS! The file has been opened.");
    }

    //reading the age and the height of the athletes
     for (i = 0; i < p; i++) {
        fscanf(archive2, "%s %s %d %f", &info2[i].name2, &info2[i].sport2, &info2[i].age2, &info2[i].height2);
     }

     for(i = 0; i < p; i++){
        if(info2[i].height2 > higher){
            higher = info2[i].height2;
            count1 = i;
        }
        if(info2[i].age2 > old){
            old = info2[i].age2;
            count2 = i;
        }

     }
    /*
    Testing the if the read values are right
     for(i = 0; i < p; i ++){
        printf("\nName: %s", info2[i].name2);
        printf("\nSport: %s", info2[i].sport2);
        printf("\nAge: %d", info2[i].age2);
        printf("\nHeight: %.2f", info2[i].height2);
     }
    */
    printf("\nThe most higher athlete is %s and the most old athlete is %s", info2[count1].name2, info2[count2].name2);

    fclose(archive2);
    return 0;
}
