using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class AnimButton : MonoBehaviour
{




    Animator anim;

    void Start()
    {
        anim = GetComponent<Animator>();
    }


    // Update is called once per frame
    void Update()
    {

        {

            if (!GlobalGonfig.isSocket) return;

            if (Input.GetKeyDown(KeyCode.E))
            {
                var prev = anim.GetBool("button");
                anim.SetBool("button", !prev);
                if (anim.GetBool("button"))
                {


                    anim.Play("On");
                }
                else
                {

                    anim.Play("Off");
                }


            }
        }
    }
}
