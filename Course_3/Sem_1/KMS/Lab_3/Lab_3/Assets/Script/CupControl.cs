using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class CupControl : MonoBehaviour
{
    Animator cup;


    void Start()
    {
        cup = GetComponent<Animator>();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.T)) { cup.SetTrigger("hit"); }
    }
}