# Metodología

## Enfoque general

La metodología utilizada en este laboratorio se basa en una idea sencilla: realizar primero un pequeño preanálisis y, después, utilizar x64dbg para confirmar cómo se comporta el binario en tiempo de ejecución.

El flujo seguido es:
1. Compilar y ejecutar el binario.
2. Realizar un preanálisis básico con strings, símbolos o información PE.
3. Abrir el ejecutable en x64dbg.
4. Localizar una función útil.
5. Colocar un breakpoint.
6. Ejecutar el programa con una entrada de prueba.
7. Inspeccionar registros, pila y memoria.
8. Volver al llamador e identificar el bloque de decisión.
9. Documentar el resultado con capturas y comentarios.

## Por qué esta metodología es útil

Este enfoque es útil porque evita comenzar la depuración sin contexto. Incluso un preanálisis pequeño proporciona una hipótesis inicial y facilita decidir dónde detener la ejecución.

En este laboratorio, esa hipótesis era sencilla: la entrada sería procesada en una función llamada `validate_code`, y el valor devuelto se comprobaría después en un bloque de comparación.

## Qué aporta x64dbg

Dentro de esta metodología, x64dbg aporta la parte dinámica del análisis. Permite al analista:
- detener la ejecución en una función concreta,
- inspeccionar valores reales de los registros,
- ver el contexto de llamada en la pila,
- seguir la entrada en memoria,
- e identificar el bloque de instrucciones que decide entre éxito y error.

## Papel de las herramientas de preanálisis

Antes de x64dbg, herramientas como DIE, PE-bear, Strings o Ghidra pueden aportar contexto útil:
- DIE para identificar rápidamente el binario,
- PE-bear para la estructura PE y los imports,
- Strings para los textos visibles,
- y Ghidra para una visión más amplia del código.

## Idea final

La metodología utilizada aquí es sencilla, pero eficaz para un binario de práctica. Combina una pequeña cantidad de preanálisis con una depuración enfocada, lo que hace que el laboratorio sea más fácil de entender y más fácil de reproducir.