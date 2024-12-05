#include "Assento.h"
#include "fazCodigo.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Construtor da classe Assento
 * Inicializa um novo assento, associando-o ao passageiro informado.
 * Define o status inicial como desocupado.
 */
Assento::Assento(int passageiro) {
    this->numero = fazCodigo("data-files/assentos.txt");
    this->passageiro = passageiro;
    this->status = "desocupado";

    cout << "Criando assento de número " << this->numero << "...\n";
    if (!assentoExiste(to_string(numero))) {
        string assentoStr = criaStringDeDados();
        if (armazenaDadosEmArquivo(assentoStr) == 0) {
            cout << "Assento cadastrado com sucesso!\n";
        } else {
            cerr << "Erro ao armazenar os dados do assento.\n";
        }
    } else {
        cout << "Assento já existente.\n";
    }
}

/**
 * Cria uma string formatada com os dados do assento para armazenamento no arquivo.
 * Retorna uma string contendo as informações do assento.
 */
string Assento::criaStringDeDados() {
    return to_string(this->numero) + "," + to_string(this->passageiro) + "," + this->status + ";\n";
}

/**
 * Verifica se um assento já existe no arquivo.
 * Recebe o número do assento como identificador.
 * Retorna true se o assento já existir, ou false caso contrário.
 */
bool Assento::assentoExiste(string identificador) {
    ifstream arquivoAssento("data-files/assentos.txt");

    if (!arquivoAssento) {
        cerr << "Erro ao abrir o arquivo de assentos.\n";
        return false;
    }

    string line;
    while (getline(arquivoAssento, line)) {
        string codigo;
        stringstream ss(line);
        getline(ss, codigo, ',');
        if (codigo == identificador) {
            arquivoAssento.close();
            return true;
        }
    }

    arquivoAssento.close();
    return false;
}

/**
 * Armazena os dados do assento no arquivo.
 * Recebe os dados do assento como string.
 * Retorna 1 em caso de erro ao abrir o arquivo, ou 0 em caso de sucesso.
 */
int Assento::armazenaDadosEmArquivo(string dados) {
    ofstream arquivoAssento("data-files/assentos.txt", ios::app);

    if (!arquivoAssento.is_open()) {
        cerr << "Erro ao abrir o arquivo de assentos.\n";
        return 1;
    }

    arquivoAssento << dados;
    arquivoAssento.flush();
    arquivoAssento.close();

    return 0;
}

/**
 * Pesquisa os detalhes de um assento pelo número.
 * Recebe o número do assento.
 * Exibe os dados do assento no terminal, ou uma mensagem de erro caso não seja encontrado.
 */
void Assento::pesquisarAssento(int numeroAssento) {
    ifstream arquivoAssento("data-files/assentos.txt");

    if (!arquivoAssento) {
        cerr << "Erro ao abrir o arquivo de assentos.\n";
        return;
    }

    string line;
    while (getline(arquivoAssento, line)) {
        if (line.find(to_string(numeroAssento)) != string::npos) {
            cout << "Assento encontrado: " << line << endl;
            arquivoAssento.close();
            return;
        }
    }

    cout << "Assento não encontrado.\n";
    arquivoAssento.close();
}

/**
 * Atualiza o status de um assento no arquivo.
 * Recebe o número do assento e o novo status.
 * Exibe uma mensagem de sucesso ou erro.
 */
void Assento::atualizarAssento(int numeroAssento, string novoStatus) {
    ifstream arquivoAssento("data-files/assentos.txt");
    if (!arquivoAssento.is_open()) {
        cerr << "Erro ao abrir o arquivo de assentos.\n";
        return;
    }

    ofstream arquivoTemp("data-files/temp.txt");
    string line;
    bool encontrado = false;

    while (getline(arquivoAssento, line)) {
        if (line.find(to_string(numeroAssento)) != string::npos) {
            encontrado = true;
            stringstream ss(line);
            string numero, passageiro, status;

            getline(ss, numero, ',');
            getline(ss, passageiro, ',');
            getline(ss, status, ',');

            string novoRegistro = numero + "," + passageiro + "," + novoStatus + ";\n";
            arquivoTemp << novoRegistro;
        } else {
            arquivoTemp << line << endl;
        }
    }

    arquivoAssento.close();
    arquivoTemp.close();

    remove("data-files/assentos.txt");
    rename("data-files/temp.txt", "data-files/assentos.txt");

    if (encontrado) {
        cout << "Assento atualizado com sucesso.\n";
    } else {
        cout << "Assento não encontrado.\n";
    }
}

/**
 * Remove um assento do arquivo.
 * Recebe o número do assento.
 * Exibe uma mensagem de sucesso ou erro.
 */
void Assento::removerAssento(int numeroAssento) {
    ifstream arquivoAssento("data-files/assentos.txt");
    if (!arquivoAssento.is_open()) {
        cerr << "Erro ao abrir o arquivo de assentos.\n";
        return;
    }

    ofstream arquivoTemp("data-files/temp.txt");
    string line;
    bool encontrado = false;

    while (getline(arquivoAssento, line)) {
        if (line.find(to_string(numeroAssento)) != string::npos) {
            encontrado = true;
        } else {
            arquivoTemp << line << endl;
        }
    }

    arquivoAssento.close();
    arquivoTemp.close();

    remove("data-files/assentos.txt");
    rename("data-files/temp.txt", "data-files/assentos.txt");

    if (encontrado) {
        cout << "Assento removido com sucesso.\n";
    } else {
        cout << "Assento não encontrado.\n";
    }
}
