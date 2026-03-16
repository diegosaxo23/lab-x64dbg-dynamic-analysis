# Conclusions

This lab shows that x64dbg is a very useful tool for understanding how a Windows binary behaves at runtime.

Through a simple but practical workflow, it was possible to observe:
- how the program receives user input,
- which function validates it,
- where that input appears in memory,
- and how the program decides between success and error.

The lab also shows that dynamic analysis works better when it is supported by a small pre-analysis stage. Searching for strings, reviewing symbols or checking basic PE information makes it easier to reach the important parts of the program.

In this specific case, x64dbg was most useful for:
- placing breakpoints,
- reviewing registers and stack,
- following pointers to the dump,
- and locating the final comparison and conditional jump.

As a limitation, x64dbg does not provide the same overall view as a static analysis tool, so it works best when combined with other utilities such as DIE, PE-bear, Strings or Ghidra.

In summary, this lab demonstrates that x64dbg is a very effective tool for introductory dynamic analysis, especially when the goal is to connect the visible behavior of a program with its internal logic.
