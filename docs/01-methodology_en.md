# Methodology

## General approach

The methodology used in this lab is based on a simple idea: perform a short pre-analysis first, and then use x64dbg to confirm how the binary behaves at runtime.

The workflow followed is:
1. Build and run the binary.
2. Perform a basic pre-analysis with strings, symbols or PE information.
3. Open the executable in x64dbg.
4. Locate a useful function.
5. Place a breakpoint.
6. Run the program with a test input.
7. Inspect registers, stack and memory.
8. Return to the caller and identify the decision block.
9. Document the result with screenshots and comments.


## What x64dbg contributes

x64dbg contributes the dynamic part of the analysis. It allows the analyst to:
- stop execution at a specific function,
- inspect real register values,
- see the call context in the stack,
- follow the input in memory,
- and identify the instruction block that decides between success and error.

## Role of pre-analysis tools

Before x64dbg, tools such as DIE, PE-bear, Strings or Ghidra can provide useful context:
- DIE for quick binary identification,
- PE-bear for PE structure and imports,
- Strings for visible texts,
- and Ghidra for a broader code view.

