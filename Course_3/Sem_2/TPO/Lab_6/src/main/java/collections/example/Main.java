package collections.example;

import collections.Vegetable.Vegetable;

import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        Vegetable cucumber = new Vegetable("огурец", 15,3);
        Vegetable carrot = new Vegetable("морковка", 40,2);
        Vegetable cabbage = new Vegetable("капуста",25 ,6);
        Vegetable onion = new Vegetable("буряк", 41,12);
        Vegetable tomatoes = new Vegetable("пипидорка", 25,6);

        List<Vegetable> mySalad = new ArrayList<Vegetable>();
        mySalad.add(cabbage);
        mySalad.add(onion);
        mySalad.add(cucumber);
        mySalad.add(carrot);
        mySalad.add(tomatoes);

        int sumCal = 0;
        int currentCal = 25;
        ArrayList<Vegetable> findVegetable = new ArrayList<Vegetable>();

        for (var a: mySalad) {
            sumCal += a.calories;
            if(a.calories == currentCal)
            {
                findVegetable.add(a);
            }
        }
        System.out.println("Каллорийность салата: " + sumCal + " каллорий");
        System.out.println("Овощи с " + currentCal + " каллорием: ");

        for (var a: findVegetable
             ) {
            System.out.println(a.name);
        }

        System.out.println("Сортировка по количеству продуктов:");

        Collections.sort(mySalad);
        mySalad.forEach(sal -> {
            System.out.println(sal.getName() + " " + sal.getCount() + " " +
                    sal.getCalories());
        });
    }


}