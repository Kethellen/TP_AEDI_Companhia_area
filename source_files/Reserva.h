#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Classe Reserva
 * Gerencia os dados e operações de uma reserva
 */
class Reserva {
private:
    int codigo;
    string codigoVoo;
    int numeroAssento;
    string codigoPassageiro;

    /**
     * Verifica se uma reserva já existe no arquivo
     * @param identificador - Código da reserva
     * @return true se a reserva existir, false caso contrário
     */
    bool reservaExiste(string identificador);

    /**
     * Cria uma string formatada com os dados da reserva
     * @return String formatada com os dados da reserva
     */
    string criaStringDeDados();

    /**
     * Armazena os dados da reserva no arquivo
     * @param dados - Informações da reserva
     * @return 1 em caso de erro, 0 em caso de sucesso
     */
    int armazenaDadosEmArquivo(string dados);

public:
    /**
     * Construtor da classe Reserva
     * @param codigoVoo - Código do voo
     * @param numeroAssento - Número do assento
     * @param codigoPassageiro - Código do passageiro
     */
    Reserva(string codigoVoo, int numeroAssento, string codigoPassageiro);

    /**
     * Pesquisa uma reserva pelo código
     * @param identificador - Código da reserva
     */
    void pesquisarReserva(string identificador);

    /**
     * Atualiza uma reserva
     * @param identificador - Código da reserva
     */
    void atualizarReserva(string identificador);

    /**
     * Remove uma reserva do arquivo
     * @param identificador - Código da reserva
     */
    void removerReserva(string identificador);
};

#endif
