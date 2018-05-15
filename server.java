import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class server{
	public static void main(String[] args){
	
	try{
		System.out.println("Listening.....");
		ServerSocket ss = new ServerSocket(9999);
		Socket soc = ss.accept();
		System.out.println("Connection Established");
		
	//	InetAddress addr = InetAddress.getLocalHost();
		InetAddress hostname = InetAddress.getInetAddress();
		String ip = hostname.getHostAddress();
			
	while(true){
		BufferedReader in = new BufferedReader(new 
InputStreamReader(soc.getInputStream()));
		String message = in.readLine();
		PrintWriter out = new 
PrintWriter(soc.getOutputStream(),true);

		String a = new String("Assalamualaikum");
		String q = new String("quit");
	//	String ipc = new String("getipclient");
		String ips = new String("getipserver");
	//	String hostc = new String("getHostclient");
		String hosts = new String("getHostServer");

		if(message.equalsIgnoreCase(a))
		{ out.println("Waalaikumussalam");}
		
	//	else if(message.equalsIgnoreCase(ipc))
	//	{ out.println(addr.getHostAddress()); }
		
		else if(message.equalsIgnoreCase(ips))
		{ out.println(ip);}

		else if(message.equalsIgnoreCase(hosts))
		{ out.println(hostname);}

	//	else if(message.equalsIgnoreCase(hostc))
	//   	{ out.println(addr.getLocalHost());}

		else if(message.equalsIgnoreCase(q))
		{ break ; }

		else
		{ out.println("Invalid Command");}
			
		
 }
		soc.close();
}
	catch(Exception e)
	{ e.printStackTrace(); }
	
  }
	 
}

