package fundamentals;

import java.util.Random;

public class RandomNumbers {
    public static void main(String[] args) {
        int count = 5; // Заданное количество случайных чисел
        Random random = new Random();

        System.out.println("Случайные числа с переходом на новую строку:");
        for (int i = 0; i < count; i++) {
            System.out.println(random.nextInt(100)); // Генерация случайного числа от 0 до 99
        }

        System.out.println("\nСлучайные числа без перехода на новую строку:");
        for (int i = 0; i < count; i++) {
            System.out.print(random.nextInt(100) + " "); // Генерация случайного числа от 0 до 99
        }
    }
}