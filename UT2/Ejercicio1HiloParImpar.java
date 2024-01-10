
public class Ejercicio1HiloParImpar implements Runnable{

	
		int numhilo;
		
		public Ejercicio1HiloParImpar(int numhilo) {
			this.numhilo= numhilo;
		}
		 
	    //Constructor
	   
	    public void run() {
	         
	            //Segun el tipo hace una u otra cosa
	            switch (numhilo) {
	                case 1:
	                    for (int i = 1; i <=100; i++) {
							if ( i%2==0)
	                         System.out.println("HILO "+Thread.currentThread().getId()+" generando número "+i);
	                    }
	                    break;
	                case 2:
	                    
	                    for (int i = 101; i <=200; i++) {
							  if ( i%2==1)
	                          System.out.println("HILO "+Thread.currentThread().getId()+" generando número "+i);

	                    }
	                    break;
	                     
	            				}
	 
	    }
	

}
