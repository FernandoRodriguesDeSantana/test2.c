#include <stdio.h>
#include <stdlib.h>

struct athlete{
    char name[30];
    char sport[20];
    int age;
    float height;
};

int main(){
    struct athlete info[10];
    FILE *archive;
    int i;

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
    for(i = 0; i < 10; i++){
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
    for(i = 0; i < 10; i++){
        fwrite(&info[i], sizeof(struct athlete), 1, archive);
    }

    fclose(archive);


    return 0;
}
