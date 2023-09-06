echo off
cls
echo String params:  %*
echo param 1: %1
echo param 2: %2
echo param 3: %3
set /A res = %1 %3 %2
echo %res%
pause