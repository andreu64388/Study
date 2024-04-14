package Planes;

import java.util.Objects;

public class PassengerPlane extends Plane{

    //=================FIELDS=================
    private int capacity;

    //=================CONSTRUCTORS=================
    public PassengerPlane(String model, int maxSpeed, int maxFlightDistance, int maxLoadCapacity, int passengersCapacity) {
        super(model, maxSpeed, maxFlightDistance, maxLoadCapacity);
        this.capacity = passengersCapacity;
    }


    //=================METHODS=================
    public int getCapacity() {
        return capacity;
    }

    @Override
    public String toString() {
        return super.toString().replace("}",
                ", capacity=" + capacity +
                '}');
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof PassengerPlane)) return false;
        if (!super.equals(o)) return false;
        PassengerPlane plane = (PassengerPlane) o;
        return capacity == plane.capacity;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), capacity);
    }
}
