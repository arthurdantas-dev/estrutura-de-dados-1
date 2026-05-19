#include <cstdlib>
#include <iostream>

using namespace std;

class ListaDeArray
{
private:
	int *VET; //DECLARAÇÃO DO PONTEIRO
	int ProximaPosicaoLivre;
	int MAX;
	int PrimeiroDaFila;
public:
	ListaDeArray(int qtde)
	{
		MAX = qtde;
		VET = new int[MAX];
		ProximaPosicaoLivre = 0;
	}

	//destrutor
	~ListaDeArray() {
		delete[] VET;
	}

	void Mostra()
	{
		cout << "pos - valor\n";
		for(int i = 0; i<ProximaPosicaoLivre; i++)
		{
			cout << i+1 << "   - " << VET[i] << "\n";
		}
	}

	void Adicionar(int pos, int n)
	{
		if(ProximaPosicaoLivre >= MAX || pos < 0 || pos > ProximaPosicaoLivre) {
			cout << "Posicao invalida ou lista cheia!\n";
			return;
		}

		for(int i = ProximaPosicaoLivre; i > pos; i--) {
			VET[i] = VET[i-1];
		}
		VET[pos] = n;
		ProximaPosicaoLivre++;
	}
	void Remover(int pos)
	{
		if(ProximaPosicaoLivre == 0 || pos < 0 || pos >= ProximaPosicaoLivre) {
			cout << "Posicao invalida ou lista vazia!\n";
			return;
		}
		for(int i = pos; i < ProximaPosicaoLivre - 1; i++) {
			VET[i] = VET[i+1];
		}
		ProximaPosicaoLivre--;
	}
};

int main(int argc, char *argv[])
{
	int menu = 1, pos, n;
	ListaDeArray lista(50);
	lista.Adicionar(0, 3);
	lista.Adicionar(1, 5);
	lista.Adicionar(2, 7);
	lista.Adicionar(3, 1);
	lista.Mostra();
	while(menu != 0) {

		cout << "======= MENU =======\n";
		cout << "1. Adicionar\n";
		cout << "2. Remover\n";
		cout << "3. Exibir lista\n";
		cout << "0. Sair\n";
		cout << "Escolha uma opcao: ";
		cin >> menu;

		switch(menu) {
		case 1:
			cout << "------- Adicionar -------\n";
			cout << "escolha a posição para adicionar um numero: " << endl;
			cin >> pos;
			if(pos < 1) {
				cout << "posição deve ser maior que 0!!!" << endl;
				break;
			}
			cout << "digite o numero a ser adicionado: " << endl;
			cin >> n;
			lista.Adicionar(pos-1, n);

			break;
		case 2:
			cout << "------- Remover -------\n";
			cout << "escolha a posição a ser removida: " << endl;
			cin >> pos;
			if(pos < 1) {
				cout << "posição deve ser maior que 0!!!" << endl;
				break;
			}
			lista.Remover(pos-1);

			break;
		case 3:
			lista.Mostra();
			break;
		case 0:
			cout << "Encerrando programa...";
			break;
		default:
			cout << "Opção inválida, tente novamente!\n\n";
			break;
		}
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
