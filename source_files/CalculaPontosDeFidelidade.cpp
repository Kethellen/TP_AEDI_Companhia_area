#include "CalculaPontosDeFidelidade.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Procedimento que calcula os pontos de fidelidade de um passageiro
 * Procura no arquivo de voos todos os voos associados ao codigo do passageiro
 * Atualiza o arquivo de clientes com os novos pontos de fidelidade
 * Entrada: string codigoPassageiro (codigo do passageiro)
 * Retorna: void
 */
void calculaPontosDeFidelidade(string codigoPassageiro) {
    ifstream arquivoVoos("data-files/voos.txt");

    if (!arquivoVoos) {
        cerr << "Erro ao abrir o arquivo de voos na funcao de calculo de pontos de fidelidade." << endl;
        return;
    }

    string line;
    vector<string> voosDoCliente;

    /*
    Armazena todas as linhas contendo voos do passageiro especificado
    */
    while (getline(arquivoVoos, line)) {
        stringstream ss(line);
        string codigoPessoa, temp;
        getline(ss, temp, ','); /*Ignorar campos iniciais*/
        getline(ss, temp, ',');
        getline(ss, temp, ',');
        getline(ss, temp, ',');
        getline(ss, codigoPessoa, ',');

        if (codigoPessoa == codigoPassageiro) {
            voosDoCliente.push_back(line);
        }
    }

    arquivoVoos.close();

    if (voosDoCliente.empty()) {
        cout << "Nenhum voo foi encontrado para o passageiro " << codigoPassageiro << "." << endl;
        return;
    }

    int numVoos = 0;

    /*
    Calcula o total de voos do passageiro
    */
    for (const string &voo : voosDoCliente) {
        numVoos++; /*Cada voo encontrado no vetor representa um voo valido*/
    }

    /*
    Calcula os pontos de fidelidade do passageiro
    */
    int pontos = 10 * numVoos;

    ifstream clientesFileRead("data-files/clientes.txt");

    if (!clientesFileRead) {
        cerr << "Erro ao abrir o arquivo de passageiros para leitura na funcao de calculo de pontos de fidelidade." << endl;
        return;
    }

    vector<string> vetorDePassageiros;
    string passageiroDados;
    string codigoCliente, nome, endereco, telefone;

    /*
    Armazena todos os clientes exceto o buscado e extrai os dados do cliente
    */
    while (getline(clientesFileRead, passageiroDados)) {
        stringstream ss(passageiroDados);
        string codigo;
        getline(ss, codigo, ',');
        if (codigo != codigoPassageiro) {
            vetorDePassageiros.push_back(passageiroDados);
        } else {
            stringstream ss(passageiroDados);
            getline(ss, codigoCliente, ',');
            getline(ss, nome, ',');
            getline(ss, telefone, ',');
            getline(ss, endereco, ',');
        }
    }

    clientesFileRead.close();

    /*
    Cria uma string com os dados do passageiro e seus pontos atualizados
    */
    string strModificada =
        codigoPassageiro + "," +
        nome + "," +
        telefone + "," +
        endereco + "," +
        to_string(pontos) + ";";

    /*
    Atualiza o vetor de passageiros com os dados modificados
    */
    vetorDePassageiros.push_back(strModificada);

    ofstream clientesFileWrite("data-files/clientes.txt", ios::trunc);

    if (!clientesFileWrite.is_open()) {
        cerr << "Erro ao abrir o arquivo de passageiros para escrita." << endl;
        return;
    }

    /*
    Sobrescreve o arquivo de clientes com os dados atualizados
    */
    for (const string &cliente : vetorDePassageiros) {
        clientesFileWrite << cliente << endl;
    }

    clientesFileWrite.close();

    cout << "Pontos de fidelidade atualizados com sucesso para o passageiro " << codigoPassageiro << "." << endl;
}
