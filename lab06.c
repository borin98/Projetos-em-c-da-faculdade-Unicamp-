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

   /*printf("--------------------------------------\n"); */

    contador = 1;
   /* troca = 0; */
    Primeira_Vez = 0;
    for ( lin = 0; lin < i; lin ++ )
    {

      for ( col = 0; col < j; col ++ )
      {

       if (M[lin][col] == 1 )
       {
         contador = contador + 1;
         M[lin][col] = contador;

           if (lin - 1 >=  0  && M[lin - 1][col] > 1 )   /* //0 */
           {

               M[lin][col] = M[lin - 1][col];

           }

           if (lin - 1 >= 0 &&  col + 1 <= j && M[lin - 1][col + 1] > 1) /* //1 */
           {

               M[lin][col] = M[lin - 1][col + 1] ;

           }

           if ( col + 1 <= j && M[lin][col + 1] > 1) /* //2 */
           {

               M[lin][col] = M[lin][col + 1];

           }

           if (lin + 1 <= i && col + 1 <= j && M[lin + 1][col + 1] > 1) /* //3 */
           {

               M[lin][col] = M[lin + 1][col + 1];

           }

           if (lin + 1 <= i  && M[lin + 1][col] > 1) /* //4 */
           {

               M[lin][col] = M[lin + 1][col];

           }

          if (lin + 1 <= i && col - 1 >= 0  && M[lin + 1][col - 1] > 1) /* //5 */
           {

             M[lin][col] = M[lin + 1][col - 1];

           }

          if ( col - 1 >= 0  && M[lin][col - 1] > 1) /* //6 */
           {

             M[lin][col] = M[lin][col - 1];

           }

          if (lin - 1 >= 0  && col - 1 >= 0  && M[lin - 1][col - 1] > 1) /* //7 */
           {

             M[lin][col] = M[lin - 1][col - 1];

           }


       }


     }

    }

/*  //  contador = 1;
  //  verificador[300][300] = contador; */
    for ( k = 0; k < 600; k++ )
    {

      for ( lin = 0; lin < i; lin++ )
      {
          for ( col = 0; col < j; col++ )
          {

            if (M[lin][col] > 1 )
            {
        /*    //  contador = contador + 1;
            //  M[lin][col] = contador; */

                if (lin - 1 >= 0 && M[lin - 1][col] > M[lin][col] )   /* //0 */
                {

                    M[lin][col] = M[lin - 1][col];


		/*  //      contador = contador - 1; */
                }

                if (lin - 1 >= 0 && col + 1 <= j && M[lin - 1][col + 1] > M[lin][col] )  /* //1 */
                {

                    M[lin][col] = M[lin - 1][col + 1] ;
           /*   //      contador = contador - 1; */
                }

                if ( col + 1 <= j && M[lin][col + 1] > M[lin][col]) /* //2 */
                {

                    M[lin][col] = M[lin][col + 1];
            /*  //      contador = contador - 1; */
                }

                if (lin + 1 <= i && col + 1 <= j && M[lin + 1][col + 1] > M[lin][col] ) /* //3 */
                {

                    M[lin][col] = M[lin + 1][col + 1];
           /*     //    contador = contador - 1; */
                }

                if (lin + 1 <= i && M[lin + 1][col] > M[lin][col] ) /* //4 */
                {

                    M[lin][col] = M[lin + 1][col];
            /*  //      contador = contador - 1; */
                }

               if (lin + 1 <= i && col - 1 >= 0  && M[lin + 1][col - 1] > M[lin][col] ) /* //5 */
                {

                  M[lin][col] = M[lin + 1][col - 1];
           /*   //    contador = contador - 1; */
                }

               if ( col - 1 >= 0 && M[lin][col - 1] > M[lin][col] ) /* //6 */
                {

                  M[lin][col] = M[lin][col - 1];
              /* //    contador = contador - 1; */
                }

               if (lin - 1 >= 0 && col - 1 >= 0 && M[lin - 1][col - 1] > M[lin][col] ) /* //7 */
                {

                  M[lin][col] = M[lin - 1][col - 1];
               /* //  contador = contador - 1; */
                }

            }

          }

      }

    }
    Primeira_Vez = 0;
  /* printf("--------------------------------------\n"); */



   contador = 0;
/*  //  salva_contador = 0; */

  d = 0;
    for ( lin = 0; lin < i; lin ++)
    {

      for ( col = 0; col < j; col ++ )
      {

        if ( M[lin][col] > 0  )
         {

              vetor[d] = M[lin][col];

         }


      /*  printf("%d ", M[lin][col]); */
        d++;

      }
      /*  printf(" \n"); */

  /*  //    printf("-------------------------------------------------\n" );

    //    printf("%4.d", vetor[90000] ); */

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

       /* printf("%4.d", vetor[i] ); */
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



/*    for ( i = 0; i < a; i++ )
    {
        for ( j = i + 1; j < a; j++)
        {
            if ( Primeira_Vez == 0 && vetor[i] > 0 )
            {
                contador = contador + 1;
                Primeira_Vez = 1;
                vetor_aux = vetor[i];
            }

            else
            {
                if ( )
                {

                    contador = contador + 1;

                }

            }

        }

    }

    */
      /* printf("--------------------------------------\n"); */
       
    printf("%d\n", contador);

    return 0;
}


/*

P1
6 6
1 0 0 0 0 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 0 1
1 0 0 0 1 0
1 1 1 1 0 1



P1
6 6
1 0 0 0 0 0
1 0 1 0 0 0
1 0 1 0 1 0
1 1 1 0 0 1
1 1 1 0 1 0
1 1 1 1 0 1




P1
6 6
0 0 0 0 0 0
1 1 1 0 0 0
1 0 0 0 1 0
1 1 1 1 0 0
1 0 0 0 0 0
1 1 1 1 0 0


P1
6 6
0 0 0 0 0 0
0 0 1 0 0 1
0 0 1 0 0 1
0 0 1 0 1 0
0 0 1 1 1 1
1 1 0 0 0 0

P1
40 22
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 0 0 1 1 1 1 0 0 0 0 0 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0
0 1 1 1 1 1 1 1 1 0 1 0 0 1 1 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 0 0
0 1 1 1 1 1 1 1 0 0 1 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 1 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 0 0
0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 0 0 1 0 0 0
0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0 0 1 0 0 0
0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 1 1 0 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 1 1 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 1
0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
