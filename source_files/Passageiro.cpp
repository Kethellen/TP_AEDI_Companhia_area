#include "Passageiro.h"
#include "fazCodigo.h"

/**
 * Construtor da classe Passageiro
 */
Passageiro::Passageiro(string nome, string telefone, string endereco)
    : Pessoa(nome, telefone) {
    this->codigo = fazCodigo("../data-files/passageiros.txt");
    this->endereco = endereco;
    this->pontosDeFidelidade = 0;

    cout << "Criando passageiro " << this->nome << " com codigo " << this->codigo << "...\n";

    if (!pessoaExiste(to_string(codigo), "../data-files/passageiros.txt")) {
        string passageiroStr = criaStringDeDados();
        armazenaDadosEmArquivo("../data-files/passageiros.txt", passageiroStr);
    } else {
        cout << "Passageiro ja existe.\n";
    }
}

/**
 * Metodo que cria a string de dados para armazenamento no arquivo
 */
string Passageiro::criaStringDeDados() {
    return to_string(this->codigo) + "," + this->nome + "," + this->telefone + "," +
           this->endereco + "," + to_string(this->pontosDeFidelidade) + ";\n";
}
