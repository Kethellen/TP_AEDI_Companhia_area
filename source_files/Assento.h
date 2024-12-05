#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Classe Assento
 * Responsável por gerenciar os assentos dos voos
 */
class Assento {
private:
    int numero;        // Número do assento
    int passageiro;    // Código do passageiro associado ao assento
    string status;     // Status do assento (ocupado/desocupado)

    /**
     * Verifica se um assento já existe no arquivo com base no número.
     * Recebe o número do assento como argumento.
     * Retorna true se o assento existir, false caso contrário.
     */
    bool assentoExiste(string identificador);

    /**
     * Cria uma string formatada com os dados do assento
     * Retorna uma string com os dados do assento.
     */
    string criaStringDeDados();

    /**
     * Armazena os dados do assento no arquivo.
     * Recebe os dados do assento como string.
     * Retorna 1 em caso de erro ao abrir o arquivo, ou 0 em caso de sucesso.
     */
    int armazenaDadosEmArquivo(string dados);

public:
    /**
     * Construtor da classe Assento
     * Recebe o código do passageiro associado ao assento.
     * Inicializa um novo assento e define seu status como desocupado.
     */
    Assento(int passageiro);

    /**
     * Pesquisa os detalhes de um assento pelo número.
     * Recebe o número do assento a ser pesquisado.
     * Exibe os dados do assento no terminal.
     */
    void pesquisarAssento(int numeroAssento);

    /**
     * Atualiza o status de um assento.
     * Recebe o número do assento e o novo status (ocupado/desocupado).
     * Atualiza os dados no arquivo.
     */
    void atualizarAssento(int numeroAssento, string novoStatus);

    /**
     * Remove um assento do arquivo.
     * Recebe o número do assento a ser removido.
     * Exclui os dados do arquivo.
     */
    void removerAssento(int numeroAssento);
};

#endif
