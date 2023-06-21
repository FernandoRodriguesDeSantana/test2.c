#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arch;
    int i, num[20], crossed = 0, max = 100;
    int *number;

    //testing the file "speed.txt" opening
    arch = fopen("speed.txt", "r"); 
    if(arch == NULL){
        printf("\nERROR! The file cannot be opened.");
    }
    else{
        printf("\nSUCESS! The file has been opened.");
    }

    //reading and storing the 20 speed values of "speed.txt" file
    for(i = 0; i < 20; i++){
        fscanf(arch, "%d", &num[i]);
    }

    //printing the 20 speed values stored in the variable: int num[20]
    printf("\n\nSTORED SPEED NUMBERS: {");
    for(i = 0; i < 20; i++){
        printf(" %d ", num[i]);
    }
    printf("}");


    //analyzing how many values ​​exceed the speed limit of 100 km/h
    for(i = 0; i < 20; i++){
        if(num[i] > max){
            crossed++;
        }
    }
    printf("\n\nIn total %d cars exceed the speed limit of 100 km/h", crossed);

    fclose(arch);

    return 0;
}
