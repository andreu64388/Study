var dialogOn = false;

function dialog_window() {
  document.body.innerHTML +=
    "<div id='dialog' class='dialog' style='margin-left:-45px;'>" +
    "<div class='label' onclick='openDialog()'>Нажми, чтобы спросить!</div>" +
    "<div class='header'>История:</div>" +
    "<div class='history' id='history'></div>" +
    "<div class='question'><input id='Qdialog' placeholder='Введите вопрос'/> <br><button onclick='ask(\"Qdialog\")'>Спросить</button></div>" +
    "</div>";

  //API-ключ для подключения к речевому сервису Yandex
  window.ya.speechkit.settings.apikey = "5c6d6536-b453-4589-9bc7-f16c7a795106";
  //добавление элемента управления "Поле для голосового ввода"
  //с выводом распознанной речи в строку ввода текста
  var textline = new ya.speechkit.Textline("Qdialog", {
    onInputFinished: function (text) {
      document.getElementById("Qdialog").value = text;
    },
  });
}

function openDialog() {
  if (dialogOn) {
    //анимация закрытия диалогового окна
    $("#dialog").animate({ "margin-left": "-45px" }, 1000, function () {});
    dialogOn = false;
  } else {
    //анимация открытия диалогового окна
    $("#dialog").animate({ "margin-left": "-1100px" }, 1000, function () {});
    dialogOn = true;
    clearInterval(timer);
  }
}

function ask(questionInput) {
  //переменная для считывания содержания окна ввода вопроса:
  var question = document.getElementById(questionInput).value;
  //активизация диалога
  dialogOn = true;
  //создаем переменную и сохраняем в ней тег <div>
  var newDiv = document.createElement("div");
  //задаем класс оформления созданного блока
  newDiv.className = "question";
  //заполняем созданный блок текстом вопроса
  newDiv.innerHTML = question;
  //вставляем созданный блок в блок <history> и закрываем его
  document.getElementById("history").appendChild(newDiv);
  +"</div>";
  //создаем еще один блок <div>
  newDiv = document.createElement("div");
  //задаем класс оформления созданного блока
  newDiv.className = "answer";
  //наполняем созданный блок ответом, полученным от функции getAnswer()
  newDiv.innerHTML = getAnswer(question);
  //добавляем в ответ тег аудио, ссылающийся на звук от синтезатора Yandex
  newDiv.innerHTML +=
    "<audio controls='true' autoplay='true' " +
    "src='http://tts.voicetech.yandex.net/" +
    "generate?format=wav&lang=ru-RU&" +
    "key=4a4d3a13-d206-45fc-b8fb-e5a562c9f587&" +
    "text=" +
    newDiv.innerText +
    "'></audio>";
  //вставка звукового блока в блок <history>
  document.getElementById("history").appendChild(newDiv);
  //запуск звука
  if (newDiv.lastChild.tagName == "AUDIO") {
    newDiv.lastChild.play();
  }
  //прокрутка в окне истории ответов в самый низ
  document.getElementById("history").scrollTop =
    document.getElementById("history").scrollHeight;
  //очистка текстового поля для ввода нового вопроса
  document.getElementById(questionInput).value = "";
}
