import java.util.Scanner;
import java.net.Socket;
import java.io.*;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.DateFormat;


public class clienttime{
	public static void main(String args[]){
	try
   {			
	System.out.println("Client Started");
	Socket soc = new Socket("192.168.184.137",7778);
	
 	Date d = new Date();
	String strDateFormat ="HH";
	DateFormat dateformat = new SimpleDateFormat(strDateFormat);
	String formattedDate = dateformat.format(d);
	
	PrintWriter out = new PrintWriter(soc.getOutputStream(),true);
	out.println(formattedDate);	
	BufferedReader in = new BufferedReader(new 
InputStreamReader(soc.getInputStream()));
	String message = in.readLine();
	System.out.println("Server Reply: " + message);

	soc.close();
   }
	catch(Exception e)
	{e.printStackTrace();}
    }

}

