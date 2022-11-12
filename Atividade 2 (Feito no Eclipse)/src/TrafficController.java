package src;

import java.util.concurrent.Semaphore;

public class TrafficController {
	Semaphore sem = new Semaphore(1, true);

    public void enterLeft() {
    	try {
			sem.acquire();
			System.out.println("Carro vermelho entrando na ponte");
		} catch (InterruptedException e) {
			System.out.println("enterLeft acquire() exception");
		}
    }
    
    public void enterRight() {
    	try {
			sem.acquire();
			System.out.println("Carro azul entrando na ponte");
		} catch (InterruptedException e) {
			System.out.println("enterRight acquire() exception");
		}
    }
    
    public void leaveLeft() {
    	sem.release();
    	System.out.println("Carro vermelho saindo da ponte");
    }
    
    public void leaveRight() {
    	sem.release();
    	System.out.println("Carro azul saindo da ponte");
    }
}