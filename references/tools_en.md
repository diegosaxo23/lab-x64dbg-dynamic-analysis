\# Tools used in the lab



\## Main tool



\### x64dbg

Main tool used in the lab. It was used to load the executable, reach the user code, locate relevant strings, set breakpoints, inspect registers, review the stack, follow pointers in memory, and document the analysis with comments.



In this lab, x64dbg was used to:

\- open `validation\_lab.exe`

\- search for strings such as `Access denied` and `Access granted`

\- reach the binary entry point

\- set a breakpoint in `validate\_code`

\- stop execution after entering a test input

\- inspect registers, stack, and dump

\- observe the final comparison and conditional jump

\- add comments inside the disassembly



\## Other tools used



\### Microsoft Visual Studio Build Tools

Used to compile the training binary on Windows through the `build\_with\_msvc.bat` script.



\## Files used in the lab



\### `lab\_validation.c`

Source code of the training binary. It implements a simple input validation routine to make dynamic analysis easier.



\### `build\_with\_msvc.bat`

Build script used to generate `validation\_lab.exe`.



\### `validation\_lab.exe`

Executable analyzed during the lab.



\## Why these tools?



The chosen combination is simple and sufficient for an introductory dynamic analysis exercise:

\- \*\*x64dbg\*\* makes it possible to observe the real behavior of the binary while it is running.

\- \*\*Build Tools\*\* make it possible to generate the sample quickly and in a controlled way.

\- \*\*Snipping Tool\*\* makes it possible to capture clear evidence to document the work.



\## Note



The goal of this lab was not to use many tools, but to work with a small set of tools that are well integrated into a clear workflow: compilation, binary loading, debugging, observation, and documentation.

