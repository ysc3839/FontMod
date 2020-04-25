@echo off
setlocal enabledelayedexpansion

mkdir build
cd build

cmake -G "Visual Studio 16 2019" -A Win32 ..

for /f "usebackq tokens=*" %%i in (`vswhere -latest -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe`) do (
  "%%i" FontMod.sln /p:Configuration=Release /p:Platform=Win32
  exit /b !errorlevel!
)
