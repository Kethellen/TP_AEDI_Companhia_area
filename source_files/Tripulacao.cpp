#include "Tripulacao.h"
#include "fazCodigo.h"

/**
 * Construtor da classe Tripulacao
 */
Tripulacao::Tripulacao(string nome, string telefone, string cargo)
    : Pessoa(nome, telefone) {
    this->codigo = fazCodigo("../data-files/tripulacao.txt");
    this->cargo = cargo;

    cout << "Criando membro da tripulacao " << this->nome << " com codigo " << this->codigo << "...\n";

    if (!pessoaExiste(to_string(codigo), "../data-files/tripulacao.txt")) {
        string tripulacaoStr = criaStringDeDados();
        armazenaDadosEmArquivo("../data-files/tripulacao.txt", tripulacaoStr);
    } else {
        cout << "Membro da tripulacao ja existe.\n";
    }
}

/**
 * Metodo que cria a string de dados para armazenamento no arquivo
 */
string Tripulacao::criaStringDeDados() {
    return to_string(this->codigo) + "," + this->nome + "," + this->telefone + "," + this->cargo + ";\n";
}
