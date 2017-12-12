#include <stdio.h>

/* Nome: Gabriel Borin Macedo */
/*Ra: 197201 */
/* Turma I */

/*Objetivo do Lab01: Neste lab, faremos um lab no qual terá objetivo de "traduzir" números que são separados em duas categorias, Os Bi's que são dados de entrada dos números de buracos de cada figura e os Ci's que são os dado de entrada dos diacíticos. Nos quais, ao longo do programa, eles vão mudando de acordo com as regras que serão descritas no decorrer destas linhas de códicos */

int main()
{
	int B1, B2, B3, B4, B5, B6, B7, B8;		/* Dados  de entrada dos buracos */
	int C1, C2, C3, C4, C5, C6, C7, C8;		/* Dados  de entrada dos diacríticos */
	int X1, X2, X3, X4, X5, X6, X7, X8;	
	
	scanf("%d %d %d %d %d %d %d %d", &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8);	
	scanf("%d %d %d %d %d %d %d %d", &C1, &C2, &C3, &C4, &C5, &C6, &C7, &C8);
	
	X1=B1, X2=B2;	/* No começo do programa, os valores dos Xi's são definidos como Xi==Bi */
	X3=B3, X4=B4;
	X5=B5, X6=B6;
	X7=B7, X8=B8;
	
	if( !( (C4==2 || C4==9) ) )		/* 1 Caso : Quando o valor do 4 diacrítico é diferente de 2 ou 9 */
	{
		
		X1=X1+3;
		X2=X2+3;
		X3=X3+3;
		X4=X4+3;
		X5=X5+3;
		X6=X6+3;
		X7=X7+3;
		X8=X8+3;
	}
	
	if(11<=C1 && C1<=42)	/* 2 Caso : Quando os valor de C1 está entre 11 e 42 */
	{	
		
		X8=X8+7;
		X7=X7+8;
	}
	
	if( (C1%2!=0) && (C2%2!=0) && (C3%2!=0) && (C4%2!=0) && (C5%2!=0) && (C6%2!=0) && (C7%2!=0) && (C8%2!=0) )	 /* 3 Caso : Quando todos os diacríticos são ímpares */
	{
		
		X1=X1+2*C5;
	}
	
	if(  (C3<20 && C6>=20) || (C3>=20 && C6<20) ) 	/* 4 Caso : quando o terceiro e o sexto diacríticos ,com um deles apenas, um é menor e o outro é maior ou igual que 20 */
	{
		
		X4=X4+6;
		X5=X5+6;
	}	
	
	if( (C8!=3) && (C8>=C7) ) 	/* 5 Caso : quando o oitavo diacrítico é diferente de 3 e o oitavo é maior ou igual que o sétimo diacrítico */
	{
		
		X3=X3+C2;
	}
	
	if( ( (C1*C2*C3*C4*C5*C6*C7*C8)%5==0) && ( (C1*C2*C3*C4*C5*C6*C7*C8)%10!=0||C1*C2*C3*C4*C5*C6*C7*C8==30) )		/*	6 Caso : Quando o produto de todos os diacríticos são divisíveis por 5, mas não por 10, com exeção do produto ser igual à 30 */
	{
		
		X6=X6+1;
	}
	
	if( (C2==C8) || (C3==C7) )	 /* 7 Caso : Quando o segundo diacrítico é igual ao oitavo ou o terceiro é igual ao sétimo diacrítico */
	{
	
		X6=X6+1;
	}
	
	/* Agora, vamos definir a lógica da tradução das letras em palavras */
	if (X1==1)
	{
		printf("A");
	}
	
	if (X1==2)
	{
		printf("B");
	}
	
	if (X1==3)
	{
		printf("C");
	}
	
	if (X1==4)
	{
		printf("D");
	}
	
	if (X1==5)
	{
		printf("E");
	}
	
	if (X1==6)
	{
		printf("F");
	}
	
	if (X1==7)
	{
		printf("G");
	}
	
	if (X1==8)
	{
		printf("H");
	}
	
	if (X1==9)
	{
		printf("I");
	}
	
	if (X1==10)
	{
		printf("J");
	}
	
	if (X1==11)
	{
		printf("K");
	}
	
	if (X1==12)
	{
		printf("L");
	}
	
	if (X1==13)
	{
		printf("M");
	}
	
	if (X1==14)
	{
		printf("N");
	}
	
	if (X1==15)
	{
		printf("O");
	}
	
	if (X1==16)
	{
		printf("P");
	}
	
	if (X1==17)
	{
		printf("Q");
	}
	
	if (X1==18)
	{
		printf("R");
	}
	
	if (X1==19)
	{
		printf("S");
	}
	
	if (X1==20)
	{
		printf("T");
	}
	
	if (X1==21)
	{
		printf("U");
	}
	
	if (X1==22)
	{
		printf("V");
	}
	
	if (X1==23)
	{
		printf("W");
	}
	
	if (X1==24)
	{
		printf("X");
	}
	

	if (X1==25)
	{
		printf("Y");
	}
	
	if (X1==26)
	{
		printf("Z");
	}
	
	if(X1==27)
	{
		printf(" ");
	}
	
	if (X2==1)
	{
		printf("A");
	}
	
	if (X2==2)
	{
		printf("B");
	}
	
	if (X2==3)
	{
		printf("C");
	}
	
	if (X2==4)
	{
		printf("D");
	}
	
	if (X2==5)
	{
		printf("E");
	}
	
	if (X2==6)
	{
		printf("F");
	}
	
	if (X2==7)
	{
		printf("G");
	}
	
	if (X2==8)
	{
		printf("H");
	}
	
	if (X2==9)
	{
		printf("I");
	}
	
	if (X2==10)
	{
		printf("J");
	}
	
	if (X2==11)
	{
		printf("K");
	}
	
	if (X2==12)
	{
		printf("L");
	}
	
	if (X2==13)
	{
		printf("M");
	}
	
	if (X2==14)
	{
		printf("N");
	}
	
	if (X2==15)
	{
		printf("O");
	}
	
	if (X2==16)
	{
		printf("P");
	}
	
	if (X2==17)
	{
		printf("Q");
	}
	
	if (X2==18)
	{
		printf("R");
	}
	
	if (X2==19)
	{
		printf("S");
	}
	
	if (X2==20)
	{
		printf("T");
	}
	
	if (X2==21)
	{
		printf("U");
	}
	
	if (X2==22)
	{
		printf("V");
	}
	
	if (X2==23)
	{
		printf("W");
	}
	
	if (X2==24)
	{
		printf("X");
	}
	
	if (X2==25)
	{
		printf("Y");
	}
	
	if (X2==26)
	{
		printf("Z");
	}
	
	if(X2==27)
	{
		printf(" ");
	}
	
	if (X3==1)
	{
		printf("A");
	}
	
	if (X3==2)
	{
		printf("B");
	}
	
	if (X3==3)
	{
		printf("C");
	}
	
	if (X3==4)
	{
		printf("D");
	}
	
	if (X3==5)
	{
		printf("E");
	}
	
	if (X3==6)
	{
		printf("F");
	}
	
	if (X3==7)
	{
		printf("G");
	}
	
	if (X3==8)
	{
		printf("H");
	}
	
	if (X3==9)
	{
		printf("I");
	}
	
	if (X3==10)
	{
		printf("J");
	}
	
	if (X3==11)
	{
		printf("K");
	}
	
	if (X3==12)
	{
		printf("L");
	}
	
	if (X3==13)
	{
		printf("M");
	}
	
	if (X3==14)
	{
		printf("N");
	}
	
	if (X3==15)
	{
		printf("O");
	}
	
	if (X3==16)
	{
		printf("P");
	}
	
	if (X3==17)
	{
		printf("Q");
	}
	
	if (X3==18)
	{
		printf("R");
	}
	
	if (X3==19)
	{
		printf("S");
	}
	
	if (X3==20)
	{
		printf("T");
	}
	
	if (X3==21)
	{
		printf("U");
	}
	
	if (X3==22)
	{
		printf("V");
	}
	
	if (X3==23)
	{
		printf("W");
	}
	
	if (X3==24)
	{
		printf("X");
	}
	
	if (X3==25)
	{
		printf("Y");
	}
	
	if (X3==26)
	{
		printf("Z");
	}
	
	if(X3==27)
	{
		printf(" ");
	}
	
	if (X4==1)
	{
		printf("A");
	}
	
	if (X4==2)
	{
		printf("B");
	}
	
	if (X4==3)
	{
		printf("C");
	}
	
	if (X4==4)
	{
		printf("D");
	}
	
	if (X4==5)
	{
		printf("E");
	}
	
	if (X4==6)
	{
		printf("F");
	}
	
	if (X4==7)
	{
		printf("G");
	}
	
	if (X4==8)
	{
		printf("H");
	}
	
	if (X4==9)
	{
		printf("I");
	}
	
	if (X4==10)
	{
		printf("J");
	}
	
	if (X4==11)
	{
		printf("K");
	}
	
	if (X4==12)
	{
		printf("L");
	}
	
	if (X4==13)
	{
		printf("M");
	}
	
	if (X4==14)
	{
		printf("N");
	}
	
	if (X4==15)
	{
		printf("O");
	}
	
	if (X4==16)
	{
		printf("P");
	}
	
	if (X4==17)
	{
		printf("Q");
	}
	
	if (X4==18)
	{
		printf("R");
	}
	
	if (X4==19)
	{
		printf("S");
	}
	
	if (X4==20)
	{
		printf("T");
	}
	
	if (X4==21)
	{
		printf("U");
	}
	
	if (X4==22)
	{
		printf("V");
	}
	
	if (X4==23)
	{
		printf("W");
	}
	
	if (X4==24)
	{
		printf("X");
	}
	
	if (X4==25)
	{
		printf("Y");
	}
	
	if (X4==26)
	{
		printf("Z");
	}
	
	if(X4==27)
	{
		printf(" ");
	}
	
	if (X5==1)
	{
		printf("A");
	}
	
	if (X5==2)
	{
		printf("B");
	}
	
	if (X5==3)
	{
		printf("C");
	}
	
	if (X5==4)
	{
		printf("D");
	}
	
	if (X5==5)
	{
		printf("E");
	}
	
	if (X5==6)
	{
		printf("F");
	}
	
	if (X5==7)
	{
		printf("G");
	}
	
	if (X5==8)
	{
		printf("H");
	}
	
	if (X5==9)
	{
		printf("I");
	}
	
	if (X5==10)
	{
		printf("J");
	}
	
	if (X5==11)
	{
		printf("K");
	}
	
	if (X5==12)
	{
		printf("L");
	}
	
	if (X5==13)
	{
		printf("M");
	}
	
	if (X5==14)
	{
		printf("N");
	}
	
	if (X5==15)
	{
		printf("O");
	}
	
	if (X5==16)
	{
		printf("P");
	}
	
	if (X5==17)
	{
		printf("Q");
	}
	
	if (X5==18)
	{
		printf("R");
	}
	
	if (X5==19)
	{
		printf("S");
	}
	
	if (X5==20)
	{
		printf("T");
	}
	
	if (X5==21)
	{
		printf("U");
	}
	
	if (X5==22)
	{
		printf("V");
	}
	
	if (X5==23)
	{
		printf("W");
	}
	
	if (X5==24)
	{
		printf("X");
	}
	
	if (X5==25)
	{
		printf("Y");
	}
	
	if (X5==26)
	{
		printf("Z");
	}
	
	if(X5==27)
	{
		printf(" ");
	}
	
	if (X6==1)
	{
		printf("A");
	}
	
	if (X6==2)
	{
		printf("B");
	}
	
	if (X6==3)
	{
		printf("C");
	}
	
	if (X6==4)
	{
		printf("D");
	}
	
	if (X6==5)
	{
		printf("E");
	}
	
	if (X6==6)
	{
		printf("F");
	}
	
	if (X6==7)
	{
		printf("G");
	}
	
	if (X6==8)
	{
		printf("H");
	}
	
	if (X6==9)
	{
		printf("I");
	}
	
	if (X6==10)
	{
		printf("J");
	}
	
	if (X6==11)
	{
		printf("K");
	}
	
	if (X6==12)
	{
		printf("L");
	}
	
	if (X6==13)
	{
		printf("M");
	}
	
	if (X6==14)
	{
		printf("N");
	}
	
	if (X6==15)
	{
		printf("O");
	}
	
	if (X6==16)
	{
		printf("P");
	}
	
	if (X6==17)
	{
		printf("Q");
	}
	
	if (X6==18)
	{
		printf("R");
	}
	
	if (X6==19)
	{
		printf("S");
	}
	
	if (X6==20)
	{
		printf("T");
	}
	
	if (X6==21)
	{
		printf("U");
	}
	
	if (X6==22)
	{
		printf("V");
	}
	
	if (X6==23)
	{
		printf("W");
	}
	
	if (X6==24)
	{
		printf("X");
	}
	
	if (X6==25)
	{
		printf("Y");
	}
	
	if (X6==26)
	{
		printf("Z");
	}
	
	if(X6==27)
	{
		printf(" ");
	}
	
	if (X7==1)
	{
		printf("A");
	}
	
	if (X7==2)
	{
		printf("B");
	}
	
	if (X7==3)
	{
		printf("C");
	}
	
	if (X7==4)
	{
		printf("D");
	}
	
	if (X7==5)
	{
		printf("E");
	}
	
	if (X7==6)
	{
		printf("F");
	}
	
	if (X7==7)
	{
		printf("G");
	}
	
	if (X7==8)
	{
		printf("H");
	}
	
	if (X7==9)
	{
		printf("I");
	}
	
	if (X7==10)
	{
		printf("J");
	}
	
	if (X7==11)
	{
		printf("K");
	}
	
	if (X7==12)
	{
		printf("L");
	}
	
	if (X7==13)
	{
		printf("M");
	}
	
	if (X7==14)
	{
		printf("N");
	}
	
	if (X7==15)
	{
		printf("O");
	}
	
	if (X7==16)
	{
		printf("P");
	}
	
	if (X7==17)
	{
		printf("Q");
	}
	
	if (X7==18)
	{
		printf("R");
	}
	
	if (X7==19)
	{
		printf("S");
	}
	
	if (X7==20)
	{
		printf("T");
	}
	
	if (X7==21)
	{
		printf("U");
	}
	
	if (X7==22)
	{
		printf("V");
	}
	
	if (X7==23)
	{
		printf("W");
	}
	
	if (X7==24)
	{
		printf("X");
	}
	
	if (X7==25)
	{
		printf("Y");
	}
	
	if (X7==26)
	{
		printf("Z");
	}
	
	if(X7==27)
	{
		printf(" ");
	}
	
	if (X8==1)
	{
		printf("A");
	}
	
	if (X8==2)
	{
		printf("B");
	}
	
	if (X8==3)
	{
		printf("C");
	}
	
	if (X8==4)
	{
		printf("D");
	}
	
	if (X8==5)
	{
		printf("E");
	}
	
	if (X8==6)
	{
		printf("F");
	}
	
	if (X8==7)
	{
		printf("G");
	}
	
	if (X8==8)
	{
		printf("H");
	}
	
	if (X8==9)
	{
		printf("I");
	}
	
	if (X8==10)
	{
		printf("J");
	}
	
	if (X8==11)
	{
		printf("K");
	}
	
	if (X8==12)
	{
		printf("L");
	}
	
	if (X8==13)
	{
		printf("M");
	}
	
	if (X8==14)
	{
		printf("N");
	}
	
	if (X8==15)
	{
		printf("O");
	}
	
	if (X8==16)
	{
		printf("P");
	}
	
	if (X8==17)
	{
		printf("Q");
	}
	
	if (X8==18)
	{
		printf("R");
	}
	
	if (X8==19)
	{
		printf("S");
	}
	
	if (X8==20)
	{
		printf("T");
	}
	
	if (X8==21)
	{
		printf("U");
	}
	
	if (X8==22)
	{
		printf("V");
	}
	
	if (X8==23)
	{
		printf("W");
	}
	
	if (X8==24)
	{
		printf("X");
	}
	
	if (X8==25)
	{
		printf("Y");
	}
	
	if (X8==26)
	{
		printf("Z");
	}
	
	if (X8==27)
	{
		printf(" ");
	}
	
	printf("\n");	

	return 0;
}
