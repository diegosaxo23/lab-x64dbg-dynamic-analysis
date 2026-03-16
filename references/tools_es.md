# Herramientas utilizadas en el laboratorio

## Herramienta principal

### x64dbg
Herramienta principal del laboratorio. Se ha utilizado para cargar el ejecutable, alcanzar el código de usuario, localizar cadenas relevantes, colocar breakpoints, observar registros, revisar la pila, seguir punteros a memoria y documentar el análisis con comentarios.

En este laboratorio, x64dbg se ha usado para:
- abrir `validation_lab.exe`
- buscar strings como `Access denied` y `Access granted`
- llegar al entry point del binario
- poner un breakpoint en `validate_code`
- detener la ejecución tras introducir una entrada de prueba
- revisar registros, stack y dump
- observar la comparación final y el salto condicional
- añadir comentarios dentro del desensamblado

## Herramientas utilizadas adicionales

### Microsoft Visual Studio Build Tools
Se han utilizado para compilar el binario de laboratorio en Windows mediante el script `build_with_msvc.bat`.


## Archivos utilizados en el laboratorio

### `lab_validation.c`
Código fuente del binario de práctica. Implementa una validación simple de entrada para facilitar el análisis dinámico.

### `build_with_msvc.bat`
Script de compilación usado para generar `validation_lab.exe`.

### `validation_lab.exe`
Ejecutable analizado durante el laboratorio.

## ¿Por qué usar esta herramienta?

La combinación elegida es sencilla y suficiente para una práctica introductoria de análisis dinámico:
- **x64dbg** permite observar el comportamiento real del binario en ejecución.
- **Build Tools** permiten generar la muestra de forma rápida y controlada.
- **Snipping Tool** permite recoger evidencias claras para documentar el trabajo.

## Nota

En este laboratorio no se ha buscado utilizar muchas herramientas, sino trabajar con pocas, pero bien integradas en un flujo claro: compilación, carga del binario, depuración, observación y documentación.
