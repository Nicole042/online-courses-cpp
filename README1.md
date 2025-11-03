# Plataforma de Cursos en Linea (C++)

Este proyecto es una aplicacion desarrollada en **C++** que representa una **plataforma de cursos en linea**, donde los usuarios pueden registrarse, iniciar sesion, inscribirse a cursos, seguir su progreso y recibir notificaciones.  
Fue creado aplicando principios de ingenieria de software, buenas practicas de codigo limpio y control de versiones usando Git y GitHub.

---

## Descripcion general

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

