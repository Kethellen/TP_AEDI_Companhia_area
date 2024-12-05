#include "Pessoa.h"
#include "fazCodigo.h"

/**
 * Construtor da classe Pessoa
 */
Pessoa::Pessoa(string nome, string telefone) {
    this->codigo = 0; // O codigo sera atribuido pelas classes derivadas
    this->nome = nome;
    this->telefone = telefone;
}

/**
 * Metodo que verifica se a pessoa ja existe no arquivo
 * Entrada: string identificador (codigo ou nome), string arquivo
 * Retorna: true se a pessoa existir, false caso contrario
 */
bool Pessoa::pessoaExiste(string identificador, string arquivo) {
    ifstream arquivoLeitura(arquivo);
    if (!arquivoLeitura.is_open()) {
        cerr << "Erro ao abrir o arquivo " << arquivo << " para verificacao de existencia.\n";
        return false;
    }

    string line;
    while (getline(arquivoLeitura, line)) {
        if (line.find(identificador) != string::npos) {
            arquivoLeitura.close();
            return true;
        }
    }

    arquivoLeitura.close();
    return false;
}

/**
 * Metodo que armazena os dados da pessoa no arquivo
 * Entrada: string arquivo, string dados
 * Retorna: -1 em caso de erro, 0 em caso de sucesso
 */
int Pessoa::armazenaDadosEmArquivo(string arquivo, string dados) {
    ofstream arquivoEscrita(arquivo, ios::app);
    if (!arquivoEscrita.is_open()) {
        cerr << "Erro ao abrir o arquivo " << arquivo << " para escrita.\n";
        return -1;
    }

    arquivoEscrita << dados;
    arquivoEscrita.close();
    return 0;
}


int Pessoa::getPessoa(string nome){

}