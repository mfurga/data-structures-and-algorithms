
public class SelectionSort {

  public static int[] SelectionSort(int[] array) {

    for (int i = 0; i < array.length; i++) {
      int k = i;

      for (int j = i + 1; j < array.length; j++) {
        if (array[j] > array[k]) {
          k = j;
        }
      }

      int t = array[i];
      array[i] = array[k];
      array[k] = t;
    }

    return array;
  }
}
