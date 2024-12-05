#include "Voo.h"
#include "fazCodigo.h"

/**
 * Construtor da classe Voo
 * Inicializa um novo voo com os parâmetros fornecidos
 */
Voo::Voo(string data, string hora, string origem, string destino, string codigoAviao,
         string codigoPiloto, string codigoCopiloto, string codigoComissario, float tarifa) {
    this->codigo = fazCodigo("data-files/voos.txt");
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

    cout << "Criando voo de código " << this->codigo << "...\n";
    if (!vooExiste(to_string(codigo))) {
        string vooStr = criaStringDeDados();
        if (armazenaDadosEmArquivo(vooStr) == 0) {
            cout << "Voo cadastrado com sucesso!\n";
        } else {
            cerr << "Erro ao armazenar os dados do voo.\n";
        }
    } else {
        cout << "Voo já existente.\n";
    }
}

/**
 * Cria uma string formatada com os dados do voo
 * @return String com os dados do voo
 */
string Voo::criaStringDeDados() {
    string dados = 
        to_string(this->codigo) + "," +
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
 * Verifica se um voo já existe no arquivo
 * @param identificador - Código do voo
 * @return true se o voo existir, false caso contrário
 */
bool Voo::vooExiste(string identificador) {
    ifstream arquivoVoo("data-files/voos.txt");

    if (!arquivoVoo) {
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
 * Armazena os dados do voo no arquivo
 * @param dados - Informações do voo
 * @return 1 em caso de erro, 0 em caso de sucesso
 */
int Voo::armazenaDadosEmArquivo(string dados) {
    ofstream arquivoVoo("data-files/voos.txt", ios::app);

    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos.\n";
        return 1;
    }

    arquivoVoo << dados;
    arquivoVoo.flush();
    arquivoVoo.close();

    return 0;
}

/**
 * Valida se a tripulação está completa para ativar o voo
 * @return true se a tripulação for válida, false caso contrário
 */
bool Voo::validarTripulacao() {
    return (!codigoPiloto.empty() && !codigoCopiloto.empty() && !codigoComissario.empty());
}

/**
 * Pesquisa um voo pelo código
 * @param identificador - Código do voo
 */
void Voo::pesquisarVoo(string identificador) {
    ifstream arquivoVoo("data-files/voos.txt");

    if (!arquivoVoo) {
        cerr << "Erro ao abrir o arquivo de voos.\n";
        return;
    }

    string linha;
    while (getline(arquivoVoo, linha)) {
        if (linha.find(identificador) != string::npos) {
            cout << "Voo encontrado: " << linha << endl;
            arquivoVoo.close();
            return;
        }
    }

    cout << "Voo não encontrado.\n";
    arquivoVoo.close();
}

/**
 * Atualiza os dados de um voo
 * @param identificador - Código do voo
 */
void Voo::atualizarVoo(string identificador) {
    ifstream arquivoVoo("data-files/voos.txt");
    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos para atualização.\n";
        return;
    }

    ofstream arquivoTemporario("data-files/temp.txt");
    string linha;
    bool encontrado = false;

    while (getline(arquivoVoo, linha)) {
        if (linha.find(identificador) != string::npos) {
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
            cout << "Digite o novo código do avião: ";
            getline(cin, novoCodigoAviao);
            cout << "Digite o novo código do piloto: ";
            getline(cin, novoCodigoPiloto);
            cout << "Digite o novo código do copiloto: ";
            getline(cin, novoCodigoCopiloto);
            cout << "Digite o novo código do comissário: ";
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

    remove("data-files/voos.txt");
    rename("data-files/temp.txt", "data-files/voos.txt");

    if (encontrado) {
        cout << "Voo atualizado com sucesso.\n";
    } else {
        cout << "Voo não encontrado.\n";
    }
}

/**
 * Remove um voo do arquivo
 * @param identificador - Código do voo
 */
void Voo::removerVoo(string identificador) {
    ifstream arquivoVoo("data-files/voos.txt");
    if (!arquivoVoo.is_open()) {
        cerr << "Erro ao abrir o arquivo de voos para exclusão.\n";
        return;
    }

    ofstream arquivoTemporario("data-files/temp.txt");
    string linha;
    bool encontrado = false;

    while (getline(arquivoVoo, linha)) {
        if (linha.find(identificador) != string::npos) {
            encontrado = true;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoVoo.close();
    arquivoTemporario.close();

    remove("data-files/voos.txt");
    rename("data-files/temp.txt", "data-files/voos.txt");

    if (encontrado) {
        cout << "Voo removido com sucesso.\n";
    } else {
        cout << "Voo não encontrado.\n";
    }
}
