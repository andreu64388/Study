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

            if (message.text == "��� 3: ����� ����� ����� ��� ������� ������ � ���������� �����. ��� ����, ����� �������� ���������� ��� ����� ������ �� ������ P")
            {
                message.text = "��� 4: ��������� ���� � ����������� � ���. ��������� ������� �� ������� O";

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
