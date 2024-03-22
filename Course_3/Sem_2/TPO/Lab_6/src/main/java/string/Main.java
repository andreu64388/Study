package string;

import java.util.Arrays;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) {
        String text = "Это пример текста. В этом тексте есть несколько предложений. Эти предложения содержат общие слова. Слово 'этот' встречается в нескольких предложениях.  ";

        System.out.println("Task2");
        Task2(text);

        System.out.println("Task3");
        Task3(text);

        System.out.println("Task5");
        Task5(text);

        System.out.println("Task6");
        Task6(text);

        System.out.println("Task12");
        Task12(text, 6);
    }

    static void Task2(String text) {
        String[] sentences = text.split("\\. ");

        Arrays.sort(sentences, Comparator.comparingInt(sentence -> sentence.split("\\s+").length));

        System.out.println("Предложения в порядке возрастания количества слов:");
        for (String sentence : sentences) {
            System.out.println(sentence);
        }
    }

    static void Task3(String text) {
        String[] sentences = text.split("\\. ");
        String[] firstSentenceWords = sentences[0].split("\\s+");
        boolean foundUniqueWord = false;

        for (String word : firstSentenceWords) {
            boolean isUnique = true;

            for (int i = 1; i < sentences.length; i++) {
                String[] otherSentenceWords = sentences[i].split("\\s+");
                for (String otherWord : otherSentenceWords) {
                    if (word.toLowerCase().equals(otherWord.toLowerCase())) {
                        isUnique = false;
                        break;
                    }
                }
                if (!isUnique) {
                    break;
                }
            }
            if (isUnique) {
                System.out.println("Уникальное слово в первом предложении: " + word);
                foundUniqueWord = true;
                break;
            }
        }
        if (!foundUniqueWord) {
            System.out.println("В первом предложении нет уникальных слов.");
        }
    }

    static void Task5(String text) {
        String[] sentences = text.split("\\. ");

        for (int i = 0; i < sentences.length; i++) {
            String sentence = sentences[i];
            String[] words = sentence.split("\\s+");

            if (words.length >= 2) {
                String firstWord = words[0];
                words[0] = words[words.length - 1];
                words[words.length - 1] = firstWord;
            }
            sentence = String.join(" ", words);
            sentences[i] = sentence;
        }
        String result = String.join(". ", sentences);

        System.out.println("Измененный текст:");
        System.out.println(result);
    }

    static void Task6(String text) {
        String[] words = text.split("\\s+");

        Comparator<String> wordComparator = (word1, word2) -> word1.charAt(0) - word2.charAt(0);

        Arrays.sort(words, wordComparator);

        char currentLetter = ' ';
        for (String word : words) {
            if (word.charAt(0) != currentLetter) {
                currentLetter = word.charAt(0);
                System.out.println();
            }
            System.out.print(word + " ");
        }
        System.out.println();
    }

    static void Task12(String text, int count) {
        String consonants = "бвгджзйклмнпрстфхцчшщ";
        String[] sentences = text.split("\\. ");

        for (int i = 0; i < sentences.length; i++) {
            String sentence = sentences[i];
            String[] words = sentence.split("\\s+");

            for (int j = 0; j < words.length; j++) {
                String word = words[j].toLowerCase(); // Исключаем не-буквенные символы
                if (word.length() == count && consonants.indexOf(word.charAt(0)) != -1) {
                    words[j] = "";
                }
            }
            sentence = String.join(" ", words).trim();
            sentences[i] = sentence;
        }

        String result = String.join(". ", sentences);
        System.out.println("Измененный текст:");
        System.out.println(result);
    }
}