using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveCam : MonoBehaviour
{

    bool move = false;
    float speed = 0.01f;
    float offset = 0;
    Vector3 startPosition;
    Vector3 needPosition;
    Quaternion startRotation;
    Quaternion needRotaton;
    public void Move0()     //функция для начального положения
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(46.7f, 124f, 830.4f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }
    public void Move1()         //функция для просмотра Пирометра
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(63.4347f, 102.7913f, 890.0599f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }
    public void Move2()     //функция для просмотра Вольтметра
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(61.32006f, 103.1837f, 880.1401f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }
    public void Move3()     //функция для просмотра Амперметра
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(87.41313f, 102.3982f, 880.9795f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }
    public void Move4()     //функция для просмотра ЛАТР
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(48.11927f, 103.1837f, 879.1404f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }
    public void Move5()     //функция для просмотра Лампы
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(31.34561f, 101.2199f, 883.7385f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }

    public void Move6()     //функция для просмотра Лампы
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(73.09177f, 101.2199f, 883.7385f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }

    public void Move7()     //функция для просмотра Лампы
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(40.74721f, 102.791f, 880.0601f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }

    public void Move8()     //функция для просмотра Лампы
    {
        move = true;
        startPosition = transform.position;
        startRotation = transform.rotation;
        needPosition = new Vector3(15.36858f, 94.15027f, 900.2919f);
        needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
    }


    void Update()
    {
        if (move)
        {
            offset += speed;
            transform.position = Vector3.Lerp(startPosition, needPosition, offset);
            transform.rotation = Quaternion.Slerp(startRotation, needRotaton, offset);
            if (offset >= 1)
            {
                move = false;
                offset = 0;
            }
        }
    }

}
