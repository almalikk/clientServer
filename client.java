import java.net.Socket;
import java.io.*;

public class client{
	public static void main(String args[]){
	try
	{	System.out.println("Client Started");
		Socket soc = new Socket("192.168.184.137",5356);
		BufferedReader input = new 
BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a text : ");
		String message = input.readLine();
		PrintWriter out = new 
PrintWriter(soc.getOutputStream(),true);
		out.println(message);
		BufferedReader in = new 
BufferedReader(new InputStreamReader(soc.getInputStream()));
		System.out.println(in.readLine());
	}
	catch(Exception e)
	{e.printStackTrace();}
    }
}
# clientServer
# clientServer
