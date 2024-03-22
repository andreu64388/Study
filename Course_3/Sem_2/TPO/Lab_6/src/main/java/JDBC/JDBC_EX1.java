package epam;

import java.sql.*;
import java.util.List;

/**
 * Hello world!
 *
 */
public class JDBC_EX1
{
//    В БД хранится англо-русский словарь, в котором для одного
//    английского слова может быть указано несколько его значений
//    и  наоборот. Со стороны клиента вводятся последовательно
//    английские (русские) слова. Для каждого из них вывести на
//    консоль все русские (английские) значения слова.
    public static void main( String[] args ) throws ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url = "jdbc:mysql://localhost:3306/dictionaryDatabase";
        String username = "my";
        String password = "1111";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("We're connected");
            do {
                System.out.println("Enter word:");
                String word = new java.util.Scanner(System.in).nextLine();
                List<String> list = findWord(connection, word);
                if (list.size() == 0) {
                    System.out.println("No such word in dictionary");
                } else {
                    System.out.println("Translate:");
                    for (String s : list) {
                        System.out.println(s);
                    }
                }
            } while (true);
        } catch (SQLException e) {
            System.out.println("Something went wrong");
            e.printStackTrace();
        }
    }

    public static List<String> findWord(Connection connection, String word) throws SQLException {
        Statement statement = connection.createStatement();
        ResultSet set = statement.executeQuery("select translate from dictionary where word = '" + word + "'");
        List<String> list = new java.util.ArrayList<>();
        while(set.next()) {
            list.add(set.getString("translate"));
        }
        return list;
    }
}
