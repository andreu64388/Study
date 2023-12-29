using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class Trigger_Anim : MonoBehaviour {

    [SerializeField]
    Text message;
    public Animator anim;
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {


        if (GlobalGonfig.Step == 1)
        {


            if (Input.GetMouseButtonDown(0))
            {


                if (message.text == "Шаг 1: включите в розетку нажав клавишу C. Затем включите тумблер на источнике питания")
                {
                    message.text = "Шаг 2: двигайте на реостате ручку на 1 см, 2 см, 3 см. Делайте без серд 3 р и записывайте в табл,а после с X";
                    anim.SetTrigger("hit");
                }
            }
        }
    }


}