#include <stdio.h>

int cuenta; /*cuenta es una variable global*/

void Func1 (void);

void Func2 (void);

int main(void){

  cuenta = 10;

  printf ("A la entrada del main cuenta es %d\n", cuenta); /*muestra el valor de cuenta*/

  Func1 ();

  printf ("A la salida del main cuenta es %d\n", cuenta); /*muestra el valor de cuenta*/

  return 0;

}

void Func1 (void){

  int temp;

  temp = cuenta;

  Func2 ();

  printf ("A la salida de Func1 temp es %d y cuenta es %d\n", temp,cuenta); /*muestra el valor de temp*/

}

void Func2 (void){

  /*int cuenta;*/

  cuenta = 15;

  printf ("A la salida de Func2 cuenta es %d\n", cuenta); /*muestra el valor de cuenta*/ 

}