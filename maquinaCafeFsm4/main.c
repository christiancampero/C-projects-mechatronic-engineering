#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // para función Sleep
#include "maquinaCafeFsm4.h"

//estados descartados: control, expresoLargo, expresoCorto, capuccino,


void esperarando()
{
    printf("\nBienvenido! Ingrese un billete (opciones: 1, 0)\n"); //pido billete al usuario de la maquina
    scanf("%d", &billete);
    switch(billete)
    {
        case 0:
            no_billete();
            break;

        case 1:
            billete_ok();
            break;
    }


}
void billete_ok()
{
    molerCafe = 1;
    calentarAgua = 1;
    liberarVaso = 1;
    printf("Moliendo cafe...\n");
    Sleep(2000);
    printf("Calentando el agua, espere...\n");
    Sleep(3000);
    printf("Vaso listo...\n");
    Sleep(3000);
    estado = estado_menuSeleccion; //mientras se muele el cafe y se calienta el agua, se pasa al siguiente estado (menu)
}

void no_billete()
{
    molerCafe = 0;
    calentarAgua = 0;
    liberarVaso = 0;
    estado = estado_esperando;
}

void menuSeleccion() // se muestra el menu y pasa al siguiente estado
{
    printf("\nBienvenido al menu de seleccion de la maquina de cafe. Las opciones son: \n 1-Expreso corto\n 2-Expreso largo\n 3-Capuccino\n");
    printf("\nCual eliges?\n");
    estado = estado_empezar;

}

void expreso_corto()
{
    cafe = 1;
    printf("Dispensando cafe molido...\n");
    Sleep(1000);
    cafe = 0;

    agua = 1;
    printf("Dispensando agua caliente...\n");
    Sleep(1000);
    agua = 0;
    printf("Expreso corto listo para retirar. Gracias por su compra!\n");
    estado = estado_esperando;

}

void expreso_largo()
{

    cafe = 1;
    printf("Dispensando cafe molido...\n");
    Sleep(1000);
    cafe = 0;

    agua = 1;
    printf("Dispensando agua...\n");
    Sleep(3000);
    agua = 0;

    printf("Expreso largo listo para retirar. Gracias por su compra!\n");
    estado = estado_esperando;
}

void cafe_capuccino()
{
    cafe = 1;
    printf("Dispensando cafe molido...\n");
    Sleep(1000);
    cafe = 0;

    agua = 1;
    printf("Dispensando agua caliente...\n");
    Sleep(1000);
    agua = 0;

    leche = 1;
    vapor = 1;
    printf("Dispensando leche y haciendo espuma...\n");
    Sleep(1000);
    leche = 0;
    vapor = 0;
    printf("Capuccino listo para retirar. Gracias por su compra!\n");
    estado = estado_esperando;
}

void empezar()
{
    scanf("%d", &cafe2); //el usuario elige entre el menu

    switch(cafe2)
    {
        case expresoC:
            expreso_corto();
            break;

        case expresoL:
            expreso_largo();
            break;

        case Capucc:
            cafe_capuccino();
            break;

        default:
            printf("Esa opcion de cafe no existe! Vuelva a seleccionar el tipo de cafe\n\n");
            //scanf("%d", &cafe2);
            break;
    }


}

int main()
{
    void(*maquina_controlFSM[ESTADO_MAX])(void); //array de punteros a funcion, tamaño [ESTADO_MAX]
    maquina_controlFSM[0] = esperarando;
    maquina_controlFSM[1] = empezar;
    maquina_controlFSM[2] = menuSeleccion;


    while(1) //super loop
    {
        maquina_controlFSM[estado]();
        //maquina_cafeFSM();
        mantenimiento_maquinaFSM();
    }

    return 0;
}

