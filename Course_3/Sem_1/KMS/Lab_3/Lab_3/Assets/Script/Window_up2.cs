using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Window_up2 : MonoBehaviour {

    void Start()
    {
        Close(); //  ЗАКРЫТЬ ВСПЛЫВАЮЩЕЕ ОКНО ПРИ ЗАПУСКЕ ПРОГРАММЫ  
    }
    

    private bool isClose = true;
    public void Open()
    {

        if (isClose)
        {
            isClose = false;
        }
        else
        {
            isClose = true;
            
        }

        gameObject.SetActive(isClose);

    }

    public void Close()
    {
        if (!isClose)
        {
            isClose = true;

        }

        else
        {
            isClose = false;
        }
        gameObject.SetActive(isClose);


    }

}
