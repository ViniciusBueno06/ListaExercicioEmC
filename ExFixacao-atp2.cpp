#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#define TF_1 5

struct TpData
{
	int dia,mes,ano;	
};

struct TpPessoa_1
{
	char nome[25],endereco[40];
	int fone;
};

int main(void){
	int cod;
	printf("Digite o numero do exercicio:");
	scanf("%d",&cod);
	switch(cod){
		case 1:
			TpPessoa_1 TabPessoa[TF_1];
			char AuxNome[25];
			
			int TLpessoa=0;
			
			printf("\n ======================= Ex 1 =======================\n");
			printf("Nome[%d]: ",TLpessoa);
			fflush(stdin);
			gets(AuxNome);
			
			
			while(TLpessoa<TF_1 && AuxNome[0]!='\0'){
				
				strcpy(TabPessoa[TLpessoa].nome,AuxNome);
				printf("\nDigite o endereco da pessoa:");
				fflush(stdin);
				gets(TabPessoa[TLpessoa].endereco);
				fflush(stdin);
				printf("\nDigite o telefone da pessoa:");
				scanf("%d",&TabPessoa[TLpessoa].fone);
				TLpessoa++;
				
				printf("Nome[%d]: ",TLpessoa);
				fflush(stdin);
				gets(AuxNome);
			}
			for(int i=0;i<TLpessoa-1;i++){
				for(int j=i+1;j<TLpessoa;j++)
					if(strcmp(TabPessoa[i].nome,TabPessoa[j].nome)==1){
						strcpy(AuxNome,TabPessoa[j].nome);
						strcpy(TabPessoa[j].nome,TabPessoa[i].nome);
						strcpy(TabPessoa[i].nome,AuxNome);
					}
					
			}
			
			for(int i=0;i<TLpessoa;i++){
				printf("---------------------------------------------");
				printf("\nNome: %s",TabPessoa[i].nome);
				printf("\nEndereco: %s",TabPessoa[i].endereco);
				printf("\nTelefone: %d",TabPessoa[i].fone);
				printf("\n-------------------------------------------");
			}
			
			break;
	}
	
	
	
	return 0;
}
