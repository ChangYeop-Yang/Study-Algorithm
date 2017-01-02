import java.util.Base64;
import java.util.Base64.Encoder;
import java.util.Scanner;

public class Test
{
	public static void main(String[] args)
	{
		Scanner mScanner = new Scanner(System.in);
		String Message = mScanner.nextLine();
		
		Encoder encoded = Base64.getEncoder();
		
		System.out.println(encoded.encodeToString(Message.getBytes()));
	}
}
