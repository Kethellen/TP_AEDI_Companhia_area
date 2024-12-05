#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"

/**
 * Classe Passageiro que herda de Pessoa
 */
class Passageiro : public Pessoa {
private:
    string endereco;
    int pontosDeFidelidade;

public:
    Passageiro(string nome, string telefone, string endereco);
    string criaStringDeDados() override;
};

#endif
