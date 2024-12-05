#ifndef CALCULAPONTOSDEFIDELIDADE_H
#define CALCULAPONTOSDEFIDELIDADE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Funcao para calcular os pontos de fidelidade de um passageiro
 * Procura no arquivo de voos todos os voos associados ao codigo do passageiro
 * Atualiza o arquivo de clientes com os novos pontos de fidelidade
 * Entrada: string PassangerCode (codigo do passageiro)
 * Retorna: void
 */
void calculaPontosDeFidelidade(string PassangerCode);

#endif
