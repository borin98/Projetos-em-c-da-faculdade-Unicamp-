#include <stdio.h>
/*Mc102 Algorítimos e Programação de Computadores

*Nome : Gabriel Borin Macedo
*Ra : 197201
*Turma : I
*Objetivo : Neste lab, iremos simular uma entrada de dado de imagem com formato P1 e respectivamente a largura (colunas) e tamanho (Linha) da matriz. Além disso, entrada com dados binários nela, onde "1" é um pedaço de terra e "0" é mar. O objetivo no final será printar quantas ilhas cada arquivo de imagem P1 possui. */ 

int main()
{
    int i, j, M[300][300], col, lin, b, contador;
    int  k, vetor [90000], Primeira_Vez, vetor_aux ;
    int a, d ;
    char c;


    scanf("%c %d", &c, &b);
    scanf("%d %d", &j, &i);

    a = i*j;

    for ( lin = 0; lin < i; lin ++)
    {

      for ( col = 0; col < j; col ++ )
      {

          scanf("%d", &M[lin][col]);

      }

    }

    contador = 1;
    Primeira_Vez = 0;
   
    for ( lin = 0; lin < i; lin ++ )
    {

      for ( col = 0; col < j; col ++ )
      {

       if (M[lin][col] == 1 )
       {
         contador = contador + 1;
         M[lin][col] = contador;

           if (lin - 1 >=  0  && M[lin - 1][col] > 1 ) 
           {

               M[lin][col] = M[lin - 1][col];

           }

           if (lin - 1 >= 0 &&  col + 1 <= j && M[lin - 1][col + 1] > 1)
           {

               M[lin][col] = M[lin - 1][col + 1] ;

           }

           if ( col + 1 <= j && M[lin][col + 1] > 1) 
           {

               M[lin][col] = M[lin][col + 1];

           }

           if (lin + 1 <= i && col + 1 <= j && M[lin + 1][col + 1] > 1)
           {

               M[lin][col] = M[lin + 1][col + 1];

           }

           if (lin + 1 <= i  && M[lin + 1][col] > 1)
           {

               M[lin][col] = M[lin + 1][col];

           }

          if (lin + 1 <= i && col - 1 >= 0  && M[lin + 1][col - 1] > 1)
           {

             M[lin][col] = M[lin + 1][col - 1];

           }

          if ( col - 1 >= 0  && M[lin][col - 1] > 1)
           {

             M[lin][col] = M[lin][col - 1];

           }

          if (lin - 1 >= 0  && col - 1 >= 0  && M[lin - 1][col - 1] > 1)
          {

             M[lin][col] = M[lin - 1][col - 1];

          }

       }

     }

    }

    for ( k = 0; k < 600; k++ )
    {

      for ( lin = 0; lin < i; lin++ )
      {
          for ( col = 0; col < j; col++ )
          {

            if (M[lin][col] > 1 )
            {
      
                if (lin - 1 >= 0 && M[lin - 1][col] > M[lin][col] ) 
                {

                    M[lin][col] = M[lin - 1][col];

                }

                if (lin - 1 >= 0 && col + 1 <= j && M[lin - 1][col + 1] > M[lin][col] ) 
                {

                    M[lin][col] = M[lin - 1][col + 1] ;
         
                }

                if ( col + 1 <= j && M[lin][col + 1] > M[lin][col]) /* //2 */
                {

                    M[lin][col] = M[lin][col + 1];
           
                }

                if (lin + 1 <= i && col + 1 <= j && M[lin + 1][col + 1] > M[lin][col] )
                {

                    M[lin][col] = M[lin + 1][col + 1];
          
                }

                if (lin + 1 <= i && M[lin + 1][col] > M[lin][col] ) 
                {

                    M[lin][col] = M[lin + 1][col];

                }

               if (lin + 1 <= i && col - 1 >= 0  && M[lin + 1][col - 1] > M[lin][col] )
                {

                  M[lin][col] = M[lin + 1][col - 1];

                }

               if ( col - 1 >= 0 && M[lin][col - 1] > M[lin][col] ) 
                {

                  M[lin][col] = M[lin][col - 1];

                }

               if (lin - 1 >= 0 && col - 1 >= 0 && M[lin - 1][col - 1] > M[lin][col] ) /
                {

                  M[lin][col] = M[lin - 1][col - 1];
               
                }

            }

          }

      }

    }
    Primeira_Vez = 0;
    contador = 0;

    d = 0;
    for ( lin = 0; lin < i; lin ++)
    {

      for ( col = 0; col < j; col ++ )
      {

        if ( M[lin][col] > 0  )
         {

              vetor[d] = M[lin][col];

         }

        d++;

      }
   

    }


    for ( i = 0; i < a; i++ )
    {
        for ( j = i + 1; j < a; j++ )
        {

            if ( vetor[i] > vetor[j] )

            {
                vetor_aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = vetor_aux;
            }



        }

    }

    Primeira_Vez = 0;
    contador = 0;
    for ( i = 0; i <= a; i++ )
    {
        if ( vetor[i] > Primeira_Vez )
        {
            contador = contador + 1;
            Primeira_Vez = vetor[i];
        }

    }

    printf("%d\n", contador);

    return 0;
}
