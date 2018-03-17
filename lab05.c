#include <stdio.h>
/* MC 102 - Algoritmos e Programação de Computadores
*   Lab05
*   Nome : Gabriel Borin Macedo.
*   Ra : 197201
*   Turma : I
*   Objetivo : Neste lab, faremos um programa que irá verificar se a dança de um grifo Macho é compatível com a dança de uma grifo fêmea.No qual será possível atrávez dos dados de entrada que são, respectivamente a quantidade de passos que o grifo fêmea dará e depois o do macho, Logo após isso, teremos dados que são de um vetor de tamanho até 1000 do dobro dos primeiros dados de entrada, onde metade deles serão as direções que os grifos podem andar, variando de 0 à 7 e  do quanto que ele andou aque chega até  100 metros . Já os dados de saída será uma das possiveis mensagens  : Compatibilidade total, Incompatibilidade total e Reverso tem compatibilidade */




int main ( void )
{

    int Passos_Femea, Passos_Macho,Compativel, vetor1 [1000], vetor2 [1000], P[8]={0, 0, 0, 0, 0, 0, 0, 0}; /* Indica a quantidade de passos que o macho e a femea darao */

    int interacao, posicao_femea, posicao_macho, posicao_atual_macho, posicao_atual_femea, F, M, ip, saldo, saldo_anterior;

    scanf("%d %d", &Passos_Femea, &Passos_Macho );




    for (F = 0; F < 2 * Passos_Femea; F++) /* Acumulando os valores dos passos dos grifos */
    {
        scanf("%d", &vetor1[F] );
    }

    for(M = 0; M < 2 * Passos_Femea; M++)
    {
        scanf("%d", &vetor2[M] );
    }

    Compativel = 0;

    posicao_femea = 360 - vetor1[0]*45;
    posicao_macho = 360 - vetor2[0]*45;

    posicao_atual_femea = posicao_femea;
    posicao_atual_macho = posicao_macho;

    ip=0;

      for ( interacao = 0; interacao < 2 *  Passos_Femea ; interacao = interacao + 2 )
        {
          ip=vetor1[interacao];
          P[ip]=P[ip] + vetor1[interacao+1];
        }

    if ( P[0] != P[4] || P[1] != P[5] || P[2] != P[6] || P[3] != P[7] || Passos_Femea != Passos_Macho)
    {
        Compativel = 9;
    }

    for  ( interacao = 0; interacao < 2 * Passos_Femea && Compativel != 9 && Compativel != 8; interacao++ )
    {

      if ( interacao%2 != 0)
      {
          if   (interacao <= (2 * Passos_Femea) - 2)
          {
                if    ( (vetor2[interacao]*100) / vetor1[interacao] == (vetor2[interacao + 2] * 100) / vetor1[interacao + 2] && ( (vetor2[interacao]*100) / vetor1[interacao]) > 100 )
                          {
                            Compativel  = 1;

                          }
                          else

                          {
                            Compativel = 8;
                          }
          }
      }

      else
      {

         posicao_atual_femea = posicao_femea + (vetor1[interacao]*45);
         posicao_atual_macho = posicao_macho + (vetor2[interacao]*45);


          if ( posicao_atual_femea  >= 360 )
          {
               posicao_atual_femea =  posicao_atual_femea - 360;
          }

          if (posicao_atual_macho  >= 360 )
          {
              posicao_atual_macho = posicao_atual_macho - 360;
          }
          if (posicao_atual_femea != posicao_atual_macho  )
          {
              Compativel = 8;
          }
      }
  }


if ( Compativel == 8 )
{
  Compativel = 2;
   M = (2 * Passos_Macho) - 1;
   posicao_macho = 360 - (vetor2[M - 1]  * 45);
   posicao_femea = 360 - (vetor1[0]*45);
   posicao_atual_femea = posicao_femea;
   posicao_atual_macho = posicao_macho;

   saldo_anterior=0;
  for ( interacao = 0; interacao < 2 *  Passos_Femea && Compativel != 8; interacao=interacao + 2 )
{


  posicao_atual_femea = posicao_femea   + (vetor1[interacao] * 45);
  posicao_atual_macho = posicao_macho + (vetor2[M - 1] * 45);
  if ( posicao_atual_femea >= 360 )
  {
      posicao_atual_femea = posicao_atual_femea - 360;
  }
  if ( posicao_atual_macho >= 360 )
  {
      posicao_atual_macho = posicao_atual_macho - 360;
  }
  /*printf("Direcao: %d || %d || %d || %d \n",  posicao_atual_femea, posicao_atual_macho,M - 1, interacao);*/

  if ( posicao_atual_macho != posicao_atual_femea )
     {
         Compativel = 8;
     }

  saldo =  ( (vetor2[M] * 100) / vetor1[interacao+1]) ;
/*  printf("Passo: %d || %d || %d || %d \n", saldo, saldo_anterior, vetor2[M], interacao + 1);*/
  if (interacao > 0  && (saldo <= 100 ||  saldo != saldo_anterior) )
        {
            Compativel  = 8;
        }
  saldo_anterior = saldo;
  M=M - 2;
}
}

   if ( Compativel == 1 )
    {
        printf("Compatibilidade natural.\n" );
    }

    else  if  (Compativel == 2 )
     {
        printf("Reverso tem compatibilidade.\n");
    }
    else
    {
        printf("Incompatibilidade total.\n");
    }

    return 0;
}
