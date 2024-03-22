package collections.Vegetable;

public class Vegetable implements IVegetable, Comparable {
    public String name;
    public int calories;
    public int count;

    public Vegetable(String name, int calories, int count) {
        this.name = name;
        this.calories = calories;
        this.count = count;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCalories() {
        return calories;
    }

    public void setCalories(int calories) {
        this.calories = calories;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return super.toString();
    }

    public Vegetable(){}

    @Override
    public int compareTo(Object o) {
            Vegetable f = (Vegetable) o;
            return this.count - f.count ;
    }
}
