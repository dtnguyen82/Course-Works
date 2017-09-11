import static java.lang.System.*;
import java.util.Scanner;
import java.util.Random;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random rng = new Random();
		AVLTree tree = new AVLTree();
		int nodeCount = 0;
		int maxValue = 299;
		int Insert = 1;
		int [] numOfInsert = new int[3];
		int [] numOfDelete = new int[3];
		double [] insertTime = new double[3];
		double [] deleteTime = new double[3];
		numOfInsert[0] = 0;
		numOfInsert[1] = 0;
		numOfInsert[2] = 0;
		numOfDelete[0] = 0;
		numOfDelete[1] = 0;
		numOfDelete[2] = 0;
		insertTime[0] = 0;
		insertTime[1] = 0;
		insertTime[2] = 0;
		deleteTime[0] = 0;
		deleteTime[1] = 0;
		deleteTime[2] = 0;
		
		int i = 0;
		while(i < 100000){
			int temp = rng.nextInt(maxValue);
			if(Insert ==1 && nodeCount < 50){
				if(!tree.find(temp)){
					double start = System.nanoTime();
					tree.insert(temp);
					insertTime[(temp%3)] += (System.nanoTime()- start );
					nodeCount++;
					numOfInsert[(temp %3)]++;
					if(i%5000== 0 && i !=0){
						System.out.println("Average time for " + i);
						System.out.println("Insertions: " + ((insertTime[0]+insertTime[1]+insertTime[2])/i) + " nanoseconds");
						System.out.println("Deletions: " + ((deleteTime[0]+deleteTime[1]+deleteTime[2])/i) + " nanoseconds");
					}
					i++;
				}
			}else if(tree.find(temp)){
				double start = System.nanoTime();
				tree.remove(temp);
				deleteTime[(temp %3)] += (System.nanoTime()- start);
				if(i%5000 == 0 && i !=0){
					System.out.println("Average time for " + i);
					System.out.println("Insertions: " + ((insertTime[0]+insertTime[1]+insertTime[2])/i) + " nanoseconds");
					System.out.println("Deletions: " + ((deleteTime[0]+deleteTime[1]+deleteTime[2])/i) + " nanoseconds");
				}
				nodeCount--;
				numOfDelete[(temp%3)]++;
				i++;
			}
			Insert = rng.nextInt()%2;
		}
		System.out.println("Inserts of M=0 ["+numOfInsert[0]+"]: AVG time = "+
				(insertTime[0]/numOfInsert[0])+"nanoseconds");
		System.out.println("Inserts of M=1 ["+numOfInsert[1]+"]: AVG time = "+
				(insertTime[1]/numOfInsert[1])+"nanoseconds");
		System.out.println("Inserts of M=2 ["+numOfInsert[2]+"]: AVG time = "+
				(insertTime[2]/numOfInsert[2])+"nanoseconds");
		System.out.println("Deletes of M=0 ["+numOfDelete[0]+"]: AVG time = "+
				(deleteTime[0]/numOfDelete[0])+"nanoseconds");
		System.out.println("Deletes of M=1 ["+numOfDelete[1]+"]: AVG time = "+
				(deleteTime[1]/numOfDelete[1])+"nanoseconds");
		System.out.println("Deletes of M=2 ["+numOfDelete[2]+"]: AVG time = "+
				(deleteTime[2]/numOfDelete[2])+"nanoseconds");
				
		System.out.println("Total Insert Time: "+((insertTime[0]+insertTime[1]+insertTime[2])/1000000000)+" seconds");
		System.out.println("Total Delete Time: "+((deleteTime[0]+deleteTime[1]+deleteTime[2])/1000000000)+" seconds");
	}

}
