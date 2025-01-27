#include <iostream>
#include "usuario.h"
#include "pacientes.h"
#include "auditoria.h"
#include "menupacientes.h"
#include "menuprincipal.h"
#include "menuadmin.h"

int main() {
    GerenciamentoPacientes gerenciamentoPacientes;
    std::string nomeArquivo = "../data/pacientes.csv";  // Caminho relativo para salvar em 'data'
    Auditoria auditoria;

    // Etapa 1: Escolher entre login ou cadastro
    int opcaoAutenticacao;
    std::cout << "Escolha uma opção:\n";
    std::cout << "1. Login\n";
    std::cout << "2. Cadastro\n";
    std::cin >> opcaoAutenticacao;

    std::string username, password;
    Usuario* usuarioAutenticado = nullptr;

    if (opcaoAutenticacao == 1) {
        // Realiza o Login
        while (usuarioAutenticado == nullptr) {
            std::cout << "Digite seu nome de usuario: ";
            std::cin >> username;
            std::cout << "Digite sua senha: ";
            std::cin >> password;

            usuarioAutenticado = autenticar_usuario(username, password);
            if (usuarioAutenticado == nullptr) {
                std::cout << "Nome de usuário ou senha incorretos. Tente novamente.\n";
            }
        }
    } else if (opcaoAutenticacao == 2) {
        // Realiza o Cadastro
        std::cout << "Digite o nome de usuario: ";
        std::cin >> username;
        std::cout << "Digite a senha: ";
        std::cin >> password;

        // Solicitar o nível de acesso
        int nivelAcessoInt;
        std::cout << "Escolha o nível de acesso:\n";
        std::cout << "0. ADMIN\n";
        std::cout << "1. MEDICO\n";
        std::cout << "2. ENFERMEIRO\n";
        std::cout << "3. TECNICO_LABORATORIO\n";
        std::cout << "4. RECEPCIONISTA\n";
        std::cout << "5. FARMACEUTICO\n";
        std::cout << "6. ADMINISTRACAO\n";
        std::cout << "7. PACIENTE\n";
        std::cout << "8. AUDITOR\n";
        std::cin >> nivelAcessoInt;

        if (nivelAcessoInt >= 0 && nivelAcessoInt <= 8) {
            NivelAcesso nivel = static_cast<NivelAcesso>(nivelAcessoInt);
            bool cadastroRealizado = cadastrar_usuario(username, password, nivel);
            if (cadastroRealizado) {
                std::cout << "Cadastro realizado com sucesso!\n";
                usuarioAutenticado = autenticar_usuario(username, password);  // Logar automaticamente após o cadastro
                auditoria.registrarAtividade("Paciente cadastrado!" + username);
            } else {
                std::cout << "Erro ao realizar o cadastro. Tente novamente.\n";
            }
        } else {
            std::cout << "Opção de nível de acesso inválida.\n";
        }
    } else {
        std::cout << "Opção inválida! Saindo do sistema.\n";
        return 1;
    }

    // Etapa 2: Exibir o menu com base no nível de acesso
    int opcaoPrincipal;
    do {
        exibirMenuPrincipal(*usuarioAutenticado);  // Passando o usuário autenticado

        std::cin >> opcaoPrincipal;

        // Verifica o nível de acesso e direciona para o menu correspondente
        switch (opcaoPrincipal) {
            case 1:  // Gerenciamento de Pacientes
                if (usuarioAutenticado->get_nivel_acesso() == NivelAcesso::ADMIN ||
                    usuarioAutenticado->get_nivel_acesso() == NivelAcesso::MEDICO ||
                    usuarioAutenticado->get_nivel_acesso() == NivelAcesso::ENFERMEIRO) {
                    menuPacientes(gerenciamentoPacientes, nomeArquivo);  // Chama o menu de pacientes
                } else {
                    std::cout << "Você não tem permissão para acessar o gerenciamento de pacientes.\n";
                }
                break;

            case 0:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cerr << "Opção inválida! Tente novamente.\n";
        }
    } while (opcaoPrincipal != 0);

    return 0;
}
