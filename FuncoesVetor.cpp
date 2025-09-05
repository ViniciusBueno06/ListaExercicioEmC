#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

#define TF 100

//Declarando do Protótipo da Função
void LeVetor(int V[TF], int &QtdeElem);
void Frequencia(int Vetor[TF],int TL,int &MaiorFreq,int &QtdeVezes);
void ExibeVetor(int Vet[TF], int Qtde);
int SomaElementos(int VetNum[TF], int QtdeN);

void Frequencia(int Vetor[TF],int TL,int &MaiorFreq,int &QtdeVezes)
{
	int cont, i, j;
	QtdeVezes=0;
	
	for(i=0; i < TL - 1;i++)
	{
		cont=1;
		for(j = i+1; j < TL;j++)
		{
			if(Vetor[i] == Vetor[j])
				cont++;
		}
		
		if(cont>QtdeVezes)
		{
			MaiorFreq = Vetor[i];
			QtdeVezes = cont;	
		}
	
	}
}

void ExibeVetor(int Vet[TF], int Qtde)
{
	int i;
	clrscr();
	printf("\n### Conteudo do Vetor ###\n");
	if (Qtde==0)
		printf("\nVetor esta Vazio!\n");
	else
		for(i=0; i<Qtde; i++)
			printf("\nVetor[%d]: %d",i,Vet[i]);
	
	getch();
}

void LeVetor(int V[TF], int &QtdeElem)
{
	int aux;
	clrscr();
	printf("\n### Inserir Elementos em um Vetor ###\n");
	printf("Vetor[%d]: ",QtdeElem);
	scanf("%d",&aux);
	while(QtdeElem<TF && aux>0)
	{
		V[QtdeElem] = aux;
		QtdeElem++;
		
		printf("\nVetor[%d]: ",QtdeElem);
		scanf("%d",&aux);
	}
}

int SomaElementos(int VetNum[TF], int QtdeN)
{
	int i,soma=0;
	for(i=0; i<QtdeN; i++)
		soma+= VetNum[i]; // soma = soma+VetNum[i];
		
	return soma;
}

//Busca Exaustiva  --  Exercício 3
int AchouElemento(int V[TF], int TL, int Numero)
{
	int p=0;
	while(p<TL && Numero!=V[p])
			p++;
	
	if (Numero==V[p])
		return 1;  //achou
	else
		return 0;  //não achou
}

void Subtracao(int A[TF],int QA,int B[TF],int QB,int C[TF],int &QC)
{
	int i;
	QC=0;
	for(i=0; i<QA; i++)
		if (!AchouElemento(B,QB,A[i]))
			if (!AchouElemento(C,QC,A[i]))
				C[QC++] = A[i];
	
	printf("\nSubtracao concluida!\n");
	getch();
}

int main(void)
{
	int VA[TF],VB[TF],VC[TF*2],TLA=0,TLB=0,TLC, Valor, Vezes;
	printf("\n*** VETOR A ***");
	LeVetor(VA,TLA);
	ExibeVetor(VA,TLA);
	//Exercício 1
	Frequencia(VA,TLA,Valor,Vezes);
	printf("\nValor de Maior Frequencia: %d",Valor);
	printf("\nQuantidade de Vezes: %d",Vezes);
	//Exercício 2
	printf("\n\nSoma dos valores do Vetor: %d",SomaElementos(VA,TLA));
	//Exercício 3
	printf("\n\nQue Numero procurar? ");
	scanf("%d",&Valor);
	if (!AchouElemento(VA,TLA,Valor))
		printf("\nNumero [%d] NAO encontrado!",Valor);
	else
		printf("\nNumero [%d] encontrado!",Valor);
	getch();
	//Exercício 5a
	printf("\n*** VETOR B ***");
	LeVetor(VB,TLB);
	ExibeVetor(VB,TLB);
	
	Subtracao(VA,TLA,VB,TLB,VC,TLC);
	printf("\n### Resultado da Subtracao: VA-VB ###\n");
	ExibeVetor(VC,TLC);
	getch();
	return 0;
}





