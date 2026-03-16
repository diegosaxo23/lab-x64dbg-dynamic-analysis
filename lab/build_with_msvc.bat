@echo off
setlocal
where cl >nul 2>nul
if errorlevel 1 (
  echo [ERROR] Microsoft C compiler not found.
  echo Open "x64 Native Tools Command Prompt for VS" and run this script again.
  exit /b 1
)
cl /nologo /Od /Zi /GS- /Fe:validation_lab.exe lab_validation.c
if errorlevel 1 (
  echo [ERROR] Build failed.
  exit /b 1
)
echo [OK] Built validation_lab.exe
