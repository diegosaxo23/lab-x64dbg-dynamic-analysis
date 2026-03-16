\# Conclusiones



Este laboratorio muestra que x64dbg es una herramienta muy útil para comprender cómo se comporta un binario de Windows en tiempo de ejecución.



A través de un flujo sencillo pero práctico, ha sido posible observar:

\- cómo el programa recibe la entrada del usuario,

\- qué función la valida,

\- dónde aparece esa entrada en memoria,

\- y cómo el programa decide entre éxito y error.



El laboratorio también muestra que el análisis dinámico funciona mejor cuando está apoyado por una pequeña fase de preanálisis. Buscar strings, revisar símbolos o comprobar información básica del PE facilita llegar a las partes importantes del programa.



En este caso concreto, x64dbg ha sido especialmente útil para:

\- colocar breakpoints,

\- revisar registros y pila,

\- seguir punteros hasta el dump,

\- y localizar la comparación final y el salto condicional.



Como limitación, x64dbg no ofrece la misma visión global que una herramienta de análisis estático, por lo que funciona mejor cuando se combina con utilidades como DIE, PE-bear, Strings o Ghidra.



En resumen, este laboratorio demuestra que x64dbg es una herramienta muy eficaz para un análisis dinámico introductorio, especialmente cuando el objetivo es conectar el comportamiento visible de un programa con su lógica interna.

