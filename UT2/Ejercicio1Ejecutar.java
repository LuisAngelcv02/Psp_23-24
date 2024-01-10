
public class Ejercicio1Ejecutar {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Ejercicio1HiloParImpar eje1= new Ejercicio1HiloParImpar(1);
		Thread par= new Thread(eje1);
		//new Thread(new Ejercicio1HiloParImpar(1)).start();
		Ejercicio1HiloParImpar eje2= new Ejercicio1HiloParImpar(2);
		
		
		//par.setPriority(Thread.MAX_PRIORITY);
		par.start();
		try {
			par.join();
		} catch (Exception e) {
			// TODO: handle exception
		}
		new Thread(eje2).start();
		
		

	}

}
