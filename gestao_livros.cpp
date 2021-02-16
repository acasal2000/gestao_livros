#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Livros{
	public:
		string nome;
		int isin;
		
		string devolverNome(){
			return nome;
		}
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "");
	
	int quantidade_livros;
	int quantidade_livros_criados;
	int opcao_menu;
	int opcao_limpar;
	
	Livros * lista_de_livros;
			
	inicio:	
	
	cout << "********** MENU **********";
	cout << endl << "1. Criar Livros" << endl << "2. Consultar Livros" << endl << "3. Fechar o Programa" << endl << endl << "Que a��o desejas tomar? " << endl;
	cin >> opcao_menu;	

	while (cin.fail())				// cin.fail -> quando verdade � porque se introduziu um caracter que n�o � do tipo esperado na vari�vel
    {
        cin.clear(); 				// limpa o buffer do input
        cin.ignore(INT_MAX, '\n'); 	// ignora o total de caracteres introduzidos no input at� a quebra de linha do input
       
	    /* 
			sem o "INT_MAX , \n" as 2 mensagens abaixo iriam ser mostradas de seguida na mesma quantidade de caracteres introduzidos no input (ex: escrevemos "as" no input que s� aceita n�meros, 
			como iria falhar a leitura devido ao cin.fail(), mostrar-nos-ia as duas mensagens abaixo (seguidas) na mesma quantidade que o n� de caracteres que metemos no input (neste caso "as" = 2 caracteres)) 
		*/
        
		cout << endl << "Essa op��o n�o existe!" << endl;
        cout << "Introduz uma op��o v�lida: ";
        cin >> opcao_menu;
    }
    
    system("cls");																// limpar a consola
	switch(opcao_menu){		
		case 1:		
			quantidade_livros_criados = 0;	
			
			cout << "Quantos livros desejas criar?" << endl;
			cin >> quantidade_livros;
			
			lista_de_livros = new Livros[quantidade_livros];
			
			for(int index = 0; index < quantidade_livros; index ++){
				cout << endl <<"Nome do Livro N� " << index+1 << endl;			
				cin.ignore();
				getline (cin, lista_de_livros[index].nome); 					//getline para poder utilizar espa�os
				
				cout << endl << "C�digo do Livro N� " << index+1 << endl;
  				cin >> lista_de_livros[index].isin;

  				while (cin.fail()) 												
    			{
        			cin.clear(); 
        			cin.ignore(INT_MAX, '\n');
        			
        			cout << endl << "O c�digo introduzido n�o � v�lido!" << endl;
        			cout << "Introduz um novo c�digo num�rico: ";
        			cin >> lista_de_livros[index].isin;
    			}  				
				quantidade_livros_criados++;		
			}
			cout << endl << "Foram criados " << quantidade_livros_criados << " livros!" << endl;			
			break;				
		case 2:		
			// Listagem dos livros	
			cout << endl << "***** LISTAGEM DE LIVROS *****" << endl << endl;			
			
			if(quantidade_livros_criados == 0){
				cout << "N�o existem livros criados!" << endl;
			}
			else{		
				cout << endl << "Quantidade de livros criados: " << quantidade_livros_criados << endl << endl;			
				for(int index = 0; index < quantidade_livros; index ++){
					cout << endl << "Nome do Livro N� " << index+1 << ": " << endl;  				
					cout << lista_de_livros[index].devolverNome();
					
					cout << endl << endl << "C�digo do Livro N� " << index+1 << ": " << endl << lista_de_livros[index].isin << endl;			
					cout << endl;
				}
			}				
			break;			
		case 3:
			// Sair do programa
			exit(3);
			break;
		default:
			// Qualquer outra op��o		
			cout << endl << "Essa op��o n�o existe!" << endl;
			break;				
	}
 	
 	cout << endl << endl << "Desejas limpar a consola?" << endl << "1. Sim" << endl << "2. N�o" << endl << endl;
 	cout << "Op��o: ";
 	cin >> opcao_limpar;
 	
 	if(opcao_limpar == 1){
 		system("cls");	
 		goto inicio;
	}
	else
	{
		goto inicio;
	}	
	// dois gotos e n�o apenas 1 fora do IF para evitar ciclos infitinos quando se utilizava a op��o "n�o"	
	return 0;
}

