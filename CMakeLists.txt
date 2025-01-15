cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(hosptech)

# Define a versão do C++ a ser utilizada
set(CMAKE_CXX_STANDARD 11)

# Adiciona o diretório include ao caminho de busca do compilador
include_directories(include)
include_directories(data)

# Adiciona os arquivos de origem do projeto
add_executable(hosptech
    src/main.cpp

)


