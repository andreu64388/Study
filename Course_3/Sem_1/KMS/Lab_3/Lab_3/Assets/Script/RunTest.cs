using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;


public class RunTest : MonoBehaviour
{
    private Animator anim;

    public delegate void PlayInstChanged(bool newValue);
    public static event PlayInstChanged OnPlayInstChanged;
    void Start()
    {
        anim = GetComponent<Animator>();
    }


    void Update()
    {
        if (Input.GetKeyDown(KeyCode.C))
        {




            GlobalGonfig.isSocket = true;
            GlobalGonfig.Step = 1;
            anim.SetBool("run",true);
            OnPlayInstChanged(true);
        }

        if (Input.GetKeyDown(KeyCode.O))
        {

            GlobalGonfig.Step = 0;
            GlobalGonfig.isSocket = false ;
            anim.SetBool("run", false); 
            OnPlayInstChanged(false);
        }
    }


}