package epam;

import java.sql.*;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class JDBC_EX2 {
    public static void main(String[] args) throws ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url1 = "jdbc:mysql://localhost:3306/rus_bel";
        String url2 = "jdbc:mysql://localhost:3306/bel_rus";
        String username = "my";
        String password = "1111";

        try (Connection rusBel = DriverManager.getConnection(url1, username, password)) {
            try(Connection belRus = DriverManager.getConnection(url2, username, password)) {
                System.out.println("We're connected");
                Scanner scanner = new Scanner(System.in);

                System.out.println("Enter word:");
                String word = scanner.nextLine();
                System.out.println("Enter language(ru, bel):");
                String language = scanner.nextLine();

                List<String> list = findWord(Objects.equals(language, "ru") ? rusBel : belRus , word);
                if (list.size() == 0) {
                    System.out.println("No such word in dictionary");
                } else {
                    System.out.println("Translate:");
                    for (String s : list) {
                        System.out.println(s);
                    }
                }
            } catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
    } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static List<String> findWord(Connection connection, String word) throws SQLException {
        Statement statement = connection.createStatement();
        ResultSet set = statement.executeQuery("select translate from dict where word = '" + word + "'");
        List<String> list = new java.util.ArrayList<>();
        while(set.next()) {
            list.add(set.getString("translate"));
        }
        return list;
    }
}
