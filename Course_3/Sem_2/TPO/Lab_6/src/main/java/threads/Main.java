package threads;

import threads.Car;
import threads.Parking;

import java.util.Random;

//Разработать консольное многопоточное приложение.
//Использовать возможности, предоставляемые пакетом java.util.concurrent.
//Все сущности, желающие получить доступ к ресурсу, должны быть потоками.

//2. Автостоянка. Доступно несколько машиномест. На одном месте может находиться только один автомобиль.
//  Если все места заняты, то автомобиль не станет ждать больше определенного времени
//  и уедет на другую стоянку.

public class Main {
    public static void main(String[] args) {

        Parking parking = new Parking(5);

        for (var i = 1; i < 10; i++) {
            Car car = new Car("Car " + i, new Random().nextInt(4, 10), parking);
            Thread thread = new Thread(car);
            thread.start();
        }
    }
}