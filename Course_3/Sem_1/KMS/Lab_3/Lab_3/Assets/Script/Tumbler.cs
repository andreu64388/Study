using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;


public class Tumbler : MonoBehaviour
{
    private Animator anim;

    [SerializeField]
    Text message;

    void Start()
    {
        anim = GetComponent<Animator>();
    }



    void Update()
    {
        if (!GlobalGonfig.isSocket) return;
        if (Input.GetKeyDown(KeyCode.X))
        {    if (message.text == "Шаг 2: двигайте на реостате ручку на 1 см, 2 см, 3 см. Делайте без серд 3 р и записывайте в табл,а после с X")
            {
                message.text = "Шаг 3: После этого нужно это сделать только с переменным током. Для того, чтобы включить переменный ток нужно нажать на кнопку P";

            }

        
            var prev = anim.GetBool("tumbler");

      
            anim.SetBool("tumbler", !prev);
            if (anim.GetBool("tumbler"))
            {
                anim.Play("end");

               
            }
            else
            {
                anim.Play("EndTwo");
            }
        }
    }


}