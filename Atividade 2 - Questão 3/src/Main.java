package src;

//Brendo Yuki Katagi - RA 120.682
//Luan Olimpio Claro da Costa - RA 120.855
//Matheus Anido Pereira Coimbra - RA 104.112

public class Main {

    private static void nap(int ms) {
		try {
		    Thread.sleep(ms);
		} catch (InterruptedException e) {}
    }

    public static void main(String[] a) {
		final CarWindow win = new CarWindow();
	
		win.pack();
		win.setVisible(true);
	
		new Thread(new Runnable() {
			public void run() {
			    while (true) {
					nap(25);
					win.repaint();
				    }
				}
		    }).start();
	
	    }
}
