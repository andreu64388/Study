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


                if (message.text == "��� 1: �������� � ������� ����� ������� C. ����� �������� ������� �� ��������� �������")
                {
                    message.text = "��� 2: �������� �� �������� ����� �� 1 ��, 2 ��, 3 ��. ������� ��� ���� 3 � � ����������� � ����,� ����� � X";
                    anim.SetTrigger("hit");
                }
            }
        }
    }


}