# Plataforma de Cursos en Línea (C++)

Dos módulos funcionales: **auth** y **course**.  
Build con CMake, pruebas con ctest, CI con GitHub Actions.

## Instalar y ejecutar
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/app
