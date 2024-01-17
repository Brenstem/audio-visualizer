@echo off

set project_dir=%~dp0
set build_dir=%project_dir%build

if not exist "%build_dir%" mkdir "%build_dir%"

cd "%build_dir%"

cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Release "%project_dir%"
cmake --build . --config Release

cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug "%project_dir%"
cmake --build . --config Debug

pause