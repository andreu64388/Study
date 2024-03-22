package threads;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

public class Parking extends  Thread {

    private int parkingCapacity;
    private int availableSpots;
    private Semaphore semaphore;

    public Parking() {
        parkingCapacity = new Random().nextInt(1, 5);
        availableSpots = parkingCapacity;
        semaphore = new Semaphore(parkingCapacity, true);
    }
    public Parking(int parkingCapacity) {
        this.parkingCapacity = parkingCapacity;
        availableSpots = parkingCapacity;
        semaphore = new Semaphore(parkingCapacity, true);
    }

    public boolean park(Car car) {

        try {
            if (semaphore.tryAcquire(car.getTimeout(), TimeUnit.SECONDS)) {
                availableSpots -= 1;
                System.out.println(car.getName() + " parked!\tAvailable parking spots: " + availableSpots);

                return true;
            }
            return false;

        } catch (InterruptedException e) {
            e.printStackTrace();
            return false;
        }
    }


    public void leave(Car car) {
        availableSpots += 1;
        System.out.println(car.getName() + " left!\tAvailable parking spots: " + availableSpots);
        semaphore.release();
    }

}
