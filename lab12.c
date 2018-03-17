/* MC 102 - Algoritimos E Programação De Computadores

*Nome : Gabriel Borin Macedo
*Ra : 197201
*Turma : I
*Objetivo Deste Lab : Neste lab12, iremos solucionar um labirinto circular da seguinte forma : da muralha mais externa até a mais interna.
Onde, adotaremos o método de Backtracking para melhor uso da recursão e melhor otimização do problema*/

#include <stdio.h>

int N_Barreiras ( char letras[] )
{

  int a = 0;
  int aux_letra = 0;
  int aux_num= 0;

    fgets(letras,50000,stdin);

    while ( letras[a] != '\n')
    {

      aux_letra = letras[a] - '0';
      aux_num = aux_num*10 + aux_letra;

      a++;

    }

    return aux_num;
}

void Leitura_String ( char letras[], int teste[19][360], int i )
{

  int j = 0;
  int k = 0;
  int aux_num = 0;
  int aux_letra = 0;

  while ( letras[j] != '\n')
  {

    if ( letras[j] != ' ')
    {

      aux_letra = letras[j] - '0';
      aux_num = aux_num*10 + aux_letra;

    }

    else
    {

      teste[i][k] = aux_num;
      k++;

      aux_num = 0;
      aux_letra = 0;

    }

    j++;

  }

  teste[i][k] = aux_num;

  while ( k + 1 < 360 )
  {

    teste[i][k +1] = - 1;
    k++;

  }

}

void Inicializa_Matriz_Lab ( int lab[19][360], int n )
{

  int i;
  int j;

  for ( i = 0; i < (2*n -1); i++ )
  {

    for ( j = 0; j < 360; j++ )
    {


      if ( i%2 == 0 )
      {

        lab[i][j] = 1;

      }

      else
      {

        lab[i][j] = 0;

      }

    }

  }

  return ;

}


void Monta_Labirinto ( int teste[][360], int lab[][360], int n )
{

  int i;
  int j;
  int aux = 0;
  int volta_i;

  Inicializa_Matriz_Lab ( lab, n );

    for ( i = 0; i < (2*n - 1); i++ )
    {

      volta_i = 0;

      for ( j = 0; j < 360 && volta_i == 0; j++ )
      {

        if ( i%2 == 0 )
        {

          if ( teste[i][j] >= 0 )
          {

          aux = teste[i][j];
          lab[i][aux] = 0;

          }

          else
          {

            volta_i = 1;

          }

        }

        else
        {

          if ( teste[i][j] >= 0 )
          {

            aux = teste[i][j];
            lab[i][aux] = 1;

          }

          else
          {

            volta_i = 1;

          }

        }

      }

    }

    return ;
}

void Obtem_Labirinto ( int lab[][360], int i, int j, int Ci, int n )
{

  for ( i = 0; i < (2*n - 1); i++ )
  {

    for ( j = 0; j < 360; j++ )
    {

      if ( lab[i][j] == 1 )
      {

        lab[i][j] = -2;

      }

      else
      {

        lab[i][j] = -1;

      }

    }

  }

  return ;
}


void Resolve_Labirinto (int lab[19][360], int *deltaL, int *deltaC,
int Li, int Ci, int Lf, int Cf/* int *min*/ )
{

  int L, C, k;

    for (k = 0; k < 4; k++)   /* testa todos os movimentos a partir da posicao atual */
    {

      L = Li + deltaL[k];
      C = Ci + deltaC[k];

      if ( C < 0 )  /* verifica se o movimento eh valido e pode gerar uma solucao otima */
      {

        C = 359;

      }

      else if ( C > 359 )
      {

        C = 0;

      }


      if ( (lab[L][C] == -1) || (lab[L][C] > lab[Li][Ci] + 1) )
      {

        lab[L][C] = lab[Li][Ci] + 1;

        Resolve_Labirinto(lab, deltaL, deltaC, L, C, Lf, Cf /*min*/);

      }

    }

  return ;
}

void Acha_Caminho ( int lab[19][360],int *resposta_posicao, int *resposta_indice, int n, int i, int j, int aux, int k, int sair )
{

    if ( i == (2*n - 2)  && sair == 0)
    {

      aux = lab[i][j];
      resposta_indice[k] = i;
      resposta_posicao[k] = j;
      k++;
      sair = 1;

      Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i, j, aux, k, sair );

    }

    else if ( i > 0)
    {

      if ( i%2 == 0 )
      {

          if ( (aux == lab[i][j + 1] + 1) && j <= 358 && lab[i][j+1] > 0 )
          {

            aux = lab[i][j + 1];
            resposta_indice[k] = i;
            resposta_posicao[k] = ( j + 1);
            k++;

            Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i, (j + 1), aux, k, sair );

          }

          else if ( (aux == lab[i + 1][j] + 1) && i <= (2*n - 2) && lab[i+1][j] > 0)
          {

            aux = lab[i + 1][j];
            resposta_indice[k] = (i + 1);
            resposta_posicao[k] = j;
            k++;

            Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, (i + 1), j, aux, k, sair);

          }

          else if ( (aux == lab[i][j - 1] + 1) && j >= 1 && lab[i][j - 1] > 0)
          {

            aux = lab[i][j - 1];
            resposta_indice[k] = i;
            resposta_posicao[k] = ( j - 1 );
            k++;

            Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i, (j - 1), aux, k, sair );

          }

          else if ( (aux == lab[i - 1][j] + 1) && i >= 1  && lab[i - 1][j] > 0)
          {

            aux = lab[i - 1][j];

            Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, (i - 1) , j, aux, k, sair );

          }

          else if ( (aux == lab[i][j] + 1) && lab[i][j] > 0 )
          {

            aux = lab[i][j];
            resposta_indice[k] = (i - 1) ;
            resposta_posicao[k] = j;
            k++;

            Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i , j, aux, k, sair );

          }

      }

      else
      {

         if ( ( ( j == 359 && aux == lab[i][0] + 1 )  || ( (aux == lab[i][j + 1] + 1) && j <= 358) ) )
        {

          if ( j == 359 )
          {

            j = 0;
            aux = lab[i][0];

          }

          else
          {

            aux = lab[i][j + 1];

          }

          Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i, (j + 1), aux, k, sair );

        }


        else if ( (aux == lab[i + 1][j] + 1) && i <= (2*n - 2) )
        {

          aux = lab[i + 1][j];

          Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, (i + 1), j, aux, k, sair );

        }

        else if (  ( j == 0 && aux == lab[i][359] + 1 )  || ( (aux == lab[i][j - 1] + 1) && j >= 1) )
        {

          if ( j == 0 )
          {

            j = 359;
            aux = lab[i][359];

          }

          else
          {

          aux = lab[i][j - 1];

          }

          Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i, (j - 1), aux, k, sair );

        }

        else if ( (aux == lab[i - 1][j] + 1) && i >= 1 )
        {

          aux = lab[i][j];

          Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, (i - 1), j, aux, k, sair );

        }

        else if ( (aux == lab[i][j] + 1) )
        {

          aux = lab[i][j];

          Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i  , j, aux, k, sair );

        }

      }

    }

    else if (  i == 0  && lab[0][j] == 0)
    {

      resposta_indice[k] = 0;
      resposta_posicao[k] = j;
      resposta_posicao[k + 1] = -1;

      return ;

    }

    return ;

}

void Organiza_Vetor_E_Printa ( int resposta_posicao[], int resposta_indice[], int k )
{

  int i;
  int tam;
  int aux;

  for ( tam = 0; resposta_posicao[tam] >= 0; tam++ )
  {

  }

  k = tam;

  for ( i = 0; i < k/2; i++ )
  {

    aux = resposta_indice[i];
    resposta_indice[i] = resposta_indice[k-1-i];
    resposta_indice[k-1-i] = aux;

  }

  for ( i = 0; i < k/2; i++ )
  {

    aux = resposta_posicao[i];
    resposta_posicao[i] = resposta_posicao[k-1-i];
    resposta_posicao[k-1-i] = aux;

  }

  for ( k = 0; (k + 1) < tam; k++ )
  {

    if ( resposta_indice[k] < resposta_indice[k + 1] )
    {

      printf("E %d", resposta_posicao[k] );
      printf("\n");

    }

    else
    {

      printf("S %d", resposta_posicao[k] );
      printf("\n");

    }

  }

  if ( resposta_indice[k - 1] < resposta_indice[k] )
  {

    printf("E %d", resposta_posicao[k] );
    printf("\n");

  }

  else
  {

    printf("S %d", resposta_posicao[k] );
    printf("\n");

  }


  return ;

}

int main ( void )
{

  int i = 0;
  int n;
  int  j = 0;
  int k = 0;
  int aux = 0;
  int lab[19][360];
  int teste[19][360];
  char letras[50000];
  int deltaC[4] = {1, 0, -1, 0};
  int deltaL[4] = {0, 1, 0, -1};
  int Li, Lf, Ci, Cf;
  int sair = 0;
  int resposta_posicao[5000];
  int resposta_indice[5000];

  n = N_Barreiras ( letras );

  for ( i = 0; i < (2*n - 1); i++ )
  {

    fgets(letras,10000,stdin);

    Leitura_String ( letras, teste ,i);

  }

  Monta_Labirinto ( teste, lab, n );

  Cf = teste[( 2*n - 2 )][0];
  Li = 0;
  Lf = (2*n - 2) ;
  Ci = teste[0][0];

  Obtem_Labirinto ( lab, i, j, Ci, n );

  lab[Li][Ci] = 0;


  Resolve_Labirinto ( lab, deltaL, deltaC, Li, Ci, Lf , Cf  /*&min*/ );

  i = (2*n - 2);
  j = Cf;

  Acha_Caminho ( lab, resposta_posicao, resposta_indice, n, i, j, aux, k, sair);

  Organiza_Vetor_E_Printa (  resposta_posicao, resposta_indice, k);

  return 0;

}
