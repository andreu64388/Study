using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;


public class Tumbler1 : MonoBehaviour
{
    private Animator anim;

 
    void Start()
    {
        anim = GetComponent<Animator>();
    }


    void Update()
    {


        if (!GlobalGonfig.isSocket) return;

        if (Input.GetKeyDown(KeyCode.X))
        {

            
            
            var prev = anim.GetBool("tumbler2");




            anim.SetBool("tumbler2", !prev);
            if (anim.GetBool("tumbler2"))
            {

                GlobalGonfig.isHeart = false;
                anim.Play("Tumbler2");
            }
            else
            {

                GlobalGonfig.isHeart = true;
                anim.Play("Tumbler2Back");
            }
        }
    }


}