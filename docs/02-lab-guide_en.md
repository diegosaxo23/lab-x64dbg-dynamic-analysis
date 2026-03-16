# Dynamic analysis lab with x64dbg

## Introduction to the tool

**x64dbg** is a debugger for Windows widely used in dynamic analysis and reverse engineering. Its main strength is that it allows the analyst to observe the real behavior of a program while it is running. This makes it possible to stop execution at specific points, inspect registers, review the stack, follow pointers in memory and understand how the program makes decisions internally.

**x64dbg** is especially useful for verifying:
- how the program receives user input,
- which function processes that input,
- where the data appears in memory,
- and which block of code decides between a success path and an error path.

---

## Objective

In this lab, a practice binary for Windows is analyzed with **x64dbg** in order to observe how it receives an input, how it validates that input and how it decides whether to show a success or an error message.

The binary used is `validation_lab.exe`, compiled from `lab_validation.c`.

---

## Environment and tools

- Windows in a virtual machine
- x64dbg
- Practice binary `validation_lab.exe`
- Screenshots stored in the `images/` folder

---

## Pre-analysis before opening x64dbg

Before starting dynamic analysis, it is useful to perform a small pre-analysis of the binary. This helps to reach the debugging phase with a clearer idea of what to look for.

In this lab, before opening x64dbg, it is useful to:
- verify that the binary compiles and runs correctly,
- identify whether it is a console executable,
- check whether the binary preserves symbols,
- search for visible strings related to its behavior,
- and review imports or basic PE information.

This pre-analysis helps to:
- locate the validation logic faster,
- choose breakpoints more effectively,
- and avoid starting the analysis completely blind.

---

## Useful tools for pre-analysis

### Detect It Easy (DIE)
It is useful for quickly identifying:
- the architecture of the executable,
- the compiler used,
- possible packing,
- and general characteristics of the binary.

### PE-bear
It is useful for reviewing the PE structure of the executable, including:
- imports,
- sections,
- headers,
- and basic metadata.

### Strings
A string extraction tool helps to locate visible texts in the executable, for example:
- `Access denied`
- `Access granted`
- `Enter access code:`

These strings are very useful for identifying success paths, error paths and user interaction points before starting the debugger.

### Ghidra
Although it is not the main tool in this lab, it can also be useful before debugging because it allows:
- viewing the overall structure of the program,
- locating functions,
- checking cross-references,
- and understanding the code in a more global way.

For a simple lab like this one it is not essential, but it complements x64dbg very well.

---

## How symbols are searched in x64dbg

If the binary preserves symbols, x64dbg can display function names in the **Symbols** tab.

The process used in this lab is the following:
1. Open the binary in x64dbg.
2. Go to the `Symbols` tab.
3. Locate the main module of the executable.
4. Search for the function name using the filter, for example `validate` or `validate_code`.
5. Double-click on the function to open it in the disassembly view.

### Note about symbols
Some binaries do not preserve function names. In those cases, the analysis must rely more on:
- strings,
- imports,
- cross-references,
- and static tools such as Ghidra.

---

## Step-by-step lab guide

## 1. Build the binary

First, the lab program must be compiled with the script `build_with_msvc.bat` in order to generate `validation_lab.exe`.

![Build process](../images/01-build-process.png)

*Figure 1. Generation of the practice executable before opening it in x64dbg.*

---

## 2. Load the binary into x64dbg

Next, `validation_lab.exe` is opened in x64dbg to begin the dynamic analysis.

![Binary loaded in x64dbg](../images/02-binary-loaded.png)

*Figure 2. Initial loading of the executable in x64dbg.*

---

## 3. Search for useful strings

Once the binary is loaded, relevant strings such as `Access denied`, `Access granted` and `Enter access code:` are searched. This makes it easier to identify the success and error paths.

**How it is done:**
1. Open the binary in x64dbg.
2. Click on the code panel.
3. Right click → `Search for` → `All referenced strings`.
4. Select the strings related to validation.

![Referenced strings](../images/03-strings.png)

*Figure 3. Useful strings used to guide the analysis of the validation flow.*

---

## 4. Go to the entry point

Then the analysis moves to the user code of the binary in order to locate the starting point of the executable.

**How it is done:**
1. With the binary open, press `Alt + F9`.
2. x64dbg runs until the user code of the program.
3. Capture the disassembly of the entry point.

![Entry point](../images/04-entry-point.png)

*Figure 4. Initial code of the executable in x64dbg.*

---

## 5. Locate the validation function and place a breakpoint

Next, the **Symbols** tab is used to locate the function `validate_code`, and a breakpoint is placed at its beginning so that execution stops when the input is about to be validated.

**How it is done:**
1. Open the `Symbols` tab.
2. Search for `validate_code`.
3. Double-click on the function.
4. Press `F2` to add the breakpoint.

![Breakpoint in validate_code](../images/05-validation-breakpoint.png)

*Figure 5. Breakpoint placed at the beginning of `validate_code`.*

---

## 6. Run the program and inspect registers

Then the binary is executed, a test input is entered and x64dbg is allowed to stop at the breakpoint. At that moment the registers are reviewed to see which data is being used in the validation process.

**Input used in the test:** `probando`

**How it is done:**
1. With the breakpoint active, press `F9`.
2. In the console, type `probando` or any other test string and press `Enter`.
3. x64dbg stops in `validate_code`.
4. Review the register panel.

![Registers in validate_code](../images/06-registers.png)

*Figure 6. Register view when execution stops inside the validation function.*

---

## 7. Inspect the stack

At the same stopping point, the stack is reviewed in order to observe the call context and return addresses.

**How it is done:**
1. Keep the program stopped in `validate_code`.
2. Locate the stack window in the lower right area.
3. Capture the code view together with the stack.

![Stack view](../images/07-stack.png)

*Figure 7. Stack inspection during the execution of `validate_code`.*

---

## 8. Follow the user buffer in memory

Next, the pointer that references the user input is followed and opened in the dump window in order to view the string directly in memory.

**How it is done:**
1. Observe that `RCX` points to the entered string.
2. Right click on `RCX`.
3. Choose `Follow in Dump`.
4. Locate the string in the dump window.

![User buffer in memory](../images/08-buffer-dump.png)

*Figure 8. Memory dump where the user input can be observed inside the process.*

---

## 9. Locate the comparison and conditional jump

After that, execution returns from `validate_code` to `main`, and the block where the program checks the returned value and decides whether to take the success path or the error path is captured.

**How it is done:**
1. While inside `validate_code`, press `Ctrl + F9` to return to the caller.
2. Advance with `F8` until the result check appears.
3. Capture the block containing the comparison and the conditional jump.

![Comparison and conditional jump](../images/09-compare-and-jump.png)

*Figure 9. Decision block that directs execution to the success path or the error path.*

---

## 10. Add comments to document the analysis

Finally, comments can be added inside x64dbg on the decision block. This makes the analysis easier to understand and easier to resume later.

**How it is done:**
1. Return to the comparison and jump block.
2. Right click on the instruction.
3. Add a comment explaining what that block does.
4. Capture the annotated view.

![Comments added in x64dbg](../images/10-comments-added.png)

*Figure 10. Comments added in x64dbg to document the decision block.*

---

## What was observed in the lab

With this workflow, it was possible to verify that:
- the program receives a string from the console,
- the function `validate_code` processes that input,
- the user string appears in memory,
- and the result of the validation is later used in a block with a comparison and a conditional jump.

---

## The most useful aspects of x64dbg in this case

In this lab, x64dbg was especially useful for:
- placing breakpoints on specific functions,
- viewing registers and stack in real time,
- following pointers into memory,
- and locating the exact point where the program decides between success and error.

---

## Limitations

Although x64dbg is very useful, this lab also shows that:
- it does not provide as comfortable a global view as a static tool,
- it forces the analyst to advance step by step if the flow is not clear,
- and it works better when there is already an initial hypothesis obtained during pre-analysis.

---

## Quick summary of the process followed

1. Build the binary.
2. Open it in x64dbg.
3. Search for relevant strings.
4. Go to the entry point.
5. Search symbols and locate `validate_code`.
6. Place a breakpoint in the function.
7. Run the program with a test input.
8. Review registers, stack and dump.
9. Locate the comparison and conditional jump block.
10. Add comments to document the analysis.
