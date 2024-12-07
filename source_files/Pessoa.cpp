#include "Pessoa.h"
#include "fazCodigo.h"

/**
 * Construtor padrao da classe Pessoa
 */
Pessoa::Pessoa() {
    codigo = 0;
    nome = '\0';
    telefone = '\0';
}

/**
 * Construtor parametrizado da classe Pessoa
 */
Pessoa::Pessoa(string nome, string telefone) {
    this->codigo = 0;
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

/**
 * Metodo para definir acessar e definir o atributo nome da classe pessoa
 */
void Pessoa::setPessoa(string nome){
    this->nome, nome;
}

/**
 * Metodo para definir acessar e definir o atributo telefone da classe pessoa
 */
void Pessoa::setTelefone(string telefone){
    this->telefone, telefone;
}

/**
 * Metodo para exibir os atributos da classe pessoa
 */
int Pessoa::mostrarPessoa(){
    cout << "Nome da pessoa: " << nome << endl;
    cout << "Telefone: " << telefone << endl;
}