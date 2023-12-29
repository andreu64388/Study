using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeText2 : MonoBehaviour {

    [SerializeField]
    Text message;

    public void OnSettings()
    {   //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ЩЕЛЧКОМ ПО КНОПКЕ 
        message.text = "Переключатель - это электрическое устройство, предназначенное для управления или переключения электрических цепей";

    }
    public void OnExit()
    {  //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ПРИ УХОДЕ КУРСОРА МЫШИ С КНОПКИ
        message.text = "Описание";

    }
}
