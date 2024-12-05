#ifndef FAZCODIGO_H
#define FAZCODIGO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Funcao para gerar automaticamente o codigo unico de qualquer classe
 * Entrada: string arquivo (caminho do arquivo onde os codigos sao armazenados)
 * Retorna: int (novo codigo gerado ou -1 em caso de erro)
 */
int fazCodigo(string arquivo);

#endif
