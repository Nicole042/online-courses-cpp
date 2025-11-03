# Plataforma de Cursos en Linea (C++)

Este proyecto es una aplicacion desarrollada en **C++** que representa una **plataforma de cursos en linea**, donde los usuarios pueden registrarse, iniciar sesion, inscribirse a cursos, seguir su progreso y recibir notificaciones.  
Fue creado aplicando principios de ingenieria de software, buenas practicas de codigo limpio y control de versiones usando Git y GitHub.

---

##  Descripcion general

El sistema esta dividido en varios modulos que se comunican entre si:

- **Auth**: manejo de usuarios, registro y login.
- **Course**: gestion de cursos, inscripciones y progreso.
- **Notify**: envio de notificaciones o mensajes simulados.
- **Config y Utils**: herramientas de apoyo (logger, validadores, configuraciones).
- **Security**: control de acceso segun el rol del usuario (admin, teacher, student).
- **Tests**: conjunto de pruebas para verificar que cada modulo funcione bien.

Cada modulo esta separado en carpetas para mantener una estructura clara y ordenada, lo que facilita la lectura y el mantenimiento del proyecto.

---

## Tecnologias usadas

- Lenguaje: **C++17**
- Sistema de compilacion: **CMake**
- Control de versiones: **Git y GitHub**
- Integracion continua: **GitHub Actions**
- Analisis de codigo: **CppCheck**
- Entorno: **Visual Studio Code**

---

## Estructura del proyecto

online-courses-cpp/
├─ app/               -> archivo principal main.cpp
├─ src/
│  ├─ auth/           -> autenticacion y gestion de usuarios
│  ├─ course/         -> cursos, inscripciones y estadisticas
│  ├─ notify/         -> notificaciones simuladas
│  ├─ utils/          -> logger y validadores de datos
│  ├─ config/         -> configuracion general
│  └─ security/       -> control de permisos por roles
├─ tests/             -> pruebas unitarias
├─ docs/              -> documentacion y diseno
└─ .github/workflows/ -> configuracion de CI


---

## Instalacion y compilacion

1. Clonar el repositorio  

   git clone https://github.com/TU_USUARIO/online-courses-cpp.git
   cd online-courses-cpp


2. Compilar el proyecto

   cmake -S . -B build
   cmake --build build

3. Ejecutar el programa

   ./build/app

4. Ejecutar los tests

   ctest --test-dir build --output-on-failure
   

---

## Ejemplo de ejecucion

Cuando el programa se ejecuta, realiza un flujo simple:

1. Registra un nuevo usuario.
2. Inicia sesion y obtiene un token.
3. Crea un curso y lo publica.
4. El usuario se inscribe y avanza en el curso.
5. El sistema muestra mensajes y estadisticas.

Salida esperada:


Online Courses C++ inicializada
Usuario: Ana Token: uid=abc123...
Inscripcion confirmada en C++ desde cero
Progreso: 30%


---

## Integracion continua (CI)

Cada vez que se hace un commit o un pull request, se ejecuta un flujo automatico en **GitHub Actions** que:

* Compila el proyecto en Ubuntu.
* Corre las pruebas unitarias con `ctest`.
* Analiza el codigo con **cppcheck** para detectar errores o malas practicas.

Esto asegura que el sistema se mantenga funcional y limpio en cada cambio.

---

## Buenas practicas aplicadas

* Codigo claro, funciones cortas y con una sola responsabilidad.
* Nombres descriptivos en clases y metodos.
* Manejo de errores con excepciones.
* Evitar duplicacion de logica (principio DRY).
* Uso de ramas y commits descriptivos.
* Integracion continua con pruebas automaticas.

---

## Uso de IA en el proyecto

Durante el desarrollo se uso **ChatGPT** y **GitHub Copilot** como apoyo para:

* Generar codigo base para los modulos de **Auth**, **Course** y **Logger**.
* Escribir parte de la documentacion y este archivo README.
* Crear ejemplos de pruebas unitarias y revisar logica de funciones.

La ia ayudo a ahorrar tiempo y a mejorar la estructura general del codigo, aunque todo el contenido fue revisado y ajustado manualmente.

---

## Licencia

Este proyecto fue creado con fines educativos y puede ser modificado libremente.
Autor: **Estudiante de Ingenieria de Software**
Version: **v0.3**


---

 **tip:**  
1. Crea el archivo `README.md` en la raíz de tu proyecto.  
2. Pega todo este contenido.  
3. Guarda y haz commit:  

   git add README.md
   git commit -m "docs: add complete README with project overview"
   git push



