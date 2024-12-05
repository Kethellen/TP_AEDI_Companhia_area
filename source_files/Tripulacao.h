#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include "Pessoa.h"

/**
 * Classe Tripulacao que herda de Pessoa
 */
class Tripulacao : public Pessoa {
private:
    string cargo;

public:
    Tripulacao(string nome, string telefone, string cargo);
    string criaStringDeDados() override;
};

#endif
