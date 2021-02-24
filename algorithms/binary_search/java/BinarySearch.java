
class BinarySearch {

  private static boolean BinarySearch(int[] array, int value, int left, int right) {
    if (left > right) {
      return false;
    }

    int mid = (left + right) / 2;

    if (array[mid] > value) {
      return BinarySearch.BinarySearch(array, value, left, mid - 1);
    }

    if (array[mid] < value) {
      return BinarySearch.BinarySearch(array, value, mid + 1, right);
    }

    return true;
  }

  public static boolean BinarySearch(int[] array, int value) {
    return BinarySearch.BinarySearch(array, value, 0, array.length - 1);
  }
}
