#include "Voo.h"

#define FILE_VOOS "data-files/voos.txt"

/**
 * Construtor da classe Voo
 * Inicializa um novo voo com os parametros fornecidos
 */
Voo::Voo(string data, string hora, string origem, string destino, string codigoAviao,
         string codigoPiloto, string codigoCopiloto, string codigoComissario, float tarifa) {
    this->codigo = gerarCodigo();
    this->data = data;
    this->hora = hora;
    this->origem = origem;
    this->destino = destino;
    this->codigoAviao = codigoAviao;
    this->codigoPiloto = codigoPiloto;
    this->codigoCopiloto = codigoCopiloto;
    this->codigoComissario = codigoComissario;
    this->tarifa = tarifa;
    this->ativo = validarTripulacao();

    cout << "Criando codigo de voo " << this->codigo << "...\n"; 
    if (!vooExiste(this->codigo)) {
        string vooStr = criaStringDeDados();
        if (armazenaDadosEmArquivo(vooStr) == 0) {
            cout << "Voo cadastrado com sucesso!\n";
        } else {
            cerr << "Erro ao armazenar os dados do voo.\n";
        }
    } else {
        cout << "Voo ja existente.\n";
    }
}

/**
 * Metodo que cria uma string formatada com os dados do voo
 * @return String com os dados do voo
 */
string Voo::criaStringDeDados() {
    string dados =
        this->codigo + "," +
        this->data + "," +
        this->hora + "," +
        this->origem + "," +
        this->destino + "," +
        this->codigoAviao + "," +
        this->codigoPiloto + "," +
        this->codigoCopiloto + "," +
        this->codigoComissario + "," +
        (this->ativo ? "ativo" : "inativo") + "," +
        to_string(this->tarifa) + ";\n";

    return dados;
}

/**
 * Metodo que verifica se um voo ja existe no arquivo
 * @param identificador - Codigo do voo
 * @return true se o voo existir, false caso contrario
 */
bool Voo::vooExiste(string identificador) {
    ifstream arquivoVoo(FILE_VOOS);

    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos.\n";
        return false;
    }

    string linha;
    while (getline(arquivoVoo, linha)) {
        string codigo;
        stringstream ss(linha);
        getline(ss, codigo, ',');
        if (codigo == identificador) {
            arquivoVoo.close();
            return true;
        }
    }

    arquivoVoo.close();
    return false;
}

/**
 * Metodo que armazena os dados do voo no arquivo
 * @param dados - Informacoes do voo
 * @return 1 em caso de erro, 0 em caso de sucesso
 */
int Voo::armazenaDadosEmArquivo(string dados) {
    ofstream arquivoVoo(FILE_VOOS, ios::app);

    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos.\n";
        return 1;
    }

    arquivoVoo << dados;
    arquivoVoo.close();

    return 0;
}

/**
 * Metodo que gera um novo codigo para o voo
 * @return Novo codigo gerado
 */
string Voo::gerarCodigo() {
    int maiorCodigoAtual = 0;
    ifstream arquivoVoo(FILE_VOOS);

    if (arquivoVoo.is_open()) {
        string linha;

        while (getline(arquivoVoo, linha)) {
            if (linha.empty()) continue;

            size_t pos = linha.find(",");
            if (pos != string::npos) {
                try {
                    int codigoAtual = stoi(linha.substr(0, pos));
                    if (codigoAtual > maiorCodigoAtual) {
                        maiorCodigoAtual = codigoAtual;
                    }
                } catch (const std::invalid_argument &e) {
                    continue;
                } catch (const std::out_of_range &e) {
                    continue;
                }
            }
        }

        arquivoVoo.close();
    }

    return to_string(maiorCodigoAtual + 1);
}

/**
 * Metodo que valida se a tripulacao esta completa para ativar o voo
 * @return true se a tripulacao for valida, false caso contrario
 */
bool Voo::validarTripulacao() {
    return (!codigoPiloto.empty() && !codigoCopiloto.empty() && !codigoComissario.empty());
}

/**
 * Metodo para pesquisar um voo pelo codigo
 * @param identificador - Codigo do voo
 */
void Voo::pesquisarVoo(string identificador) {
    ifstream arquivoVoo(FILE_VOOS);

    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos.\n";
        return;
    }

    string linha;
    while (getline(arquivoVoo, linha)) {
        if (linha.find(identificador + ",") == 0) {
            cout << "Voo encontrado: " << linha << endl;
            arquivoVoo.close();
            return;
        }
    }

    cout << "Voo nao encontrado.\n";
    arquivoVoo.close();
}

/**
 * Metodo para atualizar os dados de um voo
 * @param identificador - Codigo do voo
 */
void Voo::atualizarVoo(string identificador) {
    ifstream arquivoVoo(FILE_VOOS);
    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos para atualizacao.\n";
        return;
    }

    ofstream arquivoTemporario("data-files/temp.txt");
    string linha;
    bool encontrado = false;

    while (getline(arquivoVoo, linha)) {
        if (linha.find(identificador + ",") == 0) {
            encontrado = true;

            string novaData, novaHora, novaOrigem, novoDestino, novoCodigoAviao, novoCodigoPiloto, novoCodigoCopiloto, novoCodigoComissario;
            float novaTarifa;

            cout << "Digite a nova data: ";
            cin.ignore();
            getline(cin, novaData);
            cout << "Digite a nova hora: ";
            getline(cin, novaHora);
            cout << "Digite a nova origem: ";
            getline(cin, novaOrigem);
            cout << "Digite o novo destino: ";
            getline(cin, novoDestino);
            cout << "Digite o novo codigo do aviao: ";
            getline(cin, novoCodigoAviao);
            cout << "Digite o novo codigo do piloto: ";
            getline(cin, novoCodigoPiloto);
            cout << "Digite o novo codigo do copiloto: ";
            getline(cin, novoCodigoCopiloto);
            cout << "Digite o novo codigo do comissario: ";
            getline(cin, novoCodigoComissario);
            cout << "Digite a nova tarifa: ";
            cin >> novaTarifa;
            cin.ignore();

            string novoRegistro =
                identificador + "," + novaData + "," + novaHora + "," + novaOrigem + "," + novoDestino + "," +
                novoCodigoAviao + "," + novoCodigoPiloto + "," + novoCodigoCopiloto + "," + novoCodigoComissario + "," +
                to_string(novaTarifa) + ";\n";

            arquivoTemporario << novoRegistro;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoVoo.close();
    arquivoTemporario.close();

    remove(FILE_VOOS);
    rename("data-files/temp.txt", FILE_VOOS);

    if (encontrado) {
        cout << "Voo atualizado com sucesso.\n";
    } else {
        cout << "Voo nao encontrado.\n";
    }
}

/**
 * Metodo para remover um voo do arquivo
 * @param identificador - Codigo do voo
 */
void Voo::removerVoo(string identificador) {
    ifstream arquivoVoo(FILE_VOOS);
    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos para exclusao.\n";
        return;
    }

    ofstream arquivoTemporario("data-files/temp.txt");
    string linha;
    bool encontrado = false;

    while (getline(arquivoVoo, linha)) {
        if (linha.find(identificador + ",") == 0) {
            encontrado = true;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoVoo.close();
    arquivoTemporario.close();

    remove(FILE_VOOS);
    rename("data-files/temp.txt", FILE_VOOS);

    if (encontrado) {
        cout << "Voo removido com sucesso.\n";
    } else {
        cout << "Voo nao encontrado.\n";
    }
}
