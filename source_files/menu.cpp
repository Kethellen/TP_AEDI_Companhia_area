#include "menu.h"
#include "Passageiro.h"
#include "Tripulacao.h"
#include "Voo.h"
#include "Reserva.h"
#include "CalculaPontosDeFidelidade.h"
#include <iostream>

using namespace std;

/**
 * Funcao principal do menu
 */
void menu() {
    bool exit = false;

    cout << "Bem vindo(a) a Companhia Aerea Voo Seguro\n";

    while (!exit) {
        cout << "\n1) Gerenciar Passageiros\n"
            << "2) Gerenciar Tripulacao\n"
            << "3) Gerenciar Voos\n"
            << "4) Gerenciar Reservas\n"
            << "5) Programa de Fidelidade\n"
            << "6) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1:
                menu_passageiro();
                break;
            case 2:
                menu_tripulacao();
                break;
            case 3:
                menu_voo();
                break;
            case 4:
                menu_reserva();
                break;
            case 5:
                programaFidelidade();
                break;
            case 6:
                cout << "Saindo... Obrigado por utilizar o sistema!\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar voos
 */
void menu_voo() {
    bool exit = false;

    while (!exit) {
        cout << "\n*** Gerenciar Voos ***\n"
            << "1) Cadastrar Voo\n"
            << "2) Atualizar Voo\n"
            << "3) Buscar Voo\n"
            << "4) Excluir Voo\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                string data, hora, origem, destino, codigoAviao, codigoPiloto, codigoCopiloto, codigoComissario;
                double tarifa;

                cout << "Digite a data do voo (DD/MM/AAAA): ";
                cin.ignore();
                getline(cin, data);

                cout << "Digite a hora do voo (HH:MM): ";
                getline(cin, hora);

                cout << "Digite a origem do voo: ";
                getline(cin, origem);

                cout << "Digite o destino do voo: ";
                getline(cin, destino);

                cout << "Digite o codigo do aviao: ";
                getline(cin, codigoAviao);

                cout << "Digite o codigo do piloto: ";
                getline(cin, codigoPiloto);

                cout << "Digite o codigo do copiloto: ";
                getline(cin, codigoCopiloto);

                cout << "Digite o codigo do comissario: ";
                getline(cin, codigoComissario);

                cout << "Digite a tarifa do voo: ";
                cin >> tarifa;

                Voo novoVoo(data, hora, origem, destino, codigoAviao, codigoPiloto, codigoCopiloto, codigoComissario, tarifa);
                break;
            }
            case 2:
                cout << "Funcao de atualizar voo ainda nao implementada.\n";
                break;
            case 3:
                cout << "Funcao de buscar voo ainda nao implementada.\n";
                break;
            case 4:
                cout << "Funcao de excluir voo ainda nao implementada.\n";
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar reservas
 */
void menu_reserva() {
    bool exit = false;

    while (!exit) {
        cout << "\n*** Gerenciar Reservas ***\n"
            << "1) Cadastrar Reserva\n"
            << "2) Atualizar Reserva\n"
            << "3) Buscar Reserva\n"
            << "4) Excluir Reserva\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                string codigoVoo, codigoPassageiro, numeroAssento;

                cout << "Digite o codigo do voo: ";
                cin.ignore();
                getline(cin, codigoVoo);

                cout << "Digite o numero do assento: ";
                getline(cin, numeroAssento);

                cout << "Digite o codigo do passageiro: ";
                getline(cin, codigoPassageiro);

                try {
                    int numeroAssentoInt = stoi(numeroAssento); // Converte string para int
                    Reserva novaReserva(codigoVoo, numeroAssentoInt, codigoPassageiro);
                } catch (const invalid_argument &e) {
                    cerr << "Erro: O numero do assento deve ser um numero válido.\n";
                } catch (const out_of_range &e) {
                    cerr << "Erro: O numero do assento estae fora do intervalo permitido.\n";
                }
                break;
            }
            case 2:
                cout << "Funcao de atualizar reserva ainda nao implementada.\n";
                break;
            case 3:
                cout << "Funcao de buscar reserva ainda nao implementada.\n";
                break;
            case 4:
                cout << "Funcao de excluir reserva ainda nao implementada.\n";
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar passageiros
 */
void menu_passageiro(){
    bool exit = false;

    while (!exit) {
        cout << "\n*** Gerenciar Passageiros ***\n"
            << "1) Cadastrar Passageiro\n"
            << "2) Atualizar Passageiro\n"
            << "3) Buscar Passageiro\n"
            << "4) Excluir Passageiro\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                string nomePassageiro, telefonePassageiro;
                Passageiro p;

                cout << "Digite o nome do passageiro: ";
                cin.ignore();
                getline(cin, nomePassageiro);
                p.setPessoa(nomePassageiro);

                cout << "Digite o telefone do passageiro: ";
                cin.ignore();
                getline(cin, telefonePassageiro);
                p.setTelefone(telefonePassageiro);

                // p.mostrarPessoa();

                break;
            }
            case 2:
                cout << "Funcao de atualizar passageiro ainda nao implementada.\n";
                break;
            case 3:
                cout << "Funcao de buscar passageiro ainda nao implementada.\n";
                break;
            case 4:
                cout << "Funcao de excluir passageiro ainda nao implementada.\n";
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar tripulacao
 */
void menu_tripulacao(){
    bool exit = false;

    while (!exit) {
        cout << "\n*** Gerenciar Tripulacao ***\n"
            << "1) Cadastrar Tripulacao\n"
            << "2) Atualizar Tripulacao\n"
            << "3) Buscar Tripulacao\n"
            << "4) Excluir Tripulacao\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                string nomeTripulacao;

                cout << "Digite o nome do integrante da tripulacao: ";
                cin.ignore();
                getline(cin, nomeTripulacao);
                break;
            }
            case 2:
                cout << "Funcao de atualizar tripulacao ainda nao implementada.\n";
                break;
            case 3:
                cout << "Funcao de buscar tripulacao ainda nao implementada.\n";
                break;
            case 4:
                cout << "Funcao de excluir tripulacao ainda nao implementada.\n";
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}


/**
 * Programa de fidelidade
 */
void programaFidelidade() {
    cout << "\n*** Programa de Fidelidade ***\n";
    cout << "Digite o codigo do passageiro para calcular os pontos de fidelidade: ";
    cin.ignore();
    string codigo;
    getline(cin, codigo);

    calculaPontosDeFidelidade(codigo);
}
