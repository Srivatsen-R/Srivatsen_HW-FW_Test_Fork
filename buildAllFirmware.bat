:: Deletes All files in the Build and Rebuilds 
::(Hidden, System, and Read-Only Files are Not Affected) 
::
@ECHO OFF 
@REM rd /s /q Build
@REM mkdir Build
cd .\Build\
cmake -G "MinGW Makefiles" --toolchain ../arm-none-eabi-gcc.cmake -DCMAKE_BUILD_TYPE=Debug -DNDEBUG=1 .. 
cmake --build . --
cd ..