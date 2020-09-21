#include <stdio.h>
#include <time.h> //para funcion sleep()
#include <unistd.h>
#include <stdlib.h>

void reloj_fsm();
void reloj_fsm2();
void reloj_fsm3();
int horas = 0, minutos = 0, segundos = 0;

void reloj_fsm()
{
    system("cls");

        printf("   Reloj:\n");
        printf("\n-----------------------\n");
        printf("  ||%02d : %02d : %02d ||", horas, minutos, segundos); //muestra el reloj en formato HH : MM : SS
        printf("\n-----------------------");
        //fflush(stdout);

        segundos++;

        if(segundos == 60)
        {
            minutos += 1;
            segundos = 0;
        }

        if(minutos == 60)
        {
            horas += 1;
            minutos = 0;
        }

        if(horas == 24)
        {
            horas = 0;
            minutos = 0;
            segundos = 0;
        }

        reloj_fsm2();
        reloj_fsm3();
        sleep(1);   //espera 1 segundo

}

void reloj_fsm2()
{
    if(segundos % 5 == 0)
    {
        printf("\nHan pasado 5 segundos...\n");
    }
}

void reloj_fsm3()
{

    if(segundos % 15 == 0)
    {
        printf("\nHan pasado 15 segundos...\n");
    }

}


int main()
{


    while(1)
    {
        reloj_fsm();
        //reloj_fsm2();
        //reloj_fsm3();
    }

    return 0;
}
