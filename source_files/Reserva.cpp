#include "Reserva.h"
#include "fazCodigo.h"

/**
 * Construtor da classe Reserva
 * Inicializa uma nova reserva com os parâmetros fornecidos
 */
Reserva::Reserva(string codigoVoo, int numeroAssento, string codigoPassageiro) {
    this->codigo = fazCodigo("data-files/reservas.txt");
    this->codigoVoo = codigoVoo;
    this->numeroAssento = numeroAssento;
    this->codigoPassageiro = codigoPassageiro;

    cout << "Criando reserva de código " << this->codigo << "...\n";
    if (!reservaExiste(to_string(codigo))) {
        string reservaStr = criaStringDeDados();
        if (armazenaDadosEmArquivo(reservaStr) == 0) {
            cout << "Reserva cadastrada com sucesso!\n";
        } else {
            cerr << "Erro ao armazenar os dados da reserva.\n";
        }
    } else {
        cout << "Reserva já existente.\n";
    }
}

/**
 * Cria a string formatada para armazenar no arquivo
 * @return String com os dados da reserva
 */
string Reserva::criaStringDeDados() {
    return to_string(this->codigo) + "," + this->codigoVoo + "," +
           to_string(this->numeroAssento) + "," + this->codigoPassageiro + ";\n";
}

/**
 * Verifica se uma reserva já existe no arquivo
 * @param identificador - Código da reserva
 * @return true se a reserva existir, false caso contrário
 */
bool Reserva::reservaExiste(string identificador) {
    ifstream arquivoReserva("data-files/reservas.txt");

    if (!arquivoReserva) {
        cerr << "Erro ao abrir o arquivo de reservas.\n";
        return false;
    }

    string linha;
    while (getline(arquivoReserva, linha)) {
        string codigo;
        stringstream ss(linha);
        getline(ss, codigo, ',');
        if (codigo == identificador) {
            arquivoReserva.close();
            return true;
        }
    }

    arquivoReserva.close();
    return false;
}

/**
 * Armazena os dados da reserva no arquivo
 * @param dados - Informações da reserva
 * @return 1 em caso de erro, 0 em caso de sucesso
 */
int Reserva::armazenaDadosEmArquivo(string dados) {
    ofstream arquivoReserva("data-files/reservas.txt", ios::app);

    if (!arquivoReserva.is_open()) {
        cerr << "Erro ao abrir o arquivo de reservas.\n";
        return 1;
    }

    arquivoReserva << dados;
    arquivoReserva.flush();
    arquivoReserva.close();

    return 0;
}

/**
 * Pesquisa uma reserva pelo código
 * @param identificador - Código da reserva
 */
void Reserva::pesquisarReserva(string identificador) {
    ifstream arquivoReserva("data-files/reservas.txt");

    if (!arquivoReserva) {
        cerr << "Erro ao abrir o arquivo de reservas.\n";
        return;
    }

    string linha;
    while (getline(arquivoReserva, linha)) {
        if (linha.find(identificador) != string::npos) {
            cout << "Reserva encontrada: " << linha << endl;
            arquivoReserva.close();
            return;
        }
    }

    cout << "Reserva não encontrada.\n";
    arquivoReserva.close();
}

/**
 * Atualiza uma reserva
 * @param identificador - Código da reserva
 */
void Reserva::atualizarReserva(string identificador) {
    ifstream arquivoReserva("data-files/reservas.txt");
    if (!arquivoReserva.is_open()) {
        cerr << "Erro ao abrir o arquivo de reservas para atualização.\n";
        return;
    }

    ofstream arquivoTemporario("data-files/temp.txt");
    string linha;
    bool encontrado = false;

    while (getline(arquivoReserva, linha)) {
        if (linha.find(identificador) != string::npos) {
            encontrado = true;

            string novoCodigoVoo, novoCodigoPassageiro;
            int novoNumeroAssento;

            cout << "Digite o novo código do voo: ";
            cin.ignore();
            getline(cin, novoCodigoVoo);
            cout << "Digite o novo número do assento: ";
            cin >> novoNumeroAssento;
            cin.ignore();
            cout << "Digite o novo código do passageiro: ";
            getline(cin, novoCodigoPassageiro);

            string novoRegistro = identificador + "," + novoCodigoVoo + "," +
                                  to_string(novoNumeroAssento) + "," + novoCodigoPassageiro + ";\n";
            arquivoTemporario << novoRegistro;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoReserva.close();
    arquivoTemporario.close();

    remove("data-files/reservas.txt");
    rename("data-files/temp.txt", "data-files/reservas.txt");

    if (encontrado) {
        cout << "Reserva atualizada com sucesso.\n";
    } else {
        cout << "Reserva não encontrada.\n";
    }
}

/**
 * Remove uma reserva do arquivo
 * @param identificador - Código da reserva
 */
void Reserva::removerReserva(string identificador) {
    ifstream arquivoReserva("data-files/reservas.txt");
    if (!arquivoReserva.is_open()) {
        cerr << "Erro ao abrir o arquivo de reservas para exclusão.\n";
        return;
    }

    ofstream arquivoTemporario("data-files/temp.txt");
    string linha;
    bool encontrado = false;

    while (getline(arquivoReserva, linha)) {
        if (linha.find(identificador) != string::npos) {
            encontrado = true;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoReserva.close();
    arquivoTemporario.close();

    remove("data-files/reservas.txt");
    rename("data-files/temp.txt", "data-files/reservas.txt");

    if (encontrado) {
        cout << "Reserva removida com sucesso.\n";
    } else {
        cout << "Reserva não encontrada.\n";
    }
}
