using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeColor : MonoBehaviour
{
    private Color currentColor;

    private void Start()
    {
        Renderer renderer = GetComponent<Renderer>();
        if (renderer != null)
        {
            currentColor = GetComponent<Renderer>().material.color;
        }
    }

    public void ChangeCol()
    {
        Renderer renderer = GetComponent<Renderer>();
        if (renderer != null)
        {
            GetComponent<Renderer>().material.color = new Color(1, 1, 0); 
        }
    }

    public void ChangeCol1()
    {
        Renderer renderer = GetComponent<Renderer>();
        if (renderer != null)
        {
            GetComponent<Renderer>().material.color = currentColor; 
        }
    }
}
