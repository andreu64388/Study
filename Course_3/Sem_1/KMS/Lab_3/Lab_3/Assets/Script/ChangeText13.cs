using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeText13 : MonoBehaviour {

    [SerializeField]
    Text message;

    public void OnSettings()
    {   //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ЩЕЛЧКОМ ПО КНОПКЕ 
        message.text = "4. Посмотреть данные на приборе ";

    }
    public void OnExit()
    {  //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ПРИ УХОДЕ КУРСОРА МЫШИ С КНОПКИ
        message.text = "Описание";

    }
}
