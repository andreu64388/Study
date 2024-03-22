package epam;

import java.sql.*;
import java.util.Scanner;

public class JDBC_EX3 {
    private static final String username = "my";
    private static final String password = "1111";

    public static void main(String[] args) throws ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter author:");
        String author = scanner.nextLine();

        System.out.println("Choose option:\n1 - find most exclamatory poem\n2 - find least narrative poem\n3 - find count sonests");
        String option = scanner.nextLine();

        switch (option) {
            case "1":
                System.out.println(findMostExclamatoryPoem(author));
                break;
            case "2":
                System.out.println(findLeastNarrativePoem(author));
                break;
            case "3":
                System.out.println(countSonnets(author));
                break;
            default:
                System.out.println("Wrong option");
        }
    }

    public static String findMostExclamatoryPoem(String author) {
        String mostExclamatoryPoem = null;

        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/PoetryDatabase", username, password);

            String sql = "SELECT id, poem FROM poems where author = '" + author + "' ORDER BY LENGTH(poem) - LENGTH(REPLACE(poem, '!', '')) DESC LIMIT 1";
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                mostExclamatoryPoem = resultSet.getString("poem");
            }

            resultSet.close();
            statement.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return mostExclamatoryPoem;
    }

    public static String findLeastNarrativePoem(String author) {
        String leastNarrativePoem = null;

        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/PoetryDatabase", username, password);

            String sql = "SELECT id, poem FROM poems where author = '" + author + "' ORDER BY LENGTH(poem) - LENGTH(REPLACE(poem, '.', '')) ASC LIMIT 1";
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                leastNarrativePoem = resultSet.getString("poem");
            }

            resultSet.close();
            statement.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return leastNarrativePoem;
    }

    public static int countSonnets(String author) {
        int sonnetCount = 0;

        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/PoetryDatabase", username, password);

            String sql = "SELECT COUNT(*) AS sonnet_count FROM poems WHERE poem LIKE 'Сонет%' and author = '" + author + "'";
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                sonnetCount = resultSet.getInt("sonnet_count");
            }

            resultSet.close();
            statement.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return sonnetCount;
    }
}
