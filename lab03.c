#include <stdio.h>
/* Turma I
   Aluno : Gabriel Borin Macedo
   Ra : 197201
   Objetivo : Faremos um programa que terá quatro dados de entrada que são, respectivamente, o termo da PG, o primeiro termo da PA, o segundo termo da PA e o valor de moedas que ele irá retirar. Além disso, o programa imprimirá dois dados de saída, que são, respectivamente, a quantidade de moedas e o preço das moedas. Com isso, vamos ter um programa que ira fazer o pagamento salarial ( 4*dado de entrada ) pelos termos da PG, de tal forma que estes não estejam na PG e na PA ao mesmo tempo, fazendo pelo maior valor de joias possíveis, supondo que há quantidade infinitas destas joias para tal */
   

int main()
{
    int  contador, Q, R, A, B; /* Colocamos int pois se trata apenas de números inteiros pequenos */
    unsigned long int PGAUX, saque,pago, PG, LOOP;	/*	Aqui são valores que ultrapassam o espaço de memória convencional da função int */

    scanf("%d", &Q); /* RAZÃO DA PG */
    scanf("%d", &A); /* Primeiro termo da PA */
    scanf("%d", &B); /* Segundo termo da PA */
    scanf("%lu", &saque); /* Valor do pagamento salarial */
    
    R = B - A; /* Razão da PA */
    PG = 1;	/* Variáveis auxiliares para maior facilidade com o tratamento do programa */
    PGAUX = 1;
    LOOP = 0;
  

    while (LOOP!=1)	/* Neste while, iremos calcular o valor máximo da PG */
  
    {
        PG = PG* Q;
        PGAUX= PG * Q;

       if  ( (PG >= saque || PGAUX%Q != 0 || PGAUX == 0 ) )
       {
            LOOP=1;
        }    

     }


   contador = 0; /* Variáveis auxiliares para maior facilidade com o tratamento do programa */
   pago = 0;
   LOOP=0;
    
    while (LOOP != 1 )	/* Vamos comparar os valores das joias que não estão em falta do universo para ser utilizado na soma */
    {
  
      if (

        ( PG  +  pago <= saque) &&
        ( ((PG  + pago)%Q == 0)  &&   ( (PG  + pago) !=0 || PG == 1) ) &&
        ( ( (PG - A)%R != 0 && (PG - A >= 0) ) || (PG < A) )

        )
      {

        pago = pago + PG;
        contador = contador + 1;
  
      }
      
      else
      {
         if (contador != 0 ) 
        {
           printf("%d %lu\n", contador, PG);  
        }
        PG = (PG /  Q);
        contador = 0;
        
	if (PG == 1 && saque - pago != 0)
	{
			printf("%lu 1\n", saque - pago );
			LOOP = 1;
	}
    
    if  (pago == saque)
    {            
        LOOP=1; 
    }
    
    }
      
    }

      return 0;
  }
