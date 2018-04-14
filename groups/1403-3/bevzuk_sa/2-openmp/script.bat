
@echo 
echo Size array 
set /p n=
 
#echo Name of the test file
#set /p name=

cd Debug
START "" /WAIT Generator.exe %n% Test%n%
START "" /WAIT Task.exe Test%n%
START "" /WAIT Checker.exe Test%n%

cd ..
DEL Test%n%.out
