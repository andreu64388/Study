package threads;

import threads.Parking;
import java.util.Random;

public class Car implements Runnable {

    private Parking parking;
    private final String name;
    private final int timeout;

    public String getName() {
        return name;
    }

    public int getTimeout() {
        return timeout;
    }

    public Car() {
        name = "Car" + new Random().nextInt(1, 20000);
        timeout = new Random().nextInt(2, 5);
        parking = new Parking();
    }
    public Car(String name, int timeout, Parking parking) {
        this.name = name;
        this.timeout = timeout;
        this.parking = parking;
    }

    @Override
    public void run() {
        try {
            if (parking.park(this)) {
                Thread.sleep(new Random().nextInt(2000, 7000));
                parking.leave(this);
            } else {
                System.out.println(this.name + " left parking because he didn't find a place");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
