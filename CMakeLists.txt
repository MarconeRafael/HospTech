# Definir a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Definir o nome do projeto
project(HospTech)

# Definir o padrão C++ a ser usado (C++17, por exemplo)
set(CMAKE_CXX_STANDARD 17)

# Incluir o diretório de cabeçalhos
include_directories(include)

# Adicionar os arquivos de código-fonte
set(SOURCES
    src/pacientes.cpp
    #src/menupacientes.cpp        # Adicionado o arquivo de menu de pacientes
    #src/exibirMenuPrincipal.cpp  # Adicionado o arquivo de menu principal
    # src/financeiro.cpp        # Comentado conforme solicitado
    # src/inventario.cpp        # Comentado conforme solicitado
    # src/agendamentos.cpp      # Comentado conforme solicitado
    # src/leitos.cpp            # Comentado conforme solicitado
    # src/prescricao.cpp       # Comentado conforme solicitado
    # src/usuario.cpp          # Comentado conforme solicitado
    # src/relatorios.cpp       # Comentado conforme solicitado
    # src/notificacoes.cpp     # Comentado conforme solicitado
    src/main.cpp
)

# Definir o diretório de saída para os binários
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Criar o executável final a partir dos arquivos fonte
add_executable(hosptech ${SOURCES})

# Se estiver usando C++17 ou superior, pode adicionar a flag de compilação
target_compile_options(hosptech PRIVATE -Wall -Wextra)

# Se for necessário linkar bibliotecas externas (por exemplo, SQLite)
# find_package(SQLite3 REQUIRED)
# target_link_libraries(hosptech PRIVATE SQLite3::SQLite3)
