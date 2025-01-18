#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

enum class NivelAcesso {
    ADMIN,
    MEDICO,
    ENFERMEIRO,
    TECNICO_LABORATORIO,
    RECEPCIONISTA,
    FARMACEUTICO,
    ADMINISTRACAO,
    PACIENTE,
    AUDITOR
};

class Usuario {
private:
    std::string nome_usuario;
    std::string senha;
    NivelAcesso nivel_acesso;

public:
    Usuario(std::string nome, std::string senha, NivelAcesso nivel);

    std::string get_nome_usuario() const;
    NivelAcesso get_nivel_acesso() const;

    bool validar_login(const std::string& username, const std::string& password) const;
};

extern std::vector<Usuario> banco_de_usuarios; // Declaração do vetor global

// Declare apenas a assinatura da função aqui
Usuario* autenticar_usuario(std::string username, std::string password);

#endif // USUARIO_H
