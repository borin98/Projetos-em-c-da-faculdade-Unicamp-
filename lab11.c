#include <stdio.h>

int Divisao ( int Dado_Entrada, int Ajuda_Luciano, int vetor_divisao[], int vetor_resto[] )
{

  int a = 0;

  if ( Dado_Entrada >= 100 && Ajuda_Luciano == 0)
  {

    vetor_resto[Ajuda_Luciano] = Dado_Entrada%10;

    vetor_divisao[Ajuda_Luciano] = Dado_Entrada/10;

    Ajuda_Luciano = 1;

  a =  Divisao ( Dado_Entrada, Ajuda_Luciano, vetor_divisao, vetor_resto );

  }

  else if ( Dado_Entrada < 100 && Ajuda_Luciano == 0 )
  {

    vetor_resto[Ajuda_Luciano] = Dado_Entrada%10;

    vetor_divisao[Ajuda_Luciano] = Dado_Entrada/10;

    Ajuda_Luciano = 2;

  a = Divisao ( Dado_Entrada, Ajuda_Luciano, vetor_divisao, vetor_resto );

  }

  else if ( Ajuda_Luciano == 1 && Dado_Entrada >= 100)
  {

    vetor_divisao[Ajuda_Luciano] = vetor_divisao[Ajuda_Luciano - 1]/10;

    vetor_resto[Ajuda_Luciano] = vetor_divisao[Ajuda_Luciano - 1]%10;

    Ajuda_Luciano = 2;

    a = Divisao ( Dado_Entrada, Ajuda_Luciano, vetor_divisao, vetor_resto );

  }


  else if ( Ajuda_Luciano == 2 && Dado_Entrada >= 100)
  {

    a = (vetor_resto[0]* vetor_resto[1]);
  /*  return (vetor_resto[0]* vetor_resto[1]);*/

  }

  else if ( Ajuda_Luciano == 2 && Dado_Entrada < 100 )
  {

    a = ( vetor_resto[0]*vetor_divisao[0] );
  /*  return ( vetor_resto[0]*vetor_divisao[0] );*/

  }

  return a;
}


int Vida_Em_Jogo ( int Dado_Entrada )
{

  int aux, aux2;
  int Ajuda_Luciano = 0;
  int vetor_divisao[2], vetor_resto[2];
  int passa = 0;


   if ( Dado_Entrada > 42  && ( Dado_Entrada%5 == 0 || Dado_Entrada%3 == 0 || Dado_Entrada%4 == 0 ||  Dado_Entrada%2 == 0 ) )
  {

    if (  Dado_Entrada%5 == 0 && passa == 0 && Dado_Entrada > 42)
    {

      Dado_Entrada = Dado_Entrada - 42;

      passa = Vida_Em_Jogo ( Dado_Entrada);

      if ( passa == 0 &&  (Dado_Entrada%3 == 0 || Dado_Entrada%4 == 0 || Dado_Entrada%2 == 0) )
      {

        Dado_Entrada = Dado_Entrada + 42;

      }

    }

     if ( (Dado_Entrada%3 == 0 || Dado_Entrada%4 == 0) && passa == 0 && Dado_Entrada > 42)
    {

      aux = Divisao ( Dado_Entrada, Ajuda_Luciano, vetor_divisao, vetor_resto);

      if ( aux != 0 &&  Dado_Entrada > 42 && Dado_Entrada > 42)
      {

        Dado_Entrada = Dado_Entrada - aux;

        passa = Vida_Em_Jogo ( Dado_Entrada );

        if ( passa == 0 && (Dado_Entrada%5 == 0 || Dado_Entrada%2 == 0) )
        {

          Dado_Entrada = Dado_Entrada + aux;

        }

      }

    }

    if ( Dado_Entrada%2 == 0 && passa == 0 && Dado_Entrada > 42)
   {

     aux2 = (Dado_Entrada/2);

     Dado_Entrada = Dado_Entrada - (Dado_Entrada/2);

     passa = Vida_Em_Jogo ( Dado_Entrada);

     if ( passa == 0 && (Dado_Entrada%5 == 0 || Dado_Entrada%4 == 0 || Dado_Entrada%3 == 0 ||Dado_Entrada%2 == 0) )
     {

       Dado_Entrada = Dado_Entrada + aux2;

     }

   }

  }

  if ( passa == 1 )
  {

    return 1;

  }

  else if ( ( Dado_Entrada%5 != 0 && Dado_Entrada%3 != 0 && Dado_Entrada%4 != 0 &&  Dado_Entrada%2 != 0 ) )
  {

    return 0;

  }

  else if ( Dado_Entrada == 42 || passa == 1)
  {

    return 1;

  }

  return passa;
}


int main ( void )
{
  int Dado_Entrada;
  int Resultado;

  scanf("%d", &Dado_Entrada);

  Resultado =  Vida_Em_Jogo ( Dado_Entrada);


  if ( Resultado == 1 )
  {

    printf("Sim");

  }

  else
  {

    printf("Nao");

  }

  printf("\n");

  return 0;
}
