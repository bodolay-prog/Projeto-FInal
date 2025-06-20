#include <stdio.h>


int main(){

    unsigned char device = 0, reading = 0, status = 0;

    //reading bits range: 7-4
    //status bits range: 3-0
    
    //Codification
    for(int i = 0; i < 4; i++){

        //Input
        printf("Device[%d]:\n", i + 1);
        printf("Enter its 'read' situation (0 - Low; 1 = High): ");
        scanf("%hhu", &reading);

        if(reading != 1 && reading != 0) return 1;

        //'reading' bitwise for 'device'
        device |= (reading << (i + 4));

        printf("Enter its 'status' situation (0 - Off; 1 - On): ");
        scanf("%hhu", &status);

        if(status != 1 && status != 0) return 1;

        //'status' bitwise for 'device'
        device |= (status << i);

        printf("-----------------------\n");
    }

    printf("\n\n");

    //Current protocol situation
    printf("The current status of the protocoled signal is:\n");
    for(int k = 7; k >= 0; k--){

        printf("%d ", (device >> k) & 1);
    }

    printf("\n\n");

    //Decoding
    for(int i = 0; i < 4; i++){

        unsigned char ID;
        printf("Enter the ID of the device you want to consult (0 to 3): ");
        scanf("%hhu", &ID);

        if(ID > 3) return 1;

        status = (device >> (ID)) & 1;
        reading = (device >> (ID + 4) + 4) & 1;

        printf("Device %d - ", ID);
        printf("%s - ", status == 1 ? "On" : "Off");
        printf("%s\n\n", status == 1 ? "High": "Low");
        break;
    }

    return 0;
}