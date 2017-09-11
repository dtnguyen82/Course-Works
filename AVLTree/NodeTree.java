import java.lang.Math;

public class NodeTree {
	NodeTree left;
    NodeTree right;
    int value;
    int height;
    int[] matrix;

    NodeTree(int newValue) {
        value = newValue;
        int size = 0;

        switch(value % 3) {
            case 0:
            	size = (int) java.lang.Math.pow(2, 20);
                matrix = new int[size];
                break;
            case 1:
            	size = (int) java.lang.Math.pow(2, 19) + (int) java.lang.Math.pow(2, 18);
                matrix = new int[size];
                break;
            case 2:
            	size = (int) java.lang.Math.pow(2,18) + (int) java.lang.Math.pow(2, 17);
                matrix = new int[size];
                break;
            default:
                break;
        }
	    for (int i = 0; i < size; i++) {
	    	matrix[i] = 1;
	    }
    }
}
