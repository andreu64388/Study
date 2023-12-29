using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeText6 : MonoBehaviour {

    [SerializeField]
    Text message;

    public void OnSettings()
    {   //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ЩЕЛЧКОМ ПО КНОПКЕ 
        message.text = "Реостат - это переменное электрическое устройство, используемое для изменения сопротивления в электрической цепи.";

    }
    public void OnExit()
    {  //  МЕТОД, ВЫЗЫВАЕМЫЙ ПОЛЬЗОВАТЕЛЕМ ПРИ УХОДЕ КУРСОРА МЫШИ С КНОПКИ
        message.text = "Описание";

    }
}
