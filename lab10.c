/*  MC 102 - Algoritmos e Programação de Computadores

* Nome : Gabriel Borin Macedo

* Ra : 197201

*Objetivo : Neste lab, faremos um autômato, no qual é um robo que simulará uma orquesta de acordo com os dados de entrada recebido e organizará em ordem crescente estes sons, no estilo de uma tabela SQL
  organizada da seguinte forma das colunas, da direita para a esquerda : Instante, Instrumento, Nota e Intensidade.
  Os dados de saída será esta tabela com os seus elementos ordenados. */


#include "lab10.h"
#include <stdio.h>
#include<stdlib.h>

int main ( void )
{

  int i, j;
  int aux1 =1, aux2 = 1, aux3 = 1, aux4 = 1, vanitas= 1;
  int aux;
  int tam_vetor1 = 0;

  int *vet_aux = (int*) malloc(sizeof(int) );

 TpEvento *evento =(malloc(sizeof( TpEvento ) ) );

  for ( i = 0; aux1 != 0 || aux2 != 0 || aux3 != 0 || aux4 != 0 || vanitas != 0;i++ )
  {

    scanf ( "%d %d %d %d %d", &evento[i].instrumento, &evento[i].nota, &evento[i].intensidade, &evento[i].instante, &vanitas );

    evento = realloc ( evento, ( ( i + 1 )*10)*sizeof( TpEvento ) );
    vet_aux = realloc ( vet_aux, ( ( i + 1 ))*sizeof( int ) );

    aux1 = evento[i].instrumento;
    aux2 = evento[i].nota;
    aux3 = evento[i].intensidade;
    aux4 = evento[i].instante;
    vet_aux[i] = evento[i].instante + vanitas;

    if ( aux1 != 0 || aux2 != 0 || aux3 != 0 || aux4 != 0 || vanitas != 0 )
    {

      tam_vetor1++;

    }

  }

  evento = realloc ( evento, ( (tam_vetor1)*10)*sizeof( TpEvento ) );

  for ( i = 0; i < tam_vetor1; i++ )
  {

    evento[i + tam_vetor1].instante = vet_aux[i];
    evento[i + tam_vetor1].instrumento = evento[i].instrumento;
    evento[i + tam_vetor1].nota = evento[i].nota;
    evento[i + tam_vetor1].intensidade = 0;

  }

  tam_vetor1 = tam_vetor1 + i;

  for(i = 1; i < tam_vetor1; i++)
  {
      j = i;
      while( j > 0)
      {

          if(evento[ j - 1 ].instante > evento[ j ].instante)
          {

              aux = evento[ j ].instante;
              evento[ j ].instante = evento[ j - 1].instante;
              evento[ j - 1].instante = aux;

              aux = evento[ j ].instrumento;
              evento[ j ].instrumento = evento[ j - 1].instrumento;
              evento[ j - 1].instrumento = aux;

              aux = evento[ j ].nota;
              evento[ j ].nota = evento[ j - 1].nota;
              evento[ j - 1].nota = aux;

              aux = evento[ j ].intensidade;
              evento[ j ].intensidade = evento[ j - 1].intensidade;
              evento[ j - 1].intensidade = aux;

          }

          else if ( evento[ j - 1 ].instante == evento[ j ].instante && evento[ j - 1 ].instrumento > evento[ j ].instrumento)
          {

            aux = evento[ j ].instante;
            evento[ j ].instante = evento[ j - 1].instante;
            evento[ j - 1].instante = aux;

            aux = evento[ j ].instrumento;
            evento[ j ].instrumento = evento[ j - 1].instrumento;
            evento[ j - 1].instrumento = aux;

            aux = evento[ j ].nota;
            evento[ j ].nota = evento[ j - 1].nota;
            evento[ j - 1].nota = aux;

            aux = evento[ j ].intensidade;
            evento[ j ].intensidade = evento[ j - 1].intensidade;
            evento[ j - 1].intensidade = aux;

          }

          else if ( evento[ j - 1 ].instante == evento[ j ].instante && evento[ j - 1 ].instrumento == evento[ j ].instrumento && evento[ j - 1 ].nota > evento[ j ].nota )
          {

            aux = evento[ j ].instante;
            evento[ j ].instante = evento[ j - 1].instante;
            evento[ j - 1].instante = aux;

            aux = evento[ j ].instrumento;
            evento[ j ].instrumento = evento[ j - 1].instrumento;
            evento[ j - 1].instrumento = aux;

            aux = evento[ j ].nota;
            evento[ j ].nota = evento[ j - 1].nota;
            evento[ j - 1].nota = aux;

            aux = evento[ j ].intensidade;
            evento[ j ].intensidade = evento[ j - 1].intensidade;
            evento[ j - 1].intensidade = aux;
          }

          else if ( evento[ j - 1 ].instante == evento[ j ].instante && evento[ j - 1 ].instrumento == evento[ j ].instrumento && evento[ j - 1 ].nota == evento[ j ].nota && evento[ j - 1 ].intensidade > evento[ j ].intensidade )
          {

            aux = evento[ j ].instante;
            evento[ j ].instante = evento[ j - 1].instante;
            evento[ j - 1].instante = aux;

            aux = evento[ j ].instrumento;
            evento[ j ].instrumento = evento[ j - 1].instrumento;
            evento[ j - 1].instrumento = aux;

            aux = evento[ j ].nota;
            evento[ j ].nota = evento[ j - 1].nota;
            evento[ j - 1].nota = aux;

            aux = evento[ j ].intensidade;
            evento[ j ].intensidade = evento[ j - 1].intensidade;
            evento[ j - 1].intensidade = aux;

          }
          j--;

      }

  }

  saida ( 0, tam_vetor1, evento );

  free ( evento );

  return 0;
}
