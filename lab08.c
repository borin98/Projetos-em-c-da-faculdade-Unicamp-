/*  *MC 102

    *Lab08
    *Turma : I
    *Aluno : Gabriel Borin Macedo
    *Ra : 197201
    *Objetivos : O objetivo deste laboratório é simular uma leitura de um arquivo SVG, onde receberemos as informações dessa imagem e faremos as modificações dele a partir das funçoes dadas abaixo.
    Assim, sua saída será a nova figura modificada aplicada as operações destas funções. */


#include <math.h>
#include "lab08.h"

#define MAX_POINTS      500
#define MAX_OPERATIONS  60000
#define MAX_STYLE       256
#define MY_PI 3.14159265358979323846

void Operacao_De_Translacao ( double op_p[][2], double MATRIZ_ARMAZENAMENTO[][2], int n[], int q )
{

  int a;

  for ( a = 0; a < n[0]; a++  )
  {

    MATRIZ_ARMAZENAMENTO[a][0] = op_p[q][0] + MATRIZ_ARMAZENAMENTO[a][0];
    MATRIZ_ARMAZENAMENTO[a][1] = op_p[q][1] + MATRIZ_ARMAZENAMENTO[a][1];

  }

}

void Operacao_De_Rotacao (double op_p[][2],  double MATRIZ_ARMAZENAMENTO[][2], int n[], int q )
{

  int d;

  double X, Y;

  for ( d = 0; d < n[0]; d++ )
  {

    X = MATRIZ_ARMAZENAMENTO[d][0];
    Y = MATRIZ_ARMAZENAMENTO[d][1];


     MATRIZ_ARMAZENAMENTO[d][0] =  X*cos( ( op_p[q][0]*MY_PI )/180 ) - Y*sin ( ( op_p[q][0]*MY_PI )/180 );
     MATRIZ_ARMAZENAMENTO[d][1] = Y*cos ( ( op_p[q][0]*MY_PI )/180 ) + X*sin (  ( op_p[q][0]*MY_PI)/180 );

  }


}


void Operacao_De_Escala (  double op_p[][2],  double MATRIZ_ARMAZENAMENTO[][2], int n[], int q )
{

  int b;

  for ( b = 0; b < n[0]; b++ )
  {

      MATRIZ_ARMAZENAMENTO[b][0] = op_p[q][0]*MATRIZ_ARMAZENAMENTO[b][0];
      MATRIZ_ARMAZENAMENTO[b][1] = op_p[q][1]*MATRIZ_ARMAZENAMENTO[b][1];

  }

}

void Leitura_Das_Operacoes ()
{

  int op_n[1], i;

  double op_p[MAX_OPERATIONS][2];

  char op_s[MAX_OPERATIONS];
  /* Variáveis que armazenam um polígono */
  int n[1], q;

  double p[MAX_POINTS][2];

  char s[MAX_STYLE];

  int j;

  double MATRIZ_ARMAZENAMENTO[MAX_OPERATIONS][2];

      scan_svg ( op_n, op_p, op_s);   /* salvando as operações que serao lidas mais pra frente  */

      n[0] = 0;

      while ( n[0] >= 0 )
      {

          scan_svg (n, p, s);

         for ( i = 0; i < op_n[0]; i++ )
         {

            if (op_s[i] == 'C')
            {

              for ( j = 0; j < n[0]; j++ ) /* ARMAZENA OS PONTOS EM UMA MATRIZ */
              {

                MATRIZ_ARMAZENAMENTO[j][0] = p[j][0]; /* coordenada de X */
                MATRIZ_ARMAZENAMENTO[j][1] = p[j][1]; /* Coordenada de Y */

              }

              for ( q = i + 1; q < op_n[0] && op_s[q] != 'C' ; q++ )
              {

                if ( op_s[q] == 'T' )
                {

                  Operacao_De_Translacao ( op_p, MATRIZ_ARMAZENAMENTO,  n, q );

                }

                else if ( op_s[q] == 'S' )
                {

                  Operacao_De_Escala ( op_p, MATRIZ_ARMAZENAMENTO, n, q );

                }

                else if ( op_s[q] == 'R' )
                {

                  Operacao_De_Rotacao ( op_p,  MATRIZ_ARMAZENAMENTO, n, q );

                }

              }

              print_svg ( n, MATRIZ_ARMAZENAMENTO, s);

            }

          }

     }

}


int main() 
{

  Leitura_Das_Operacoes ();

  close_svg();

  return 0;
}
