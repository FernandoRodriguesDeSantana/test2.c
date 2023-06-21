#include <stdio.h>
#include <stdlib.h>

//this function takes a value in km/h and converts it to m/s
float convert(float n){
    float speed_converted = 0;

    speed_converted = n * 0.278;

    return speed_converted;
}

int main(){
    FILE *arch;
    int i, num[20], crossed = 0, max = 100, total_speed = 0;
    float average_speed = 0, aux = 0;

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
    printf("\n\nSTORED SPEED VALUES: {");
    for(i = 0; i < 20; i++){
        printf(" %d ", num[i]);
    }
    printf("}");


    //analyzing how many values ​​exceed the speed limit of 100 km/h and calculating the total speed
    for(i = 0; i < 20; i++){
        if(num[i] > max){
            crossed++;
        }
        total_speed = total_speed + num[i];
    }
    printf("\n\nIn total %d cars exceed the speed limit of 100 km/h", crossed);

    //calculating and printing the average speed
    average_speed = total_speed / 20;
    printf("\n\nThe average speed is %.2f km/h", average_speed);

    //converting the average speed in km/h to m/s and printing it
    aux = convert(average_speed);
    printf("\n\nThe average speed converted to m/s is %.2f", aux);

    fclose(arch);

    return 0;
}
