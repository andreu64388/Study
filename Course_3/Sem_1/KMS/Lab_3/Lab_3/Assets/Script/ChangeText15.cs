using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeText15 : MonoBehaviour {

    [SerializeField]
    Text message;

    public void OnSettings()
    {
  
        message.text = "Шаг 23232";

    }
    public void OnExit()
    {  
        message.text = "Описание";

    }
}
