#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>


#define TF_1 5
#define TF_2 100

struct TpData
{
	int dia,mes,ano;	
};

struct TpEndereco
{
	char rua[30],compl[30],bairro[30],cidade[25],estado[25],pais[25];
	int numero,cep;
};
struct TpTelefone
{
	int ddd,numero;
};

struct TpPessoa_1
{
	char nome[25],endereco[40];
	int fone;
};

struct TpPessoa_2
{
	char nome[25],email[40],obs[30];
	TpEndereco endereco;
	TpTelefone telefone;
	TpData data;
	
		
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
				printf("\nNome: %s",TabPessoa[i].nome);
				printf("\nEndereco: %s",TabPessoa[i].endereco);
				printf("\nTelefone: %d",TabPessoa[i].fone);
			}
			break;
		case 2:
			char opcao;
			struct TpPessoa_2 TabAgenda[100];
			int InserePessoa(int pos);{
				for(int i = pos;i<TF_2;i++)
				printf("\nDigite o nome:")
				gets(TabAgenda[i].nome);
				printf("\nDigite o email:");
				gets(TabAgenda[i].email);
				printf("\nDigite o endereco.");
				printf("\nRua:");
				gets(TabPessoa[i].endereco.rua);
				printf("\nNumero da residencia:");
				scanf("%d",&TabPessoa[i].endereco.numero);
				printf("\nDigite o complemento:");
				gets()
			}
			do{
			printf("[A] Inserir Pessoa na agenda\n");
			printf("[B]");
			printf("[C]");
			printf("[D]");
			printf("[E]");
			printf("[F]");
			printf("[G]");
			printf("[H]");
			opcao = toupper(getch());
			switch(opcao){
				case A: 
							
				InserePessoa();
						
					
			}
			
			}while(opcao!=27)
				break;
			}
	
	
	
	return 0;
}
