
using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;
using System;
public class OutputInfo : MonoBehaviour
{
    public float l = 1.5f;
    public float s = 0.000000000155f;

    [SerializeField]
    InputField textInput;

    [SerializeField]
    Text _1;
    [SerializeField]
    Text _2;
    [SerializeField]
    Text _3;
    [SerializeField]
    Text _4;
    [SerializeField]
    Text _5;
    [SerializeField]
    Text _6;
    [SerializeField]
    Text _7;
    [SerializeField]
    Text _8;
    [SerializeField]
    Text _9;
    [SerializeField]
    Text _10;
    [SerializeField]
    Text _11;
    [SerializeField]
    Text _12;
    [SerializeField]
    Text _13;
    [SerializeField]
    Text _14;
    [SerializeField]
    Text _15;
    [SerializeField]
    Text _16;
    [SerializeField]
    Text _17;
    [SerializeField]
    Text _18;
    [SerializeField]
    Text _19;
    [SerializeField]
    Text _20;
    [SerializeField]
    Text _21;
    [SerializeField]
    Text _22;
    [SerializeField]
    Text _23;
    [SerializeField]
    Text _24;
    [SerializeField]
    //---------------//


    //---------------//
    Text R1;
    [SerializeField]
    Text R2;
    [SerializeField]
    Text R3;
    [SerializeField]
    Text R1Result;
    [SerializeField]




    Text R4;
    [SerializeField]
    Text R5;
    [SerializeField]
    Text R6;
    [SerializeField]
    Text R2Result;



    [SerializeField]
    Text Z1;
    [SerializeField]
    Text Z2;
    [SerializeField]
    Text Z3;
    [SerializeField]
    Text Z1Result;



    [SerializeField]
    Text Z4;
    [SerializeField]
    Text Z5;
    [SerializeField]
    Text Z6;
    [SerializeField]
    Text Z2Result;



    [SerializeField]
    Text L1Result;


    [SerializeField]
    Text L2Result;

    public void OnButtonClicked()
    {

        if (textInput.text.Length == 0) return;


        if (_1.text == "-")
            _1.text = textInput.text.ToString();

        else if (_2.text == "-")
        {
            _2.text = textInput.text.ToString();

            R1.text = Math.Round(float.Parse(_1.text) / float.Parse(_2.text), 2).ToString();
            
        }
        else if (_3.text == "-")
        {
            _3.text = textInput.text.ToString();

        }
        else if (_4.text == "-")
        {
            _4.text = textInput.text.ToString();

            R2.text = Math.Round(float.Parse(_3.text) / float.Parse(_4.text), 2).ToString();

        }
        else if (_5.text == "-")
        {
            _5.text = textInput.text.ToString();

        }
       else if (_6.text == "-")
        {
            _6.text = textInput.text.ToString();

            R3.text = Math.Round(float.Parse(_5.text) / float.Parse(_6.text), 2).ToString();

            R1Result.text = Math.Round((float.Parse(R1.text) + float.Parse(R2.text) + float.Parse(R3.text))/3).ToString();

        }
        else if (_7.text == "-")
        {
            _7.text = textInput.text.ToString();

        }
        else if (_8.text == "-")
        {
            _8.text = textInput.text.ToString();

            R4.text = Math.Round(float.Parse(_7.text) / float.Parse(_8.text), 2).ToString();

        }
        else if (_9.text == "-")
        {
            _9.text = textInput.text.ToString();

        }
        else if (_10.text == "-")
        {
            _10.text = textInput.text.ToString();

            R5.text = Math.Round(float.Parse(_9.text) / float.Parse(_10.text), 2).ToString();

        }
        else if (_11.text == "-")
        {
            _11.text = textInput.text.ToString();

        }
        else if (_12.text == "-")
        {
            _12.text = textInput.text.ToString();

            R6.text = Math.Round(float.Parse(_11.text) / float.Parse(_12.text), 2).ToString();

            R2Result.text = Math.Round((float.Parse(R4.text) + float.Parse(R5.text) + float.Parse(R6.text)) / 3).ToString();

        }
        else if (_13.text == "-")
        {
            _13.text = textInput.text.ToString();

        }
        else if (_14.text == "-")
        {
            _14.text = textInput.text.ToString();

            Z1.text = Math.Round(float.Parse(_13.text) / float.Parse(_14.text), 2).ToString();

        }
        else if (_15.text == "-")
        {
            _15.text = textInput.text.ToString();

        }
        else if (_16.text == "-")
        {
            _16.text = textInput.text.ToString();

            Z2.text = Math.Round(float.Parse(_15.text) / float.Parse(_16.text), 2).ToString();



        }
        else if (_17.text == "-")
        {
            _17.text = textInput.text.ToString();

        }
        else if (_18.text == "-")
        {
            _18.text = textInput.text.ToString();

            Z3.text = Math.Round(float.Parse(_17.text) / float.Parse(_18.text), 2).ToString();

            Z1Result.text = Math.Round((float.Parse(Z1.text) + float.Parse(Z2.text) + float.Parse(Z3.text)) / 3).ToString();

            L1Result.text = Math.Round((float.Parse(Z1Result.text) / (2 * 3.14))).ToString();


        }
        else if (_19.text == "-")
        {
            _19.text = textInput.text.ToString();

        }
        else if (_20.text == "-")
        {
            _20.text = textInput.text.ToString();

            Z4.text = Math.Round(float.Parse(_19.text) / float.Parse(_20.text), 2).ToString();

        }
        else if (_21.text == "-")
        {
            _21.text = textInput.text.ToString();

        }
        else if (_22.text == "-")
        {
            _22.text = textInput.text.ToString();

            Z5.text = Math.Round(float.Parse(_21.text) / float.Parse(_22.text), 2).ToString();


        }
        else if (_23.text == "-")
        {
            _23.text = textInput.text.ToString();

        }
        else if (_24.text == "-")
        {
            _24.text = textInput.text.ToString();

            Z6.text = Math.Round(float.Parse(_23.text) / float.Parse(_24.text), 2).ToString();

            Z2Result.text = Math.Round((float.Parse(Z4.text) + float.Parse(Z5.text) + float.Parse(Z6.text)) / 3).ToString();

            L2Result.text = Math.Round((float.Parse(Z2Result.text) / (2 * 3.14 )),6).ToString();

        }

        textInput.text = "";

    } 



    public void Clean()
    {
        _1.text = "-";
        _2.text = "-";
        _3.text = "-";
        _4.text = "-";
        _5.text = "-";
        _6.text = "-";
        _7.text = "-";
        _8.text = "-";
        _9.text = "-";
            
        _10.text = "-";
        _11.text = "-";
        _12.text = "-";
        _13.text = "-";
        _14.text = "-";

        _15.text = "-";

        _16.text = "-";
        _17.text = "-";

        _18.text = "-";
        _19.text = "-";
        _20.text = "-";
        _21.text = "-";
        _22.text = "-";
        _23.text = "-";
        _24.text = "-";
        textInput.text = "";

         

    }

}



