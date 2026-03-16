# x64dbg Dynamic Analysis Lab  
## Laboratorio de análisis dinámico con x64dbg

<p align="center">
  <strong>EN:</strong> A hands-on Windows dynamic analysis lab using <code>x64dbg</code> on a small training binary.<br>
  <strong>ES:</strong> Un laboratorio práctico de análisis dinámico en Windows con <code>x64dbg</code> sobre un pequeño binario de entrenamiento.
</p>

<p align="center">
  <img alt="Platform" src="https://img.shields.io/badge/platform-Windows-1f6feb">
  <img alt="Focus" src="https://img.shields.io/badge/focus-Dynamic%20Analysis-8a2be2">
  <img alt="Debugger" src="https://img.shields.io/badge/debugger-x64dbg-e5534b">
  <img alt="Languages" src="https://img.shields.io/badge/docs-English%20%7C%20Espa%C3%B1ol-2ea44f">
  <img alt="Level" src="https://img.shields.io/badge/level-Beginner%20Friendly-ffb000">
</p>

---

## Table of contents / Índice

- [Overview / Resumen](#overview)
- [Why this project? / ¿Por qué este proyecto?](#why-this-project)
- [Language guide / Guía de idiomas](#language-guide)
- [Repository structure / Estructura del repositorio](#repository-structure)
- [Guía de archivos `.md`](#md-guide)
- [Contact / Contacto](#contact)

---

<a id="overview"></a>

## Overview / Resumen

### EN
This repository contains a dynamic analysis lab focused on **Windows debugging with x64dbg**.  
It uses a small training binary designed to make the internal validation flow easy to observe and document.

The lab is meant to help you analyze:

- how a program receives user input,
- which function validates that input,
- where the input appears in memory,
- and which comparison / jump block decides between success and failure.

It is intentionally simple and reproducible.

### ES
Este repositorio contiene un laboratorio de análisis dinámico y centrado en la **depuración en Windows con x64dbg**.  
Utiliza un pequeño binario de entrenamiento pensado para que el flujo interno de validación sea fácil de observar y documentar.

El laboratorio sirve para analizar:

- cómo un programa recibe la entrada del usuario,
- qué función valida esa entrada,
- dónde aparece la entrada en memoria,
- y qué bloque de comparación / salto decide entre éxito y error.

Está planteado para ser simple y reproducible.

---

<a id="why-this-project"></a>

## Why this project? / ¿Por qué este proyecto?

### EN
This repository provides a **clean, small, controlled lab** where the analyst can focus on the fundamentals of dynamic analysis.

It is useful for:

- learning the x64dbg interface,
- practicing breakpoints and execution tracing,
- observing memory and registers during validation logic,
- and documenting an analysis workflow in a clean way.

### ES
Este repositorio ofrece un **laboratorio limpio, pequeño y controlado** donde el analista puede centrarse en los fundamentos del análisis dinámico.

Es útil para:

- aprender la interfaz de x64dbg,
- practicar breakpoints y seguimiento de ejecución,
- observar memoria y registros durante una lógica de validación,
- y documentar un flujo de análisis de forma ordenada.

---

<a id="language-guide"></a>

## Language guide / Guía de idiomas

### EN
This repository is intentionally organized in **two languages**:

- files ending in **`_en.md`** are written in **English**,
- files ending in **`_es.md`** are written in **Spanish**,
- image names and technical asset names are kept mostly in **English** for consistency.

That means the repository mixes:

- **English file names** for structure and organization,
- **English and Spanish documentation** depending on the selected version,
- and technical assets with neutral naming.

### ES
Este repositorio está organizado intencionadamente en **dos idiomas**:

- los archivos terminados en **`_en.md`** están escritos en **inglés**,
- los archivos terminados en **`_es.md`** están escritos en **español**,
- los nombres de imágenes y recursos técnicos se mantienen en su mayoría en **inglés** para dar coherencia a la estructura.

Eso significa que el repositorio combina:

- **nombres de archivo en inglés** para mantener una estructura limpia,
- **documentación en inglés y español** según la versión elegida,
- y recursos técnicos con nombres neutrales.

---

<a id="repository-structure"></a>

## Repository structure / Estructura del repositorio

```text
lab-x64dbg-dynamic-analysis/
├── docs/
│   ├── 01-lab-guide_en.md
│   ├── 01-lab-guide_es.md
│   ├── 02-methodology_en.md
│   ├── 02-methodology_es.md
│   ├── 03-conclusions_en.md
│   └── 03-conclusions_es.md
├── images/
│   ├── 01-build-process.png
│   ├── 02-binary-loaded.png
│   ├── 03-strings.png
│   ├── 04-entry-point.png
│   ├── 05-validation-breakpoint.png
│   ├── 06-registers.png
│   ├── 07-stack.png
│   ├── 08-buffer-dump.png
│   ├── 09-compare-and-jump.png
│   └── 10-comments-added.png
├── lab/
│   ├── lab_validation.c
│   ├── build_with_msvc.bat
│   └── HOW_TO_COMPILE.txt
├── references/
│   ├── tools_en.md
│   └── tools_es.md
└── README.md
```

---

<a id="md-guide"></a>

## Guía de archivos `.md`

### EN
This repository includes several Markdown files organized by purpose and language.

#### Root
- `README.md`  
  Main entry point of the repository. It explains the purpose of the lab, the structure of the project, the language organization, and how to use the material.

#### Documentation (`docs/`)
- `docs/01-lab-guide_en.md`  
  Step-by-step lab guide in English. It walks through the dynamic analysis workflow with x64dbg.

- `docs/01-lab-guide_es.md`  
  Guía paso a paso del laboratorio en español. Explica el flujo de análisis dinámico con x64dbg.

- `docs/02-methodology_en.md`  
  Methodology used in the exercise in English. Describes the analysis approach and reasoning behind the workflow.

- `docs/02-methodology_es.md`  
  Metodología utilizada en la práctica en español. Describe el enfoque de análisis y la lógica seguida durante el laboratorio.

- `docs/03-conclusions_en.md`  
  Final conclusions in English. Summarizes what was learned and the main takeaways from the exercise.

- `docs/03-conclusions_es.md`  
  Conclusiones finales en español. Resume lo aprendido y las ideas principales extraídas del laboratorio.

#### References (`references/`)
- `references/tools_en.md`  
  Reference list of the tools used during the lab in English.

- `references/tools_es.md`  
  Lista de referencia de las herramientas utilizadas durante la práctica en español.

---

### ES
Este repositorio incluye varios archivos Markdown organizados por función e idioma.

#### Raíz
- `README.md`  
  Punto de entrada principal del repositorio. Explica el propósito del laboratorio, la estructura del proyecto, la organización por idiomas y cómo utilizar el material.

#### Documentación (`docs/`)
- `docs/01-lab-guide_en.md`  
  Guía paso a paso del laboratorio en inglés. Describe el flujo de análisis dinámico con x64dbg.

- `docs/01-lab-guide_es.md`  
  Guía paso a paso del laboratorio en español. Describe el flujo de análisis dinámico con x64dbg.

- `docs/02-methodology_en.md`  
  Metodología de la práctica en inglés. Explica el enfoque del análisis y el razonamiento seguido.

- `docs/02-methodology_es.md`  
  Metodología de la práctica en español. Explica el enfoque del análisis y el razonamiento seguido.

- `docs/03-conclusions_en.md`  
  Conclusiones finales en inglés. Resume los aprendizajes y las ideas principales del ejercicio.

- `docs/03-conclusions_es.md`  
  Conclusiones finales en español. Resume los aprendizajes y las ideas principales del ejercicio.

#### Referencias (`references/`)
- `references/tools_en.md`  
  Lista de referencia de las herramientas utilizadas durante la práctica en inglés.

- `references/tools_es.md`  
  Lista de referencia de las herramientas utilizadas durante la práctica en español.

---

<a id="contact"></a>

## Contact / Contacto

**Diego Rodríguez Fuertes**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Diego%20Rodr%C3%ADguez%20Fuertes-0A66C2?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/diego-rodriguez-fuertes/)
[![Email](https://img.shields.io/badge/Email-diegosaxo23%40gmail.com-D14836?logo=gmail&logoColor=white)](mailto:diegosaxo23@gmail.com)
