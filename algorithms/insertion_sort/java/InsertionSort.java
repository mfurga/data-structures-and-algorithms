
public class InsertionSort {

  public static int[] InsertionSort(int[] array) {
  
    for (int i = 1; i < array.length; i++) {
      int j = i;
      int key = array[i];

      while (j > 0 && array[j - 1] > key) {
        array[j] = array[j - 1];
        j--;
      }

      array[j] = key;
    }

    return array;
  }
}