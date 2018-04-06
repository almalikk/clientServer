import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class server{
	public static void main(String[] args){
	try{
		System.out.println("Listening.....");
		ServerSocket ss = new ServerSocket(5356);
		Socket soc = ss.accept();
		System.out.println("Connection Established");
		BufferedReader in = new BufferedReader(new 
InputStreamReader(soc.getInputStream()));
		String message = in.readLine();
		PrintWriter out = new 
PrintWriter(soc.getOutputStream(),true);

		String a = new String("Assalamualaikum");
		String b = new String();
		if(message.equalsIgnoreCase(a))
		{ b = "Waalaikumussalam";}
		else
		{ b = "Are you muslim?";}
		out.println("Server Reply : " + b );
	}
	catch(Exception e)
	{ e.printStackTrace(); }
    } 
}
# clientServer_server
