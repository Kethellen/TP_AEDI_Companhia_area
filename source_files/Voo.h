#ifndef VOO_H
#define VOO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Classe Voo
 * Gerencia os dados e operações relacionadas a um voo
 */
class Voo {
private:
    int codigo;
    string data;
    string hora;
    string origem;
    string destino;
    string codigoAviao;
    string codigoPiloto;
    string codigoCopiloto;
    string codigoComissario;
    bool ativo;
    float tarifa;

    /**
     * Verifica se um voo já existe no arquivo
     * @param identificador - Código do voo
     * @return true se o voo existir, false caso contrário
     */
    bool vooExiste(string identificador);

    /**
     * Cria uma string formatada com os dados do voo
     * @return String formatada com os dados do voo
     */
    string criaStringDeDados();

    /**
     * Valida se a tripulação está completa para ativar o voo
     * @return true se a tripulação for válida, false caso contrário
     */
    bool validarTripulacao();

    /**
     * Armazena os dados do voo no arquivo
     * @param dados - Informações do voo
     * @return 1 em caso de erro, 0 em caso de sucesso
     */
    int armazenaDadosEmArquivo(string dados);

public:
    /**
     * Construtor da classe Voo
     * Inicializa um novo voo com os parâmetros fornecidos
     */
    Voo(string data, string hora, string origem, string destino, string codigoAviao,
        string codigoPiloto, string codigoCopiloto, string codigoComissario, float tarifa);

    /**
     * Pesquisa um voo pelo código
     * @param identificador - Código do voo
     */
    void pesquisarVoo(string identificador);

    /**
     * Atualiza os dados de um voo
     * @param identificador - Código do voo
     */
    void atualizarVoo(string identificador);

    /**
     * Remove um voo do arquivo
     * @param identificador - Código do voo
     */
    void removerVoo(string identificador);
};

#endif
