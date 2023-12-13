#include <windows.h>
#include <stdio.h>

void main(void){
	int nj,casillas[6]={0,0,0,0,0,0},dado,turno=-1,seis,come,i;
   printf("¿Cuantos jugadores?");
   scanf("%d",&nj);
   do
   {
   	seis=0;
   	turno=(turno+1)%nj;
      do
      	{
      	do
      	{
      		printf("jugador %d, dado",turno+1);
         	scanf("%d",&dado);
      	}while(dado<1 || dado>6);
      	if(casillas[turno]==0)
      	{
      		if(dado==5)
         	{
         		casillas[turno]=5;
         	}else
         	{
         		if(dado==6)
            	{
            		seis++;
            	}
         	}
      	}else
      	{
      		casillas[turno]+=dado;
         	if(dado==6)
         	{
         		seis++;
         		if(seis==3)
         		{
            		casillas[turno]=0;
         		}
         	}
         	if(casillas[turno]>70)
         	{
         		casillas[turno]=140-casillas[turno];
         	}
      	}
      	printf("jugador %d, casilla %d",turno+1,casillas[turno]);
      	do
      	{
         	come=0;
      		for(i=0;i<nj;i++)
      		{
      			if(casillas[i]==casillas[turno] && i!=turno && casillas[turno]%10!=0)
         		{
         			printf("comes al jugador %d",i+1);
            		casillas[i]=0;
            		casillas[turno]+=5;
               	if(casillas[turno]>70)
         			{
         				casillas[turno]=140-casillas[turno];
         			}
               	come=1;
               	printf("jugador %d, casilla %d",turno+1,casillas[turno]);
         		}
      		}
      	}while(come==1);
      }while(dado==6 && seis!=3 && casillas[turno]<70);
   }while(casillas[turno]!=70);
   system("pause");
}