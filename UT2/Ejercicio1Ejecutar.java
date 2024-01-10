
public class Ejercicio1Ejecutar {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
//se pueden hacer de ambas formas la que creas mas conveniente. tanto las dos lineas que estan comentadas como la que no.
		
		//Ejercicio1HiloParImpar eje1= new Ejercicio1HiloParImpar(1);
		//Thread par= new Thread(eje1);
		Thread par=new Thread(new Ejercicio1HiloParImpar(1));
		Ejercicio1HiloParImpar eje2= new Ejercicio1HiloParImpar(2);
		Thread impar= new Thread(eje2);
		

		impar.start();
		try {
			impar.join();
			
		} catch (Exception e) {
			// TODO: handle exception
		}
		
		par.start();
		

	}

}
