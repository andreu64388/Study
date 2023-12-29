using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AnimBlock : MonoBehaviour
{
    [SerializeField]
    Text message;
    Animator anim;
    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
    }



    void Update()
    {

      
        if (!GlobalGonfig.isSocket) return;
        if (Input.GetKeyDown(KeyCode.P))
        {

            if (message.text == "Шаг 3: После этого нужно это сделать только с переменным током. Для того, чтобы включить переменный ток нужно нажать на кнопку P")
            {
                message.text = "Шаг 4: Проведите опыт с сердечником и без. Отключите приборы на клавишу O";

            }
            var prev = anim.GetBool("block");
            anim.SetBool("block", !prev);
            if (anim.GetBool("block"))
            {
                GlobalGonfig.isConstTok = false;
                anim.Play("onBlock");
            }
            else
            {
                GlobalGonfig.isConstTok = true;
                anim.Play("OffBlock");
            }
       
        }
    }
}
