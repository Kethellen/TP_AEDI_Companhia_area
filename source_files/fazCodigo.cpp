#include "fazCodigo.h"

using namespace std;

/**
 * Funcao para gerar o codigo de qualquer classe automaticamente
 * Entrada: string arquivo (caminho do arquivo onde os codigos sao armazenados)
 * Retorna: int (novo codigo gerado ou -1 em caso de erro)
 */
int fazCodigo(string arquivo) {
    ifstream arquivoLeitura(arquivo);

    if (!arquivoLeitura.is_open()) {
        cout << "Houve um problema ao abrir o arquivo para geracao de codigo." << endl;
        return -1;
    }

    string line;
    int maiorCodigo = 0;

    while (getline(arquivoLeitura, line)) {
        stringstream ss(line);
        string codigo;
        getline(ss, codigo, ',');
        if (stoi(codigo) > maiorCodigo) {
            maiorCodigo = stoi(codigo);
        }
    }

    arquivoLeitura.close();

    if (maiorCodigo == 0) {
        return 1; 
    }

    return ++maiorCodigo;
}