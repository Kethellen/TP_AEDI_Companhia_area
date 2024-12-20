#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Classe base para representar uma pessoa (Passageiro ou Tripulacao)
 */
class Pessoa {
private:
    int codigo;
    string nome;
    string telefone;

public:
    Pessoa();
    Pessoa(string nome, string telefone);
    virtual ~Pessoa() = default;

    virtual string criaStringDeDados() = 0; // Metodo abstrato a ser implementado nas classes derivadas
    bool pessoaExiste(string identificador, string arquivo);
    int armazenaDadosEmArquivo(string arquivo, string dados);

    //Metodos set para para os atributos da pessoa
    void setPessoa(string nome);
    void setTelefone(string telefone);
    int mostrarPessoa();
};

#endif
