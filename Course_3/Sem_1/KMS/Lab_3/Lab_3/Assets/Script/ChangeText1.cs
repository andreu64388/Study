using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeText1 : MonoBehaviour {

    [SerializeField]
    Text message;

    public void OnSettings()
    {   //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ЩЕЛЧКОМ ПО КНОПКЕ 
        message.text = "Трансформатор - это электрическое устройство, которое используется для передачи электрической энергии между двумя или более обмоткам.";

    }
    public void OnExit()
    {  //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ПРИ УХОДЕ КУРСОРА МЫШИ С КНОПКИ
        message.text = "Описание";

    }
}
