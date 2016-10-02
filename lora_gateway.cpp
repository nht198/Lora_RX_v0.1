#include "SX1272.h"
char my_packet[100];
int main (int argc, char *argv[]){
        int e;
        e=sx1272.ON();
        if (e==0)
        printf("Setting POWER ON: SUCCES\n");
        else
        printf("Setting Power ON: ERROR \n");

        e= sx1272.setMode(1);
        if (e==0)
        printf("Setting Mode: SUCCES\n");
        else
        printf("Setting Mode: ERROR \n");
        e= sx1272.setHeaderON();
        if (e==0)
        printf("Setting Header ON: SUCCESS\n");
        else
        printf("Setting Header ON: ERROR \n");

        e= sx1272.setChannel(CH_00_433);
        if (e==0)
        printf("Setting Channel: SUCCESS\n");
        else
        printf("Setting Channel: ERROR \n");
        e= sx1272.setCRC_ON();
        if (e==0)
        printf("Setting CRC: SUCCESS\n");
        else
        printf("Setting CRC: ERROR \n");

        e= sx1272.setPower('x');
        if (e==0)
        printf("Setting Power: SUCCESS\n");
        else
        printf("Setting Power: ERROR \n");
	        e= sx1272.setNodeAddress(1);
        if (e==0)
        printf("Setting Node address: SUCCESS\n");
        else
        printf("Setting Node address: ERROR \n");


        while(1)
        {
                e= sx1272.receivePacketTimeout(10000);
                if (e==0)
                {
                        printf("packet received success\n");
                        printf("%x\n",sx1272.packet_received.length);
     for (unsigned int i = 0; i < sx1272.packet_received.length; i++) {
            my_packet[i] = (char)sx1272.packet_received.data[i];
//      printf("%x\n",sx1272.packet_received.data[i]);
                 }
            printf(my_packet);
                }
                else printf("error\n");
             delay(1000);
        }
return 0;
}

