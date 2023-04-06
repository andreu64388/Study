function oms_matr_text(){
	this.text = new Array();
	this.text['ru'] = new Array();
	this.text['en'] = new Array();
	this.text['ua'] = new Array();
	this.text['es'] = new Array();
	this.t=get_text;

	function get_text(i){return this.text[languag][i];}

	
	this.text['ru'][1]='<p style="color:red">Проверьте, правильно ли вы ввели выражение, а также все ли поля заполнены. В поля ввода можно вводить числа или дроби. Более подробно читайте в правилах ввода чисел.</p>';
	this.text['ua'][1]='<p style="color:red">Перевірте чи правильно ви ввели вираз, а також чи всі поля заповнені. В поля вводу можна вводити тільки числа та дроби. Більш детально читайте в правилах вводу чисел.</p>';
	this.text['en'][1]='<p style="color:red">Check up the input data and fill all fields. You can input only integer numbers or fractions in this online calculator.</p>';
	this.text['es'][1]='<p style="color:red">Verifique si todos los parámetros están correctamente introducidos y también si todos los campos están rellenados. En los campos Usted tiene posibilidad de introducir números y fracciones. Se puede leer la información más detallada en las reglas de introducción de números.</p>';

	this.text['ru'][2]='Такие матрицы нельзя перемножить, так как количество столбцов матрицы <b>А</b> не равно количеству строк матрицы <b>В</b>.';
	this.text['en'][2]='Such matrices can not multiply as the number of columns of the matrix <b>A</b> is not equal to the number of rows in matrix <b>B</ b>.';
	this.text['ua'][2]='Такі матриці неможливо помножити, так як кількість стовпчиків матриці <b>А</b> не дорівнює кількості рядків матриці <b>В</b>.';
	this.text['es'][2]='Es imposible multiplicar entre si tales matrices, así que el número de columnas de la matriz <b>A</b> no equivale al número de filas de la matriz <b>B</b>.';

	this.text['ru'][3]='<p>Компоненты матрицы С вычисляются следующим образом:</p>';
	this.text['en'][3]='<p>The components of the matrix <b>C</b> is calculated as:</p>';
	this.text['ua'][3]='<p>Компоненти матриці С обраховуються наступним чином:</p>';
	this.text['es'][3]='<p>Los componentes de la matriz <b>C</b> se calculan del modo siguiente:</p>';

	this.text['ru'][4]='В качестве степени матрицы можно вводить целые неотрицательные числа большие единицы!';
	this.text['en'][4]='As the power of the matrix you can enter non-negative integers greater than one!';
	this.text['ua'][4]='В якості степеня матриці можна вводити цілі невід&#39;ємні числа більші за одиницю!';
	this.text['es'][4]='В качестве степени матрицы можно вводить целые неотрицательные числа большие единицы!';

	
	this.text['ru'][5]='Такую матрицу нельзя возвести в степень, так как количество столбцов и количество строк матрицы А не равны.';
	this.text['en'][5]='The matrix must be square in order to raise it to a power.';
	this.text['ua'][5]='Таку матрицю неможливо піднести до степеня, так як кількість рядків не дорівнює кількості стовпчиків матриці А.';
	this.text['es'][5]='Такую матрицу нельзя возвести в степень, так как количество столбцов и количество строк матрицы А не равны.';

	this.text['ru'][6]='Посмотреть детальный ход вычисления компонент этой матрицы:';
	this.text['en'][6]='See a detailed calculation of this matrix:';
	this.text['ua'][6]='Дивитися детальний хід обрахунку компонентів цієї матриці:';
	this.text['es'][6]='Посмотреть детальный ход вычисления компонент этой матрицы:';

	this.text['ru'][7]='<p>Чтобы найти транспонированную матрицу поменяем рядки и столбики матрицы A местами:</p>';
	this.text['en'][7]='<p>To calculate the transposed matrix to interchange the rows and columns of the matrix A:</p>';
	this.text['ua'][7]='<p>Щоб знайти транспоновану матрицю поміняємо рядки і стовпці матриці A місцями:</p>';
	this.text['es'][7]='<p>Чтобы найти транспонированную матрицу поменяем рядки и столбчики матрицы A местами:</p>';

	
	this.text['ru'][8]="<p>Для вычисления ранга приведем матрицу к <a href='//"+oms_s_name+"/math/library/matrix/type/#h9'>ступенчатому виду</a>, используя <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>элементарные преобразования над строками и столбцами матрицы</a>.</p>";
	this.text['en'][8]="<p>To calculate matrix rank transform matrix to <a href='//"+oms_s_name+"/math/library/matrix/type/#h7'>upper triangular form</a>, using <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>elementary row operations</a>.</p>";
	this.text['ua'][8]="<p>Для обрахунку рангу приведемо матрицю до <a href='//"+oms_s_name+"/math/library/matrix/type/#h9'>ступенчатого вигляду</a>, для цього використаємо <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>елементарні перетворення над рядками і стовпчиками матриці</a>.</p>";
	this.text['es'][8]="<p>Для вычисления ранга приведем матрицу к <a href='//"+oms_s_name+"/math/library/matrix/type/#h9'>ступенчатому виду</a>, используя <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>элементарные преобразования над строками и столбцами матрицы</a>.</p>";
	
	this.text['ru'][9]='<p>поменяем {i}-ую строку и {j}-ую строку местами<p>';
	this.text['en'][9]='<p>R<sub>{i}</sub> ↔ R<sub>{j}</sub> (interchange the {i} and {j} rows)<p>';
	this.text['ua'][9]='<p>поміняємо {i}-ий рядок і {j}-ий рядок місцями<p>';
	this.text['es'][9]='<p>R<sub>{i}</sub> ↔ R<sub>{j}</sub> (intercambiamos las filas {i} y {j})<p>';
	
	this.text['ru'][10]='<p>{i}-ую строку делим на {n}</p>';
	this.text['en'][10]='<p>R<sub>{i}</sub> / {n} → R<sub>{i}</sub> (divide the {i} row by {n})</p>';
	this.text['ua'][10]='<p>{i}-ий рядок ділимо на {n}</p>';
	this.text['es'][10]='<p>R<sub>{i}</sub> / {n} → R<sub>{i}</sub> (dividamos la fila {k} por {n})</p>';

	this.text['ru'][11]='от {n} строки отнимаем {k} строку, умноженную на {m}';
	this.text['en'][11]='R<sub>{n}</sub> - {m} R<sub>{k}</sub> → R<sub>{n}</sub> (multiply {k} row by {m} and subtract it from {n} row)';
	this.text['ua'][11]='від {n}-ого рядка віднімаємо {k}-ий рядок, помножений на {m}';
	this.text['es'][11]='R<sub>{n}</sub> - {m} R<sub>{k}</sub> → R<sub>{n}</sub> (multiplicamos la fila {k} por {m} y restamos a la fila {n})';

	this.text['ru'][12]='к {n} строке добавляем {k} строку, умноженную на {m}';
	this.text['en'][12]='R<sub>{n}</sub> + {m} R<sub>{k}</sub> → R<sub>{n}</sub> (multiply {k} row by {m} and add it to {n} row)';
	this.text['ua'][12]='до {n}-ого рядка додамо {k}-ий рядок, помножений на {m}';
	this.text['es'][12]='R<sub>{n}</sub> + {m} R<sub>{k}</sub> → R<sub>{n}</sub> (multiplicamos la fila {k} por {m} y sumar a la fila {n})';

	this.text['ru'][13]="<p><b>Ответ</b>. Так как <a href='//"+oms_s_name+"/math/library/matrix/definition/#h3'>ненулевых строк</a> {k}, то Rank(<b>A</b>)&nbsp;=&nbsp;{k}.</p>";
	this.text['en'][13]="<p><b>Answer</b>. Since there is {k} <a href='//"+oms_s_name+"/math/library/matrix/definition/#h3'>non-zero rows</a>, then Rank(<b>A</b>)&nbsp;=&nbsp;{k}.</p>";
	this.text['ua'][13]="<p><b>Відповідь</b>. Так як <a href='//"+oms_s_name+"/math/library/matrix/definition/#h3'>ненулевих рядків</a> {k}, то Rank(<b>A</b>)&nbsp;=&nbsp;{k}.</p>";
	this.text['es'][13]="<b>Resultado</b>. Así que hay {k} <a href='//"+oms_s_name+"/math/library/matrix/definition/#h3'>filas no nulas</a>, entonces Rank(<b>A</b>)&nbsp;=&nbsp;{k}.</p>";

	this.text['ru'][14]='<p>Для вычисления обратной матрицы запишем матрицу <b>А</b>, дописав к ней справа единичную матрицу:</p>';
	this.text['en'][14]='<p>Adjoin the <a href='+"'"+'//'+oms_s_name+'/math/library/matrix/type/'+"'"+'>identity matrix</a> onto the right of the original matrix, so that you have <b>A</b> on the left side and the identity matrix on the right side. It will look like this:</p>';
	this.text['ua'][14]='<p>Для обрахунку оберненої матриці запишемо матрицю <b>А</b>, дописавши до неї справа одиничну матрицю:</p>';
	this.text['es'][14]='<p>Для вычисления обратной матрицы запишем матрицу <b>А</b>, дописав к ней справа единичную матрицу:</p>';

	this.text['ru'][15]='<p><b>Ответ:</b></p>';
	this.text['en'][15]='<p><b>Answer:</b></p>';
	this.text['ua'][15]='<p><b>Відповідь:</b></p>';
	this.text['es'][15]='<p><b>Resultado:</b></p>';

	this.text['ru'][16]="<p>Теперь чтобы найти обратную матрицу, используя <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>элементарные преобразования над строками матрицы</a>,  преобразуем левую часть полученной матрицы в единичную.</p>";
	this.text['en'][16]="<p>Now find the inverse matrix. Using <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>elementary row operations</a> to transform the left side of the resulting matrix to the identity matrix.</p>";
	this.text['ua'][16]="<p>Зараз щоб знайти обернену матрицю, використаємо <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>елементарні перетворення над рядками матриці</a>,  перетворимо ліву частину отриманої матриці в одиничну.</p>";
	this.text['es'][16]="<p>Теперь чтобы найти обратную матрицу, используя <a href='//"+oms_s_name+"/math/library/matrix/elementary_matrix/#h1'>элементарные преобразования над строками матрицы</a>,  преобразуем левую часть полученной матрицы в единичную.</p>";

	this.text['ru'][17]='Обратную матрицу невозможно найти, так как количество строк не равно количеству столбцов';
	this.text['en'][17]='Since the number of rows is not equal to the number of columns then the inverse matrix does not exist';
	this.text['ua'][17]='Обернену матрицю неможливо знайти, так як кількість рядків не дорівнює кількості стовбців';
	this.text['es'][17]='Es imposible calcular una matriz invertible, así que el número de filas no equivale al número de columnas. (La matriz no es cuadrada)';
	
	this.text['ru'][18]='Обратную матрицу невозможно найти, так как детерминант матрицы равен нулю';
	this.text['en'][18]='Since the determinant of a matrix <b>A</b> is zero, then the inverse matrix does not exist';
	this.text['ua'][18]='Обернену матрицю неможливо знайти, так як детермінант матриці дорівнює нулю';
	this.text['es'][18]='El determinante de la matriz es cero, la matriz es no invertible';

	this.text['ru'][19]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h5'+"'"+'>Воспользуемся формулой для вычисления определителя матрицы 2×2:</a><br><br>';
	this.text['en'][19]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h5'+"'"+'>Use the formula to calculate the determinant of matrix with size 2×2:</a><br><br>';
	this.text['ua'][19]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h5'+"'"+'>Скористаємося формулою для обрахунку визначника матриці 2×2:</a><br><br>';
	this.text['es'][19]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h5'+"'"+'>Воспользуемся формулой для вычисления определителя матрицы 2×2:</a><br><br>';

	this.text['ru'][20]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h8'+"'"+'>Воспользуемся формулой для вычисления определителя матрицы 3×3:</a><br><br>';
	this.text['en'][20]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h8'+"'"+'>Use the triangle'+"'"+'s rule to calculate the determinant of matrix with size 3×3:</a><br><br>';
	this.text['ua'][20]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h8'+"'"+'>Скористаємося формулою для обрахунку визначника матриці 3×3:</a><br><br>';
	this.text['es'][20]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h8'+"'"+'>Воспользуемся формулой для вычисления определителя матрицы 3×3:</a><br><br>';

	this.text['ru'][21]="<p>Для вычисления определителя приведем матрицу к <a href='//"+oms_s_name+ "/math/library/matrix/type/#h7'>верхнетреугольному виду</a>, используя <a href='//"+oms_s_name+ "/math/library/matrix/elementary_matrix/#h1'>элементарные преобразования над строками матрицы</a> и <a href='//"+oms_s_name+ "/math/library/matrix/determinant/#h2'>свойства определителя матрицы</a>.</p>";
	this.text['en'][21]="<p>Transform matrix to <a href='//"+oms_s_name+ "/math/library/matrix/type/#h7'>upper triangular form</a>, using <a href='//"+oms_s_name+ "/math/library/matrix/elementary_matrix/#h1'>elementary row operations</a> and <a href='//"+oms_s_name+ "/math/library/matrix/determinant/#h2'>properties of a matrix determinant</a>.</p>";
	this.text['ua'][21]="<p>Для обрахунку визначника зведемо матрицю до <a href='//"+oms_s_name+ "/math/library/matrix/type/#h7'>верхньотрикутнї форми</a>, скориставшись <a href='//"+oms_s_name+ "/math/library/matrix/elementary_matrix/#h1'>елементарними перетвореннями над рядками матриці</a> і <a href='//"+oms_s_name+ "/math/library/matrix/determinant/#h2'>властивостями визначника матриці</a>.</p>";
	this.text['es'][21]="<p>Для вычисления определителя приведем матрицу к <a href='//"+oms_s_name+ "/math/library/matrix/type/#h7'>верхнетреугольному виду</a>, используя <a href='//"+oms_s_name+ "/math/library/matrix/elementary_matrix/#h1'>элементарные преобразования над строками матрицы</a> и <a href='//"+oms_s_name+ "/math/library/matrix/determinant/#h2'>свойства определителя матрицы</a>.</p>";

//	this.text['ru'][22]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Разложим определитель матрицы по {n} строке:</a><br><br>';
//	this.text['en'][22]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Разложим определитель матрицы по {n} строке:</a><br><br>';
//	this.text['ua'][22]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Розкладемо визначник  матриці по {n} рядку:</a><br><br>';
//	this.text['es'][22]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Разложим определитель матрицы по {n} строке:</a><br><br>';

//	this.text['ru'][23]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Разложим определитель {i} матрицы по {n} столбцу:</a><br><br>';
//	this.text['en'][23]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Разложим определитель {i} матрицы по {n} столбцу:</a><br><br>';
//	this.text['ua'][23]='<a href='+"'"+'//'+oms_s_name+'/math/library/matrix/determinant/#h10'+"'"+'>Розкладемо визначник {i} матриці по {n} стовбцю:</a><br><br>';

	this.text['ru'][24]='<p>Выпишем союзную матрицу (матрицу алгебраических дополнений):</p>';
	this.text['en'][24]='<p>Write matrix of cofactors:</p>';
	this.text['ua'][24]='<p>Випишемо союзну матрицю (матрицю алгебраїчних доповнень):</p>';
	this.text['es'][24]='<p>Выпишем союзную матрицу:</p>';

	this.text['ru'][25]='<p>Найдем детерминант матрицы <b>А</b>:</p>';
	this.text['en'][25]='<p>Find matrix determinant:</p>';
	this.text['ua'][25]='<p>Знайдемо визначник матриці <b>А</b>:</p>';
	this.text['es'][25]='<p>Найдем детерминант матрицы <b>А</b>:</p>';

	this.text['ru'][26]='Показать детальнее ход вычисления определителя матрицы';
	this.text['en'][26]='Show detailed calculation of the determinant';
	this.text['ua'][26]='Показати детальний хід обрахунку визначника матриці';
	this.text['es'][26]='Показать детальнее ход вычисления определителя матрицы';

	this.text['ru'][27]='<p><b>Ответ:</b> Обратную матрицу невозможно найти, так как детерминант матрицы равен нулю.</p>';
	this.text['en'][27]='<p><b>Answer:</b> The inverse matrix can not be found, as the determinant of the matrix is equal to zero.</p>';
	this.text['ua'][27]='<p><b>Відповідь:</b> Обернену матрицю неможливо знайти, так як визначник матриці дорівнює нулю.</p>';
	this.text['es'][27]='<p><b>Resultado:</b> El determinante de la matriz es cero, la matriz es no invertible.</p>';

	
	this.text['ru'][28]='<p>Определитель матрицы <b>А</b> отличен от нуля, следовательно обратная матрица <b>A</b><sup>-1</sup> существует. Для вычисления обратной матрицы найдем дополнительные миноры и алгебраические дополнения матрицы <b>А</b></p>';
	this.text['en'][28]='<p>The determinant of <b>А</b> is not zero, therefore the inverse matrix <b>A</b><sup>-1</sup> exist. To calculate the inverse matrix find additional minors and cofactors of matrix <b>А</b></p>';
	this.text['ua'][28]='<p>Визначник матриці <b>А</b> відмінний від нуля, відповідно обернена матриця <b>A</b><sup>-1</sup> існує. Для обрахунку оберненої матриці знайдемо допоміжні мінори і алгебраїчні доповнення матриці <b>А</b></p>';
	this.text['es'][28]='<p>Определитель матрицы <b>А</b> отличен от нуля, следовательно обратная матрица <b>A</b><sup>-1</sup> существует. Для вычисления обратной матрицы найдем дополнительные миноры и алгебраические дополнения матрицы <b>А</b></p>';

	this.text['ru'][29]='<p>Найдем минор M{k1} и алгебраическое дополнение A{k1}. В матрице <b>А</b> вычеркиваем строку {k3} и столбец {k4}.</p>';
	this.text['en'][29]='<p>Find the minor M{k1} and the cofactor C{k1}. In matrix <b>A</b> cross out row {k3} and column {k4}.</p>';
	this.text['ua'][29]='<p>Знайдемо мінор M{k1} і алгебраїчне доповнення A{k1}. В матриці <b>А</b> викреслюємо рядок {k3} і стовпчик {k4}.</p>';
	this.text['es'][29]='<p>Найдем минор M{k1} и алгебраическое дополнение A{k1}. В матрице <b>А</b> вычеркиваем строку {k3} и столбец {k4}.</p>';

	this.text['ru'][30]='<p>Транспонированная союзная матрица:</p>';
	this.text['en'][30]='<p>Transposed matrix of cofactors:</p>';
	this.text['ua'][30]='<p>Транспонована союзна матриця:</p>';
	this.text['es'][30]='<p>Транспонированная союзная матрица:</p>';

	this.text['ru'][31]='<p>Найдем обратную матрицу:</p>';
	this.text['en'][31]='<p>Find inverse matrix:</p>';
	this.text['ua'][31]='<p>Знайдемо обернену матрицю:</p>';
	this.text['es'][31]='<p>Найдем обратную матрицу:</p>';

	this.text['ru'][32]='<p>Перепишем систему уравнений в матричном виде и решим его методом Гаусса</p>';
	this.text['en'][32]='<p>Rewrite the system in matrix form and solve it by Gaussian Elimination (Gauss-Jordan elimination)</p>';
	this.text['ua'][32]='<p>Запишемо систему рівнянь в матричному вигляді і розв&#39;яжемо її методом Гауса</p>';
	this.text['es'][32]='<p>Reescribamos el sistema de ecuaciones en forma de matrices y la resolvamos por el método de eliminación de Gauss-Jordan</p>';

//	this.text['ru'][33]='<p><b>Ответ:</b></p>';
//	this.text['en'][33]='<p><b>Answer:</b></p>';
//	this.text['ua'][33]='<p><b>Відповідь:</b></p>';
//	this.text['es'][33]='<p><b>Resultado:</b></p>';

	this.text['ru'][34]='Система уравнений не имеет решений так как:';
	this.text['en'][34]='The system of equations has no solution because:';
	this.text['ua'][34]='Система рівнянь не має розв&#39;язків так як:';
	this.text['es'][34]='El sistema de ecuaciones no tiene solución ya que:';

	this.text['ru'][35]='<p>Сделаем проверку. Подставим полученное решение в уравнения из системы и выполним вычисления:</p>';
	this.text['en'][35]='<p>Make a check:</p>';
	this.text['ua'][35]='<p>Зробимо перевірку. Підставимо отриманий розв&#39;язок в рівняння з системи і виконаємо обрахунки:</p>';
	this.text['es'][35]='<p>Vamos a verificar. Pongamos la solución obtenida en la ecuacióndel sistema y realicemos el cálculo:</p>';

	this.text['ru'][36]='<p>Проверка выполнена успешно.</p>';
	this.text['en'][36]='<p>Check completed successfully.</p>';
	this.text['ua'][36]='<p>Перевірка виконана вірно.</p>';
	this.text['es'][36]='<p>¡La verificación está completada exitosamente!</p>';

	this.text['ru'][37]='<p><b>Ответ</b>. Так как детерминант матрицы равен нулю, то система не не может быть решена этим методом (система не имеет решений или имеет множество решений).</p>';
	this.text['en'][37]='<p><b>Answer</b>. Since the determinant of a matrix is zero, this system can not be solved by this method.</p>';
	this.text['ua'][37]='<p><b>Відповідь</b>. Так як визначник матриці дорівнює нулю, то система не може бути розв&#39;язана цим методом (система не має розв&#39;язків або має множину розв&#39;язків).</p>';
	this.text['es'][37]='<p><b>Resultado</b>. Так как детерминант матрицы равен нулю, то система не не может быть решена этим методом (система не имеет решений или имеет множество решений).</p>';

	this.text['ru'][38]='<p>значит</p>';
	this.text['en'][38]='<p>so</p>';
	this.text['ua'][38]='<p>тобто</p>';
	this.text['es'][38]='<p>значит</p>';

	this.text['ru'][39]='<p>Найдем решение:</p>';
	this.text['en'][39]='<p>Find a solution:</p>';
	this.text['ua'][39]='<p>Знайдемо розв&#39;язок:</p>';
	this.text['es'][39]='<p>Найдем решение:</p>';

//	this.text['ru'][40]='<p>Ответ: так как детерминант матрицы равен нулю, то система не не может быть решена этим методом (система не имеет решений или имеет множество решений).</p>';
//	this.text['en'][40]='<p>Answer: Since the determinant of a matrix is zero, then the system has no solutions.</p>';
//	this.text['ua'][40]='<p>Відповідь: так як визначник матриці дорівнює нулю, то система не може бути розв&#39;язана цим методом (система не має розв&#39;язків або має множину розв&#39;язків).</p>';

	this.text['ru'][41]='<p>Найдем обратную матрицу методом алгебраических дополнений (если вам не подходит такой метод вычисления обратной матрицы воспользуйтесь <a href='+"'"+'//'+oms_s_name+'/math/assistance/matrix/inverse/'+"'"+'>онлайн калькулятором для вычисления обратной матрицы</a>)</p>';
	this.text['en'][41]='<p>Find the inverse matrix using matrix of cofactors (also you can calculate the inverse matrix, using the online <a href='+"'"+'//'+oms_s_name+'/math/assistance/matrix/inverse/'+"'"+'>Inverse matrix calculator (Gaussian elimination)</a>)';
	this.text['ua'][41]='<p>Знайдемо обернену матрицю методом алгебраїчних доповнень (якщо вам не підходить такий метод обрахунку оберненої матриці скористайтесь <a href='+"'"+'//'+oms_s_name+'/math/assistance/matrix/inverse/'+"'"+'>онлайн калькулятором для обрахунку оберненої матриці</a>)</p>';
	this.text['es'][41]='<p>Найдем обратную матрицу методом алгебраических дополнений (если вам не подходит такой метод вычисления обратной матрицы воспользуйтесь <a href='+"'"+'//'+oms_s_name+'/math/assistance/matrix/inverse/'+"'"+'>онлайн калькулятором для вычисления обратной матрицы</a>)</p>';

//////////////////////////////////
	this.text['ru'][42]='<p>Для разложения вектора по базису запишем векторное уравнение:</p>';
	this.text['en'][42]='<p>For the expansion of the vector in the basis, we write the vector equation:</p>';
	this.text['ua'][42]='<p>Для розкладу вектора за базисом запишемо векторне рівняння:</p>';
	this.text['es'][42]='<p>Для разложения вектора по базису запишем векторное уравнение:</p>';
	
	this.text['ru'][43]='<p>Перепишем векторное уравнение в матричном виде и решим его методом Гаусса</p>';
	this.text['en'][43]='<p>Rewrite the vector equation in matrix form and solve it by Gauss-Jordan elimination</p>';
	this.text['ua'][43]='<p>Перепишемо векторне рівняння в матричному вигляді</p>';
	this.text['es'][43]='<p>Перепишем векторное уравнение в матричном виде и решим его методом Гаусса</p>';

	this.text['ru'][44]='<b>Ответ</b>: Данная система векторов образует базис (линейно независимая система векторов), так как все ';
	this.text['en'][44]='<b>Answer</b>: This system of vectors forms the basis (linearly independent system of vectors), since all ';
	this.text['ua'][44]='<b>Відповідь</b>: Дана система векторів є базисом (лінійно незалежна система векторів), так як усі ';
	this.text['es'][44]='<b>Ответ</b>: Данная система векторов образует базис (линейно независимая система векторов), так как все ';

	this.text['ru'][45]='<b>Ответ</b>: Данная система векторов не является базисом (линейно зависимая система векторов), так как существуют ';
	this.text['en'][45]='<b>Answer</b>: This system of vectors not forms the basis (linearly dependent system of vectors), since there ';
	this.text['ua'][45]='<b>Відповідь</b>: Дана система векторів не є базисом (лінійно залежна система векторів), так як існує ';
	this.text['es'][45]='<b>Ответ</b>: Данная система векторов не является базисом (линейно зависимая система векторов), так как существуют ';
	
	this.text['ru'][46]='<p>Решим уравнение методом Гауса:</p>';
	this.text['en'][46]='<p>Solve the system of equations by Gauss-Jordan elimination:</p>';
	this.text['ua'][46]='<b>Ррозв&#39;яжемо систему рівнянь методом Гауса</p>';
	this.text['es'][46]='<p>Решим уравнение методом Гауса:</p>';

	this.text['ru'][47]='<p>Проверим образуют ли заданные вектора базис, для этого найдем определитель матрицы:</p>';
	this.text['en'][47]='<p>Let us make sure that the the set of vectors is basis, for this we find the determinant of the matrix:</p>';
	this.text['ua'][47]='<p>Перевіремо чи утворюють задані вектори базіс, для цього знайдемо визначник матриці:</p>';
	this.text['es'][47]='<p>Проверим образуют ли заданные вектора базис, для этого найдем определитель матрицы:</p>';

	this.text['ru'][48]='<p>Так как определитель матрицы равен нулю, то введеная система векторов не является базисом!</p><p>Введите другую систему базисных векторов и попробуйте снова!</p>';
	this.text['en'][48]='<p>Since the determinant of the matrix is zero, the entered system of vectors is not a basis!</p><p>Enter another system of basis vectors and try again!</p>';
	this.text['ua'][48]='<p>Так як визначник матриці дорівнює нулю, то введена система векторів не є базисом!</p><p>Введіть іншу систему базисних векторів і спробуйте знову!</p>';
	this.text['es'][48]='<p>Так как определитель матрицы равен нулю, то введеная система векторов не является базисом!</p><p>Введите другую систему базисных векторов и попробуйте снова!</p>';

	this.text['ru'][49]='<p>Так как определитель матрицы не равен нулю, то введеная система векторов является базисом.</p>';
	this.text['en'][49]='<p>Since the determinant of the matrix isn&#39;t zero, the entered system of vectors is a basis.</p>';
	this.text['ua'][49]='<p>Так як визначник матриці не дорівнює нулю, то введена система векторів є базисом.</p>';
	this.text['es'][49]='<p>Так как определитель матрицы не равен нулю, то введеная система векторов является базисом.</p>';

	this.text['ru'][50]='<p>Решим систему уравнений:</p>';
	this.text['en'][50]='<p>Solve the system of equations:</p>';
	this.text['ua'][50]='<p>Ррозв&#39;яжемо систему рівнянь:</p>';
	this.text['es'][50]='<p>Resolvemos el sistema de ecuaciones:</p>';

	this.text['ru'][51]='<p>Упростим систему:</p>';
	this.text['en'][51]='<p>Simplify the system:</p>';
	this.text['ua'][51]='<p>Спростимо систему:</p>';
	this.text['es'][51]='<p>Simplifiquemos el sistema:</p>';

	this.text['ru'][52]='<p>Поменяем {i}-ое уравнение и {j}-ое уравнения местами:</p>';
	this.text['en'][52]='<p>Interchange the {i}-th equation and {j}-th equation:</p>';
	this.text['ua'][52]='<p>Поміняємо {i}-те рівняння та {j}-те рівняння місцями:</p>';
	this.text['es'][52]='<p>cambiemos de lugares ecuaciones {i}-ésima {j}-ésimo:</p>';

	this.text['ru'][53]='<p>Поделим {i}-ое уравнение на {n}</p>';
	this.text['en'][53]='<p>Divide the {i}-th equation by {n}</p>';
	this.text['ua'][53]='<p>Поділимо {i}-те рівняння на {n}</p>';
	this.text['es'][53]='<p>Dividir {i}-ésima ecuación por {n}</p>';

	this.text['ru'][54]='<p>Из {i}-ого уравнения выразим {j} через остальные переменные</p>';
	this.text['en'][54]='<p>From {i}-th equation we find {j} by other variables</p>';
	this.text['ua'][54]='<p>З {i}-ого рівняння виразимо {j} через інші змінні</p>';
	this.text['es'][54]='<p>Из {i}-ого уравнения выразим {j} через остальные переменные</p>';
	
	this.text['ru'][55]='<p>В {n} уравнение подставляем {j}</p>';
	this.text['en'][55]='<p>In {n}-th equation substitute {j}</p>';
	this.text['ua'][55]='<p>В {n} рівняння підставимо {j}</p>';
	this.text['es'][55]='<p>En {n} ecuación pongamos {j}</p>';

	this.text['ru'][56]='<p>после упрощения получим:</p>';
	this.text['en'][56]='<p>After simplification we get:</p>';
	this.text['ua'][56]='<p>після спрощення отримаємо:</p>';
	this.text['es'][56]='<p>после упрощения получим:</p>';

	this.text['ru'][57]='<p>Теперь двигаясь от последнего уравнения к первому можно найти значения остальных переменных</p>';
	this.text['en'][57]='<p>Now moving from the last equation to first equation we can find the values of other variables</p>';
	this.text['ua'][57]='<p>Рухаючись від останнього рівняння до першого можна знайти значення інших змінних</p>';
	this.text['es'][57]='<p>Ahora pasando desde la última ecuación a la primera se puede calcular el signidicado de otras variables.</p>';

////////////////////////////	
	this.text['ru'][58]='Очистить';
	this.text['en'][58]='Clear';
	this.text['ua'][58]='Очистити';
	this.text['es'][58]='Очистить';

	this.text['ru'][59]='Размер';
	this.text['en'][59]='Size';
	this.text['ua'][59]='Розмір';
	this.text['es'][59]='Размер';

	this.text['ru'][60]='Транспонировать';
	this.text['en'][60]='Size';
	this.text['ua'][60]='Транспонувати';
	this.text['es'][60]='Транспонировать';

	this.text['ru'][61]='Умножить на';
	this.text['en'][61]='Multiply by';
	this.text['ua'][61]='Помножити на';
	this.text['es'][61]='Умножить на';

	this.text['ru'][62]='Найти определитель';
	this.text['en'][62]='Finf the determinant';
	this.text['ua'][62]='Знайти визначник';
	this.text['es'][62]='Найти определитель';

	this.text['ru'][63]='Возвести в степень';
	this.text['en'][63]='Raise to the power of';
	this.text['ua'][63]='Піднести до степеню';
	this.text['es'][63]='Возвести в степень';

	this.text['ru'][64]='Найти ранг';
	this.text['en'][64]='Finf the rank';
	this.text['ua'][64]='Знайти ранг';
	this.text['es'][64]='Найти ранг';

	this.text['ru'][65]='Найти обратную';
	this.text['en'][65]='Finf the inverse';
	this.text['ua'][65]='Знайти обернену';
	this.text['es'][65]='Найти обратную';

	this.text['ru'][66]='<p style="color:red;">Ошибка! Размеры матриц не равны!</p><p style="color:blue;">При сложении или вычитании, матрицы должны иметь одинаковый размер!!!</p>';
	this.text['en'][66]='<p style="color:red;">Error! Different size of matrices!</p><p style="color:blue;">For addition or subtraction you can use only matrices with the same size!!!</p>';
	this.text['ua'][66]='<p style="color:red;">Помилка! Розміри матриць не рівні!</p><p style="color:blue;">Під час додавання або віднімання, матриці мають бути однакового разміру!!!</p>';
	this.text['es'][66]='<p style="color:red;">Error! Different size of matrices!</p><p style="color:blue;">For addition or subtraction you can use only matrices with the same size!!!</p>';   //////////////// - need translate!!!!!

	this.text['ru'][67]='<p style="color:red;">Ошибка! Невозможно найти определитель матрицы, так как количество строк не равно количеству столбцов!</p>';
	this.text['en'][67]='<p style="color:red;">Error! Different size of matrices!</p><p style="color:blue;">For addition or subtraction you can use only matrices with the same size!!!</p>';
	this.text['ua'][67]='<p style="color:red;">Помилка! Неможливо знайти визначник матриці, так як кількість стрічок не дорівнює кількості стовпців!</p>';
	this.text['es'][67]='<p style="color:red;">Error! Different size of matrices!</p><p style="color:blue;">For addition or subtraction you can use only matrices with the same size!!!</p>';   //////////////// - need translate!!!!!

	this.text['ru'][100]='<p>Система имеет множество решений:</p>';
	this.text['en'][100]='<p>The system of equations has a solution set:</p>';
	this.text['ua'][100]='<p>Система має множину розв&#39;язків:</p>';
	this.text['es'][100]='<p>Система имеет множество решений:</p>';

	this.text['ru'][101]='A';
	this.text['en'][101]='C';
	this.text['ua'][101]='A';
	this.text['es'][101]='C';

	this.text['ru'][102]='M';
	this.text['en'][102]='M';
	this.text['ua'][102]='M';
	this.text['es'][102]='M';

	this.text['ru'][103]='<b>C</b><sup>*</sup>';
	this.text['en'][103]='<b>C</b>';
	this.text['ua'][103]='<b>C</b><sup>*</sup>';
	this.text['es'][103]='<b>C</b>';

	this.text['ru']['er']='<span style="color:red">Ошибка!</p>';
	this.text['en']['er']='<span style="color:red">Error!</p>';
	this.text['ua']['er']='<span style="color:red">Помилка!</p>';
	this.text['es']['er']='<span style="color:red">Error!</p>';
}
var matr_text = new oms_matr_text();