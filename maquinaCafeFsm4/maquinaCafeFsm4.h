#ifndef MAQUINACAFEFSM4_H_INCLUDED
#define MAQUINACAFEFSM4_H_INCLUDED

enum estadosMaq{
    estado_esperando, estado_empezar, estado_menuSeleccion, ESTADO_MAX
}estado = estado_esperando;

enum tiposCafe{
    expresoC = 1, expresoL, Capucc,
}tiposCafe;


//estadosMaq estado = esperando;
int billete = 0;
int calentarAgua = 0;
int agua, cafe, leche, vapor, cafe2, molerCafe, liberarVaso;

void empezar();
void esperarando();
void menuSeleccion();
void expreso_corto();
void expreso_largo();
void cafe_capuccino();
//void maquina_cafeFSM();
void mantenimiento_maquinaFSM();
void billete_ok();
void no_billete();

void mantenimiento_maquinaFSM() //funcion para verificar el estado de la maquina
{
    if(calentarAgua != 1 && calentarAgua != 0) //&& calentarAgua < 0)
    {
        printf("Se genero un problema con la maquina...\n");
        Sleep(1000);
        printf("La bateria tiene baja tension! Recarge la bateria\n");
    }

    if(molerCafe != 1 && molerCafe != 0)
    {
        printf("No hay granos de cafe! Por favor vuelva a llenar el deposito\n");
    }

    if(agua != 1 && agua != 0)
    {
        printf("\nProblema con el agua! Por favor verifique el deposito de agua\n");
    }

}

/*void maquina_cafeFSM()
{

    switch(estado)
    {
        case esperando:
            estado_esperarando();
            break;

        case menuSeleccion:
            estado_menuSeleccion();
            break;

        case empezar:
            estado_empezar();
            break;
    }

}*/

#endif // MAQUINACAFEFSM4_H_INCLUDED
