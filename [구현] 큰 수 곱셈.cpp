import java.util.Scanner;
import java.math.BigInteger;

public class Main{

     public static void main(String []args){
        Scanner scan = new Scanner(System.in);
        
        String[] value = scan.nextLine().split(" ");
        
        BigInteger answer = new BigInteger(value[0]);
        
        System.out.println(answer.multiply(new BigInteger(value[1])));
     }
}
