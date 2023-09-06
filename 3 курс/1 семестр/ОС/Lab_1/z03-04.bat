echo off
cls
echo String params:  %*
echo param 1: %1
echo param 2: %2
echo param 3: %3
set /A a = %1
set /A b = %2
set /A c = %3
set /A sum = a + b
set /A multi = a * b
set /A div = c / a
set /A minus1 = b - a
set /A minus2 = a - b
set /A multi2 = minus1 * minus2
echo %a% + %b% = %sum%
echo %a% * %b% = %multi%
echo %c% / %a% = %div%
echo (%b% - %a%) * (%a% - %b%) = %multi2%
pause